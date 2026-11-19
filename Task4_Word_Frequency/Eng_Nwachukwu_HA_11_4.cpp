#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cctype>

int main() {
    std::ifstream in_file("sample_text.txt");

    if (!in_file) {
        std::cerr << "Error opening sample_text.txt" << std::endl;
        return 1;
    }

    std::map<std::string, int> word_count;
    std::string word;

    while (in_file >> word) {
        std::string clean_word;

        for (char ch : word) {
            unsigned char character = static_cast<unsigned char>(ch);

            if (std::isalnum(character)) {
                clean_word += static_cast<char>(std::tolower(character));
            }
        }

        if (!clean_word.empty()) {
            word_count[clean_word]++;
        }
    }

    in_file.close();

    std::ofstream out_file("word_count.txt");

    if (!out_file) {
        std::cerr << "Error opening word_count.txt" << std::endl;
        return 1;
    }

    std::cout << "\nWord frequencies:\n";

    for (const auto& entry : word_count) {
        std::cout << entry.first << ": " << entry.second << std::endl;
        out_file << entry.first << ": " << entry.second << std::endl;
    }

    out_file.close();

    std::cout << "\nResults saved to word_count.txt" << std::endl;

    return 0;
}
