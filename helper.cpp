#include "header.h"
#include <stdio.h>
#include <string.h>

void printArray(char* _input)
{
  unsigned int n = strlen(_input);
  for (int i = 0; i < n; i++)
  {
    printf("%c", _input[i]);
  }
  printf("\r\n");
}

void userInterface()
{
    char _input[100];
    int cipherIdx;
    int key;
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
          cipherFile(cipherIdx, _input, key);
        }
        else if (direction == 'd')
        {
          selectText(_input);
          decipherFile(cipherIdx, _input, key);
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
          cipherCapitols(_input, key);
          printArray(_input);
        }
        else if (direction == 'd')
        {
          selectText(_input);
          decipherCapitols(_input, key);
          printArray(_input);
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
          cipherLetters(_input, key);
          printArray(_input);
        }
        else if (direction == 'd')
        {
          selectText(_input);
          decipherLetters(_input, key);
          printArray(_input);
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
          cipherAll(_input, key);
          printArray(_input);
        }
        else if (direction == 'd')
        {
          selectText(_input);
          decipherAll(_input, key);
          printArray(_input);
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
