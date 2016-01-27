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
  delete[] board;
}
/*
  addLine take a char* input. It updates the width of the board. It then checks
  to see if the board array needs to be resized and resizes it if needed. Then
  it adds line to the board array and increments size.
*/
void GameBoard::addLine(char* line)
{
  cout << "Here: " << board << endl;
  if(width == -1)
  {
    width = strlen(line);
    for(int i = 0; i < capacity; i++)
      board[i] = new char[width + 1];
  }

  for(int i = 0; i < width; i++)
    line[i] = tolower(line[i]);

  if(size == capacity)
    resize();

  strcpy(board[size], line);
  cout << board[size] << endl;
  size++;
}

void GameBoard::resize()
{
  //dynamically allocates a larger array of Word object pointers
  char** temp = new char*[capacity + 5];
  //population of the new array
  for(int i = 0; i < size; i++)
    temp[i] = board[i];
  for(int i = 0; i < 5; i++)
    temp[size + i] = new char[width + 1];
  //deletes the old board array
  delete[]board;
  //increments capazity
  capacity += 5;
  //points board to the new, bigger array
  board = temp;
  cout << "resize ran" << endl;
}

/*
  printBoard function is for use in debuging. Prints the board
*/
void GameBoard::printBoard()
{
  cout << endl;

  cout << "Here: " << board << endl;
  // cout << "Here: " << board[0] << endl;
  for(int i = 0; i < size; i++)
  {
    cout << board[i];
    cout << "." << endl;
  }
}

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

char* GameBoard::operator[](int i)
{
  return board[i];
}
