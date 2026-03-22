#ifndef FILESTORAGE_H
#define FILESTORAGE_H

#include <fstream>
#include <sstream>
#include <cstdlib>
#include "TaskManager.h"

using namespace std;

class FileStorage {
private:
    string file = "data/assignments.txt";

public:
    FileStorage() {
        system("mkdir data >nul 2>&1");
    }

    void saveAssignments(TaskManager& manager) {
        ofstream out(file);
        for (auto& a : manager.assignments) {
            out << a.toFileString() << endl;
        }
        out.close();
    }

    void loadAssignments(TaskManager& manager) {
        ifstream in(file);
        string line;

        while (getline(in, line)) {
            stringstream ss(line);
            string id, title, subject, deadline, completed;

            getline(ss, id, '|');
            getline(ss, title, '|');
            getline(ss, subject, '|');
            getline(ss, deadline, '|');
            getline(ss, completed, '|');

            Assignment a(stoi(id), title, subject, deadline);
            if (completed == "1") a.setCompleted(true);

            manager.addAssignment(a);
        }
        in.close();
    }
};

#endif