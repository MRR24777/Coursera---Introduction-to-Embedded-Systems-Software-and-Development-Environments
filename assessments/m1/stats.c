/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file <Add File Name> 
 * @brief <Add Brief Description Here >
 *
 * <Add Extended Description Here>
 *
 * @author Misael Reyna
 * @date <Add date >
 *
 */



 #include <stdio.h>
 #include "stats.h"
 
 /* Size of the Data Set */
 #define SIZE (40)
 
 unsigned char find_median(unsigned char *test, int size)
 {
   // Sorting the array in order to compute the median
   for (unsigned char *i = test; i < test + size - 1; i++)
   {
     for (unsigned char *j = test; j < test + size - 1 - (i - test); j++)
     {
       if (*j > *(j + 1))
       {
         unsigned char temp = *j;
         *j = *(j + 1);   // Fixed the bug here
         *(j + 1) = temp;
       }
     }
   }
 
   // Check if size is even or odd
   if (size % 2 == 0)
   {
     return (*(test + (size / 2) - 1) + *(test + (size / 2))) / 2; // Average of two middle values
   }
   else
   {
     return *(test + (size / 2)); // Middle element
   }
 }
 
 float find_mean(unsigned char *test, int size)
 {
   float sum = 0;
   for (unsigned char *i = test; i < test + size; i++)
   {
     sum += (float)*i;
   }
   return sum / size;  // Fixed semicolon issue
 }
 
 unsigned char find_maximum(unsigned char *test, int size)
 {
   unsigned char max = *test;
   for (unsigned char *ptr = test; ptr < test + size; ptr++)  // Fixed initialization of ptr
   {
     if (*ptr > max)
     {
       max = *ptr;  // Fixed missing semicolon
     }
   }
   return max;
 }
 
 unsigned char find_minimum(unsigned char *test, int size)
 {
   unsigned char min = *test;
   for (unsigned char *ptr = test; ptr < test + size; ptr++)  // Fixed initialization of ptr
   {
     if (*ptr < min)
     {
       min = *ptr;  // Fixed missing semicolon
     }
   }
   return min;
 }

 void print_statistics(unsigned char median, float mean, unsigned char maximum, unsigned char minimum)
 {
  printf("Median: %d\n", median);
  printf("Mean: %.2f\n", mean);
  printf("Maximum: %d\n", maximum);
  printf("Minimum: %d\n", minimum);
 }

 void sort_array(unsigned char *test, int size)
 {
  for (unsigned char *i = test; i < test + size - 1; i++) 
  {
      for (unsigned char *j = test; j < test + size - 1 - (i - test); j++) 
      {
          if (*j < *(j + 1))  // Compare to sort from largest to smallest
          {
              unsigned char temp = *j;
              *j = *(j + 1);
              *(j + 1) = temp;
          }
      }
  }
 }

 void print_array(unsigned char *array, int size) {
  for (unsigned char *i = array; i < array + size; i++) {
      printf("%d ", *i);
  }
  printf("\n"); // Nueva línea para formato limpio
}

 
 int main()
 {
   unsigned char test[SIZE] = { 34, 201, 190, 154, 8, 194, 2, 6,
                                 114, 88, 45, 76, 123, 87, 25, 23,
                                 200, 122, 150, 90, 92, 87, 177, 244,
                                 201, 6, 12, 60, 8, 2, 5, 67,
                                 7, 87, 250, 230, 99, 3, 100, 90 };
 
   /* Example function calls */
  unsigned char median = find_median(test, SIZE);
  float mean = find_mean(test, SIZE);
  unsigned char maximum = find_maximum(test, SIZE);
  unsigned char minimum = find_minimum(test, SIZE);
  print_statistics(median,mean,maximum,minimum);
  printf("Original Array:\n");
  print_array(test, SIZE);

  sort_array(test, SIZE);
  printf("Sorted Array:\n");
  print_array(test, SIZE);
 

 
   return 0;
 }

/* Add other Implementation File Code Here */
