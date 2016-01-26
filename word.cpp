#include "word.h"
#include "gameboard.h"


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
  //cout << word << endl;
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
  //will change to fout
  cout << word << "|" << xCoord << "|" << yCoord << "|";
  if(direction == 1)
    cout << "ul";
  else if(direction == 2)
    cout << "u";
  else if(direction == 3)
    cout << "ur";
  else if(direction == 4)
    cout << "r";
  else if(direction == 5)
    cout << "dr";
  else if(direction == 6)
    cout << "d";
  else if(direction == 7)
    cout << "dl";
  else if(direction == 8)
    cout << "l";
  cout << endl;
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

void Word::searchBoard(GameBoard board)
{
  array = new char*[board.getSize()];
  // for(int i = 0; i < board.getSize(); i++)
  // {
  //   array[i] = board[i];
  // }
  cout << "Searching board" << endl;
  // for(int i = 0; i < board.getSize(); i++)
  // {
  //   for(int j = 0; j < board.getWidth(); j++)
  //   {
  //     if(word[0] == array[i][j])
  //     {
  //       cout << "Mathch Found: " << i << ", " << j << endl;
  //     }
  //   }
  // }
}
