/*
 * Author: Chris Dorr & Jordyn Marlow
 * Assignment Number: 1
 * Date of Submission: 10/21/2020
 * 5ps.c
 *
 * Student written version of the ps command.
 * Supports 5 options, p, s, t, v, and c
 * -p <PID>         When provided PID, 5ps returns information about
 *                  the process with a process ID equal to PID
 * -s               Display single-character state information about 
 *                  the process
 * -t               Display total time consumed by the process in
 *                  HH:MM:SS format
 * -v               Display pages of virtual memory currently being
 *                  used by this process
 * -c               Display the command-line that started this process 
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "options.h"

const int GETOPT_FAILURE = -1;
const int PID_DEFAULT = 1;

int main(int argc, char *argv[]) {
    int op;
    int pid = PID_DEFAULT;
    bool pid_was_set = false;

    char state_char;
    char* uptime;
    char virtual_mem[BUFFER_LEN];
    char cmd_line[BUFFER_LEN];

    while ((op = getopt(argc, argv, "p:stvc")) != GETOPT_FAILURE) {
        switch (op) {
	    case 'p':
		//Display PID when given PID value as argument
 		pid = atoi(optarg);
		pid_was_set = true;
		printf("PID:  %d\n", pid);
	        break;
            case 's':
	        //Single Character State Information
                state_char = return_state_character(pid);
                printf("STAT: %c\n", state_char);
		break;
            case 't':
	        //utime information
		uptime = return_uptime(pid);
		printf("TIME: %s\n", uptime);
	        break;
            case 'v':
		//Virtual Memory Used (Pages)
	        return_virtual_mem(pid, virtual_mem);
		printf("VMEM: %s\n", virtual_mem);
	        break;
            case 'c':
		//Display Command Line which started this process
                return_command_line(pid, cmd_line);
		printf("CMD:  %s\n", cmd_line);
		break;
            default:
		exit(EXIT_FAILURE);
        }
    }
    
    exit(EXIT_SUCCESS);
}
