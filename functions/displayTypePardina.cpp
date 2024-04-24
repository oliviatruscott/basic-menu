/*
Daniel Pardina                   CS11 "Intro to Computer Science-C++"
SPRING 2024                             PROFESSOR THURSTON

Project #3

Display values in Default, Scientific, or Fixed Decimal Formats -
Name this function displayType.
The function data type should be void and it should take an int parameter.
If the parameter value is 0 it will display the values in default format.
If the value is 1 it will display in scientific format, and
if the value is 2 it will display the values in fixed decimal format.
Collect the parameters in the case statement, call the function, and display the result.*/

#include <iostream>
using namespace std;

void displayType(int formatType) {


    //Declare and initialize variables
    double hours = 35.45;
    double rate = 15.00;
    double tolerance = 0.01000;

    switch (formatType)
    {
        case 0: // Default
            //Display variables in default format
            cout << defaultfloat;
            cout << "hours = " << hours << ", rate = " << rate << ", pay = " << hours * rate;
            cout << ", tolerance = " << tolerance << endl << endl;
        break;

        case 1: // Scientific
            //Display variables in scientific format
            cout << scientific;
            cout << "Scientific notation: " << endl;
            cout << "hours = " << hours << ", rate = " << rate << ", pay = " << hours * rate ;
            cout << ", tolerance = " << tolerance << endl << endl;
        break;

        case 2: // Decimal
            //Display variables in fixed decimal format
            cout << fixed;
            cout << "Fixed decimal notation: " << endl;
            cout << "hours = " << hours << ", rate = " << rate << ", pay = " << hours * rate ;
            cout << ", tolerance = " << tolerance << endl << endl;
        break;
    }

  cout << defaultfloat;

}
