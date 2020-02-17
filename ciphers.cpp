#include "header.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

//Works
void cipherCapitols(char* plain, int key)
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
  for (unsigned int i = 0; i < n; i++)
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

//works
void cipherFile(int algorithm, char* fileName, int key)
{
  FILE *fileRead;
  long lSize;
  char * buffer;
  fileRead = fopen(fileName, "r");
  if (fileRead == NULL)
  {
    printf("Error opening file %s", fileName);
    exit(1);
  }
  fseek(fileRead, 0, SEEK_END);
  lSize = ftell (fileRead);
  rewind(fileRead);
  buffer = (char*) malloc (sizeof(char)*lSize);
  fread(buffer, 1, lSize, fileRead);
  fclose(fileRead);
  FILE *fileWrite;
  fileWrite = fopen(fileName, "w");
  if (fileWrite == NULL)
  {
    printf("Error opening file %s", fileName);
    exit(1);
  }
  if (algorithm == 1)
    cipherCapitols(buffer, key);
  else if (algorithm == 2)
    cipherLetters(buffer, key);
  else if (algorithm == 3)
    cipherAll(buffer, key);
  fwrite(buffer, 1, lSize, fileWrite);
  fclose(fileWrite);
  printf("Ciphered file %s successfully.\r\n", fileName);
}

//works
void decipherFile(int algorithm, char* fileName, int key)
{
  FILE *fileRead;
  long lSize;
  char * buffer;
  fileRead = fopen(fileName, "r");
  if (fileRead == NULL)
  {
    printf("Error opening file %s", fileName);
    exit(1);
  }
  fseek(fileRead, 0, SEEK_END);
  lSize = ftell (fileRead);
  rewind(fileRead);
  buffer = (char*) malloc (sizeof(char)*lSize);
  fread(buffer, 1, lSize, fileRead);
  fclose(fileRead);
  FILE *fileWrite;
  fileWrite = fopen(fileName, "w");
  if (fileWrite == NULL)
  {
    printf("Error opening file %s", fileName);
    exit(1);
  }
  if (algorithm == 1)
    decipherCapitols(buffer, key);
  else if (algorithm == 2)
    decipherLetters(buffer, key);
  else if (algorithm == 3)
    decipherAll(buffer, key);
  fwrite(buffer, 1, lSize, fileWrite);
  fclose(fileWrite);
  printf("Ciphered file %s successfully.\r\n", fileName);
}
