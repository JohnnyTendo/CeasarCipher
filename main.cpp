#include <stdio.h>
#include "header.h"
#include <string.h>

#define KEY 2
#define PLAIN "A CDEFGHIZA"

int main()
{
    char plain[100] = PLAIN;
    UserInterface(plain);
    /*
    printf("Plain:     ");
    PrintArray(plain);
    char* encrypted = CipherLetters(plain, KEY);
    printf("Encrypted: ");
    PrintArray(encrypted);
    char* decrypted = DecipherLetters(encrypted, KEY);
    printf("Decrypted: ");
    PrintArray(decrypted);
    */
    return 0;
}


void UserInterface(char* _input)
{
    int cipherIdx;
    int key;
    char direction;
    printf("Select Cipher: \r\n");
    printf("1 - CAPITOL LETTERS\r\n");
    printf("2 -   all letters  \r\n");
    printf("___________________\r\n");
    printf("Insert Index: ");
    scanf("%d", &cipherIdx);
    printf("___________________\r\n");
    printf("Cipher or decipher (c/d): ");
    scanf(" %c", &direction);
    printf("___________________\r\n");
    printf("Insert Key: ");
    scanf("%d", &key);
    printf("___________________\r\n");
    printf("Input Text: ");
    scanf("%s", _input);
    
    switch (cipherIdx)
    {
    case 1:
        if (direction == 'c')
        {
            char* encrypted = CipherCapitols(_input, key);
            PrintArray(encrypted);
        }
        else if (direction == 'd')
        {
            char* decrypted = DecipherCapitols(_input, key);
            PrintArray(decrypted);
        }
        break;

    case 2:
        if (direction == 'c')
        {
            char* encrypted = CipherLetters(_input, key);
            PrintArray(encrypted);
        }
        else if (direction == 'd')
        {
            char* decrypted = DecipherLetters(_input, key);
            PrintArray(decrypted);
        }
        break;
    
    default:
        printf("Invalid Cipher Index\r\n");
        break;
    }
}

char* CipherCapitols(char* plain, int key)
{
    key %= 26;
    unsigned int n = strlen(plain);
    for (int i = 0; i < n; i++)
    {
        if (64 < plain[i] && plain[i] < 91)
        {
            plain[i] += key;
            if (plain[i] > 90)
            {
                plain[i] -= 26;
            }
        }
    }
    return plain;
}

char* DecipherCapitols(char* encrypted, int key)
{
    key %= 26;
    unsigned int n = strlen(encrypted);
    for (int i = 0; i < n; i++)
    {
        if (64 < encrypted[i] && encrypted[i] < 91)
        {
            encrypted[i] -= key;
            if (encrypted[i] < 65)
            {
                encrypted[i] += 26;
            }
        }
    }
    return encrypted;
}


char* CipherLetters(char* plain, int key)
{
    key %= 52;
    unsigned int n = strlen(plain);
    for (int i = 0; i < n; i++)
    {
        if ((64 < plain[i] && plain[i] < 91) || (96 < plain[i] && plain[i] < 123))
        {
            plain[i] += key;
            if (90 < plain[i] && plain[i] < 97)
            {
                plain[i] += 6;
            }
            if (123 < plain[i])
            {
                plain[i] -= 59;
            }
        }
    }
    return plain;
}

char* DecipherLetters(char* encrypted, int key)
{
    key %= 52;
    unsigned int n = strlen(encrypted);
    for (int i = 0; i < n; i++)
    {
        if ((64 < encrypted[i] && encrypted[i] < 91) || (96 < encrypted[i] && encrypted[i] < 123))
        {
            encrypted[i] -= key;
            if (90 < encrypted[i] && encrypted[i] < 97)
            {
                encrypted[i] -=6 ;
            }
            else if (encrypted[i] < 65)
            {
                encrypted[i] += 59;
            }
        }
    }
    return encrypted;
}