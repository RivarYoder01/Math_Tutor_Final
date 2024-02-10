//*************************************************************************************
// Inlcudes
//*************************************************************************************

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include "mathTutor.h"

using namespace std;

/**************************************************************************************
Program--------;Simple Math Tutor
Programmer-----:Alyssa Yoder
Date-----------:December 9th 2022
Repl.it--------:https://replit.com/@Alyode01/Alyssa-Yoder-Math-Tutor#main.cpp
*************************************************************************************
Description----:This program will display a welcome message and then ask for the
---------------:users name. It will then generate 2 numbers to be
---------------:added,subtracted, multiplied, or divided. If the first number is
---------------:larger than the second number, the two numbers will be swapped
---------------:in order to avoid negative numbers. If a divisor is generated
---------------:the first number is multiplied by the second number to avoidss
---------------:decimals. The user gets 3 tries toget a question right will be
---------------:given the percentage they get right. All this in contained in a
---------------:while loop, the user will receive a report at the end showing
---------------:what they got right and wrong.
***************************************************************************************/

//*************************************************************************************
// Main Function that calls functions to display header, get username, and
// generate randome time seed. A while loop keeps a switch displaying  amenue
// for the user to choose from.
//
// 1 is for addition, 2 is for subractions, 3 is for multiplication, 4 is for
// division, 5 is to display the summary report, 6 saves the game, 7 loads the
// last game, 8 ends the game, and 9 resets the game.
//*************************************************************************************
int main() {
  int mathOp = 0;
  int choice = 0;
  string inputGarbage = ""; // used to clear input buffer
  vector<vector<int>> mathQuestions;

  srand(time(0));

  DisplayGameHeader();
  GetUserName();

  while ((choice = DisplayMenu())) {

	switch (choice) {
    case 1:
    case 2:
    case 3:
    case 4:
      mathOp = choice - 1;
      DisplayQuestion(mathOp, mathQuestions);
      break;
    case 5:
      DisplayStatusReport(mathQuestions);
      break;
    case 6:
      try {
        LoadPreviousGame(mathQuestions);
      } catch (runtime_error &excpt) {
        cout << endl;
        cout << excpt.what() << endl;
        cout << "Program did NOT end normally: Error -3" << endl;
        return -3;
      }
      break;
      break;
    case 7:
      try {
        SaveGame(mathQuestions);
      } catch (runtime_error &excpt) {
        cout << endl;
        cout << excpt.what() << endl;
        cout << "Program did NOT end normally: Error -4" << endl;
        return -3;
      }
      break;
      break;
    case 8:
      cout << "Goodbye!" << endl;
      return 0;
    case 9:
      mathQuestions.clear();
      cout << "Game Reset" << endl;
      break;
    default:
      cout << endl;
      cout << "Invalid Choice: " << choice << endl;
      cout << "Program ended with an -1 error code." << endl;
      cout << "Please contact Lys Yoder." << endl;
      return -1;
    }

    getline(cin, inputGarbage); // clear anything still in the input buffer
    cout << "Please the enter key to continue...";
    getline(cin, inputGarbage); // wait until the user presses the enter key
    cout << endl;
  }

  return 0;
}
// End of Main

