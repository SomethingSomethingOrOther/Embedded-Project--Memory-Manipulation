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
 * @file stats.h
 * @brief Header file for the stats.c functions
 * 
 * This file contains the declarations and descriptions of the all the functions
 * found in the stats.c file.
 * 
 *
 * @author Abdoul Diallo
 * @date 4/20/24
 *
 */

#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 

void print_array(unsigned char array[], unsigned int size);
/**
 * @brief Given an array of some length, it prints the array to the screen
 *
 * This functions takes as input an array of n-length and the size of the array.
 * It iterates through the array and prints each member of the array to the screen.
 *
 * 
 * @param array The array to be printed
 * @param size The size of the array
 * 
 *
 * @return Only prints. Does not return anything
 */

unsigned char find_median(unsigned char array[], unsigned int size);

/**
 * @brief Given an array and its size, returns the median value
 *
 * This function takes as inputs an array of n-length and the size of this array.
 * It returns the median value 
 *
 *
 * @param array The array whose median value is to be found
 * @param size The size of the array
 * 
 *
 * @return The median of array as integer
 */

unsigned char find_mean(unsigned char array[], unsigned int size);
/**
 * @brief Given an array and its size, returns the mean value
 * 
 * This function takes as inputs an array of n-length and the size of this array.
 * It returns the mean value.
 * 
 * 
 * @param array The array whose mean value is to be founc
 * @param size The size of the array
 * 
 * 
 * @return The mean value as integer
 * 
*/
unsigned char find_maximum(unsigned char array[], unsigned int size);
/**
 * @brief Given an array and size of the array, returns the largest value
 *
 * This function takes as input an array of n-length and the length of the array.
 * It returns the largest value in the array
 *
 * 
 * @param array The array whose max is to be found
 * @param size The size of the array
 * 
 *
 * @return The largest value
 */

unsigned char find_minimum(unsigned char array[],unsigned int size);
/**
 * @brief Given an array and length, returns the smallest value
 *
 * This function takes as inputs an array of n-length and the length of the array.
 * It returns the smallest value in the array.
 *
 * 
 * @param array The array whose min is to be found
 * @param size The size of the array
 * 
 *
 * @return The smallest value
 */

void sort_array(unsigned char array[],unsigned int size);

/**
 * @brief Given an array and length, sorts the array from largest to smallest
 * 
 * This function takes as input an array of size n and the length of the array.
 * The members of the array are sorted from largest to smallest. The array is 
 * sorted in place and printed to the screen.
 * 
 * @param array The array to be sorted
 * @param size The size of the array
 * 
 * 
 * @return None
*/
void print_statistics(unsigned char array[]);
/**
 * @brief Given an array it prints the max, min, median, and mean of the array
 *
 * This function takes as input an array of size n. It then calls the 
 * find_mean, find_median, find_maximum, and find_minimum functions. The return
 * values of these functions are then printed to the screen
 *
 * 
 * @param array The array whose statistics is to be printed
 * 
 * 
 * @return <Add Return Informaiton here>
 */
#endif /* __STATS_H__ */
