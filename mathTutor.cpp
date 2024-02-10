
//*************************************************************************************
// Inlcudes
//*************************************************************************************

#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using namespace std; // so we don't have to type std::cin etc

/**************************************************************************************
Program--------;Simple Math Tutor
Programmer-----:Alyssa Yoder
Date-----------:December 9th 2022
Repl.it--------:https://replit.com/@Alyode01/Alyssa-Yoder-Math-Tutor#main.cpp
*************************************************************************************
Description----:All fuctions called by main
***************************************************************************************/

const int MAX_ATTEMPTS = 3;
const vector<char> MATH_OPERATORS = {'+', '-', '*', '/'};
const string FILE_NAME = "MathTutor.txt";
enum MathType { ADD, SUB, MULT, DIV };

//*************************************************************************************
// Function will display game header
//*************************************************************************************
void DisplayGameHeader() {
  cout << "---------------------------" << endl;
  cout << "         Math Tutor        " << endl;
  cout << "---------------------------" << endl;
  cout << endl;
  return;
}
// End of DisplayGameHeader

//*************************************************************************************
// Program will ask user for their name, then display a greeting message
//*************************************************************************************
void GetUserName() {
  string userName = "?";
  cout << "Please enter your first name." << ' ';
  // user inputs their first name
  getline(cin, userName); // getline is used to account for spaces

  cout << "Hello, " << userName << "! :3" << endl;
  cout << "You get three attempts for each question!" << endl;
  cout << endl;
  cout << endl;

  return;
}
// End of GetUserName

//*************************************************************************************
// Function to ensure any input from the user is numeric
//*************************************************************************************
int GetNumericValue() {
  int userInput = 0;
  // loops until a number is entered

  while (!(cin >> userInput)) {
    cin.clear(); // Clear error flag
    cin.ignore(
        numeric_limits<streamsize>::max()); // ignore max input up to '/n'
    cout << "Invalid. Please input a number." << endl;
    cout << endl;
  } // end of numeric value check\

  return userInput;
}
// End of GetNumericValue

//*************************************************************************************
// Function will display menue for user to choose options from. then take the
// user's input and run GetNumericValue to ensure that it is a number
//
// That entered number will be returned to main
//*************************************************************************************
int DisplayMenu() {
  int choice = 0;
  cout << "------- Math Types -------" << endl;

  cout << "    1 = (+) Addition" << endl;
  cout << "    2 = (-) Subtraction" << endl;
  cout << "    3 = (*) Multiply" << endl;
  cout << "    4 = (/) Divide" << endl;
  cout << "---------------------------" << endl;
  cout << "    5 = Status Report" << endl;
  cout << "    6 = Save Current Game" << endl;
  cout << "    7 = Load Previous Game" << endl;
  cout << "---------------------------" << endl;
  cout << "    8 = Quit" << endl;
  cout << "    9 = Reset" << endl;
  cout << "---------------------------" << endl;
  cout << endl;

  cout << "What kind of math problem do you want?" << endl;

  while (true) { // ensures the imput is a number and within range
    choice = GetNumericValue();
    if (choice >= 1 && choice <= 9)
      break;

    cout << "Out of range! Please try again..." << endl;
    cout << endl;
    break;
  }
  return choice;
}
// End of DisplayMenue

//*************************************************************************************
// Left and right numbers will be generated. They will be swapped around if left
// is bigger then right or left will be multiplied by right to avoid negative
// numbers and decimals.
//
// these numbers will be stored in a vector and passed to GetCorrectAwnser
//*************************************************************************************
vector<int> CreateQuestion(int mathOp) {

  int leftNum = rand() % 10 + 1; // number that is on the left side of displayOp
  int temp = 0;
  int rightNum = rand() % 10 + 1; // number on th eright side of displayOp

  if (leftNum < rightNum) { // prevents negative results
    temp = leftNum;
    leftNum = rightNum;
    rightNum = temp;
  }
  if (mathOp == DIV) { // prevents decimal results
    leftNum *= rightNum;
  }

  return {leftNum, mathOp, rightNum}; // returns numbers into vector
}
// End of CreateQuestion

//*************************************************************************************
// leftNum, mathOp, and rightNum will be taken though a switch statement to find
// the correct awnser to the generated equasion
//
// correctAwns will be returned to DisplayQuestion
//*************************************************************************************
int GetCorrectAwnser(const vector<int> row) {
  int correctAwns = 0;

  // all numbers are pulled from vector for use
  int leftNum = row.at(0);
  int mathOp = row.at(1);
  int rightNum = row.at(2);

  switch (mathOp) {
  case ADD:
    correctAwns = leftNum + rightNum;
    break;
  case SUB:
    correctAwns = leftNum - rightNum;
    break;
  case MULT:
    correctAwns = leftNum * rightNum;
    break;
  case DIV:
    correctAwns = leftNum / rightNum;
    break;
  default:
    cout << "Invalid question type" << endl;
    cout << "Program ended with an error -1" << endl;
    cout << "Please report this error to Alyssa Yoder :/ " << endl;
    return -1;
  }
  return correctAwns;
}
// End of GetCorrectAwnser

