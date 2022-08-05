#include <iostream>
#include <vector>
#include <cstring>
#include <string.h>

/**
 * FORMAT:
 * termble <book> <chapter>:<verse>
 */

/**
 * @brief Main function
 * 
 * @param argc - argument count
 * @param argv - argument array
 * @return int 
 */
int main(int argc, char *argv[])
{
    // check argument length
    if (argc < 3) {
        // print cross
        std::cout << std::endl;
        std::cout << "          ___        " << std::endl;
        std::cout << "          | |        " << std::endl;
        std::cout << "          | |        " << std::endl;
        std::cout << "          | |        " << std::endl;
        std::cout << "  |-----------------|" << std::endl;
        std::cout << "  |-----------------|" << std::endl;
        std::cout << "          | |        " << std::endl;
        std::cout << "          | |        " << std::endl;
        std::cout << "          | |        " << std::endl;
        std::cout << "          | |        " << std::endl;
        std::cout << "          | |        " << std::endl;
        std::cout << "          | |        " << std::endl;
        std::cout << "          | |        " << std::endl;
        std::cout << "          |_|        " << std::endl;
        std::cout << std::endl << std::endl;

        // exit
        exit(0);
    }

    // args vector
    std::vector <std::string> args_vec;

    // loop through args
    for (auto i = 0; i < argc; i++)
    {
        // push to args
        std::string arg(argv[i]);
        args_vec.push_back(arg);
    }

    // remove command index
    args_vec.erase(args_vec.begin());

    // create identifier
    char *identifier = (char*) malloc(100);
    for (auto index : args_vec)
    {
        char *array = new char[index.length() + 1];
        std::strcpy(array, index.c_str());
        std::strcat(identifier, array);
        std::strcat(identifier, " ");
    }

    // remove last whitespace
    identifier[std::strlen(identifier) - 1] = '\0';

    // create command
    char *command = (char*) malloc(100);
    sprintf(command, "node termble_get.js %s", identifier);

    // run command
    system(command);

    // free memory
    free(identifier);
    free(command);
}