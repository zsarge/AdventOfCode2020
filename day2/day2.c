/* 
 * advent of code, day 2
 * https://adventofcode.com/2020/day/2
 * using C, built with GNU Make 4.1
 * by Zack Sargent
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
general structure:

function testLine(string) return int
readfilebylines(file) {
    for each line
        count += testline(line)
    return count
}
*/

int charToInt(char c)
{
    return c - '0';
}

int strToInt(char *str)
{
    printf("Str: ");
    for (size_t i = 0; i < strlen(str); i++)
    {
        printf("%c", str[i]);
    }

    printf("\n");
    return 1;
    // int length = strlen(str);
    // printf("String %s", str);
    // printf(" - length %d\n", length);
    // unsigned int result = 0;
    // if (length <= 0)
    //     return NULL;
    // if (length == 1)
    //     return charToInt(*str);
    // for (int i = 0; i < length; i++)
    // {
    //     result += charToInt(str[i]);
    //     result *= 10;
    // }
    // result /= 10;
    // return result;
}

// Checks the validity of a line
// for reference, lines take the form
// 17-19 b: bbbbbbbbbbbbbbbbbbq
// More info is on the website.
int checkLine(char *line)
{
    char firstBound[10];
    char secondBound[10];
    size_t pos = 0; // line position
    size_t secondPos = 0;

    char charToCheck;
    char lineToCheck[100];

    do
    {
        firstBound[pos] = line[pos];
        pos++;
    } while (line[pos] != '-');
    printf("first bound: %c", line[pos]);
    printf("at index %d\n", pos);

    printf("first: \t%d\n", strToInt(firstBound));
    pos++;
    while (line[pos] != ' ')
    {
        secondBound[secondPos] = line[pos];
        secondPos++;
        pos++;
    }
    printf("second bound: %c", line[pos]);
    printf("at index %d\n", pos);
    // 17-19 b: bbbbbbbbbbbbbbbbbbq
    pos++;
    charToCheck = line[pos];
    printf("snd: \t%d\n", strToInt(secondBound));
    printf("char: \t%c\n", charToCheck);

    pos += 3;
    secondPos = 0;
    for (; pos < strlen(line); pos++)
    {
        lineToCheck[secondPos] = line[pos];
        secondPos++;
    }
    lineToCheck[secondPos] = '\0';

    printf("Line: \t%s\n", lineToCheck);
    printf("\n");

    return 1;
}

// returns the number of valid passwords in file
int countValidPasswordsInFile(char *fileName)
{
    unsigned int count = 0;
    FILE *file = fopen(fileName, "r");
    char line[256];

    if (file == NULL)
    {
        return NULL;
    }

    // read file line by line
    while (fgets(line, sizeof(line), file))
    {
        count += checkLine(line);
    }
    fclose(file);

    return count;
}

int main()
{
    unsigned count;

    count = countValidPasswordsInFile("./input.txt");
    printf("%d\n", count);
    // printf("%s\n", readFile("./input.txt"));
    return 0;
}