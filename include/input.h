#ifndef STUDENTGRADETRACKER_INPUT_H
#define STUDENTGRADETRACKER_INPUT_H

#include <string>
#include <vector>
#include "../include/calculation.h"

using namespace std;

void pressEnterToContinue();

void printHeader(const string& title);

void clearScreen();

string getCourseGrade();

int getCourseCredits();

string getCourseName();

Course getCourseFromUser();

void displayCourses(const vector<Course>& courses);

void displayGPAReport(double gpa, const vector<Course>& courses);

int getMenuChoice();

void displayMenu();


#endif //STUDENTGRADETRACKER_INPUT_H