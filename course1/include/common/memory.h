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
 * @file memory.h
 * @brief Abstraction of memory read and write operations
 *
 * This header file provides an abstraction of reading and
 * writing to memory via function calls. 
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#ifndef __MEMORY_H__
#define __MEMORY_H__

#include <stdint.h>
/**
 * @brief Sets a value of a data array 
 *
 * Given a pointer to a char data set, this will set a provided
 * index into that data set to the value provided.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 * @param value value to write the the locaiton
 *
 * @return void.
 */
void set_value(char * ptr, unsigned int index, char value);

/**
 * @brief Clear a value of a data array 
 *
 * Given a pointer to a char data set, this will clear a provided
 * index into that data set to the value zero.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return void.
 */
void clear_value(char * ptr, unsigned int index);

/**
 * @brief Returns a value of a data array 
 *
 * Given a pointer to a char data set, this will read the provided
 * index into that data set and return the value.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return Value to be read.
 */
char get_value(char * ptr, unsigned int index);

/**
 * @brief Sets data array elements to a value
 *
 * Given a pointer to a char data set, this will set a number of elements
 * from a provided data array to the given value. The length is determined
 * by the provided size parameter.
 *
 * @param ptr Pointer to data array
 * @param value value to write the the locaiton
 * @param size Number of elements to set to value
 *
 * @return void.
 */
void set_all(char * ptr, char value, unsigned int size);

/**
 * @brief Clears elements in a data array
 *
 * Given a pointer to a char data set, this will set a clear a number
 * of elements given the size provided. Clear means to set to zero. 
 *
 * @param ptr Pointer to data array
 * @param size Number of elements to set to zero
 *
 * @return void.
 */
void clear_all(char * ptr, unsigned int size);

/**
 * @brief Moves a byte of data from source to destination
 * 
 * Given two byte pointers a source and destination, this function will copy 
 * the data from the source pointer to the destination pointer.  This function
 * handles overlap of source and destination pointers with no data corruption
 * 
 * @param src Pointer to source
 * @param dst Pointer to destination
 * @param length length of source
 * 
 * @return ptr Pointer to destination
*/
uint8_t *my_memmove(uint8_t *src, uint8_t *dst, size_t length);

/**
 * @brief Moves data from to src to dst. Likely data corruption
 * 
 * Given two byte pointers source and destination, this function moves data from
 * src to dst. Does not handle source and destination overlap. 
 * 
 * @param src pointer to source 
 * @param dst pointer to destination
 * @param length Length of source
 * 
 * @return ptr Pointer to destination
 * 
*/
uint8_t *my_memcopy(uint8_t *src, uint8_t *dst, size_t length);

/**
 * @brief Sets src data to the value provided
 * 
 * Given a byte pointer (source), a length, and value, this functions sets the 
 * entire memory location of source to the value
 * 
 * @param src Pointer to source
 * @param length Length of source
 * @param value To to be set at source memory location
 * 
 * @return ptr Pointer to source
*/
uint8_t *my_memset(uint8_t *src, size_t length, uint8_t value);

/**
 * @brief Zeros out the memory location provided
 * 
 * Given a byte pointer (source) and its length, sets entire memory location to zero
 * 
 * @param src Pointer to source memory location
 * @param length size of source
 * 
 * @return ptr Pointer to source location
*/
uint8_t *my_memzero(uint8_t * src, size_t length);

/**
 * @brief Reverses the order of bytes at given memory location
 * 
 * Given a byte pointer (source) and its length, reverses the bytes
 * 
 * @param src Pointer to source memory location 
 * @param length size of source
 * 
 * @return ptr Pointer to source 
*/
uint8_t * my_reverse(uint8_t * src, size_t length);

/**
 * @brief Allocates memory
 * 
 * Given a size up to 32 bits, dynamically reserves memory
 * 
 * @param length size of memory to allocate
 * 
 * @return ptr Pointer to allocated memory or NULL if unsuccessful
*/
int32_t * reserve_words(size_t length);

/**
 * @brief Frees allocated memory
 * 
 * Given a 4 byte pointer, frees the dynamically allocated memory
 * 
 * @param src Pointer to dynamcially allocated memory
 * 
 * @return void.
*/
void free_words(int32_t * src);
#endif /* __MEMORY_H__ */
