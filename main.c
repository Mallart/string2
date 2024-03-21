#include "str.h"
#include <stdio.h>

// Example of use

void main()
{
    char* str = "Colon index:";
    printf("%s%d\n", str, str_indexof(str, ':'));
    printf("%s\nLength of preceeding string: %d\n", str = "idk lol", str_len(str));
    printf("%s", str_substring("hidden text hidden", 7, 4));
    printf("Comparing two exactly identical strings: \n%d\n", str_compare("abc", "abc", 3));
    printf("Comparing two different strings: \n%d\n", str_compare("acc", "abc", 3));
    str="\nplease, do, an, array";
    char** _array = str_split(str, ',');
    for(int i = 0; i < ptr_array_len(_array); ++i)
        printf("%s\n", _array[i]);
    exit(0);
}