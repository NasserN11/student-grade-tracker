#ifndef STUDENTGRADETRACKER_CALCULATION_H
#define STUDENTGRADETRACKER_CALCULATION_H

#include <string>
#include <vector>

using namespace std;

struct Course {
    string courseName;
    string courseGrade;
    int courseCredit;


};

double gradeToPoint(const string& letterGrade);

double calculateGPA(const vector<Course>& courses);


#endif //STUDENTGRADETRACKER_CALCULATION_H
