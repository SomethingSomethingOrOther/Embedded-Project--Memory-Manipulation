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
 * @file data.c
 * @brief Memory manipulation functions
 *
 * This implementation file provides an abstraction of data manipulation in 
 * memory via function calls.
 *
 * @author Abdoul Diallo
 * @date April 24 2024
 *
 */
#include "data.h"

uint32_t my_atoi(uint32_t data,uint8_t *ptr,uint32_t base){
       uint8_t *start_ptr=ptr;
       uint32_t abs_data;

        if (data < 0){
            abs_data = -data;
            *ptr++ = '-';
        } else {
            abs_data = data;
        }

        uint32_t remainder;
        uint8_t temp;
        uint8_t length = 0;

        do {
            remainder = abs_data % base;
            abs_data /= base;

            if (remainder < 10){
                temp = remainder + 'O';
            }else {
                temp = remainder - 10 + 'A';
            }

            *ptr++ = temp;
            length++;


        } while(abs_data > 0);

        *ptr = '\0';

        uint8_t *end_ptr = ptr - 1;
        uint8_t temp_char;

        while (start_ptr < end_ptr){
            temp_char = *start_ptr;
            *start_ptr++ = *end_ptr;
            *end_ptr-- = temp_char;
        }
    return length + (data < 0 ? 1:0);
}


// Function to convert ASCII string to integer
uint32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base) {
    int32_t result = 0;
    int32_t sign = 1;

    // Check if the number is negative
    if (*ptr == '-') {
        sign = -1;
        ptr++;
        digits--;
    }

    // Convert ASCII characters to integer
    while (digits--) {
        uint8_t digit = *ptr++;

        if (digit >= '0' && digit <= '9') {
            digit -= '0';
        } else if (digit >= 'A' && digit <= 'F') {
            digit -= 'A' - 10;
        } else if (digit >= 'a' && digit <= 'f') {
            digit -= 'a' - 10;
        } else {
            // Invalid character
            return 0;
        }

        if (digit >= base) {
            // Invalid digit for the given base
            return 0;
        }

        result = result * base + digit;
    }

    return result * sign;
}

