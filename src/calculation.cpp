#include <cctype>
#include "../include/calculation.h"

#include <iostream>
#include <ostream>

double gradeToPoint(const string& letterGrade) {

    string grade = letterGrade;

    for (char& c : grade) {
        c = toupper(c);
    }

    if (grade == "AA") { return 4.0; }
    else if (grade == "BA") { return 3.50; }
    else if (grade == "BB") { return 3.00; }
    else if (grade == "CB") { return 2.50; }
    else if (grade == "CC") { return 2.00; }
    else if (grade == "DC") { return 1.50; }
    else if (grade == "DD") { return 1.00; }
    else if (grade == "FD") { return 0.50; }
    else if (grade == "DD" || grade == "NA") { return 0.00; }
    else { return -1; }
}

double calculateGPA(const vector<Course>& courses) {

    if (courses.empty()) { return 0.0; }

    double totalWeightedPoints = 0.0;
    int totalCredits = 0;
    int invalidCourses = 0;

    for (const auto& course : courses) {
        // Validation check
        if (validateCourse(course)) {

            double points = gradeToPoint(course.courseGrade);
            totalWeightedPoints += (points * course.courseCredit);
            totalCredits += course.courseCredit;

        } else {
            invalidCourses++;
        }

    }

    if (totalCredits == 0) { return 0.0; }

    if (invalidCourses > 0) {
        cout << "Note: Skipped " << invalidCourses << " invalid course(s)." << endl;
    }

    return totalWeightedPoints / totalCredits;
}

bool isValidGrade(const string &grade) {

   return (gradeToPoint(grade) != -1);
}

bool isValidCredits(int credits) {

    if (credits >= 1 && credits <= 10)
        return true;
    return false;
}

bool validateCourse(const Course &course) {

    // Course not empy
    if (course.courseName.empty())
        return false;

    // Valid credits
    if (!isValidCredits(course.courseCredit))
        return false;

    // Valid grade
    if (!isValidGrade(course.courseGrade))
        return false;

    return true;
}
