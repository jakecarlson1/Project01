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
void output(Word**, int);

int main(int argc, char* argv[])
{

  // for(int i = 1; i < argc; i++)
  // {
    int p = -1;
    Word** words;

    GameBoard board;
    cout << "Input.\n";
    input(board, words, p, argv[1]); //1 should be i
    cout << "Print board.\n";
    board.printBoard();
    output(words, p);

    // board.~GameBoard();
  // }

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
      cout << buffer << endl;
      //saves p when it is found, if it hasn't been found the line is saved
      if(buffer[0] >= '0' && buffer[0] <= '9')
      {
        p = *buffer - 48;
        break;
      }
      else
        board.addLine(buffer);
    }
    cout << "p: " << p << endl;
    board.printBoard();
    //creates p-many Word object pointers
    words = new Word*[p];
    //saves the word and runs the search function
    for(int i = 0; i < p; i++)
    {
      fin.getline(buffer, 1001);
      words[i] = new Word(buffer);
      words[i]->searchBoard(board); //there is a problem here
    }
  }

  fin.close();
}

void output(Word** words, int p)
{
  cout << "output: " << p << endl;
  for(int i = 0; i < p; i++)
    words[i]->printInfo();
  cout << endl;
}
