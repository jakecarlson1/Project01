#include "word.h"


/*
  Word default constructor with initialization of variables
*/
Word::Word()
  length(25), xCoord(0), yCoord(0), direction(0)
{
  word = 0;
}

/*
  Word constructor that takes some char pointer from some buffer and stores it
  to a new character array
*/
Word::Word(char* w)
{
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
