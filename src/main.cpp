#include "../include/option_handler.h"
#include "../include/data_handler.h"
#include "../include/file_reader.h"

#include <iostream>

int main(int argc, char* argv[]) {
/*     if (handleOptions(argc, argv) == 1) {
        return 1;
    }
    return 0; */
    return handleOptions(argc, argv);
}