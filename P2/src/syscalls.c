///////////////////////////////////////////////////////////////////////////////
// name: Mathew barnard
// class: cs 537 spring 2021
// file: syscalls.c
// project: P2
///////////////////////////////////////////////////////////////////////////////
// OUTSIDE HELP////////////////////////////////////////////////////////////////
// Sources: Tutorialspoint.com helped with some syntax
///////////////////////////////////////////////////////////////////////////////
// Copyright 2021 Mathew Barnard
// Posting or sharing this file is prohibited
//
//////////////////////////////////////////////////////////////////////////////
#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[]) {
    int j = 0;
    for (int i = 1; i < atoi(argv[2]); i++) {
         j = getpid();
	 j++;
    }
    // unsuccessful
    for (int m = 0; m < (atoi(argv[1]) - atoi(argv[2])); m++) {
        kill(-1);
    }
    //for (int i = 0; i < 5; i++) {
        //kill(6969696);
    //}
    int pid = getpid();
    int getNumSysCalls = getnumsyscalls(pid);
    int sysCallsGood = getnumsyscallsgood(pid);
    //int num = numSysCalls;
    //printf(1, "The number of successful system calls is %d\n", num);
    printf(1, "%d %d\n", getNumSysCalls, sysCallsGood);
    //printf(1, "The number of successful system calls is %d\n", getnumsyscallsgood(getpid()));
    exit();
}
