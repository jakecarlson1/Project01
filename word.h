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

  void searchUL(int, int);
  void searchU(int, int);
  void searchUR(int, int);
  void searchR(int, int);
  void searchDR(int, int);
  void searchD(int, int);
  void searchDL(int, int);
  void searchL(int, int);

public:
  Word();
  Word(char*);
  ~Word();

  void printInfo(ofstream&);
  void searchBoard(GameBoard&);

};

#endif // WORD_H
