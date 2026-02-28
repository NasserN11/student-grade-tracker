#include <string>
#include <fstream>
#include "../include/storage.h"

using namespace std;

string getDefaultFileName() {
    return "courses.csv";
}

bool saveCourses(const vector<Course> &courses, const string& filename) {

    // Create output file stream
    ofstream file;
    file.open(filename);


    if (!file.is_open())
        return false;

    // Write each course
    for (const auto& course : courses) {
        file << course.courseName << ","
             << course.courseCredit << ","
             << course.courseGrade << "\n";
    }

    if (!file) {
        file.close();
        return false;
    }

    return true;
}
