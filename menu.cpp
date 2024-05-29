/*
OLIVIA TRUSCOTT                         CS11
SPRING 2024                             PROFESSOR THURSTON

Project #6

Program Purpose
Complete the code for this menu which will allow the user to select a program to run. The programs are the program that have been assigned in this course.
In next week's project you will be inserting the code from those programs into this program which will be a portfolio of the work you complete in this course.
This program demonstrates various repetition coding structures: "for", "while", "do while", and the "break" and "continue" statements.
*/

#include <cstdlib>  // for rand function (random number generator)
#include <fstream>  // for file input and output
#include <iostream> // for cin and cout
#include <iomanip>  // for manipulators such as setw
#include <string>   // for using string data types
#include <ctime>    // for time() function

// include statements for outside functions, project structure all in folder called functions
#include "functions\tempConvertFernando.cpp"   // temperature converter function
#include "functions\displayTypePardina.cpp"    // display formats
#include "functions\calcScoreRomanvaldez.cpp"  // grade average
#include "functions\calculateAreaAlduenda.cpp" // room area
#include "functions\NumAverageDickson.cpp"     // average of two numbers
#include "functions\cableBillTruscott.cpp"     // cable bill function
#include "functions\RectangleShape.h"
#include "functions\RectangleShape.cpp"        // included due to using vscode

#include "windows.h"

using namespace std;

RectangleShape box; 

struct rectDim { 
  int length;
  int width;
};
rectDim input;

void placeCursor(HANDLE, int, int);   // Function prototypes
void displayPrompts(HANDLE);
void getUserInput(HANDLE, rectDim&);
void displayData (HANDLE, rectDim);

struct logEntry {
  int optionNum;      // menu option number 
  string optionName;  // menu option name
};

