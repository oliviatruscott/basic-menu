/*
OLIVIA TRUSCOTT                         CS11 "Intro to Computer Science-C++"
SPRING 2024                             PROFESSOR THURSTON

Project #3

Program Purpose
Calculates customer's cable bill breakdown, accounting for different pricing and discounts
between two account types, residential and buissness.
*/

//***********************************************************
// Author: D. S. Malik
// Program: Cable Company Billing
// This program calculates and prints a customer�s bill for
// a local cable company. The program processes two types of
// customers: residential and business.
//***********************************************************

/*

*/

#include <iostream>
#include <iomanip>

using namespace std;

// Named constants residential customers
const double RES_BILL_PROC_FEES = 4.50;
const double RES_BASIC_SERV_COST = 20.50;
const double RES_COST_PREM_CHANNEL = 7.50;
const double RES_PREM_DISCOUNT = 0.10;

// Named constants business customers
const double BUS_BILL_PROC_FEES = 15.00;
const double BUS_BASIC_SERV_COST = 75.00;
const double BUS_BASIC_CONN_COST = 5.00;
const double BUS_COST_PREM_CHANNEL = 50.00;

void cableBill() {
     // used as a stop&check for bug fixes etc
     // cout << "GOT HERE" << endl;
     // getchar();

     // Variable declarations
     int accountNumber;
     char customerType;
     int numOfPremChannels;
     int numOfBasicServConn;
     double amountDue;
     // Add variable declaration for ZIP code
     int zipCode;
     // Add variable declaration for ZIP code 90808 premium residential channel discount
     double premiumDiscountAmount = 0;

     cout << fixed << showpoint;
     cout << setprecision(2);
     cout << "This program computes a cable bill." 
          << endl;

     cout << "Enter account number (an integer): ";
     cin >> accountNumber;
     cout << endl;

     cout << "Enter customer type: "
          << "R or r (Residential), "
          << "B or b (Business): ";
     cin >> customerType;
     cout << endl;

     switch (customerType) {
     //start of residential input/output structure  
          case 'r':
          case 'R':
               cout << "Enter the number of premium channels: ";
               cin >> numOfPremChannels;
               cout << endl;

               // Check for the number of premium channels and if zero, do not ask for zip code
               if (numOfPremChannels == 0) {
                    cout << "No ZIP code required.";
               } else if (numOfPremChannels > 0) {
                    // Ask for residential customer zip code (only if premium channels > 0)
                    cout << "Please enter ZIP code: ";
                    cin >> zipCode;
                    cout << endl;
                    // Calculate premium channel discount, if it applies
                    if (zipCode == 90808) {  // 10% discount
                         premiumDiscountAmount = RES_PREM_DISCOUNT 
                              * numOfPremChannels 
                              * RES_COST_PREM_CHANNEL;
                    }
               }

               amountDue = RES_BILL_PROC_FEES 
                    + RES_BASIC_SERV_COST 
                    + numOfPremChannels 
                    * RES_COST_PREM_CHANNEL 
                    - premiumDiscountAmount;

               cout << "Account#: "
                    << accountNumber
                    << endl;

               //set presision to show 2 after decimal for money format
               cout << fixed << showpoint;
               cout << setprecision(2);

               // Add detail lines for residential bill
               cout << setw(34) << setfill(' ') << left
                    << "Residential bill processing fees: "
                    << setw(7) << right
                    << "$" << RES_BILL_PROC_FEES
                    << endl;
               
               cout << setw(34) << left
                    << "Residential basic service cost:"
                    << setw(7) << right
                    << "$" << RES_BASIC_SERV_COST
                    << endl;

               cout << setw(34) << left
                    << "Residential premium channels:"
                    << setw(7) << right
                    << "$" << numOfPremChannels * RES_COST_PREM_CHANNEL
                    << endl;

               cout << setw(33) << left
                    << "ZIP code 90808 discount:"
                    << setw(8) << right
                    << "-$" << premiumDiscountAmount
                    << endl;

               cout << setw(34) << setfill('+') << left
                    << "TOTAL DUE: "
                    << setw(7) << right
                    << " $" << amountDue
                    << endl;
               break;

     //start of buisness input/output structure
          case 'b':
          case 'B':
               cout << "Enter the number of basic "
                    << "service connections: ";
               cin >> numOfBasicServConn;
               cout << endl;

               cout << "Enter the number"
                    << " of premium channels: ";
               cin >> numOfPremChannels;
               cout << endl;

               if (numOfBasicServConn <= 10) {
                    amountDue = BUS_BILL_PROC_FEES 
                         + BUS_BASIC_SERV_COST 
                         + numOfPremChannels 
                         * BUS_COST_PREM_CHANNEL;
               } else {
                    amountDue = BUS_BILL_PROC_FEES 
                         + BUS_BASIC_SERV_COST 
                         + (numOfBasicServConn - 10) 
                         * BUS_BASIC_CONN_COST 
                         + numOfPremChannels 
                         * BUS_COST_PREM_CHANNEL;
               }

               cout << "Account#: "
                    << accountNumber 
                    << endl;

               //set presision to show 2 after decimal for money format
               cout << fixed << showpoint;
               cout << setprecision(2);

               // Add detail lines for business bill
               cout << setw(34) << setfill(' ') << left
                    << "Buisness bill processing fee:"
                    << setw(8) << right
                    << "$" << BUS_BILL_PROC_FEES
                    << endl;

               cout << setw(34) << left
                    << "Buisness basic service cost:"
                    << setw(8) << right
                    << "$" << BUS_BASIC_SERV_COST * numOfBasicServConn //might have to change if discount is used
                    << endl;

               cout << setw(34) << left
                    << "Buisness premium channels:"
                    << setw(8) << right
                    << "$" << numOfPremChannels * BUS_COST_PREM_CHANNEL
                    << endl;

               cout << setw(34) << setfill('+') << left
                    << "TOTAL DUE: " 
                    << setw(8) << right
                    << " $" << amountDue
                    << endl;
               break;

          default:
               cout << "Invalid customer type." << endl;
     } // end switch
}

// int main() {
//      cableBill();
//      return 0;
// }
