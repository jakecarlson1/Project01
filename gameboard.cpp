#include "gameboard.h"

GameBoard::GameBoard():
  size(0), capacity(10), width(-1)
{
  board = new char*[capacity];
}

GameBoard::~GameBoard()
{
  delete[] board;
}
/*
  addLine take a char* input. It updates the width of the board. It then checks
  to see if the board array needs to be resized and resizes it if needed. Then
  it adds line to the board array and increments size.
*/
void GameBoard::addLine(char* line)
{
  if(width == -1)
    width = strlen(line);

  if(size == capacity)
    resize();

  board[size] = line;
  size++;
}

void GameBoard::resize()
{
  //dynamically allocates a larger array of Word object pointers
  char** temp = new char*[capacity + 5];
  //population of the new array
  for(int i = 0; i < size; i++){
    temp[i] = board[i];
  }
  //deletes the old board array
  delete[]board;
  //increments capazity
  capacity += 5;
  //points board to the new, bigger array
  board = temp;
}

/*
  printBoard function is for use in debuging. Prints the board
*/
void GameBoard::printBoard()
{
  cout << endl;

  for(int i = 0; i < size; i++)
  {
    for(int j = 0; j < width; j++)
      cout << board[i][j];
    cout << endl;
  }
}
