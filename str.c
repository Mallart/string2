#include "str.h"

int ptr_array_len(void** _array)
{
	CHECK_PTR(_array);
	int i = 0;
	for(; _array[i]; ++i);
	return i - 2;
}

int str_count_char(char* str, char c)
{
	CHECK_PTR(str);
	int occurences = 0;
	int length = str_len(str);
	for (int i = 0; i < length; ++i)
		if(str[i] == c)
			++occurences;
	return occurences;
}

short str_len(char* str)
{
	CHECK_PTR(str);
	int i = 0;
	for (; str[i]; ++i);
	return i;
}

char* str_copy(char* str, int len)
{
	char* output = malloc(sizeof(char*) * (len + 1));
	CHECK_PTR(output);
	for (int i = 0; i < len; ++i)
		output[i] = str[i];
	output[len] = '\0';
	return output;
}

int str_indexof(char* str, char c)
{
	int len = str_len(str);
	int i = 0;
	for (; i < len && str[i] != c; ++i);
	return i;
}

bool str_compare(char* str1, char* str2, int length)
{
	CHECK_PTR(str1);
	CHECK_PTR(str2);
	int i = 0;
	for (; i < length && str1[i] == str2[i]; ++i);
	return i == length;
}

char** str_split(char* str, char delimiter)
{
	int index = 0;
	CHECK_PTR(str);
	char** table = malloc(sizeof(char*) * str_count_char(str, delimiter));
	CHECK_PTR(table);
	for (int i = 0; i < str_count_char(str, delimiter) + 1 && str[i]; ++i)
	{
		table[i] = str_copy(str + index, str_indexof(str + index, delimiter));
		index += str_indexof(str + index, delimiter) + 1;
	}
	return table;
}

int str_to_int(char* str, int len)
{
	int offset = 0;
	int sum = 0;
	int i = len;
	for (; i; --i)
		if (str[i - 1 + offset] > 47 && str[i - 1 + offset] < 58)
			sum += (str[i - 1 + offset] - 48) * power(10, len - i);
		else
		{
			++offset;
			--i;
		}
	return sum;
}

char* int_to_str(long long n)
{
	int initial = n;
	char* str = malloc(sizeof(char) * (num_zeros(n) + 2));
	CHECK_PTR(str);
	int index = num_zeros(n);
	while (index && n / index > 10)
	{
		int div = n % 10;
		str[index] = div + 48;
		n /= 10;
		--index;
	}
	str[0] = n + 48;
	str[num_zeros(initial) + 1] = '\0';
	return str;
}


float str_to_float(char* str, int len)
{
	int offset = 0;
	float sum = 0;
	int dot = str_indexof(str, '.');
	sum += str_to_int(str, dot);
	for (int i = dot + 1; str[i] && i + offset < len; ++i)
		if (str[i] > 47 && str[i] < 57)
			sum += (float)(str[i] - 48) / power(10, i + offset - dot);
		else
			--offset;
	return sum;
}

char* float_to_str(float n)
{
	return str_insert(int_to_str((long long)(n * power(10, f_num_zeros(n) + 1))), ".", f_num_zeros(n) + 1);
}

char* str_trim(char* str)
{
	int len = str_len(str);
	int index = 0;
	char* result = malloc(sizeof(char) * (
		len
		- str_count_char(str, ' ')
		- str_count_char(str, '\t')
		- str_count_char(str, '\n'))
	);
	CHECK_PTR(str);
	CHECK_PTR(result);
	for (int i = 0; i < len; ++i)
	{
		switch (str[i])
		{
		case ' ':
		case '\t':
		case '\n': ++i;
		default:
			result[index] = str[i];
			++index;
			break;
		}
	}
	result[index] = '\0';
	return result;
}

char* str_substring(char* str, int start, int length)
{
	CHECK_PTR(str);
	char* result = malloc(sizeof(char) * (length + 1));
	CHECK_PTR(result);
	for(int i = 0; str[i] && i < length; ++i)
		result[i] = str[i + start]; 
	result[length] = '\0';
	return result;
}


char* str_concat(char* str1, char* str2)
{
	CHECK_PTR(str1);
	CHECK_PTR(str2);
	int offset = str_len(str1);
	int max_bound = str_len(str2);
	char* result = malloc(sizeof(char) * (offset + max_bound + 1));
	CHECK_PTR(result);
	for (int i = 0; i < offset; ++i)
		result[i] = str1[i];
	for (int i = offset; i < offset + max_bound; ++i)
		result[i] = str2[i - offset];
	result[offset + max_bound] = '\0';
	return result;
}

char* str_insert(char* str, char* insert, int index)
{
	CHECK_PTR(str);
	CHECK_PTR(insert);
	int len = str_len(str);
	int insert_len = str_len(insert);
	char* result = malloc(sizeof(char) * (len + insert_len + 1));
	CHECK_PTR(result);
	for (int i = len; i >= index; --i)
		result[i + insert_len] = str[i];
	for (int i = index; i < index + insert_len; ++i)
		result[i] = insert[i - index];
	for (int i = 0; i < index; ++i)
		result[i] = str[i];
	result[len + insert_len] = '\0';
	return result;
}

char* char_to_str(char c)
{
	char* str = malloc(sizeof(char) * 2);
	CHECK_NV_PTR(str);
	str[0] = c;
	str[1] = '\0';
	return str
}

size_t find_char(char* str, char c)
{
	size_t i = 0,
		len = str_len(str);
	for (; i < len && str[i] != c; ++i);
	return i;
}

int power(int a, int b)
{
	int n = a;
	if (!b)
		return 1;
	for (int i = 1; i < b; ++i)
		n *= a;
	return n;
}

float inverse_power(float n, float p)
{
	return 1 / power(n, p);
}

int num_zeros(long long n)
{
	int i = 0;
	float f = n;
	while (f > 10)
	{
		f /= 10;
		++i;
	}
	return i;
}

int f_num_zeros(float n)
{
	int i = 0;
	while (n > 10)
	{
		n /= 10;
		++i;
	}
	return i;
}