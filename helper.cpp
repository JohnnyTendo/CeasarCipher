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

int generateKey(char* _key)
{
  long key = 1;
  unsigned int n = strlen(_key);
  for (int i = 0; i < n; i++)
  {
      key += (int)_key[i];
      printf("added %d to %d\r\n",_key[i], key);
  }
    return key;
}

int fileAsKey(char* _filePath)
{
    int sum;
    FILE* file = fopen( _filePath, "r" );
    if (!file)
    {
        return 0;
    }
    for (int i = 0; i < file.length; i++)
    {
        sum += file[i];
    }
    return sum;
}
