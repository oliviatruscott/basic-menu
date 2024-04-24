/*
ADAN ROMANVALDEZ                            CS11-73734
SPRING 2024                             PROFESSOR THURSTON

Project #2-3

Program Purpose
See comment below by original author
*/

//************************************************************
// Original Author: D.S. Malik
// Edited: Karen Thurston
// Program to calculate the average test score.
// Given a student's name and five test scores, this program
// calculates the average test score. The student's name, the
// five test scores, and the average test score is stored in
// the file testavg.txt. The data is input from the file
// testscores.txt.
//************************************************************.

#include <iostream>  // for using cout to display on the console
#include <fstream>   // for using input and output file streams
#include <iomanip>   // for formatting file output
#include <string>    // for string variables

using namespace std; // for using cout

double calcScore (string fileName)
{
//INSTRUCTIONS: Reorder the lines of code below the corresponding comments
    //Declare variables
  string firstName;
  string lastName;
  double average;
  double test1, test2, test3, test4, test5;
  ifstream inFile; //input file stream variable
  ofstream outFile; //output file stream variable

  //Open input file
  inFile.open(fileName);

  //Open output file
  outFile.open("testAvg.txt");

  //Print message "Processing Data"
  cout << "Processing data" << endl;

  //Read first and last name from testScores.txt
  inFile >> firstName >> lastName;

  //Write first and last name to testAvg.txt
  outFile << "Student name: " << firstName << " " << lastName << endl;

  //Read five test scores from testScores.txt
  inFile >> test1 >> test2 >> test3 >> test4 >> test5;

  //Write five test scores to testAvg.txt
  outFile << "Test scores: " << setw(6) << test1 << setw(6) << test2 << setw(6) << test3;
  outFile << setw(6) << test4 << setw(6) << test5 << endl;

  //Calculate average of test scores
  average = (test1 + test2 + test3 + test4 + test5) / 5.0;

  //Write average to testAvg.txt
  outFile << fixed << showpoint;
  outFile << setprecision(2);
  outFile << "Average test score: " << setw(6) << average << endl;

    inFile.close();
    outFile.close();

  return average;
}
