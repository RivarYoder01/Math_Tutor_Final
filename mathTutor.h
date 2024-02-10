//*************************************************************************************
// Inlcudes
//*************************************************************************************

#include <vector>
using namespace std;

/**************************************************************************************
Program--------;Simple Math Tutor
Programmer-----:Alyssa Yoder
Date-----------:December 9th 2022
Repl.it--------:https://replit.com/@Alyode01/Alyssa-Yoder-Math-Tutor#main.cpp
*************************************************************************************
Description----: mathTutor.cpp prototypes go here
***************************************************************************************/

#ifndef MATHTUTOR_H
#define MATHTUTOR_H

void DisplayGameHeader();
void GetUserName();
int GetNumericValue();
int DisplayMenu();
vector<int> CreateQuestion(int mathOp);
void DisplayQuestion(int mathOp, vector<vector<int>> &mathQuestions);
int GetCorrectAwnser(const vector<int> row);
void DisplayStatusReport(vector<vector<int>> &mathQuestions);
void SaveGame(const vector<vector<int>> &mathQuestions);
void LoadPreviousGame(vector<vector<int>> mathQuestions);

#endif