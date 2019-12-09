#include <stdio.h>

void selectCipher(char* _cipherIdx)
{
    printf("Select Cipher: \r\n");
    printf("1 - CAPITOL LETTERS\r\n");
    printf("2 -   all letters  \r\n");
    printf("3 -    all chars   \r\n");
    printf("___________________\r\n");
    printf("Insert Index: ");
    scanf("%d", &_cipherIdx);
    printf("___________________\r\n");
}

void selectKey(char* _key)
{
    printf("Insert _key: ");
    scanf("%s", _key);
    printf("___________________\r\n");
}

void selectDirection(char* _direction)
{
    printf("Cipher or decipher (c/d): ");
    scanf(" %c", &_direction);
    printf("___________________\r\n");
}

void selectText(char* _input)
{
    printf("Input text or filename: ");
    scanf("%s", _input);
}