int main() {
  int choice = 0;  // Initialize user choice to force "while" loop to execute to get user's menu choice 
  int tempType;    // temp converter variables
  int inputTemp;
  int formatType;  // display type variables
  string fileName; // grade average variables
  int num1;        // room area variables
  int num2;
  int avgNum1;     // num average variables
  int avgNum2;
  ofstream log;    // define output file variable
  int choiceCounter = 0;

  logEntry menuChoices[10];

  // initialize menuChoices array
  menuChoices[0] = {1, "Temperature Converter"};
  menuChoices[1] = {2, "Display Formats"};
  menuChoices[2] = {3, "Grade Average"};
  menuChoices[3] = {4, "Room Area"};
  menuChoices[4] = {5, "Average of Two Values"};
  menuChoices[5] = {6, "Cable Bill"};
  menuChoices[6] = {7, "Rectangle Area"};
  menuChoices[9] = {99, "Exit"};

  do { // loops menu and selections
    char tempChar = ' '; // Goes here so char does not stay R in the menu and force exit

    system("color 02"); // system command to change terminal text color to green

    cout << "OLIVIA TRUSCOTT    CS 11 MENU      SPRING 2024" << endl
         << endl
         << endl;

    cout << setfill('=') << setw(74) << "=" << endl << endl; // Display the '=' character 75 times below the menu title

    // Display the list of programs assigned so far this semester
    cout << "1) Temperature Converter" << endl; // program 2-1
    cout << "2) Display Formats" << endl;       // program 2-2
    cout << "3) Grade Average" << endl;         // program 2-3
    cout << "4) Room Area" << endl;             // find errors 1
    cout << "5) Average of Two Values" << endl; // find errors 2
    cout << "6) Cable Bill" << endl;            // project 3
    cout << "7) Rectangle Area" << endl;
    cout << "99) Quit" << endl;
    cout << endl << endl;

    cout << "Enter a menu option --> "; // Prompt for menu choice to trigger switch
    cin >> choice;

    if (choiceCounter > 10) { // checks if choice counter has hit limit of 10
      cout << "You have reached the maximum number of selections." << endl;

      for (int i = 0; i < choiceCounter - 1; i++) { // display user options
        cout << menuChoices[i].optionNum << ", " << menuChoices[i].optionName << endl;
      }

      log.open("menuLog.txt"); // open log file

      if (log.is_open()) { // writes to log file, if open
        for (int i = 0; i < choiceCounter - 1; i++) { // writes user options to log file
          log << menuChoices[i].optionNum << ", " << menuChoices[i].optionName << endl;
        }
        log << "---> exit(1)" << endl; // logs exit with error
      } else { // error message if log file is not opened
        cout << "Log file failed to open" << endl;
      }

      exit(1); // exit program with error
    }

    switch (choice) { // displays menu selection
      case 1:
        cin.clear(); // gets rid of keyboard buffer
        system("cls"); // clears terminal (the menu)

        cout << "*************************************************" << endl;
        cout << "**                                             **" << endl;
        cout << "**            Temperature Converter            **" << endl;
        cout << "**                                             **" << endl;
        cout << "*************************************************" << endl
            << endl;

        // case specific input/output text
        cout << "Enter conversion type" << endl
            << "0 = Fahrenheit to Celsius" << endl
            << "1 = Celcius to Fahrenheit" << endl;
        cin >> tempType;
        
        cout << "Enter temperature" << endl;
        cin >> inputTemp;

        cout << tempConvert(inputTemp, tempType) << " degrees" << endl;

        while (tempChar != 'R') { // Force user to type "R" to return to menu
          cout << "Type [R] to return to menu --> " << endl;
          cin >> tempChar;
        }

        menuChoices[choiceCounter] = {1, "Temperature Converter"};
        choiceCounter++; // adds to choice counter

        system("cls");
        break; // end of case
            
      case 2:
        cin.clear();
        system("cls");

        cout << "*************************************************" << endl;
        cout << "**                                             **" << endl;
        cout << "**               Display Formats               **" << endl;
        cout << "**                                             **" << endl;
        cout << "*************************************************" << endl
            << endl;

        cout << "Enter format type" << endl
          << "0 for default" << endl
          << "1 for scientific" << endl
          << "2 for decimal" << endl;
        cin >> formatType;

        displayType(formatType);

        while (tempChar != 'R') {
          cout << "Type [R] to return to menu --> " << endl;
          cin >> tempChar;
        }

        menuChoices[choiceCounter] = {2, "Display Formats"};
        choiceCounter++;

        system("cls");
        break;

      case 3:
        cin.clear();
        system("cls");

        cout << "*************************************************" << endl;
        cout << "**                                             **" << endl;
        cout << "**                Grade Average                **" << endl;
        cout << "**                                             **" << endl;
        cout << "*************************************************" << endl
            << endl;

        cout << "Enter file name: " << endl;
        cin >> fileName;

        cout << calcScore(fileName) << endl;

        while (tempChar != 'R') {
          cout << "Type [R] to return to menu --> " << endl;
          cin >> tempChar;
        }

        menuChoices[choiceCounter] = {3, "Grade Average"};
        choiceCounter++;

        system("cls");
        break;

      case 4:
        cin.clear();
        system("cls");

        cout << "*************************************************" << endl;
        cout << "**                                             **" << endl;
        cout << "**                  Room Area                  **" << endl;
        cout << "**                                             **" << endl;
        cout << "*************************************************" << endl
            << endl;
        
        cout << "Enter length" << endl;
        cin >> num1;
        cout << "Enter width" << endl;
        cin >> num2;

        cout << "Room area is: " << calculateArea(num1, num2) << endl;

        while (tempChar != 'R') {
          cout << "Type [R] to return to menu --> " << endl;
          cin >> tempChar;
        }

        menuChoices[choiceCounter] = {4, "Room Area"};
        choiceCounter++;

        system("cls");
        break;

      case 5:
        cin.clear();
        system("cls");

        cout << "*************************************************" << endl;
        cout << "**                                             **" << endl;
        cout << "**             Average Two Values              **" << endl;
        cout << "**                                             **" << endl;
        cout << "*************************************************" << endl
            << endl;
        
        cout << "Input first number" << endl;
        cin >> avgNum1;
        cout << "Input second number" << endl;
        cin >> avgNum2;

        cout << "Average: " << NumAverage(avgNum1, avgNum2) << endl;

        while (tempChar != 'R') {
          cout << "Type [R] to return to menu --> " << endl;
          cin >> tempChar;
        }

        menuChoices[choiceCounter] = {5, "Average Two Values"};
        choiceCounter++;

        system("cls");
        break;

      case 6:
        cin.clear();
        system("cls");

        cout << "*************************************************" << endl;
        cout << "**                                             **" << endl;
        cout << "**                 Cable Bill                  **" << endl;
        cout << "**                                             **" << endl;
        cout << "*************************************************" << endl
            << endl;

        cableBill(); // void, no need for inputs in this file

        while (tempChar != 'R') {
          cout << "Type [R] to return to menu --> " << endl;
          cin >> tempChar;
        }

        menuChoices[choiceCounter] = {6, "Cable Bill"};
        choiceCounter++;

        system("cls");
        break;

      case 7: {
        cin.clear();
        system("cls");

        cout << "*************************************************" << endl;
        cout << "**                                             **" << endl;
        cout << "**             Area of a Rectangle             **" << endl;
        cout << "**                                             **" << endl;
        cout << "*************************************************" << endl
            << endl;

        // get the handle to standard output device (the console)
        HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);

	      displayPrompts(screen);
	      getUserInput(screen, input);
	      displayData (screen, input);

        // call member functions to set box dimensions
        // if the function call returns false, it means the argument sent to it was invalid and not stored
        if (!box.setLength(input.length)) {                  // store the length
          cout << "Invalid box length entered." << endl;
        } else if (!box.setWidth(input.width)) {             // store the width
          cout << "Invalid box width entered." << endl;
        } else {                                          // both values were valid
          // call member functions to get box information to display
          cout << "Here is the rectangle's data:" << endl;
          cout << "Length: " << box.getLength() << endl;
          cout << "Width: " << box.getWidth() << endl;
          cout << "Area: " << box.getArea() << endl;
        }

        while (tempChar != 'R') {
          cout << "Type [R] to return to menu --> " << endl;
          cin >> tempChar;
        }

        menuChoices[choiceCounter] = {7, "Area of a Rectangle"};
        choiceCounter++;

        system("cls");
        break; }

      default: // Error message for invalid case input
        cin.clear();
        system("cls");

        cout << "**************************************************" << endl;
        cout << "**                                              **" << endl;
        cout << "** Invalid input, please choose input from menu **" << endl;
        cout << "**                                              **" << endl;
        cout << "**************************************************" << endl
            << endl;

        while (tempChar != 'R') {
          cout << "Type [R] to return to menu --> " << endl;
          cin >> tempChar;
        }

        system("cls");
        break;

      case 99: // quit case
        for (int i = 0; i < choiceCounter; i++) {
          cout << menuChoices[i].optionNum << ", " << menuChoices[i].optionName << endl;
        }

        log.open("menuLog.txt"); // open log file

        if (log.is_open()) { // writes to log file, if open
          for (int i = 0; i < 10; i++) { // writes user options to log file
            log << menuChoices[i].optionNum << ", " << menuChoices[i].optionName << endl;
          }
        } else { // error message if log file is not opened
          cout << "Log file failed to open" << endl;
        }

        break;
    } // end switch
  } while (choice != 99); // end do...while loop
  
  return 0;
} // end of main

