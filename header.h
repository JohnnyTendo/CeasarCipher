//no returntypes for functions with pointer as parameter (refactor)

//CapitolCipher
char* cipherCapitols(char* plain, int key);
char* decipherCapitols(char* encrypted, int key);

//LetterCipher
char* cipherLetters(char* plain, int key);
char* decipherLetters(char* encrypted, int key);

//AllCipher
char* cipherAll(char* plain, int key);
char* decipherAll(char* plain, int key);

//FileCipher
void cipherFile(int algorithm, char* fileName, int key);
void decipherFile(int algorithm, char* fileName, int key);

//Helper
void printArray(char* _input);
void userInterface(char* _input);
int generateKey(char* _key);

//InterfaceHelper
void selectCipher(char* _cipherIdx);
void selectKey(char* _key);
void selectDirection(char* _direction);
void selectText(char* _input);
