#include <stdio.h>
#include "data_t.h"

void showData(data_t data)
{
  printf("%s\n", data);
}

void showAllData(data_t a[], int elemNbr)
{
  for (int i = 0; i < elemNbr; i++)
  {
    showData(a[i]);
  }
}

// data_t convert(int i) {
//   return i;
// }