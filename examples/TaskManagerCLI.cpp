#include "TaskMan.h"
#include "ArbritraryTask.h"

#include <iostream>
#include <iomanip>
#include <memory>
#include <string.h>


class Helper {
public:
    Helper(std::string option, std::string comment) : s1(option), s2(comment) {}
    friend std::ostream& operator<<(std::ostream& out, const Helper& h) {
        out << '\t' << std::setw(20) << std::left << h.s1 << '\t' << h.s2 << std::endl;
        return out;
    };

    std::string s1, s2;
};

void help() {
    std::cout << "Usage:" << std::endl
        << "Launch the application without arguments." << std::endl
        << "Once running, the following commands are accepted:" << std::endl << std::endl
        << Helper("help", "Display this message")
        << Helper("start", "Starts a random task and print its ID")
        << Helper("start [task_type_id]", "Starts a task of a given type and prints its ID")
        << Helper("pause [task_id]", "Pause a task")
        << Helper("stop [task_id]", "Stop a task")
        << Helper("status", "Report the status of all tasks")
        << Helper("status [task_id]", "Report the status of a single task")
        << Helper("quit", "Stop all tasks and exit application")
        << std::endl;
}

void command_loop() {

    taskman::TaskMan man;

    while(true) {
        std::string command;
        int argument;
        bool argument_given = false;

        std::cin >> command;

        // There's more input
        if(std::cin.peek() != '\n') {
            std::cin >> argument;
            argument_given = true;
        }

        if(command == "help") {
            help();
        }
        else if(command == "start") {
            int id = argument_given ? man.start(argument) : man.start();
            std::cout << "Started " << id << std::endl;
        }
        else if(command == "pause") {
            bool success = man.pause(argument);
            if(success) std::cout << "paused " << argument << std::endl;
            else std::cout << "Failed to pause " << argument << std::endl;
        }
        else if(command == "stop") {
            bool success = man.stop(argument);
            if(success) std::cout << "Stopped " << argument << std::endl;
            else std::cout << "Failed to stop " << argument << std::endl;
        }
        else if(command == "status") {
            std::cout << "Status:" << std::endl;
            auto ids = man.get_task_ids();
            
            for(int id : ids) {
                auto t = man.get_task(id);
                std::cout << t << std::endl;
            }
        }
        else if(command == "quit") {
            man.stop();
            break;
        }
    }
}

int main(int argc, char **argv) {

    // Help is the only command, so any arg prompts help
    // TODO: Accept runtime commands as arguments
    if(argc > 1) {
        if(strcmp(argv[1], "--help")) {
            std::cout << "Unknown argument" << std::endl;
        }

        help();
    }

    command_loop();

    return 0;
}
