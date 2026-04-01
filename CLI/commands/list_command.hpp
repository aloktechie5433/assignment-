#pragma once
#include "../icommand.hpp"
#include "../TaskManager.h"

class ListCommand : public ICommand {
public:
    ListCommand(TaskManager &manager) : manager(manager) {}

    void setup(CLI::App &app) override {
        auto sub = app.add_subcommand("list", "List assignments");

        sub->callback([this]() {
            manager.listAssignments();
        });
    }

private:
    TaskManager &manager;
};