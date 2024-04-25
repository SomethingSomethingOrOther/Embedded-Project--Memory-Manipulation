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
 * @file memory.c
 * @brief Abstraction of memory read and write operations
 *
 * This implementation file provides an abstraction of reading and
 * writing to memory via function calls. There is also a globally
 * allocated buffer array used for manipulation.
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#include "memory.h"
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
/***********************************************************
 Function Definitions
***********************************************************/
void set_value(char *ptr, unsigned int index, char value){
  ptr[index] = value;
}

void clear_value(char * ptr, unsigned int index){
  set_value(ptr, index, 0);
}

char get_value(char * ptr, unsigned int index){
  return ptr[index];
}

void set_all(char * ptr, char value, unsigned int size){
  unsigned int i;
  for(i = 0; i < size; i++) {
    set_value(ptr, i, value);
  }
}

void clear_all(char * ptr, unsigned int size){
  set_all(ptr, 0, size);
}

// data manipulation functions

uint8_t *my_memmove(uint8_t *src, uint8_t *dst, size_t length){
      uint8_t new_byte=0;
      
for (size_t i=0;i<length;i++){
      uint8_t srcbyte = *(src + i);
          for(int j=7;j>=0;j--){
              int src_bit_value = (srcbyte >> j) & 1;
              new_byte =(src_bit_value << j) | new_byte;
              printf("%d",src_bit_value);
          }
          printf("\n");
      }    
      dst=&new_byte;
      printf("%d",*dst);
      return dst;
}

uint8_t *my_memcopy(uint8_t *src, uint8_t *dst, size_t length){
        //for (size_t i=0;i<length;i++){
        //    *(dst + i)=*(src + i) ;
        //}
          *(dst) = *dst ^ *dst;
         for (size_t i=0;i<length;i++){
             uint8_t src_byte = *(src + i);
             uint8_t dst_byte = *(dst + i);
             for (int j=7;j>=0;j--){
                int src_bit_value = (src_byte >> j) & 1;
                printf("%d",src_bit_value);
                dst_byte = (src_bit_value << j) | dst_byte;
             }
             *(dst + i) = dst_byte;
             printf("%d",*(dst + i));
            }

      return dst;
}

uint8_t *my_memset(uint8_t *src, size_t length, uint8_t value){
          for (size_t i=0;i<length;i++){
            *(src + i) = value;
          }
          return src;
}

uint8_t *my_memzero(uint8_t *src, size_t length){
        for (size_t i=0;i<length;i++){
          *(src + i) = 0;
        }
        return src;
}

uint8_t *my_reverse(uint8_t *src, size_t length){
        if(length <= 1){
           printf("Single Byte. Cannot reverse");
           return src;
        }
        int i=0;
        int j=length - 1;
        while(i < j){
          uint8_t *temp= *(src + j);
          *(src + i) = *(src + j);
          *(src + j) = temp;
          i++;
          j--;
        }
        printf("%d",*src);
        return src;
}

uint32_t *reserve_words(size_t length){

      uint32_t *memory_location = (uint32_t *)malloc(length * sizeof(uint32_t));
      if(memory_location == NULL){
        return NULL;
      }
      return memory_location;
}

void free_words(uint32_t *src){
      free(src);
}