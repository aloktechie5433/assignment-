#ifndef FILESTORAGE_H
#define FILESTORAGE_H

#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include "Assignment.h"

using namespace std;

class TaskManager;

class FileStorage {
private:
    string file = "data/assignments.txt";

public:
    FileStorage() {
        system("mkdir data >nul 2>&1");
    }

    void saveAssignments(TaskManager& manager);
    void loadAssignments(TaskManager& manager);
};

#endif