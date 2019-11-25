#include <stdio.h>
#include "header.h"
#include <string.h>
#include <iostream>
#include <fstream>

int main()
{
    char plain[100];
    UserInterface(plain);
    return 0;
}


void userInterface(char* _input)
{
    int cipherIdx;
    char key[100];
    char direction;
    char kind;
    printf("File or text (f/t): \r\n");
    scanf(" %c", &kind);
    printf("___________________\r\n");
    if (kind == 'f')
    {
        printf("Select Cipher: \r\n");
        printf("1 - CAPITOL LETTERS\r\n");
        printf("2 -   all letters  \r\n");
        printf("3 -    all chars   \r\n");
        printf("___________________\r\n");
        printf("Insert Index: ");
        scanf("%d", &cipherIdx);
        printf("___________________\r\n");
        if (cipherIdx == 1 || cipherIdx == 2 || cipherIdx == 3)
        {
            printf("Insert Key: ");
            scanf("%s", key);
            printf("___________________\r\n");
            printf("Cipher or decipher (c/d): ");
            scanf(" %c", &direction);
            printf("___________________\r\n");
            if (direction == 'c')
            {
                printf("Input Filename: ");
                scanf("%s", _input);
                cipherFile(cipherIdx, _input, generateKey(key));
            }
            else if (direction == 'd')
            {
                printf("Input Filename: ");
                scanf("%s", _input);
                decipherFile(cipherIdx, _input, generateKey(key));
            }
            else
            {
                return;
            }
        }
        else
        {
            return;
        }
    }
    else if (kind == 't')
    {
        printf("Select Cipher: \r\n");
        printf("1 - CAPITOL LETTERS\r\n");
        printf("2 -   all letters  \r\n");
        printf("3 -    all chars   \r\n");
        printf("___________________\r\n");
        printf("Insert Index: ");
        scanf("%d", &cipherIdx);
        printf("___________________\r\n");
        if (cipherIdx == 1)
        {
            printf("Insert Key: ");
            scanf("%s", key);
            printf("___________________\r\n");
            printf("Cipher or decipher (c/d): ");
            scanf(" %c", &direction);
            printf("___________________\r\n");
            if (direction == 'c')
            {
                printf("Input Text: ");
                scanf("%s", _input);
                printArray(cipherCapitols(_input, generateKey(key)));
            }
            else if (direction == 'd')
            {
                printf("Input Text: ");
                scanf("%s", _input);
                printArray(decipherCapitols(_input, generateKey(key)));
            }
            else
            {
                return;
            }
        }
        else if (cipherIdx == 2)
        {
            printf("Insert Key: ");
            scanf("%s", key);
            printf("___________________\r\n");
            printf("Cipher or decipher (c/d): ");
            scanf(" %c", &direction);
            printf("___________________\r\n");
            if (direction == 'c')
            {
                printf("Input Text: ");
                scanf("%s", _input);
                printArray(cipherLetters(_input, generateKey(key)));
            }
            else if (direction == 'd')
            {
                printf("Input Text: ");
                scanf("%s", _input);
                printArray(decipherLetters(_input, generateKey(key)));
            }
            else
            {
                return;
            }
        }
        else if (cipherIdx == 3)
        {
            printf("Insert Key: ");
            scanf("%s", key);
            printf("___________________\r\n");
            printf("Cipher or decipher (c/d): ");
            scanf(" %c", &direction);
            printf("___________________\r\n");
            if (direction == 'c')
            {
                printf("Input Text: ");
                scanf("%s", _input);
                printArray(cipherAll(_input, generateKey(key)));
            }
            else if (direction == 'd')
            {
                printf("Input Text: ");
                scanf("%s", _input);
                printArray(decipherAll(_input, generateKey(key)));
            }
            else
            {
                return;
            }
        }

        else
        {
            return;
        }
    }
    else
    {
        printf("No valid output type.\r\n");
    }
}

char* cipherCapitols(char* plain, int key)
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

char* decipherCapitols(char* encrypted, int key)
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

char* cipherLetters(char* plain, int key)
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

    }
    return plain;
}

char* cipherAll(char* plain, int key)
{
  unsigned int n = strlen(plain);
  for (int i = 0; i < n; i++)
  {
    plain[i] += key;
  }
  return plain;
}

char* decipherAll(char* plain, int key)
{
  unsigned int n = strlen(plain);
  for (int i = 0; i < n; i++)
  {
    if((plain[i] - key) < 0)
    {
      plain[i] += 255 -key;
    }
    else
    {
      plain[i] -= key;
    }
  }
  return plain;
}

char* decipherLetters(char* encrypted, int key)
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

void cipherFile(int algorithm, char* fileName, int key)
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
    if (algorithm == 1)
        cipherCapitols(buffer, key);
    else if (algorithm == 2)
        cipherLetters(buffer, key);
    else if (algorithm == 3)
        cipherAll(buffer, key);
    oFile.open(fileName, std::ios::out);
    oFile.write(buffer, size);
    delete[] buffer;
    oFile.close();
    printf("Ciphered file %s successfully.\r\n", fileName);
}

void decipherFile(int algorithm, char* fileName, int key)
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
    if (algorithm == 1)
        decipherCapitols(buffer, key);
    else if (algorithm == 2)
        decipherLetters(buffer, key);
    else if (algorithm == 3)
        decipherAll(buffer, key);
    oFile.open(fileName, std::ios::out);
    oFile.write(buffer, size);
    delete[] buffer;
    oFile.close();
    printf("Deciphered file %s successfully.\r\n", fileName);
}
