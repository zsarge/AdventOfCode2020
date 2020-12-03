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

// stop is non-inclusive
int strToInt(int start, int stop, char *line)
{
    int result = 0;
    if ((start + 1) == stop) {
        return charToInt(line[start]);
    }

    for (size_t i = start; i < stop; i++)
    {
        result += charToInt(line[i]);
        result *= 10;
    }
    result /= 10;
    return result;
}

// Checks the validity of a line
// for reference, lines take the form
// 17-19 b: bbbbbbbbbbbbbbbbbbq
// More info is on the website.
int checkLine(char *line)
{
    printf("%s", line);
    int firstBoundStart = 0;
    int firstBoundEnd;
    int secondBoundStart;
    int secondBoundEnd;
    size_t pos = 0; // line position

    char charToCheck;
    char lineToCheck[258];

    do
    {
        pos++;
    } while (line[pos] != '-');
    firstBoundEnd = pos;

    pos++;

    secondBoundStart = pos;
    while (line[pos] != ' ')
    {
        pos++;
    }
    secondBoundEnd = pos;
    pos++;
    charToCheck = line[pos];

    pos += 3;
    int i = 0;
    for (; pos < strlen(line); pos++)
    {
        lineToCheck[i] = line[pos];
        i++;
    }
    lineToCheck[i] = '\0';

    int firstBound = strToInt(firstBoundStart, firstBoundEnd, line);
    int secondBound = strToInt(secondBoundStart, secondBoundEnd, line);
    printf("1 to int: \t%d\n", firstBound);
    printf("2 to int: \t%d\n", secondBound);
    printf("char: \t%c\n", charToCheck);
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