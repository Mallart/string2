#include "str.h"
#include <stdio.h>

// Example of use

void main()
{
    char* str;
    printf(str = "Colon index: %d\n", str_indexof(str, ':'));
    printf("%s\nLength of preceeding string: %d\n", str = "idk lol", str_len(str));
    printf("%s", str_substring("hidden text hidden", 7, 4));
    str="\nplease, do, an, array";
    char** _array = str_split(str, ',');
    for(int i = 0; i < ptr_array_len(_array); ++i)
        printf("%s\n", _array[i]);
    exit(0);
}