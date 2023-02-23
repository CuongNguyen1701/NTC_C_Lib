#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>

#include "adstring.h"

typedef struct
{
  const char *name;
  int (*func)();
} MenuItem;
// only use global variables
int a = 0, b = 0;
char filename[] = "input.txt";
char delimiters[] = " !\"#$%&\'()*+,-./:;<>=?@[\\]^_`{|}~\n\t";
FILE *file = NULL;

int exitMenu() { return 1; }

int splitWords()
{
  file = fopen(filename, "r");
  int size = 0;
  char output[100][100];
  char buffer[1024];
  char *num = "0123456789";
  char charList[] = {'a'};
  // Get each line from the file and then split them into "output" array
  while ((fgets(buffer, sizeof(buffer), file)) != NULL)
    stringSplitField(buffer, num, output, &size);
  // stringSplit(buffer, delimiters, output, &size);

  printf("Split completed\n");

  // int charListSize = sizeof(charList) / sizeof(char);
  // for (int i = 0; i < size; i++)
  // {
  //   if (!stringContainsChar(output[i], charList, charListSize, OR))
  //     continue;
  //   printf("%s\n", output[i]);
  // }
  for (int i = 0; i <= size; i++)
  {
    printf("%s\n", output[i]);
  }
  fclose(file);
};

int main()
{
  MenuItem m[] = {
      {"Split words from file", splitWords},
      {"exit", exitMenu}};
  int n = sizeof(m) / sizeof(m[0]);
  int lua_chon;

  for (;;)
  {
    printf("MENU:\n", a, b);

    for (int i = 0; i < n; i++)
      printf("%d. %s\n", i + 1, m[i].name);

    printf("Lua chon: ");
    scanf("%d", &lua_chon);

    if (lua_chon < 1 || lua_chon > n)
    {
      printf("Lua chon khong co\n");
      continue;
    }

    if (m[lua_chon - 1].func())
      break;
  }

  return 0;
}