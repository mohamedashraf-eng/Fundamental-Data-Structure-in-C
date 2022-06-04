/*
    Author: Mohamed Ashraf (Wx)
    Date: 11/23/2021
    Type: Sorting Algorithms in C.
*/
//=========== =========== =========== =========== =========== ===========

// HEADER LIBRARIES USED:
#include "WX_SORTING_ALGORITHMS.h"

#define SIZE 100

int main(void)
{
  int *data = (int *) malloc(SIZE*sizeof(int));

  array_init(data, SIZE, SIZE);


  merge_sort(data, SIZE);

  algorithm_start();

  array_reverse(data, SIZE);

  algorithm_end();

  array_print(data, SIZE);

  time_complexity_print();


  return 0;
}
