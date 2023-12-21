#include "../include/option_handler.h"

#include <iostream>

#define RESET         "\033[0m"
#define BRIGHT_RED    "\033[91m"
#define BRIGHT_YELLOW "\033[93m"

/*
Arguments:
-m file/lines/words (mode)
-v true/false (verbose)
-o outputfile.txt (output)
*/

int handleOptions(int argc, char* argv[]) {
    std::map<std::string, std::string> optionMap;
    if (argc == 1) {
        handleMissingFlag();
        return 1;
    }
    for (int i = 1; i < argc; i+=2) {
        std::string currentFlag = std::string(argv[i]);
        std::string nextArgument;
        if (argc > i+1)
            nextArgument = std::string(argv[i+1]);
        if (currentFlag == "-h") {
            help();
            return 0;
        } else if (currentFlag == "-m") {
            if (handleModeOption(optionMap, currentFlag, nextArgument) == 1)
                return 1;
        } else if (currentFlag == "-v") {
            if (handleVerboseOption(optionMap, currentFlag, nextArgument) == 1)
                return 1;
        } else if (currentFlag == "-o") {
            if (handleOutputOption(optionMap, currentFlag, nextArgument) == 1)
                return 1;
        } else {
            handleUnrecognizedFlag(currentFlag);
            return 1;
        }
    }
    for (const auto &pair : optionMap) {
        std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
    }
    return 0;
}

void help() {
    std::cout << "Options:" << std::endl;
    std::cout << "-h show options" << std::endl;
    std::cout << "-m set mode" << std::endl;
    std::cout << "-o write to output file" << std::endl;
    std::cout << "-v print output" << std::endl;
}

int handleModeOption(std::map<std::string, std::string> &optionMap, const std::string &currentFlag, const std::string &nextArgument) {
    if (checkDuplicateFlag(optionMap, currentFlag))
        return 1;
    if (checkMissingArgument(currentFlag, nextArgument))
        return 1;
    if (nextArgument == "lines") {
        optionMap[currentFlag] = "lines";
        return 0;
    } else if (nextArgument == "words") {
        optionMap[currentFlag] = "words";
        return 0;
    }  else {
        handleInvalidArgument(currentFlag, nextArgument);
        return 1;
    }
}

int handleVerboseOption(std::map<std::string, std::string> &optionMap, const std::string &currentFlag, const std::string &nextArgument) {
    if (checkDuplicateFlag(optionMap, currentFlag))
        return 1;
    if (checkMissingArgument(currentFlag, nextArgument))
        return 1;
    if (nextArgument == "true") {
        optionMap[currentFlag] = "true";
        return 0;
    } else if (nextArgument == "false") {
        optionMap[currentFlag] = "false";
        return 0;
    }  else {
        handleInvalidArgument(currentFlag, nextArgument);
        return 1;
    }
}

int handleOutputOption(std::map<std::string, std::string> &optionMap, const std::string &currentFlag, const std::string &nextArgument) {
    if (checkDuplicateFlag(optionMap, currentFlag))
        return 1;
    if (checkMissingArgument(currentFlag, nextArgument))
        return 1;
    if (checkInvalidFileName(currentFlag, nextArgument))
        return 1;
    optionMap[currentFlag] = nextArgument;
    return 0;
}

bool checkDuplicateFlag(const std::map<std::string, std::string> &optionMap, const std::string &currentFlag) {
    if (optionMap.count(currentFlag) > 0) {
        handleDuplicateFlag(currentFlag);
        return true;
    }
    return false;
}

bool checkMissingArgument(const std::string &currentFlag, const std::string &nextArgument) {
    if (nextArgument == "") {
        handleMissingArgument(currentFlag);
        return true;
    }
    return false;
}

bool checkInvalidFileName(const std::string &currentFlag, const std::string &nextArgument) {
    // Invalid characters for file
    const std::string invalidCharacters = "\\/:*?\"<>|";
    for (char c : invalidCharacters) {
        if (nextArgument.find(c) != std::string::npos) {
            handleInvalidFileName(currentFlag, nextArgument);
            return true;
        }
    }
    // File cannot end with a '.'
    if (nextArgument.back() == '.') {
        handleInvalidArgument(currentFlag, nextArgument);
        return true;
    }
    return false;
}

void handleMissingFlag() {
    std::cerr << BRIGHT_RED << "Usage: FileReader.exe [options]" << RESET << std::endl;
    std::cout << std::endl << BRIGHT_YELLOW << "Use -h to get help" << RESET << std::endl;
}

void handleDuplicateFlag(const std::string &currentFlag) {
    std::cerr << BRIGHT_RED << "Duplicate flag '" << currentFlag << "'" << RESET << std::endl;
}

void handleUnrecognizedFlag(const std::string &currentFlag) {
    std::cerr << BRIGHT_RED << "Unrecognized flag '" << currentFlag << "'" << RESET << std::endl;
}

void handleMissingArgument(const std::string &currentFlag) {
    std::cerr << BRIGHT_RED << "Missing argument for flag '" << currentFlag << "'" << RESET << std::endl;
}

void handleInvalidArgument(const std::string &currentFlag, const std::string &nextArgument) {
    std::cerr << BRIGHT_RED << "Invalid argument '" << nextArgument << "' for '" << currentFlag << "'" << RESET << std::endl;
}

void handleInvalidFileName(const std::string &currentFlag, const std::string &nextArgument) {
    std::cerr << BRIGHT_RED << "Invalid file name '" << nextArgument << "' for '" << currentFlag << "'" << RESET << std::endl;
}