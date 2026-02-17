#include <iostream>
#include <vector>
#include "../include/input.h"
#include "../include/calculation.h"

using namespace std;

int main() {

    vector<Course> courses;

    bool running = true;

    cout << string(50, '=') << endl;
    cout << "     STUDENT GRADE TRACKER v1.0" << endl;
    cout << "          (Single Student Mode)" << endl;
    cout << string(50, '=') << endl;

    // Main program
    while (running) {
        displayMenu();
        int choice = getMenuChoice();

        switch (choice) {

            case 1: {
                // Add a new course

                Course newCourse = getCourseFromUser();

                if (validateCourse(newCourse)) {
                    courses.push_back(newCourse);
                    cout << "Course added successfully" << endl;
                }
                else
                    cout << "\nCourse validation failed. Not added" << endl;

                pressEnterToContinue();
                break;
            }


            case 2: {
                // Calculate GPA
                if (courses.empty())
                    cout << "No courses available. Add some courses first" << endl;

                else {
                    double gpa = calculateGPA(courses);
                    cout << "Current GPA: " << gpa << endl;
                }

                pressEnterToContinue();
                break;
            }


            case 3: {
                // View all courses
                cout << endl;
                displayCourses(courses);
                pressEnterToContinue();
                break;
            }


            case 4: {
                // View GPA report
                if (courses.empty())
                    cout << "No courses available for report" << endl;

                else {
                    double gpa = calculateGPA(courses);
                    displayGPAReport(gpa, courses);
                }

                pressEnterToContinue();
                break;
            }


            case 5: {
                // Exit program
                cout << string(50, '=') << endl;

                if (!courses.empty()) {
                    double finalPGA = calculateGPA(courses);
                    cout << "Final GPA: " << finalPGA << endl;
                    cout << "Total courses: " << courses.size() << endl;
                }
                cout << endl;

                cout << "Exiting..." << endl;
                running = false;
                break;
            }


            default: {
                cout << "Invalid choice. Please try again." << endl;
                pressEnterToContinue();
                break;
            }

        }
    }

    return 0;
}