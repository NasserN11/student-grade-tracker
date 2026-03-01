#ifndef STUDENTGRADETRACKER_STORAGE_H
#define STUDENTGRADETRACKER_STORAGE_H

#include <string>
#include <vector>
#include "../include/calculation.h"

using namespace std;

string getDefaultFileName();

bool saveCourses(const vector<Course> &courses, const string& filename);

bool loadCourses(vector<Course>& course, const string& filename);


#endif //STUDENTGRADETRACKER_STORAGE_H