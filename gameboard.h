#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <iostream>
#include <cstring>
#include <cctype>
#include <fstream>
using namespace std;

class GameBoard
{
private:
  char** board;
  int size;
  int capacity;
  int width;

  void resize();

public:
  GameBoard();
  ~GameBoard();

  void addLine(char*);
  int getWidth();
  int getSize();
  char** getBoard();
  char* operator[] (int);
};

#endif // GAMEBOARD_H
