#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

#include "Task.h"

class Assignment : public Task {
private:
    string subject;
    string deadline;

public:
    Assignment(int i = 0, string t = "", string s = "", string d = "")
        : Task(i, t), subject(s), deadline(d) {}

    string getSubject() const { return subject; }
    string getDeadline() const { return deadline; }

    void display() const override {
        cout << "ID: " << id
             << "\nTitle: " << title
             << "\nSubject: " << subject
             << "\nDeadline: " << deadline
             << "\nStatus: " << (completed ? "Completed" : "Pending")
             << "\n----------------------\n";
    }

    // For file saving
    string toFileString() const {
        return to_string(id) + "|" + title + "|" + subject + "|" + deadline + "|" + (completed ? "1" : "0");
    }

    void setCompleted(bool val) {
        completed = val;
    }
};

#endif