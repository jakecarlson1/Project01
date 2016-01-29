#include "gameboard.h"

GameBoard::GameBoard():
  size(0), capacity(10), width(-1)
{
  board = new char*[capacity];
  for(int i = 0; i < capacity; i++)
    board[i] = 0;
}

GameBoard::~GameBoard()
{
  for(int i = 0; i < capacity; i++)
    delete[] board[i];
  delete board;
}

/*
  addLine take a char* input. It updates the width of the board. It then checks
  to see if the board array needs to be resized and resizes it if needed. Then
  it adds line to the board array and increments size.
*/
void GameBoard::addLine(char* line)
{
  //gets the width of the board and generates a character array that long for
  //each line
  if(width == -1)
  {
    width = strlen(line);
    for(int i = 0; i < capacity; i++)
      board[i] = new char[width + 1];
  }
  //sets all of the characters being saved to the board to lowercase
  for(int i = 0; i < width; i++)
    line[i] = tolower(line[i]);
  //runs resize if the board is full
  if(size == capacity)
    resize();
  //copys a line into the board and increments size
  strcpy(board[size], line);
  size++;
}

/*
  resize creates a new larger array, points the elements of that array to the
  existing array, and then populates the remaining spaces with new char arrays.
  The memory used for the old board is released and board is pointed toward the
  new array.
*/
void GameBoard::resize()
{
  //dynamically allocates a larger array of char pointers
  char** temp = new char*[capacity + 5];
  //population of the new array
  for(int i = 0; i < size; i++)
    temp[i] = board[i];
  for(int i = 0; i < 5; i++)
    temp[size + i] = new char[width + 1];
  //deletes the old board array
  for(int i = 0; i < size; i++)
    delete[] board[i];
  delete board;
  //increments capazity
  capacity += 5;
  //points board to the new, bigger array
  board = temp;
}

/**********************
  Setters and Getters
**********************/

int GameBoard::getWidth()
{
  return width;
}

int GameBoard::getSize()
{
  return size;
}

char** GameBoard::getBoard()
{
  return board;
}

/*************
  Operators
*************/

char* GameBoard::operator[](int i)
{
  return board[i];
}
