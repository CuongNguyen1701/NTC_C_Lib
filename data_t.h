#ifndef __DATA_T_H__
#define __DATA_T_H__

typedef struct {
  char name[20], tel[20], email[32];
} phoneAddr_t;

typedef char *data_t;//string

// Must Adapt to new problem
void showData(const data_t data);
void showAllData(data_t a[], int elemNbr);
// data_t convert(int i);

#endif