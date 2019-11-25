//CapitolCipher
char* CipherCapitols(char* plain, int key);
char* DecipherCapitols(char* encrypted, int key);

//LetterCipher
char* CipherLetters(char* plain, int key);
char* DecipherLetters(char* encrypted, int key);

//AllCipher
char* CipherAll(char* plain, int key);
char* DecipherAll(char* plain, int key);

//FileCipher
void CipherFile(int algorithm, char* fileName, int key);
void DecipherFile(int algorithm, char* fileName, int key);

//Helper
void PrintArray(char* _input);
void UserInterface(char* _input);
int GenerateKey(char* _key);
