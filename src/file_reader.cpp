#include "../include/file_reader.h"

#include <iostream>
#include <fstream>
#include <sstream>

#define RESET         "\033[0m"
#define BRIGHT_RED    "\033[91m"

std::vector<std::string> readFile(std::string inputFile, std::string mode) { // we add this to header later
    std::ifstream file(inputFile);
    std::vector<std::string> outputVector;
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            if (mode == "lines") {
                outputVector.push_back(line);
            } else if (mode == "words") {
                std::istringstream iss(line);
                std::string word;
                while (iss >> word) {
                    outputVector.push_back(word);
                }
            }

        }
    }
    else {
        std::cerr << BRIGHT_RED << "Cannot open file '" << inputFile << "'" << RESET << std::endl;
    }
    return outputVector;
}