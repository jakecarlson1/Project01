#include "word.h"


/*
  Word default constructor with initialization of variables
*/
Word::Word():
  length(25), xCoord(0), yCoord(0), direction(0), wordFound(0)
{
  word = 0;
}

/*
  Word constructor that takes some char pointer from some buffer and stores it
  to a new character array. Also updates the length value
*/
Word::Word(char* w)
{
  length = strlen(w);
  word = new char[strlen(w) + 1];
    strcpy(word, w);
}

/*
  Word destructor, dealocated the memory used to store the word as long as
  word has been initialized
*/
Word::~Word()
{
  if(word != 0)
    delete[] word;
}

/*
  getWord returns the memory address stored in word
*/
char* Word::getWord()
{
  return word;
}

/*
  printInfo prints the word, the x and y coordinate of it's first character and
  direction if it has been found, and prints -1 if it hasn't been found
*/
void Word::printInfo()
{

}

/**********************
  Getters and Setters
**********************/

void Word::setXCoord(int x)
{
  xCoord = x;
}

int Word::getXCoord()
{
  return xCoord;
}

void Word::setYCoord(int y)
{
  yCoord = y;
}

int Word::getYCoord()
{
  return yCoord;
}

void Word::setDirection(int dir)
{
  direction = dir;
}

int Word::getDirection()
{
  return direction;
}

void Word::changeWordFound()
{
  wordFound = 1;
}
