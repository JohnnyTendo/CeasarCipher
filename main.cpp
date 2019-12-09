#include <stdio.h>
#include "header.h"
#include <string.h>
#include <iostream>
#include <fstream>

int main()
{
    char plain[100];
    userInterface(plain);
    return 0;
}

//Works perfectly
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
        selectCipher(cipherIdx);
        if (cipherIdx == 1 || cipherIdx == 2 || cipherIdx == 3)
        {
            selectKey(key);
            selectDirection(direction);
            if (direction == 'c')
            {
                selectText(_input);
                cipherFile(cipherIdx, _input, generateKey(key));
            }
            else if (direction == 'd')
            {
                selectText(_input);
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
        selectCipher(cipherIdx);
        if (cipherIdx == 1)
        {
            selectKey(key);
            selectDirection(direction);
            if (direction == 'c')
            {
                selectText(_input);
                printArray(cipherCapitols(_input, generateKey(key)));
            }
            else if (direction == 'd')
            {
                selectText(_input);
                printArray(decipherCapitols(_input, generateKey(key)));
            }
            else
            {
                return;
            }
        }
        else if (cipherIdx == 2)
        {
            selectKey(key);
            selectDirection(direction);
            if (direction == 'c')
            {
                selectText(_input);
                printArray(cipherLetters(_input, generateKey(key)));
            }
            else if (direction == 'd')
            {
                selectText(_input);
                printArray(decipherLetters(_input, generateKey(key)));
            }
            else
            {
                return;
            }
        }
        else if (cipherIdx == 3)
        {
            selectKey(key);
            selectDirection(direction);
            if (direction == 'c')
            {
                selectText(_input);
                printArray(cipherAll(_input, generateKey(key)));
            }
            else if (direction == 'd')
            {
                selectText(_input);
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

//Works perfectly
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

//Works perfectly
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

//Unexpected behaviour
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

//Should work now 031219
char* cipherAll(char* plain, int key)
{
  unsigned int n = strlen(plain);
  for (int i = 0; i < n; i++)
  {
    long _value = plain[i];
    if((_value + key)>255)
        plain[i] += (key - 255);
    else
        plain[i] += key;
  }
  return plain;
}

//Should work now 031219
char* decipherAll(char* plain, int key)
{
  unsigned int n = strlen(plain);
  for (int i = 0; i < n; i++)
  {
    long _value = plain[i];
    if((_value - key) < 0)
        plain[i] += (-key + 255);
    else
        plain[i] -= key;
  }
  return plain;
}

//Unexpected behaviour
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

//Works perfectly
void cipherFile(int algorithm, char* fileName, int key)
{
    //filestream ist cpp nicht c -> weg in reinem c suchen (structs hatten wir aber noch nicht)
    //ggf structs mit erklären
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

//Works perfectly
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
