//  main.c
//  HYoshidaNucleotideCounter
//  Created by Hideaki Yoshida on 2017/02/07.
//  Copyright © 2017年 Hideaki Yoshida. All rights reserved.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    setvbuf(stdout, NULL, _IONBF, 0);
    
    int numA = 0;
    int numC = 0;
    int numG = 0;
    int numT = 0;
    
    char inFilename[101]; // To store the name of the file to read.
    char outFilename[101];
    char nextChar; // To store character while reading through file.
    FILE *inFile;
    FILE *outFile;
    int nameLength;
    
    printf("Enter input filename:\n");
    fgets(inFilename, 100, stdin);
    nameLength = (int) strlen(inFilename);
    inFilename[nameLength-1] = '\0';
    
    printf("Enter output filename:\n");
    fgets(outFilename, 100, stdin);
    nameLength = (int) strlen(outFilename);
    outFilename[nameLength-1] = '\0';
    
    // Open the files.
    inFile = fopen(inFilename, "r");
    outFile = fopen(outFilename, "w");

    if (inFile == NULL) {
        printf("File could not be opened.\n");
    } else {
        while (!feof(inFile)) {
            fscanf(inFile, "%c", &nextChar);
            // nextChar = fgetc(fp);
            switch (nextChar) {
                case 'A':
                    numA++;
                    break;
                case 'C':
                    numC++;
                    break;
                case 'G':
                    numG++;
                    break;
                case 'T':
                    numT++;
                    break;
                case '\n':
                    fprintf(outFile, "%d %d %d %d \n", numA, numC, numG, numT);
                    numA = 0;
                    numC = 0;
                    numG = 0;
                    numT = 0;
                    break;
            }
        }
    }
    
    // Close the files.
    fclose(inFile);
    fclose(outFile);

    printf("Complete\n");

    return 0;
}
