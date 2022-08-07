#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * FORMAT:
 * termble <book> <chapter>:<verse>
 */

// Logo
char *logo[16] = {
    " ",
    "          ___        ",
    "          | |        ",
    "          | |        ",
    "          | |        ",
    "  |-----------------|",
    "  |-----------------|",
    "          | |        ",
    "          | |        ",
    "          | |        ",
    "          | |        ",
    "          | |        ",
    "          | |        ",
    "          | |        ",
    "          |_|        ",
    " "
};

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
        // logo size
        size_t size = sizeof(logo) / sizeof(logo[0]);

        // print logo
        for (int i = 0; i < size; i++)
            printf("%s\n", logo[i]);

        // exit
        exit(0);
    }

    // args array
    char *args[500];
    int start = argc - 1;

    for (int i = 1; i < argc; i++)
        args[i - 1] = argv[i];

    // join args
    char *identifier = (char*) malloc(500);

    // join
    for (int i = 0; i < start; i++)
    {
        // create temp variable
        char *tmp = (char*) malloc(strlen(args[i] + 1));
        sprintf(tmp, "%s ", args[i]);
        
        // concatenate to identifier
        strcat(identifier, tmp);

        // free temp variable
        free(tmp);
    }

    // remove last space
    identifier[strlen(identifier) - 1] = '\0';

    // create command
    char *command = (char*) malloc(100);
    sprintf(command, "cd /usr/bin && node termble_get.js %s", identifier);

    // run command
    system(command);

    // free memory
    free(identifier);
    free(command);
}