#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX_PROCESSES = 1000;

struct process {
    int number;
    int start;
    int size;
};

int main(int argc, char *argv[]) {
    int process_count = 0;
    int memory_pointer = 0;

    long memory_size = atoi(argv[1]);
    char * input[1000];
    struct process processes[MAX_PROCESSES];

    while( 1 ) {

        printf("allocater> ");
        gets(input);

        char * command = strtok(input, " "); 
        //printf("%s\n", command);
        //Request
        if (strcmp(command, "RQ") == 0) {
            struct process p;
            //P0
            p.number = atoi(strtok(NULL, " ") + sizeof(char));
            p.size = atoi(strtok(NULL, " "));
            char * mode = strtok(NULL, " ");

            //handle_mode(mode);

            processes[process_count++] = p;
             
        } else if (strcmp(command, "RL") == 0) {

        } else if (strcmp(command, "C") == 0) {

        } else if (strcmp(command, "STAT") == 0) {

        } else if (strcmp(command, "X") == 0) {
            printf("Goodbye\n");
            exit(EXIT_SUCCESS);
        } else {
            printf("Please enter a valid input.\n");
        }
    }
}