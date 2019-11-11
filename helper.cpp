#include <stdio.h>
#include <string.h>

void PrintArray(char* _input)
{
    unsigned int n = strlen(_input); 
    for (int i = 0; i < n; i++)
    {
        printf("%c", _input[i]);
    }
    printf("\r\n");
}