#pragma once
#include "../icommand.hpp"
#include "../TaskManager.h"
#include "../FileStorage.h"
#include "../Assignment.h"
#include <iostream>

class AddCommand : public ICommand {
public:
    AddCommand(TaskManager &manager, FileStorage &storage)
        : manager(manager), storage(storage) {}

    void setup(CLI::App &app) override {
        auto sub = app.add_subcommand("add", "Add assignment");

        sub->add_option("title", title)->required();
        sub->add_option("--subject", subject)->required();
        sub->add_option("--deadline", deadline)->required();

        sub->callback([this]() { execute(); });
    }

private:
    TaskManager &manager;
    FileStorage &storage;
    std::string title, subject, deadline;

    void execute() {
        manager.addAssignment(Assignment(rand(), title, subject, deadline));
        storage.saveAssignments(manager);
        std::cout << "Added\n";
    }
};