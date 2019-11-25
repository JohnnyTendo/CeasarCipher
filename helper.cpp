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

int GenerateKey(char* _key)
{
  long key = 1;
  unsigned int n = strlen(_key);
  for (int i = 0; i < n; i++)
  {
      key += (int)_key[i];
      printf("added %d to %d\r\n",_key[i], key);
  }
}
