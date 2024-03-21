// multi-includes prevention
#ifndef STR2
#define STR2

#include <stdlib.h>

#define bool unsigned short
#define CHECK_PTR(ptr) if(!ptr) return 0
#define CAST_STR_TO_INT(str) str_to_int(str, str_len(str))
#define CAST_STR_TO_FLOAT(str) str_to_float(str, str_len(str))

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
// Parse a string into a float.
float str_to_float(char* str, int length);
// Removes tabs, "returns", and spaces before the first visible character and after the last.
char* str_trim(char* string);
// Creates a new string based on the given one, but beginning at a given index and finishing n characters after.
char* str_substring(char* string, int start, int length);

int power(int a, int b);
float inverse_power(float, float);

#endif