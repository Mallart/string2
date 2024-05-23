// multi-includes prevention
#ifndef STR2
#define STR2

#include <stdlib.h>

#define bool unsigned short
#define CHECK_PTR(ptr) if(!ptr) return 0
#define CAST_STR_TO_INT(str) str_to_int(str, str_len(str))
#define CAST_STR_TO_FLOAT(str) str_to_float(str, str_len(str))
#define APPEND_STR(_dest, _src) memcpy(_dest, _src, strlen(_src) * sizeof(char))
#define APPEND_INCR_STR(_index, _dest, _src) { memcpy(_dest + _index, _src, strlen(_src) * sizeof(char)); _index += strlen(_src); }
#define STR_INCR_RETURN(_index, _dest) { memcpy(_dest + index, "\n", 1); _index++; }

// Returns the number of elements in a pointer array.
int ptr_array_len(void** _array);
// Count character occurences in a string.
int str_count_char(char* str, char c);
// Returns the number of characters in a null-terminated string.
short str_len(char* string);
// Returns a new string identical to the provided one.
char* str_copy(char* string, int length_to_copy);
// Returns the given character's position in the string, or the string's length if that character isn't present.
int str_indexof(char* string, char character);
// Returns 1 if the two strings are identical, 0 otherwise.
bool str_compare(char* string_1, char* string_2, int length);
// Returns an array of strings, separated by a removed character.
char** str_split(char* string, char delimiter);
// Parse a string into an int.
int str_to_int(char* string, int length);
// Converts an int to a string
char* int_to_str(long long n);
// Parse a string into a float.
// The float part ignores any text put in the string that isn't digits.
float str_to_float(char* str, int length);
// Converts a float to a string
char* float_to_str(float n);
// Removes tabs, "returns", and spaces before the first visible character and after the last.
char* str_trim(char* string);
// Creates a new string based on the given one, but beginning at a given index and finishing n characters after.
char* str_substring(char* string, int start, int length);
// Returns a new string being the concatenations of the two one's result
char* str_concat(char* str1, char* str2);
// Inserts a string inside another with the specified index
char* str_insert(char* str, char* insert, int index);
// Converts a character to a string
char* char_to_str(char c);
// Finds a character and returns its position
size_t find_char(char* str, char c);
// Count and return the number of zeros (or the number's power of 10) of a long int
int num_zeros(long long n);
// Count and return the number of zeros (number's power of 10) of a float
int f_num_zeros(float n);
int power(int a, int b);
float inverse_power(float, float);

#endif