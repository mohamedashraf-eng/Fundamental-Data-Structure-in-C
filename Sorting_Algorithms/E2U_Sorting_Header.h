/*
    * Author: Mohamed Ashraf Wx.
    * Date: 4/29/2022
    * Purpose: Easy to call and use sorting algorithms to sort 1D Lists (Arrays0)
*/
/************************************************************************
 *                           General Declarations                       *
*************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <windows.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <time.h>

#pragma once
/************************************************************************
 *                           Functions Delcared                         *
*************************************************************************/

// ====> General Purpose Delcarations.
void swap(int *, int *);
void array_init(int *, int, int);
void array_print(int *, int);

// ====> Quick Sort Delcarations.
void quicksort(int *, int);
void quicksort_recursion(int *, int , int );
int partition(int *, int , int );

// ====> Bubble Sort Delcarations.
void bubble_sort(int *, int );

// ====> Merge Sort Delcarations.
void merge_sort(int *a, int);
void merge_sort_recursion(int *, int , int);
void merge_sorted_arrays(int *, int , int , int);

// ====> Insertion Sort Delcarations.
void insertion_sort(int *a, int );

// ====> Array Manipulation Delcarations.
void array_reverse(int *, int );

/************************************************************************
 *                           Main Functions                             *
*************************************************************************/
// ===================> Quick Sort Algorithm.
// applies quicksort algorthim to the array with the given length... strictly
// speaking this function isn't necessary because we could call
// quicksort_recursive directly, but this function makes the 'interface'
// prettier in that only the array and length need to be provided!
void quicksort(int *array, int length)
{
  // our quicksort algorithm randomly selects the pivot, so we seed the random
  // number generator to ensure the randomization of our random numbers
  srand(time(NULL));

  // calls the quicksort recursive algorithm with our array, and a starting
  // lower index bound of 0 and high index bound of the final element in the
  // array... i.e. apply quicksort to the entire length of the array
  quicksort_recursion(array, 0, length - 1);
}

// applies the recursive divide and conquer portion of the quicksort algorithm
// to the array... applying quicksort to the array between the low-high indexes
void quicksort_recursion(int *array, int low, int high)
{
  // stop recursion when low >= high
  if (low < high)
  {
    // partition the array by a pivot, and return the pivot element's index
    int pivot_index = partition(array, low, high);

    // apply quicksort to the left side subarray
    quicksort_recursion(array, low, pivot_index - 1);

    // apply quicksort to the right side subarray
    quicksort_recursion(array, pivot_index + 1, high);
  }
}

// partitions the array between low - high indexes by a pivot value and returns
// the index of the pivot
int partition(int *array, int low, int high)
{
  // randomly select a pivot value between low-high by randomly selecting an
  // index in the range low - high... we do this as opposed to just selecting
  // the last element each time because it's technically possible that always
  // selecting the same pivot will have poor performance if the array happens
  // to contain values in a way that is suboptimal
  int pivot_index = low + (rand() % (high - low));

  // swap the element at the pivot_index with the element at index high (i.e.
  // the last element in this portion of the array), doing so allows us to
  // apply the below partitioning algorithm
  if (pivot_index != high)
    swap(&array[pivot_index], &array[high]);

  // the pivot value is now whatever is in the high index
  int pivot_value = array[high];

  // the partioning algorithm will shift elements that are less than the pivot
  // value to the front portion of the low - high array indexes, with i keeping
  // track of where the elements that are greater than the pivot value begin
  int i = low;

  // increment j from low up until but not including the pivot value at high
  for (int j = low; j < high; j++)
  {
    // if the array value at j is less than the pivot value, perform a swap with
    // the value at the array at index i... this effectively moves this "less
    // than the pivot values" to the front portion, and we increment i to
    // reflect where the values that are greater than the pivot now begin
    if (array[j] <= pivot_value)
    {
      swap(&array[i], &array[j]);
      i++;
    }
  }

  // we now know that the value at index i is greater than or equal to the pivot
  // so we swap it with the pivot value to complete the partition
  swap(&array[i], &array[high]);

  // index i now contains the pivot value, so return this so that the
  // quicksort_recursion function knows where to split the array when applying
  // the algorithm to the resulting subarrays
  return i;
}

// ===================> Bubble Sort Algorithm.

