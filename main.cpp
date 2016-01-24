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

void input(GameBoard&, int&, char*);

int main(int argc, char* argv[])
{

  for(int i = 1; i <= argc; i++)
  {
    int p = -1;

    GameBoard board;

    input(board, p, argv[i]);

    board.~GameBoard();
  }

  return 0;
}

/*
  input reads from the specified input file and parses the information. The
  initial characters are read in and stored until the p-value is found. input
  saves the p-value and then creates p-many Word objects and reads into them
*/
void input(GameBoard& board, int& p, char* file)
{
  ifstream fin;
  char buffer[1001];

  fin.open(file);
  if(!fin.is_open())
    cout << "Could not open file: " << file << endl;
  else
  {
    while(fin.getline(buffer, 1001) && p == -1)
      board.addLine(buffer);
  }

  //if the line is an integer, save it to p and begin storing words

  fin.close();
}
