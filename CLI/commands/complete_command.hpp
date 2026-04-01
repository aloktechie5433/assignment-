#pragma once
#include "../icommand.hpp"
#include "../TaskManager.h"
#include "../FileStorage.h"

class CompleteCommand : public ICommand {
public:
    CompleteCommand(TaskManager &manager, FileStorage &storage)
        : manager(manager), storage(storage) {}

    void setup(CLI::App &app) override {
        auto sub = app.add_subcommand("complete", "Complete assignment");

        sub->add_option("id", id)->required();

        sub->callback([this]() { execute(); });
    }

private:
    TaskManager &manager;
    FileStorage &storage;
    int id;

    void execute() {
        manager.markComplete(id);
        storage.saveAssignments(manager);
    }
};