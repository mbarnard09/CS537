///////////////////////////////////////////////////////////////////////////////
// name: Mathew barnard
// class: cs 537 spring 2021
// file: my-look.c
// project: P1: UNIX Utilities
///////////////////////////////////////////////////////////////////////////////
// OUTSIDE HELP////////////////////////////////////////////////////////////////
// Sources: Tutorialspoint.com helped with some syntax
///////////////////////////////////////////////////////////////////////////////
// Copyright 2021 Mathew Barnard
// Posting or sharing this file is prohibited
//
///////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    // if just progam name
    if (argc < 2) {
        printf("%s\n", "my-look: invalid command line");
        exit(1);
    }
    if (strcmp(argv[1], "-V") == 0) {
        printf("%s\n", "my-look from CS537 Spring 2021");
        exit(0);
    }
    if (strcmp(argv[1], "-h") == 0) {
        printf("%s\n", "no help for you xD lmao");
        exit(0);
    }
    // this if neither -h or -V and more than 4 arguments ./file -f file code.
    if (argc > 4) {
        printf("%s\n", "my-look: invalid command line");
        exit(1);
    }

    char *fileName;
    char *codeName;
    FILE *strCheck = NULL;
    // this deals with the argument -f present
    if (strcmp(argv[1], "-f") == 0) {
        fileName = argv[2];
        // here we should check for stdin
        if (argc >=3) {
            codeName = argv[3];
        } else if (argc < 3) {
            printf("%s\n", "my-look: invalid command line");
            exit(1);
        }
    // this is the case when -f is not present
    } else {
        // when f is not present and too many args
        if (argc > 2) {
            printf("%s\n", "my-look: invalid command line");
            exit(1);
        }
        codeName = argv[1];
        // argv[1] can no longer be anything with a - at the start
        char cdd = codeName[0];
        if (cdd == '-') {
            printf("%s\n", "my-look: invalid command line");
            exit(1);
        }
        strCheck = stdin;
    }

    char *str;
    char word[256];
    if (strCheck == NULL) {
        FILE *fp;
        fp = fopen(fileName, "r");
        if (fp == NULL) {
            printf("my-look: cannot open file\n");
            exit(1);
        }
        // need to read file using fgets
        while (fgets(word, 256, fp) != NULL) {
            str = word;
            int check = 0;
            for (int i=0; i < strlen(codeName); i++) {
                if (tolower(str[i]) == codeName[i]) {
                    check = 1;
                } else {
                    check = 0;
                    break;
                }
            }
            if (check == 1) {
                printf("%s", str);
            }
        }
        fclose(fp);
    } else {
        while (fgets(word, 256, strCheck) != NULL) {
            str = word;
            int check = 0;
            for (int i=0; i < strlen(codeName); i++) {
                if (tolower(str[i]) == codeName[i]) {
                    check = 1;
                } else {
                    check = 0;
                    break;
                }
            }
            if (check == 1) {
                printf("%s", str);
            }
        }
    }
}
