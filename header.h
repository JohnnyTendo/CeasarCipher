void cipherCapitols(char* plain, int key);
void decipherCapitols(char* encrypted, int key);
void cipherAll(char* plain, int key);
void decipherAll(char* plain, int key);
void cipherLetters(char* plain, int key);
void decipherLetters(char* encrypted, int key);

void cipherFile(int algorithm, char* fileName, int key);
void decipherFile(int algorithm, char* fileName, int key);

void printArray(char* _input);
void userInterface();

void selectCipher(int &_cipherIdx);
void selectKey(int &_key);
void selectDirection(char &_direction);
void selectText(char* _input);
