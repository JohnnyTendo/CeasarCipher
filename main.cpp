#include <stdio.h>
#include "header.h"
#include <string.h>
#include <iostream>
#include <fstream>

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
    printf("3 -      File      \r\n");
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
    printf("Input Text/Filename: ");
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

    case 3:
        if (direction == 'c')
        {
            CipherFile(_input, key);
        }
        else if (direction == 'd')
        {
            DecipherFile(_input, key);
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
        long _value = plain[i];
        printf("%d -> ", _value);
        if ((64 < _value && _value < 91) || (96 < _value && _value < 123))
        {
            _value += key;
            printf("%d -> ", _value);
            if (90 < _value && _value < 97)
            {
                _value += 6;
            printf("%d a\r\n", _value);
            }
            if (122 < _value)
            {
                _value -= 59;
            printf("%d b\r\n", _value);
            }
            printf(" end\r\n");
            plain[i] = _value;
        }
        else
        {
            printf("%d end\r\n" ,plain[i]);
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
        long _value = encrypted[i];
        if ((64 < _value && _value < 91) || (96 < _value && _value < 123))
        {
            _value -= key;
            if ((90 < _value && _value < 97) || (96 < (_value + key) && (_value - key) < 97))
            {
                _value -= 6;
            }
            else if (_value < 65)
            {
                _value += 59;
            }
            encrypted[i] = _value;
        }
    }
    return encrypted;
}

void CipherFile(char* fileName, int key)
{
    std::ifstream iFile;
    std::ofstream oFile;
    iFile.open(fileName, std::ios::in);
    iFile.seekg (0,iFile.end);
    long size = iFile.tellg();
    iFile.seekg (0);

    char* buffer = new char[size];
    iFile.read(buffer, size);
    iFile.close();
    CipherLetters(buffer, key);
    oFile.open(fileName, std::ios::out);
    oFile.write(buffer, size);
    delete[] buffer;
    oFile.close();
    printf("Ciphered file %s successfully.\r\n", fileName);
}

void DecipherFile(char* fileName, int key)
{
    std::ifstream iFile;
    std::ofstream oFile;
    iFile.open(fileName, std::ios::in);
    iFile.seekg (0,iFile.end);
    long size = iFile.tellg();
    iFile.seekg (0);
    char* buffer = new char[size];
    iFile.read(buffer, size);
    iFile.close();
    DecipherLetters(buffer, key);
    oFile.open(fileName, std::ios::out);
    oFile.write(buffer, size);
    delete[] buffer;
    oFile.close();
    printf("Deciphered file %s successfully.\r\n", fileName);
}