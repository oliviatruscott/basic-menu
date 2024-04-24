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

using namespace std;

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

  // arrays for selection limit
  int optionNum[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
  string optionName[10] = { " ", " ", " ", " ", " ", " ", " ", " ", " ", " " };
  int choiceCounter = 0;

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
    cout << "99) Quit" << endl;
    cout << endl << endl;

    cout << "Enter a menu option --> "; // Prompt for menu choice to trigger switch
    cin >> choice;
    choiceCounter++; // adds to choice counter

    if (choiceCounter > 10) { // checks if choice counter has hit limit of 10
      cout << "You have reached the maximum number of selections." << endl;

      for (int i = 0; i < choiceCounter - 1; i++) { // display user options
        cout << optionNum[i] << ", " << optionName[i] << endl;
      }

      cout << "FIXME: create and log to a log file" << endl; // gradeAverage provides insite to this

      exit(1); // exit program
    }

    optionNum[choiceCounter - 1] = choice; // 

    switch (choice) { // displays menu selection
      case 1:
        cin.clear(); // gets rid of keyboard buffer
        //system("cls"); // clears terminal (the menu)
        optionName[choiceCounter - 1] = "Temperature Converter"; // assigns name for case

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

        //system("cls");
        break; // end of case
            
      case 2:
        cin.clear();
        //system("cls");
        optionName[choiceCounter - 1] = "Display Formats";

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

        //system("cls");
        break;

      case 3:
        cin.clear();
        //system("cls");
        optionName[choiceCounter - 1] = "Grade Avgerage";

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

        //system("cls");
        break;

      case 4:
        cin.clear();
        //system("cls");
        optionName[choiceCounter - 1] = "Room Area";

        cout << "*************************************************" << endl;
        cout << "**                                             **" << endl;
        cout << "**                  Room Area                  **" << endl;
        cout << "**                                             **" << endl;
        cout << "*************************************************" << endl
            << endl;
        
        cout << "Enter first number" << endl;
        cin >> num1;
        cout << "Enter second number" << endl;
        cin >> num2;

        cout << "Average is: " << NumAverage(num1, num2) << endl;

        while (tempChar != 'R') {
          cout << "Type [R] to return to menu --> " << endl;
          cin >> tempChar;
        }

        //system("cls");
        break;

      case 5:
        cin.clear();
        //system("cls");
        optionName[choiceCounter - 1] = "Average of Two Values";

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

        //system("cls");
        break;

      case 6:
        cin.clear();
        //system("cls");
        optionName[choiceCounter - 1] = "Cable Bill";

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

        //system("cls");
        break;

      default: // Error message for invalid case input
        cin.clear();
        //system("cls");
        optionName[choiceCounter - 1] = "Invalid";

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

        //system("cls");
        break;

      case 99: // quit case
        optionName[choiceCounter - 1] = "Exit";

        for (int i = 0; i <choiceCounter; i++) {
          cout << optionNum[i] << ", " << optionName[i] << endl;
        }

        cout << "FIXME: log user options to log file" << endl;

        break;
    } // end switch
  } while (choice != 99); // end do...while loop
  
  return 0;
}
