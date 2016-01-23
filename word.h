#ifndef WORD_H
#define WORD_H

#include <cstring>
#include <cctype>
using namespace std;

class Word
{
private:
  char* word;
  int length;
  int xCoord;
  int yCoord;
  int direction;

public:
  Word();
  Word(char*);
  ~Word();

  char* getWord();
  void printInfo();
};

#endif // WORD_H
