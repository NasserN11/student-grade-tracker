#include  <iostream>
#include <limits>
#include "../include/input.h"
#include "../include/calculation.h"

using namespace std;

void pressEnterToContinue() {

    cout << "Press enter to continue..." << endl;
    cin.sync();
    cin.get();
}

void printHeader(const string& title) {

    cout << "========================" << endl;
    cout << "|    " << title << "   |" << endl;
    cout << "========================" << endl;
}

void clearScreen() {

    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

string getCourseGrade() {

    string grade;

    while (true) {

        cout << "Enter a letter grade: ";
        getline(cin, grade);

        // Convert to uppercase
        for (char& c : grade) {
            c = toupper(c);
        }

        if (isValidGrade(grade)) {
            return grade;
        }
        else {
            cout << "Invalid grade. Please try again." << endl;
        }
    }
}

int getCourseCredits() {

    int credits;

    while (true) {
        cout << "Enter course credits (1-10): ";
        cin >> credits;

        if (cin.fail()) {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
        else if (isValidCredits(credits)) {
            cin.ignore(1000, '\n');
            return credits;
        }
        else {
            cout << "Credits must be between 1 and 10\n";
            cin.ignore(1000, '\n');
        }
    }
}
