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

int checkPassword(int min, int max, char charToCheck, char *password)
{
    size_t count = 0;
    for (size_t i = 0; i < strlen(password); i++)
    {
        if (password[i] == charToCheck)
            count++;
    }
    return (count >= min && count <= max);
}

// Checks the validity of a line
// for reference, lines take the form
// 17-19 b: bbbbbbbbbbbbbbbbbbq
// More info is on the website.
int parseLine(char *line)
{
    int firstBoundStart = 0;
    int firstBoundEnd;
    int secondBoundStart;
    int secondBoundEnd;

    size_t pos = 0; // position in line 

    char charToCheck;
    char lineToCheck[258];

    // get the first number, which is the minumum number of times the 
    // char should appear in the password.
    do
    {
        pos++;
    } while (line[pos] != '-');
    firstBoundEnd = pos;

    // Skip the deliminator
    pos++;

    // get the second number, which is the maximum number of times the 
    // char should appear in the password
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

// returns the number of valid passwords in file
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