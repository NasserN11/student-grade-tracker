#include <string>
#include <fstream>
#include <vector>
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

bool loadCourses(vector<Course>& courses, const string &filename) {

    // Open file for reading
    ifstream file;
    file.open(filename);

    // Check if file exists
    if (!file.is_open())
        return false;

    // Clear existing courses
    courses.clear();

    // Read line by line
    string line;
    int coursesLoaded = 0;
    while (getline(file, line)) {

        if (line.empty())
            continue;

        size_t firstComma = line.find(',');
        if (firstComma == string::npos)
            continue;

        size_t secondComma = line.find(',', firstComma+1);
        if (secondComma == string::npos)
            continue;

        // Extract fields
        string name = line.substr(0, firstComma);
        string creditsStr = line.substr(firstComma+1, secondComma - firstComma - 1);
        string grade = line.substr(secondComma+1);

        // Convert credits into int
        int credits;
        try {
            credits = stoi(creditsStr);
        } catch (...) {
            continue;
        }

        // Create course
        Course course;
        course.courseName = name;
        course.courseCredit = credits;
        course.courseGrade = grade;

        // validate course
        if (validateCourse(course)) {
            courses.push_back(course);
            coursesLoaded++;
        }
        else
            continue;

        file.close();
        return (coursesLoaded > 0);
    }
}
