#include "../include/option_handler.h"



int main(int argc, char* argv[]) {
    int exitCode = handleOptions(argc, argv);
    std::cout << std::endl << "Run again with options in terminal" << std::endl;
    std::string userInput;
    std::getline(std::cin, userInput);
    return exitCode;
}