/* 
 * advent of code, day 2, part 2
 * https://adventofcode.com/2020/day/2
 * using C, built with GNU Make 4.1
 * by Zack Sargent
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int charToInt(char c)
{
    return c - '0';
}

// stop is non-inclusive
int strToInt(int start, int stop, char *line)
{
    int result = 0;
    if ((start + 1) == stop)
    {
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

/* --- This is the only function that changes between part 1 and part 2 --- */
// Checks the validity of a line
// for reference, lines take the form
// 17-19 b: bbbbbbbbbbbbbbbbbbq
// More info is on the website.
int checkPassword(int pos1, int pos2, char charToCheck, char *password)
{
    // decrement pos1 and pos2 to use zero index, 
    // and apply Logical exclusive or:
    return (!(password[pos1 - 1] == charToCheck) != 
            !(password[pos2 - 1] == charToCheck));
}
/* ------------------------------------------------------------------------ */

// Parses a line and returns checkPassword
int parseLine(char *line)
{
    int firstBoundStart = 0;
    int firstBoundEnd;
    int secondBoundStart;
    int secondBoundEnd;

    size_t pos = 0; // position in line 

    char charToCheck;
    char lineToCheck[258];

    // get the first number, which is the first pos
    // the char should appear at
    do
    {
        pos++;
    } while (line[pos] != '-');
    firstBoundEnd = pos;

    // Skip the deliminator
    pos++;

    // get the second number, which is the second pos
    // the char should appear at
    secondBoundStart = pos;
    while (line[pos] != ' ')
    {
        pos++;
    }
    secondBoundEnd = pos;

    pos++; // Skip the space

    charToCheck = line[pos];

    pos += 3; // Skip the character, the colon, and the space

    // parse the rest of the line into another string to work with
    int i = 0;
    for (; pos < strlen(line); pos++)
    {
        lineToCheck[i] = line[pos];
        i++;
    }
    lineToCheck[i] = '\0';

    int min = strToInt(firstBoundStart, firstBoundEnd, line);
    int max = strToInt(secondBoundStart, secondBoundEnd, line);

    return checkPassword(min, max, charToCheck, lineToCheck);
}

int countValidPasswordsInFile(char *fileName)
{
    size_t count = 0;
    FILE *file = fopen(fileName, "r");
    char line[256];

    if (file == NULL)
    {
        return NULL;
    }

    // read file line by line
    while (fgets(line, sizeof(line), file))
    {
        count += parseLine(line);
    }
    fclose(file);

    return count;
}

int main()
{
    size_t count;

    count = countValidPasswordsInFile("./input.txt");
    printf("%ld\n", count);

    return 0;
}