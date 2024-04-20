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
 * @file stats.c
 * @brief Contains the declarations and definitions of all functions using 
 * in the project
 *
 * This file contains eight functions that help us find the statistics of an array
 * and perform other taskes like sorting the array and printing the return values 
 * of the other functions.The functions include find_mean, find_median, 
 * find_maximum, find_minimum, sort_array, print_statistics, print_array, and main.
 * 
 * @author Abdoul Diallo
 * @date 4/20/24
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */
  print_statistics(test,SIZE);
  print_array(test,SIZE);
  find_mean(test,SIZE);
  find_maximum(test,SIZE);
  find_minimum(test,SIZE);
  find_median(test,SIZE);
}

/* Add other Implementation File Code Here */

void print_array(unsigned char array[],unsigned int size){
  for (int i=0; i< size; i++){
    printf("%u, ",*(array + i));
  }
  printf("\n");
}

unsigned char find_mean(unsigned char array[], unsigned int size){
    unsigned char result = 0;
    unsigned int total = 0;

    for (int i=0; i<size; i++){
      total += *(array + i);
    }
    result = total/size;
    printf("The mean is: %hhu\n",result);  
    return result;
}

unsigned char find_median(unsigned char array[], unsigned int size){
  sort_array(array,size);

  unsigned char result = 0;

  if (size % 2 != 0){
    result = array[(size/2)];
  } else {
    unsigned char value_at_middle_index = *(array + (size/2));
    unsigned char value_at_middle_index_plus_one = *(array + (size/2) + 1);

    result = (value_at_middle_index + value_at_middle_index_plus_one) / 2;
  }
  
  printf("The median is: %hhu\n",result);
  return result;
}


unsigned char find_maximum(unsigned char array[], unsigned int size){
    unsigned char max_value = 0;
    for (int i=0; i<size; i++){
      if (array[i] > max_value){
        max_value = array[i];
      }
    }
    printf("The maximum is: %hhu\n",max_value);
    return max_value;
}

unsigned char find_minimum(unsigned char array[], unsigned int size){
  unsigned char min_value = 255;
    for (int i=0; i<size; i++){
      if (array[i] < min_value){
        min_value = array[i];
      }
    }
    printf("The minimum is: %hhu\n",min_value);  
    return min_value;
}

void print_statistics(unsigned char array[], unsigned int size){
  printf("Array statistics:\n");
  find_maximum(array,size);
  find_minimum(array,size);
  find_mean(array,size);
  find_median(array,size);

}

// bubble sort
void sort_array(unsigned char array[], unsigned int size){
  unsigned char bool = 1;

  while(bool != 0){
    bool = 0;
   for (int i=0; i<size - 1; i++){
    if (array[i] > array[i+1]){
      unsigned char temp = 0;
      temp = array[i];
      array[i] = array[i+1];
      array[i+1] = temp;

      bool = 1;
      }
    }
 }  
}