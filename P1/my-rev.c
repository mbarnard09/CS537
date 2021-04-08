///////////////////////////////////////////////////////////////////////////////
// name: Mathew barnard
// class: cs 537 spring 2021
// file: my-rev.c
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
    char *fileName;
    FILE *strCheck = NULL;
    if (argc > 1) {
        if (strcmp(argv[1], "-V") == 0) {
            printf("%s\n", "my-rev from CS537 Spring 2021");
            exit(0);
        }
        if (strcmp(argv[1], "-h") == 0) {
            printf("%s\n", "no help for you xD lmao");
            exit(0);
        }
        // this if neither -h or -V and more than 3 arguments ./file -f file
        if (argc > 3) {
            printf("%s\n", "my-rev: invalid command line");
            exit(1);
        }

        // now we deal with -f case
        // char *fileName;
        // FILE *strCheck = NULL;

        if (strcmp(argv[1], "-f") == 0) {
            // this is in case of ./my-rev -f (no file)
            if (argc < 3) {
                printf("%s\n", "my-rev: invalid command line");
                exit(1);
            }
            fileName = argv[2];
        // this is when -f is not present
        } else {
            printf("%s\n", "my-rev: invalid command line");
            exit(1);
        }
    } else {
        strCheck = stdin;
        // this covers options that arent valid
        if (argc > 1) {
            printf("%s\n", "my-rev: invalid command line");
            exit(1);
        }
    }
    // now we deal with getting file or stdin into reverse order
    char *str;
    char word[256];
    char *newStr;
    char newStrVar[256];
    if (strCheck == NULL) {
        FILE *fp;
        fp = fopen(fileName, "r");
        if (fp == NULL) {
            printf("%s\n", "my-rev: cannot open file");
            exit(1);
        }
        // read file and reverse lines
        int j = 0;
        newStr = newStrVar;
        int h = 0;
        while (fgets(word, 256, fp) != NULL) {
            if (h > 0) {
                printf("\n");
            }
            h++;
            str = word;
            j = 0;
            for (int i = strlen(str); i >= 0; i--) {
                if (str[i-1] != '\n') {
                    newStr[j] = str[i-1];
                    j++;
                }
            }
            printf("%s", newStr);
        }
        if (h > 1) {
            printf("\n");
        }
    } else {
        int j = 0;
        newStr = newStrVar;
        int h = 0;
        while (fgets(word, 256, strCheck) != NULL) {
            if (h > 0) {
                printf("\n");
            }
            h++;
            str = word;
            j = 0;
            for (int i = strlen(str); i >= 0; i--) {
                if (str[i-1] != '\n') {
                    newStr[j] = str[i-1];
                    j++;
                }
            }
            printf("%s", newStr);
        }
        if (h > 1) {
            printf("\n");
        }
    }
}
