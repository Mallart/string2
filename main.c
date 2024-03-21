#include "str.h"
#include <stdio.h>

// Example of use

void main()
{
    char* str = "Colon index:";
    printf("%s%d\n", str, str_indexof(str, ':'));
    printf("%s\nLength of preceeding string: %d\n", str = "idk lol", str_len(str));
    printf("%s", str_substring("hidden text hidden", 7, 4));
    printf("\nComparing two exactly identical strings: \n%d\n", str_compare("abc", "abc", 3));
    printf("\nComparing two different strings: \n%d\n", str_compare("acc", "abc", 3));
    str="1645";
    printf("Parsing \"%s\" to an int: %d\n", str, CAST_STR_TO_INT(str));
    printf("Parsing the first two digits of \"%s\" to an int: %d\n", str, str_to_int(str, 2));
    str = "13.2 random text 3";
    printf("Parsing \"%s\" to a float: %f\n", str, CAST_STR_TO_FLOAT(str));
    printf("Parsing the first four characters of \"%s\" to a float: %f\n", str, str_to_float(str, 4));
    str="\nplease, do, an, array, go, on";
    char** _array = str_split(str, ',');
    printf("%d", ptr_array_len(_array));
    for(int i = 0; i < ptr_array_len(_array); ++i)
    {
        printf("no format: \t\"%s\"\n", _array[i]);
        printf("format: \t\"%s\"\n", str_trim(_array[i]));
    }
    exit(0);
}