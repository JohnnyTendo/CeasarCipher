#include <iostream>
#include <fstream>

#include <stdio.h>
#include "header.h"
#include <string.h>

//Works
void cipherCapitols(char* plain, int key)
{
    key %= 26;
    //Besser:
    /*
    * unsigned int n = sizeof(plain) / sizeof(plain[0])
    */
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
}

//Works
void decipherCapitols(char* encrypted, int key)
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
}

//works
void cipherAll(char* plain, int key)
{
  unsigned int n = strlen(plain);
  for (int i = 0; i < n; i++)
  {
    int _value = plain[i];
    if((_value + key)>255)
        plain[i] += (key - 255);
    else
        plain[i] += key;
  }
}

//works
void decipherAll(char* plain, int key)
{
  unsigned int n = strlen(plain);
  for (int i = 0; i < n; i++)
  {
    long _value = plain[i];
    if((_value - key) < 0)
        plain[i] -= (key + 255);
    else
        plain[i] -= key;
  }
}

//works
void cipherLetters(char* plain, int key)
{
    key %= 52;
    unsigned int n = strlen(plain);
    for (int i = 0; i < n; i++)
    {
        int _value = plain[i];
        if ((64 < _value && _value < 91) || (96 < _value && _value < 123))
        {
            _value += key;
            if (90 < _value && _value < 97)
                _value += 6;
            if (122 < _value)
                _value -= 59;
            plain[i] = _value;
        }
    }
}

//works
void decipherLetters(char* encrypted, int key)
{
    key %= 52;
    unsigned int n = strlen(encrypted);
    for (int i = 0; i < n; i++)
    {
        int _value = encrypted[i];
        if ((64 < _value && _value < 91) || (96 < _value && _value < 123))
        {
            _value -= key;
            if ((90 < _value && _value < 97) || (96 < (_value - key) && (_value - key) < 97))
                _value -= 6;
            else if (_value < 65)
                _value += 59;
            encrypted[i] = _value;
        }
    }
}

//use fprint() , fopen() etc to reference the struct FILE instead

//works but deprecated in cause of c++ usage
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

//works but deprecated in cause of c++ usage
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

void cryptFile(int _cipherIdx, char* _input, int _key)
{
    _input = sprintf("%s.txt",_input);
    FILE* file = fopen(_input, "r+");
    long size = ftell(file);
    char* buffer = new char[size];
    fread(buffer, size, 1, file);
    if (algorithm == 1)
        cipherCapitols(buffer, key);
    else if (algorithm == 2)
        cipherLetters(buffer, key);
    else if (algorithm == 3)
        cipherAll(buffer, key);
    fprintf(file, buffer);
    fclose(file);
    delete[] buffer;
    printf("Deciphered file %s successfully.\r\n", _input);
}

void decryptFile(int _cipherIdx, char* _input, int _key)
{
    _input = sprintf("%s.txt",_input);
    FILE* file = fopen(_input, "r+");
    long size = ftell(file);
    char* buffer = new char[size];
    fread(buffer, size, 1, file);
    if (algorithm == 1)
        decipherCapitols(buffer, key);
    else if (algorithm == 2)
        decipherLetters(buffer, key);
    else if (algorithm == 3)
        decipherAll(buffer, key);
    fprintf(file, buffer);
    fclose(file);
    delete[] buffer;
    printf("Deciphered file %s successfully.\r\n", _input);
}
