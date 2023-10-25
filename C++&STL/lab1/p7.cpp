/*
Write a program that, for a given date, 
prints it with the name of the month (for example: October 5, 2023).
 Use a switch-case select statement with a local initializer for the month in the date.
*/

#include <iostream>
using namespace std;

int main() {
    int day, month, year;
    cin >> day >> month >> year;

    if (month < 1 || month > 12) {
        cout << "error." << endl;
        return 1;
    }
    string monthName;
    switch (month) {
        case 1:
            monthName = "January";
            break;
        case 2:
            monthName = "February";
            break;
        case 3:
            monthName = "March";
            break;
        case 4:
            monthName = "April";
            break;
        case 5:
            monthName = "May";
            break;
        case 6:
            monthName = "June";
            break;
        case 7:
            monthName = "July";
            break;
        case 8:
            monthName = "August";
            break;
        case 9:
            monthName = "September";
            break;
        case 10:
            monthName = "October";
            break;
        case 11:
            monthName = "November";
            break;
        case 12:
            monthName = "December";
            break;
    }
    cout << monthName << " " << day << " " << year << endl;
    
    return 0;
}
