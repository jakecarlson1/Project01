/*
  Word Search Solver
  Created by: Jake Carlson
  Date: 2016-01-20

  This program takes one or more input files of a certain file format and then
  searches the array of characters at the top of the file for the words stored
  at the bottom of the file. The progrm then prints information about each word
  to an output file.
*/
#include <iostream>
#include <cstring>
#include <cctype>
#include <fstream>
#include "gameboard.h"
#include "word.h"

using namespace std;

void input(GameBoard&, Word**&, int&, char*);
void output(Word**, int, char*);

int main(int argc, char* argv[])
{
  //for-loop runs the same sequence for each input file from the command line
  for(int i = 1; i < argc; i++)
  {
    int p = -1;
    Word** words;
    GameBoard board;
    input(board, words, p, argv[i]);
    output(words, p, argv[i]);
  }

  return 0;
}

/*
  input reads from the specified input file and parses the information. The
  initial characters are read in and stored until the p-value is found. input
  saves the p-value and then creates p-many Word objects and reads into them
*/
void input(GameBoard& board, Word**& words, int& p, char* file)
{
  ifstream fin;
  char buffer[1001];

  fin.open(file);
  if(!fin.is_open())
    cout << "Could not open file: " << file << endl;
  else
  {
    //saves the lines of the input file while p has not been found
    while(fin.getline(buffer, 1001) && p == -1)
    {
      //saves p when it is found, if it hasn't been found the line is saved
      if(buffer[0] >= '0' && buffer[0] <= '9')
      {
        p = atoi(buffer);
        break;
      }
      else
        board.addLine(buffer);
    }
    //creates p-many Word object pointers
    words = new Word*[p];
    //saves the word and runs the search function
    for(int i = 0; i < p; i++)
    {
      fin.getline(buffer, 1001);
      words[i] = new Word(buffer);
      words[i]->searchBoard(board);
    }
  }

  fin.close();
}

/*
  output changes the end of the input file from .in to .out. It then has all
  of the words print their info into the file and then closes the file. output
  deallocates the memory used for the word objects and the output file name.
*/
void output(Word** words, int p, char* file)
{
  //file name generation
  char* plog = new char[strlen(file) + 2];
  strcpy(plog, file);
  plog[strlen(file) - 2] = 'o';
  plog[strlen(file) - 1] = 'u';
  plog[strlen(file)] = 't';

  ofstream fout;

  //saving the word info to the output file
  fout.open(plog);
  for(int i = 0; i < p; i++)
    words[i]->printInfo(fout);
  fout << endl;
  fout.close();

  //memory deallocation
  for(int i = 0; i < p; i++)
    delete words[i];
  delete plog;
}
