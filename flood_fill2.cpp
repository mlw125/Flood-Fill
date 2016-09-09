// Created by Matthew Williams
// 10/31/14

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// function floodFill
// parameters: string array, positive int, positive int, char, char
// this function takes an array and recursively moves through it to change a specific character
// to a user-inputed one starting from a user specified position.
void floodFill( string [], int, int, char, char);

int main(int argc, char* argv[])
{
  // get the file that the program will read from
  ifstream myFile;
  myFile.open(argv[1]);
  string data = " ";

  // get the first line from the file
  myFile >> data;
  // set row to one since we got the first line
  int row = 1;
  // set col to the length of the string to get the number of columns
  int col = data.length();
  // this vector will hold all the lines from the file to be used to make the picture.
  vector<string> strStore;
  strStore.push_back( data );

  // loop until the end of the file has been reached. While looping
  // get the next line from the file and increment the number of rows
  // and finally push that data onto the vector.
  while( !myFile.eof() )
  {
    myFile >> data;
    row++;
    strStore.push_back(data);
  } // end while

  // create an array of strings to hold the picture with each string being one line from
  // the file. This array will function like a 2-dimensional since each character in the strings
  // can be accessed individually.
  string fakePic[row];
  // get the data from the vector and store it in the array.
  for( int r = 0; r < row; r++)
    fakePic[r] = strStore[r]; // end for 
  // close the file (not needed anymore)
  myFile.close();

  // this bool will be false until the user wants to end the program
  bool userEnd = false;

  // loop until the user wants to quit. Will ask user for row, col, and color
  // and change the picture appropriatly.
  while(userEnd == false)
  {
    // display the picture
    cout << endl;
    for(int r = 0; r < row; r++)
    {
      cout << fakePic[r];
      cout << endl;
    } // end for

    // these values will hold the row, col, and color respectively
    // that are gained from the user
    int userRow = 0;
    int userCol = 0;
    char userColor = ' ';
    
    // get the user's desired row
    cout << "\nEnter a row: ";
    cin >> userRow;

    // get the user's desired column
    cout << "Enter a col: ";
    cin >> userCol;

    // get the user's desired color
    cout << "Enter a color: ";
    cin >> userColor;

    // if the user enters a -1 for either row or column then program will end
    if( userRow == -1 || userCol == -1 )
      userEnd = true; // end if
    // if the value is negative ( but not -1 ) or is too large for the array
    // then tell the user and then loop again.
    else if( userRow < -1 || userRow >= row || userCol < -1 && userCol >= col )
    {
      cout << "Some value is too small/large, please try again." << endl;
    } // end else if
    // if the user's color is the same as the one they want to change
    // do nothing since user changed nothing and then start again.
    else if( userColor == fakePic[userRow][userCol])
    {
    } // end else if
    // if the user enters good data then find the color of the user selected position
    // and pass the array, user's positions, starting color, and replacement color to
    // floodFill.
    else
    {
      char targetColor = fakePic[userRow][userCol];
      floodFill( fakePic, userRow, userCol,  targetColor, userColor);
    } // end else
  } // end while

  cout << "\nHave a nice day.\n";
  return 0;
} // end main


void floodFill(string fakePic[], int row, int col, char tColor, char userColor)
{
  // base cases:
  // if the current position is the color we
  // are trying to change to then simply return.
  if( fakePic[row][col] == userColor )
    return; // end if
  // if the current position is not the color that we are targeting then simply return.
  if( fakePic[row][col] != tColor )
    return; // end if
  
  // change the target color to the desired color
  fakePic[row][col] = userColor;
  // recursively call the function to pass on the next positions from the current one
  // move one position to the left
  floodFill( fakePic, row, col-1, tColor, userColor );
  // move one position to the right
  floodFill( fakePic, row, col+1, tColor, userColor );
  // move one position up
  floodFill( fakePic, row-1, col, tColor, userColor );
  // move one position down
  floodFill( fakePic, row+1, col, tColor, userColor );
  // move one position to the left up diagonally
  floodFill( fakePic, row-1, col-1, tColor, userColor );
  // move one position to the left down diagonally 
  floodFill( fakePic, row+1, col-1, tColor, userColor );
  // move one position right up diagonally
  floodFill( fakePic, row-1, col+1, tColor, userColor );
  // move one position right down diagonally
  floodFill( fakePic, row+1, col+1, tColor, userColor );

  return;
} // end floodFill