// Accepts an array and its length and sorts it using the bubble sort algorithm
//
// Bubble sort works by continually passing through the elemnts of an array
// and swapping those that are found to be out of order, see:
//   https://en.wikipedia.org/wiki/Bubble_sort
//
void bubble_sort(int *a, int length)
{
  bool swapped = false;
  int i = 0;

  // The outer loop will continue to attempt to sort the list so long as it
  // may still be out of order.  We know the loop might still be out of order
  // if a swap has taken place... if no swap has taken place, we know that the
  // array is sorted.  So we used the bool swapped to keep track of whether a
  // swap has taken place, and to decide when to terminate the algorithm.
  do
  {
    swapped = false;

    // The inner loop makes a pass through the array elements, and if any
    // element and the element next to it are out of order, it swaps them.
    // After the first pass through the array, we know for sure that the last
    // element of the array is sorted, and after the 2nd pass through we know
    // for that the 2nd last element of the array is sorted... and so we can
    // progressively pass through less elements of the array each time we run
    // this loop.  We use i to keep track of how many passes through the array
    // we have made, and lessen the number of elements we go through each time!
    for (int j = 0; j < (length - 1 - i); j++)
    {
      // we could flip < to > to have it sort in ascending order instead of
      // descending order as it will now
      if (a[j] > a[j + 1])
      {
        // swaps elements that are detected to be out of order using a temporary
        // variable to store one value before we need to overwrite it with the
        // other, see: https://en.wikipedia.org/wiki/Swap_(computer_programming)
        int temp = a[j];
        a[j] = a[j + 1];
        a[j + 1] = temp;
        swapped = true;
      }
    }
    i++;
  } while (swapped);
}


// ===================> Merge Sort Algorithm.

// Performs a merge sort of the array a with the given length, the function
// provides an easier/prettier interface for using merge sort for the
// programmer as they simply need to provide the array and its length
void merge_sort(int *a, int length)
{
  // call the merge sort recursion function, the left index of 0 and the
  // right index of length - 1 are provided as we are initially looking
  // at sorting "the entire array"
  merge_sort_recursion(a, 0, length - 1);
}

// Applies the merge sort algorithm to the array a between the left index l
// and the right index r.  This function implements the recursive
// divide-and-conquer step of the merge sort algorithm, splitting the array
// portion between l...r at the middle, and calling itself on each portion,
// before applying the function to merge the sorted portions of the array
// that will result.
void merge_sort_recursion(int *a, int l, int r)
{
  // we stop recursion when l >= r
  if (l < r)
  {
    // find the midpoint of l and r
    int m = l + (r - l) / 2;

    // apply the function recursively to the left and right portions split
    // at the midpoint
    merge_sort_recursion(a, l, m);
    merge_sort_recursion(a, m + 1, r);

    // at this point both portions of the array have been sorted, and we now
    // merge the sorted portions of the array
    merge_sorted_arrays(a, l, m, r);
  }
}

// merges the two sorted portions of the array a between the indexes l ... m
// and m + 1 ... r
void merge_sorted_arrays(int *a, int l, int m, int r)
{
  // calculate the length of the left and right portions of the array
  int left_length = m - l + 1;
  int right_length = r - m;

  // create temporary arrays to store these portions
  int temp_left[left_length];
  int temp_right[right_length];

  // used as index/counter variables for the 3 arrays a, temp_left, temp_right
  int i, j, k;

  // copy the left portion into the temp_left array
  for (int i = 0; i < left_length; i++)
    temp_left[i] = a[l + i];

  // copy the right portion into the temp_right array
  for (int i = 0; i < right_length; i++)
    temp_right[i] = a[m + 1 + i];

  // Use i to move through the indexes of temp_left, j to move through the
  // indexes of temp_right, and k to move through the portion of the array
  // a from l ... r.  We basically keep checking the "head" of temp_left
  // and temp_right (knowing both arrays are sorted) and put the smaller of
  // the two into array a (using i, j, k to move through the arrays).  When
  // we run out elements in either temp_left or temp_right, the remaining
  // elements from the other array will be copied over into a.
  for (i = 0, j = 0, k = l; k <= r; k++)
  {
    // so long as we have not already reached the end of the temp_left array
    // with our variable i, then if the next element in the left_temp array
    // is smaller OR if we have reached the end of the temp_right array,
    // then store the next element from temp_left into the next element in
    // the array a
    if ((i < left_length) &&
        (j >= right_length || temp_left[i] <= temp_right[j]))
    {
      a[k] = temp_left[i];
      i++;
    }
    // otherwise if the next element in temp_right than the next element in
    // temp_left OR we have reached the end of temp_left, store the next
    // element from the temp_right array into the next element in array a
    else
    {
      a[k] = temp_right[j];
      j++;
    }
  }
}