//*************************************************************************************
// The vector will be taken and the question will be displayed. the user will
// input their awnser and thier input will be checked for numeric entry aswell
// as compared to correctawns. A for loop is used to give the user 3 tries.
//*************************************************************************************
void DisplayQuestion(int mathOp, vector<vector<int>> &mathQuestions) {

  char displayOp = MATH_OPERATORS.at(mathOp);
  vector<int> row = CreateQuestion(mathOp);

  int leftNum = row.at(0);
  int rightNum = row.at(2);
  int correctAwns = GetCorrectAwnser(row);
  int userInput = 0;
  int attempts = mathQuestions.size() + 1;

  for (int i = 0; i <= MAX_ATTEMPTS; i++) {

    cout << leftNum << ' ' << displayOp << ' ' << rightNum << " = ";
    userInput =
        GetNumericValue(); // display math question and get input from user

    if (correctAwns == userInput) { // when the user gets the awnser correct
      cout << endl;
      cout << "Correct! :D" << endl;
      row.push_back(i + 1);
      break;
    } else { // when the user gets it wrong, only loops 3 times
      cout << endl;
      cout << "Incorrect. :(" << endl;
      cout << "You have " << MAX_ATTEMPTS - i << " tries left." << endl;
      // user is told how many tries they have left
    }
    if (i == MAX_ATTEMPTS) { // if the user fails
      cout << "The correct awnser is: " << correctAwns << endl;
      cout << endl;
      cout << endl;
      row.push_back(0);
    }
  } // end of for loop
  mathQuestions.push_back(row);
}
// End of DisplayQuestion

//*************************************************************************************
// Program will ask user for their name, then display a greeting message
//*************************************************************************************
void DisplayStatusReport(vector<vector<int>> &mathQuestions) {

  int leftNum = 0;
  int mathOp = 0;
  int rightNum = 0;
  int correctAwns = 0;
  int totalQuestions = 0;
  int attempts = 0;
  int totalCorrect = 0;

  char displayOp = '?';

  totalQuestions = mathQuestions.size();

  cout << endl;
  cout << "*--------------------------------------------*" << endl;
  cout << "           Math Tutor Detail Report           " << endl;
  cout << "*--------------------------------------------*" << endl;
  cout << "       Questions         Right or wrong       " << endl;
  cout << "----------------------------------------------" << endl;

  if (totalQuestions == 0) {
    // for if the user tries to display report without playing
    cout << "No data, please play game" << endl;
    cout << endl;
    return;
  } // end of if statement

  for (int i = 0; i <= mathQuestions.size(); i++) {

    // pulling information from 2D vector
    leftNum = mathQuestions.at(i).at(0);
    mathOp = mathQuestions.at(i).at(1);
    rightNum = mathQuestions.at(i).at(2);
    attempts = mathQuestions.at(i).at(3);

    correctAwns = GetCorrectAwnser(mathQuestions.at(i));

    displayOp = MATH_OPERATORS.at(mathOp);

    cout << "     " << setw(2) << leftNum << left << ' ' << displayOp << ' '
         << rightNum << " = " << setw(3) << left << correctAwns
         << "           ";

    if (attempts != 0) {
      cout << "Correct" << endl;
      totalCorrect++;
      cout << endl;
    } else {
      cout << "Incorrect" << endl;
      cout << endl;
    }

    // end of detail report
  } // end of for loop
  return;
}

// End of DisplayStatusReport

//*************************************************************************************
// Program will ask user for their name, then display a greeting message
//*************************************************************************************
void SaveGame(const vector<vector<int>> &mathQuestions) {

  ofstream outFS; // Output file stream handle
  outFS.open(FILE_NAME);

  if (!outFS.is_open()) {
    throw runtime_error("Could not open file " + FILE_NAME + " for writing");
  }

  for (int i = 0; i < FILE_NAME.size(); i++) {

    if ((mathQuestions.at(i).at(3)) == 0) {
      cout << "No Data, Please play Game." << endl;
    } else {
      outFS << mathQuestions.at(i).at(0) << " " << mathQuestions.at(i).at(1)
            << " " << mathQuestions.at(i).at(2) << " "
            << mathQuestions.at(i).at(3) << endl;
      cout << "Saving Game. Please Wait..." << endl;
    }

    // Done with file, so close it
    outFS.close();
  }
  cout << "Gave Saved! ^.^" << endl;
  return;
}

// End of SaveGame

//*************************************************************************************
// Program will ask user for their name, then display a greeting message
//*************************************************************************************
void LoadPreviousGame(vector<vector<int>> mathQuestions) {

  int leftNum = 0;
  int mathOp = 0;
  int rightNum = 0;
  int attempts = 0;

  ifstream inFS; // Input stream file handle
                 // make sure the vectors are empty before loading the file
  mathQuestions.clear();

  inFS.open(FILE_NAME);
  if (!inFS.is_open()) {
    cout << "No previous game :/" << endl;
  }
  while (inFS >> leftNum >> mathOp >> rightNum >> attempts) {
    mathQuestions.push_back({leftNum, mathOp, rightNum, attempts});
  }
  if (!inFS.eof()) {
    throw runtime_error("Something went wrong with reading the " + FILE_NAME +
                        " file.");
  }
  // Done with file, so close it
  inFS.close();
	cout << "Game Loaded ^.^";
	
	return;
	}

// End of LoadPrevious

//*************************************************************************************
// Program will ask user for their name, then display a greeting message
//*************************************************************************************
