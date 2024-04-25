#include <stdint.h>

/**
 * @brief Converts type integer to ASCII-string
 * 
 * Given a signed 32-bit integer, a pointer, and base, this function converts the integer
 * to an ASCII-string based on the provided base conversion [base 10,2,16 etc..]
 * 
 * @param data integer to be converted
 * @param ptr   ASCII-string will be copied to this pointer
 * @param base integer value of the base that data should be converted to 
 * 
 * @return length The length of the converted data including negative sign and null terminator
*/
uint32_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);

/**
 * @brief Converts ASCII represented data back to integer type
 * 
 * Given a character set as a byte pointer, number of digits in character set, and
 * the base, it converts the character set to a 32-bit integer. Handles signed data 
 * 
 * @param ptr character set of ascii string 
 * @param digits number of digits in character set
 * @param base the base to convert to
 * 
 * @return integer The converted 32-bit integer 
 * 
*/
uint32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);