#include <cctype>
#include "../include/calculation.h"

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
    else if (grade == "DD") { return 0.00; }
    else if (grade == "NA") { return 0.00; }
    else { return -1; }
}