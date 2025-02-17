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
 * @author <Add FirsName LastName>
 * @date <Add date >
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/**
 * @brief Computes the median of an array.
 *
 * This function calculates the median value of a given array of unsigned 
 * characters. The array is first sorted, and then the median is determined 
 * based on the number of elements.
 *
 * @param test Pointer to the array of unsigned characters.
 * @param size The number of elements in the array.
 *
 * @return The median value as an unsigned char.
 */
 unsigned char find_median(unsigned char *test, int size);

 /**
  * @brief Computes the mean (average) of an array.
  *
  * This function calculates the mean value by summing all elements in the array 
  * and dividing by the number of elements.
  *
  * @param test Pointer to the array of unsigned characters.
  * @param size The number of elements in the array.
  *
  * @return The mean value as a float.
  */
 float find_mean(unsigned char *test, int size);
 
 /**
  * @brief Finds the maximum value in an array.
  *
  * This function iterates through the array to find and return the maximum value.
  *
  * @param test Pointer to the array of unsigned characters.
  * @param size The number of elements in the array.
  *
  * @return The maximum value as an unsigned char.
  */
 unsigned char find_maximun(unsigned char *test, int size);
 
 /**
  * @brief Finds the minimum value in an array.
  *
  * This function iterates through the array to find and return the minimum value.
  *
  * @param test Pointer to the array of unsigned characters.
  * @param size The number of elements in the array.
  *
  * @return The minimum value as an unsigned char.
  */
 unsigned char find_minimun(unsigned char *test, int size);
 
 /**
  * @brief Sorts an array in descending order.
  *
  * This function sorts the elements of the given array in descending order 
  * (from highest to lowest) using an appropriate sorting algorithm.
  *
  * @param test Pointer to the array of unsigned characters.
  * @param size The number of elements in the array.
  */
 void sort_array(unsigned char *test, int size);
 /**
 * @brief Displays statistical results of an array.
 *
 * This function prints the computed statistics, including the median, mean, 
 * maximum, and minimum values, in a formatted manner.
 *
 * @param median The median value of the array.
 * @param mean The mean (average) value of the array.
 * @param maximum The maximum value in the array.
 * @param minimum The minimum value in the array.
 */
 void print_statistics(unsigned char median, float mean, unsigned char maximum, unsigned char minimum);
/**
 * @brief Prints the elements of an array.
 *
 * This function iterates over an array and prints each element 
 * separated by a space. The function does not modify the array.
 *
 * @param array Pointer to the first element of the array.
 * @param size The number of elements in the array.
 */
 void print_array(unsigned char *array, int size);

#endif /* __STATS_H__ */
