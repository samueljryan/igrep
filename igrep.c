#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Ryan Samuel
// 2020 Fall semester
// Similar to grep, this program can search a basic textfile for a word and
// print each line containing that word. This progam also supports the -i, -n, -h flags

#define MAX_LINE_LENGTH 100

void sort(int numArg, char **valueArg);
char *lowCase(char *substring);
void printLine(char *substring);

bool TO_IGNORE_CASE = false;
bool TO_NUMBER_LINES = false;

// If there are less than five arguments sends argc and argv to sort function
int main(int argc, char **argv)
{
  if (argc < 5)
  {
    sort(argc, argv);
  }
}

// sorts arguments based on their flags
void sort(int numArg, char **valueArg)
{
  char *keyword;
  for (int i = 0; i < numArg; i++) // for loop that loops around the number of arguments
  {

    char *a = valueArg[i];       // pointer a equals index of array of chars
    if (strncmp(a, "-", 1) == 0) // checks to see if '-' is in the 1st index of array, if so, checks the for additional flags
    {
      if (strncmp(a, "-i", 2) == 0) // checks for -i flag and keywords equals valueArg
      {
        TO_IGNORE_CASE = true;
        keyword = valueArg[i];
      }
      else if (strncmp(a, "-n", 2) == 0) // checks for -n flag
      {
        TO_NUMBER_LINES = true;
      }
      else if (strncmp(a, "-h", 2) == 0) // checks for -h flag
      {
        printf("Usage: grep [OPTION]... PATTERNS [FILE]...\n");
        printf("-i, = ignore case distinctions\n");
        printf("-n, = print line number with output lines\n");
        printf("-h, = display this help text and exit\n");
        exit(0);
      }
      else // if flag not recognized,
      {
        printf("ERROR command not recognized\n");
        exit(1);
      }
    }
    else // if there is no flag
    {
      keyword = valueArg[i]; //
    }
  }
  printLine(keyword);
}

// puts word that is being searched in lower case
char *lowCase(char *substring)
{
  int i = 0;
  while (i < strlen(substring))
  {
    substring[i] = tolower(substring[i]);
    i = i + 1;
  }
  return (substring);
}

// prints the lines of the words that are being searched
void printLine(char *substring)
{
  char line[MAX_LINE_LENGTH];
  if ((TO_IGNORE_CASE) && (TO_NUMBER_LINES)) // if both -i ad -n flag
  {
    char *result = (char *)malloc(4 * MAX_LINE_LENGTH);
    char *a;
    char *b;
    int lineNum = 0;
    while (fgets(line, MAX_LINE_LENGTH, stdin)) // while loop til fgets(pointer to char array, num of char to be read, pointer to file object)
    {
      a = lowCase(line);
      b = lowCase(substring);
      strcpy(result, a);
      lineNum++;

      if (strstr(result, b) != NULL) // finds first occurence of the substring
      {
        printf("%d:%s", lineNum, result);
      }
    }
  }
  else if (TO_IGNORE_CASE) // if just -i flag
  {
    char *result = (char *)malloc(4 * MAX_LINE_LENGTH);
    char *a;
    char *b;
    while (fgets(line, MAX_LINE_LENGTH, stdin))
    {
      a = lowCase(line);
      b = lowCase(substring);
      strcpy(result, a);

      if (strstr(result, b) != NULL)
      {
        printf("%s", result);
      }
    }
  }
  else if (TO_NUMBER_LINES) // if just -n flag
  {
    int lineNum = 0;
    while (fgets(line, MAX_LINE_LENGTH, stdin))
    {
      lineNum++;
      if (strstr(line, substring) != NULL)
      {
        printf("%d:%s", lineNum, line);
      }
    }
  }
  else // if there is no flags
  {
    while (fgets(line, MAX_LINE_LENGTH, stdin))
    {
      if (strstr(line, substring) != NULL)
      {
        printf("%s", line);
      }
    }
  }
}
