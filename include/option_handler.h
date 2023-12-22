#ifndef OPTION_HANDLER_H
#define OPTION_HANDLER_H

#include <string>
#include <map>
#include <iostream>

int handleOptions(int argc, char* argv[]);

int handleOptionFlow(std::map<std::string, std::string> &optionMap);
void help();

int handleInputOption(std::map<std::string, std::string> &optionMap, const std::string &currentFlag, const std::string &nextArgument);
int handleOutputOption(std::map<std::string, std::string> &optionMap, const std::string &currentFlag, const std::string &nextArgument);
int handleModeOption(std::map<std::string, std::string> &optionMap, const std::string &currentFlag, const std::string &nextArgument);
int handleVerboseOption(std::map<std::string, std::string> &optionMap, const std::string &currentFlag, const std::string &nextArgument);

bool checkDuplicateFlag(const std::map<std::string, std::string> &optionMap, const std::string &currentFlag);
bool checkMissingArgument(const std::string &currentFlag, const std::string &nextArgument);
bool checkInvalidFileName(const std::string &currentFlag, const std::string &nextArgument);
bool checkMissingFile(const std::string &currentFlag, const std::string &nextArgument);

void handleMissingFlag();
void handleDuplicateFlag(const std::string &currentFlag);
void handleUnrecognizedFlag(const std::string &currentFlag);
void handleMissingArgument(const std::string &currentFlag);
void handleInvalidArgument(const std::string &currentFlag, const std::string &nextArgument);
void handleInvalidFileName(const std::string &currentFlag, const std::string &nextArgument);
void handleMissingFile(const std::string &currentFlag, const std::string &nextArgument);

#endif