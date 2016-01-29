#include "word.h"
#include "gameboard.h"


/*
  Word default constructor with initialization of variables
*/
Word::Word():
  length(0), xCoord(-1), yCoord(-1), direction(0), wordFound(0)
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
    delete[] word;
}

/*
  printInfo prints the word, the x and y coordinate of it's first character and
  direction if it has been found, and prints -1 if it hasn't been found
*/
void Word::printInfo(ofstream& fout)
{
  if(direction == 0)
  {
    fout << word << "|-1|-1|";
  }
  else
  {
  fout << word << "|" << xCoord << "|" << yCoord << "|";
  // if(direction == 0)
  //   fout << " ";
  if(direction == 1)
    fout << "ul";
  else if(direction == 2)
    fout << "u";
  else if(direction == 3)
    fout << "ur";
  else if(direction == 4)
    fout << "r";
  else if(direction == 5)
    fout << "dr";
  else if(direction == 6)
    fout << "d";
  else if(direction == 7)
    fout << "dl";
  else if(direction == 8)
    fout << "l";
  }
  fout << endl;
}

/*
  The following functions search the GameBoard for the word. A copy of the
  board is saved and then the function begins to search. First the function
  looks for anywhere the first letter of the word appears in the board. The
  folling if-statements only allow the word to search the board if it is within
  the scope of the related search algorithm (if the first letter of the word
  is in the upper left corner of the board, there is no need to search UL, U,
  UR, DL, or L because the word cannot possibly fit in these directions). Once
  the word is found the direction the word was found in is saved and the
  searching stops.
*/
void Word::searchBoard(GameBoard& board)
{
  //a copy of the board is saved
  array = new char*[board.getSize()];
  for(int i = 0; i < board.getSize(); i++)
  {
    array[i] = new char[board.getWidth()];
    strcpy(array[i], board[i]);
  }

  //searching starts
  for(int i = 0; i < board.getSize(); i++)
  {
    for(int j = 0; j < board.getWidth(); j++)
    {
      //if the first letter is found the searching gets more specific
      if(word[0] == array[i][j] && wordFound == 0)
      {
        //all of the following if-statements determine if the first letter is
        //in a place where the folling search function is applicable
        if(i - length >= -1 && j - length >= -1)
          searchUL(i, j);
        if(i - length >= -1)
          searchU(i, j);
        if(i - length >= -1 && board.getWidth() - length >= j)
          searchUR(i, j);
        if(board.getWidth() - length >= j)
          searchR(i, j);
        if(board.getSize() - length >= i && board.getWidth() - length >= j)
          searchDR(i, j);
        if(board.getSize() - length >= i)
          searchD(i, j);
        if(board.getSize() - length >= i && j - length >= -1)
          searchDL(i, j);
        if(j - length >= -1)
          searchL(i, j);
      }
    }
  }
  //deallocates the copy of board
  for(int i = 0; i < board.getSize(); i++)
    delete[] array[i];
  delete[] array;
}

/*
  The following direction-specific search functions each check one of the eight
  possible directions for the word from the first letter. They each opperate in
  a similar way. First they make the assumption that the word is found. Then a
  for-loop runs to see if a letter does not match the space that it is supposed
  to in the board. If a letter does not match then wordFound is set back to
  false. At the end of the loop if wordFound is still true then the word has
  been found and the direction is saved.
*/
void Word::searchUL(int x, int y)
{
  wordFound = 1;
  for(int i = 1; i < length; i++)
  {
    if(word[i] != array[x - i][y - i])
      wordFound = 0;
  }
  if(wordFound == 1)
  {
    direction = 1;
    xCoord = x + 1;
    yCoord = y + 1;
  }
}

void Word::searchU(int x, int y)
{
  wordFound = 1;
  for(int i = 1; i < length; i++)
  {
    if(word[i] != array[x - i][y])
      wordFound = 0;
  }
  if(wordFound == 1)
  {
    direction = 2;
    xCoord = x + 1;
    yCoord = y + 1;
  }
}

void Word::searchUR(int x, int y)
{
  wordFound = 1;
  for(int i = 1; i < length; i++)
  {
    if(word[i] != array[x - i][y + i])
      wordFound = 0;
  }
  if(wordFound == 1)
  {
    direction = 3;
    xCoord = x + 1;
    yCoord = y + 1;
  }
}

void Word::searchR(int x, int y)
{
  wordFound = 1;
  for(int i = 1; i < length; i++)
  {
    if(word[i] != array[x][y + i])
      wordFound = 0;
  }
  if(wordFound == 1)
  {
    direction = 4;
    xCoord = x + 1;
    yCoord = y + 1;
  }
}

void Word::searchDR(int x, int y)
{
  wordFound = 1;
  for(int i = 1; i < length; i++)
  {
    if(word[i] != array[x + i][y + i])
      wordFound = 0;
  }
  if(wordFound == 1)
  {
    direction = 5;
    xCoord = x + 1;
    yCoord = y + 1;
  }
}

void Word::searchD(int x, int y)
{
  wordFound = 1;
  for(int i = 1; i < length; i++)
  {
    if(word[i] != array[x + i][y])
      wordFound = 0;
  }
  if(wordFound == 1)
  {
    direction = 6;
    xCoord = x + 1;
    yCoord = y + 1;
  }
}

void Word::searchDL(int x, int y)
{
  wordFound = 1;
  for(int i = 1; i < length; i++)
  {
    if(word[i] != array[x + i][y - i])
      wordFound = 0;
  }
  if(wordFound == 1)
  {
    direction = 7;
    xCoord = x + 1;
    yCoord = y + 1;
  }
}

void Word::searchL(int x, int y)
{
  wordFound = 1;
  for(int i = 1; i < length; i++)
  {
    if(word[i] != array[x][y - i])
      wordFound = 0;
  }
  if(wordFound == 1)
  {
    direction = 8;
    xCoord = x + 1;
    yCoord = y + 1;
  }
}
