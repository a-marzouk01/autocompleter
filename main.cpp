#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <fstream>

std::map<std::string, int> words;

void typo(std::string str) {
}

void frequancies() {
    std::ifstream myfile ("words.txt");

    if (!myfile.is_open()) { 
        std::cerr << "Error opening the file!" << std::endl; 
        return ; 
    }

    std::string line;
    while (getline(myfile, line)) { 
        std::string word;
        int freq;

        std::stringstream ss(line);

        ss >> word >> freq;

        words.insert(std::make_pair(word, freq));
    }
    myfile.close();

    // std::ifstream story("story.txt");
    // if (!story.is_open()) { 
    //     std::cerr << "Error opening the file!" << std::endl; 
    //     return ; 
    // }
    //
    // std::string ln;
    // while (getline(story, ln)) {
    //     std::string word;
    //     std::stringstream ss(ln);
    //
    //     while (ss >> word) {
    //         if (words.find(word) != words.end()) {
    //             words[word]++;
    //         } else {
    //             words.insert(std::make_pair(word, 1));
    //         }
    //     }
    // }

    std::ofstream mfile("words.txt");
    if (!mfile.is_open()) { 
        std::cerr << "Error opening the file!" << std::endl; 
        return ; 
    }

    for (auto it = words.begin(); it != words.end(); ++it) {
        mfile << it->first << " " << it-> second << std::endl;
    }
}

int main() {
    frequancies();

    std::string str;
    std::cout << "Enter your word: ";
    std::cin >> str;

    auto it = words.find(str);
    if (it != words.end()) {
        std::cout << "The word " << it->first << " appears " << it->second << " times." << std::endl;
    } else {
        typo(str);
    }

    return 0;
}
