#include  <iostream>
#include <iomanip>
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
    cout << "     " << title << "    " << endl;
    cout << "========================" << endl;
    cout << endl;
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

string getCourseName() {

    string name;

    while (true) {
        cout << "Enter course name: ";
        getline(cin, name);

        size_t start = name.find_first_not_of("\t\n\r");
        size_t end = name.find_last_not_of("\t\n\r");

        if (start == string::npos) {
            cout << "Course name cannot be empty. Please try again." << endl;
            continue;
        }

        // Extract trimmed string
        name = name.substr(start, end - start + 1);

        return name;
    }
}

Course getCourseFromUser() {

    Course newCourse;

    printHeader("ADD NEW COURSE");

    newCourse.courseName = getCourseName();
    newCourse.courseGrade = getCourseGrade();
    newCourse.courseCredit = getCourseCredits();

    return newCourse;
}

void displayCourses(const vector<Course>& courses) {

    if (courses.empty()) {
        cout << "No courses found." << endl;
        return;
    }
    else {
        cout << left << setw(4) << "No"
             << left << setw(21) << "Course Name"
             << left << setw(8) << "Credits"
             << left << setw(6) << "Grade" << endl;

        cout << left << setw(4) << "---"
             << left << setw(21) << "--------------------"
             << left << setw(8) << "-------"
             << left << setw(6) << "-----" << endl;

        int size = courses.size();
        for (int i = 0; i < size; i++) {
            const Course& course = courses[i];

            cout << left << setw(4) << i + 1
             << left << setw(21) << course.courseName
             << left << setw(8) << course.courseCredit
             << left << setw(6) << course.courseGrade << endl;
        }

        cout << "\nTotal courses: " << size << endl;
    }
}

void displayGPAReport(double gpa, const vector<Course> &courses) {

    // Print header
    printHeader("GPA REPORT");

    // Show all courses
    displayCourses(courses);

    cout << "\n" << string(50, '=') << "\n";

    // Show GPA
    cout << "CURRENT GPA: " << fixed << setprecision(2) << gpa << endl;
    cout << endl;

    // Show performance message based on GPA

    cout << "Performance Analysis:" << endl;

    if (gpa >= 3.5 && gpa <= 4.0)
        cout << "Excellent! Dean's List candidate" << endl;

    else if (gpa >= 3.0 && gpa <= 3.49)
        cout << "Very Good! Above average" << endl;

    else if (gpa >= 2.5 && gpa <= 2.99)
        cout << "Good, but room for improvement" << endl;

    else if (gpa >= 2.0 && gpa <= 2.49)
        cout << "Satisfactory - keep working hard." << endl;

    else
        cout << "Needs improvement. Consider seeking acdemic support." << endl;

    cout << string(50, '=') << "\n";
}

int getMenuChoice() {

    int choice;

    while (true) {
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear();
            continue;
        }

        if (choice >= 1 && choice <= 5)
            return choice;

        else
            cout << "Please enter a number between 1 and 5." << endl;
    }
}

void displayMenu() {

    clearScreen();

    printHeader("MENU");

    cout << "1. Add New Course" << endl;
    cout << "2. Calculate Current GPA" << endl;
    cout << "3. View ALL Courses" << endl;
    cout << "4. View Complete GPA Report" << endl;
    cout << "5. Exit" << endl;

    cout << endl;
    cout << string(50, '=') << endl;
    cout << endl;
    cout << "Choose an option (1-5): ";
}
