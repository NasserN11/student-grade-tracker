#ifndef STUDENTGRADETRACKER_INPUT_H
#define STUDENTGRADETRACKER_INPUT_H

#include <string>

using namespace std;

void pressEnterToContinue();

void printHeader(const string& title);

void clearScreen();

string getCourseGrade();

int getCourseCredits();


#endif //STUDENTGRADETRACKER_INPUT_H