/******************************************************
 *                    placeCursor                     *
 ******************************************************/
void placeCursor(HANDLE screen, int row, int col)
{                       // COORD is a defined C++ structure that
  COORD position;       // holds a pair of X and Y coordinates
	position.Y = row;
	position.X = col;
  SetConsoleCursorPosition(screen, position);
}

/******************************************************
 *                   displayPrompts                   *
 ******************************************************/
void displayPrompts(HANDLE screen)
{
	placeCursor(screen, 13, 25);
	cout << "******* Data Entry Form *******" << endl;
	placeCursor(screen, 15, 25);
	cout << "Length: " << endl;
	placeCursor(screen, 17, 25);
	cout << "Width : " << endl;
}

/******************************************************
 *                    getUserInput                    *
 ******************************************************/
void getUserInput(HANDLE screen, rectDim &input)
{
	placeCursor(screen, 15, 33);
	cin >> input.length;
	placeCursor(screen, 17, 33);
	cin >> input.width;
}

/******************************************************
 *                     displayData                    *
 ******************************************************/
void displayData(HANDLE screen, rectDim input)
{
	placeCursor(screen, 20, 0);
	cout << "Here is the data you entered.\n";
	cout << "Length  : " << input.length   << endl;
	cout << "Width   : " << input.width    << endl;
}