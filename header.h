//CapitolCipher
char* CipherCapitols(char* plain, int key);
char* DecipherCapitols(char* encrypted, int key);

//LetterCipher
char* CipherLetters(char* plain, int key);
char* DecipherLetters(char* encrypted, int key);

//FileCipher
void CipherFile(char* fileName, int key);
void DecipherFile(char* fileName, int key);

//Helper
void PrintArray(char* _input);
void UserInterface(char* _input);