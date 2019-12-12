//CapitolCipher
void cipherCapitols(char* plain, int key);
void decipherCapitols(char* encrypted, int key);

//LetterCipher
void cipherLetters(char* plain, int key);
void decipherLetters(char* encrypted, int key);

//AllCipher
void cipherAll(char* plain, int key);
void* decipherAll(char* plain, int key);

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

//Structures
void initializeStructures(void);
