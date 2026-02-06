#ifndef STUDENTGRADETRACKER_CALCULATION_H
#define STUDENTGRADETRACKER_CALCULATION_H

#include <string>

using namespace std;

struct Course {
    string course_name;
    string course_grade;
    int course_credit;


};

double gradeToPoint(const string& letterGrade);


#endif //STUDENTGRADETRACKER_CALCULATION_H
