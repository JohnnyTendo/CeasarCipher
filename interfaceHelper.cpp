#include <stdio.h>

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
                //ref header.h for refactor
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
    generateKey(_key);
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
