#include "str.h"
#include <stdio.h>

// Example of use

int main()
{
    char* str = "Colon index:";
    float f_test = 597.64;
    int i_test = 651;

    printf("%s%d\n", str, str_indexof(str, ':'));
    str = "idk lol";
    printf("%s\nLength of preceeding string: %d\n", str, str_len(str));
    printf("%s", str_substring("hidden text hidden", 7, 4));
    printf("\nComparing two exactly identical strings: \n%d\n", str_compare("abc", "abc", 3));
    printf("\nComparing two different strings: \n%d\n", str_compare("acc", "abc", 3));
    str="1645";
    printf("Parsing \"%s\" to an int: %d\n", str, CAST_STR_TO_INT(str));
    printf("Parsing the first two digits of \"%s\" to an int: %d\n", str, str_to_int(str, 2));
    str = "13.2 random text 3";
    printf("Parsing \"%s\" to a float: %f\n", str, CAST_STR_TO_FLOAT(str));
    printf("Parsing the first four characters of \"%s\" to a float: %f\n", str, str_to_float(str, 4));
    printf(str_insert("This was into this string.\n", " an insert", 8));
    printf("This int: %d\tDisplayed as a string: %s\n", i_test, int_to_str(i_test));
    printf("This float: %f\tDisplayed as a string: %s\n", f_test, float_to_str(f_test, 2));
    printf(str_concat("Now be ready for ", "concatenation !\n"));
    str="\nplease, do, an , array\t, go\n, on";
    char** _array = str_split(str, ',');
    printf("Size of array: %d\n", ptr_array_len((void**)_array));
    for(int i = 0; i < ptr_array_len((void**)_array); ++i)
    {
        printf("no format: \t\"%s\"\n", _array[i]);
        printf("format: \t\"%s\"\n", str_trim(_array[i]));
    }
    return 0;
}