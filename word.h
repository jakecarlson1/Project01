#ifndef WORD_H
#define WORD_H

#include <iostream>
#include <cstring>
#include <cctype>
#include <fstream>
#include "gameboard.h"
using namespace std;

class Word
{
private:
  char* word;
  int length;
  int xCoord;
  int yCoord;
  int direction;
  bool wordFound;
  char** array;

public:
  Word();
  Word(char*);
  ~Word();

  char* getWord();
  void printInfo();
  void searchBoard(GameBoard);

  void setXCoord(int);
  int getXCoord();
  void setYCoord(int);
  int getYCoord();
  void setDirection(int);
  int getDirection();
  void changeWordFound();
};

#endif // WORD_H