// Example visualization of the merge sort algorithm:
//
//          [38, 27, 43, 3, 9, 82, 10]
//                     /   \
//       [38, 27, 43, 3]   [9, 82, 10]
//        /         |         |      \
//   [38, 27]    [43, 3]   [9, 82]   [10]
//    /   |      /    |    /    \      |
// [38]  [27]  [43]  [3]  [9]   [82]  [10]
//    \  /       \   /     \     /     |
//   [27, 38]    [3, 43]   [9, 82]    [10]
//       \         /          \        /
//     [3, 27, 38, 43]        [9, 10, 82]
//           \                  /
//          [3, 9, 10, 27, 38, 43, 82]
//
// The array is first broken up into progressively smaller unsorted portions of
// the array, and once we have "sub-arrays" of 1 element they are by definition
// sorted arrays.  From here the "sorted arrays" are merged together until we
// arrive at the complete sorted array.
//

// ===================> Insertion Sort Algorithm.

// sorts the array a with the given length using the insertion sort algorithm:
//   https://en.wikipedia.org/wiki/Insertion_sort
void insertion_sort(int *a, int length)
{
  // the outer loop examines each element on the right-hand side of the array
  // from the 2nd element on to the end of the array
  for (int i = 1; i < length; i++)
  {
    // the inner loop shifts over elements on the sorted left hand side of the
    // list until the correct sorted position for the key element is found, at
    // which point we place it there
    int key = a[i];
    int j = i - 1;
    while (j >= 0 && a[j] > key)
    {
      a[j + 1] = a[j];
      j = j - 1;
    }
    a[j + 1] = key;
  }
  return;
}

/*
  for Ex *a->addr->List[9, 4, 6, 7, 1]

  First run: i = 1.

  key = a[i] =  4
  j = 1-1 = 0

  while(0 >= 0 && a[j] > 4)
  {
    a[j+1] = a[0] (swap 9 with 4)
    j = j - 1 (j = -1)
  }
  
}
*/

/************************************************************************
 *                           Array M Functions                          *
*************************************************************************/

void array_reverse(int *array, int length)
{
  //int temp = 0;

  for(int i = 0; i < (length/2); i++)
    {

      // Using temp method.
    /*
      temp = array[i];
      array[i] = array[length-i-1];
      array[length-i-1] = temp;
    */
   // Using the XOR Method.
      array[i]          = array[i] ^ array[length-i-1];
      array[length-i-1] = array[i] ^ array[length-i-1];
      array[i]          = array[i] ^ array[length-i-1];

      /*
        a[i] = 2, a[length-i-1] = 3. (Assumed)

        a[i] = a[i] ^ a[length-i-1];                      (Assumed 8-bits) 0000 0010 XOR 0000 0011 : 0000 0001 (1)
        array[length-i-1] = array[i] ^ array[length-i-1]; (Assumed 8-bits) 0000 0001 XOR 0000 0011 : 0000 0010 (2)
        array[i] = array[i] ^ array[length-i-1];          (Assumed 8-bits) 0000 0001 XOR 0000 0010 : 0000 0011 (3)

      */
    }

}

/************************************************************************
 *                           Sub Functions                              *
*************************************************************************/

void swap(int *a, int *b)
{
    int temp = 0;

    temp = *a;
    *a = *b;
    *b = temp;
}

void array_print(int *array, int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
}

void array_init(int *array, int size, int range)
{
    for(int i = 0; i < size; i++)
    {
        array[i] = rand()%range;
    }
}

struct timeval start, end;

void algorithm_start(void)
{
    gettimeofday(&start, NULL);
}

void algorithm_end(void)
{
    gettimeofday(&end, NULL);
}

void time_complexity_print(void)
{
     // Calculating total time taken by the program.
  double time_taken;

  time_taken = (end.tv_sec - start.tv_sec) * 1e6;
  time_taken = (time_taken + (end.tv_usec -
                            start.tv_usec)) * 1e-6;

  printf("\n Execution Time: %.10lf ms", time_taken*(1e3));
}
