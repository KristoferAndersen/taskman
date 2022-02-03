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

struct Action {
    typedef taskman::TaskMan& M;
    typedef std::vector<int>& Arg;

    static void start(M m, Arg a) {
        int id;
        if(a.size() > 0) {
            id = m.start(a[0]);
        }
        else {
            // You can submit client defined tasks!
            id = m.start(
                std::shared_ptr<taskman::ITask>(
                    new examples::ArbritraryTask()
                )
            );
        }

        std::cout << "Started " << id << std::endl;
    }

    static void pause(M m, Arg a) {
        if(a.size() != 1) {
            std::cout << "Task ID expected. Type \"help\" to see accepted command formats" << std::endl;
            return;
        }

        bool success = m.pause(a[0]);
        if(success) std::cout << "Paused " << a[0] << std::endl;
        else std::cout << "Failed to pause " << a[0] << std::endl;
    }

    static void resume(M m, Arg a) {
        if(a.size() != 1) {  // TODO: Do this in a function
            std::cout << "Task ID expected. Type \"help\" to see accepted command formats" << std::endl;
            return;
        }

        bool success = m.resume(a[0]);
        if(success) std::cout << "Resumed " << a[0] << std::endl;
        else std::cout << "Failed to resume " << a[0] << std::endl;
    }

    static void stop(M m, Arg a) {
        if(a.size() != 1) {
            std::cout << "Task ID expected. Type \"help\" to see accepted command formats" << std::endl;
            return;
        }

        bool success = m.stop(a[0]);
        if(success) std::cout << "Stopped " << a[0] << std::endl;
        else std::cout << "Failed to stop " << a[0] << std::endl;
    }

    static void status(M m, Arg a) {
        std::vector<int> task_ids;

        if(a.size() == 1) {
            task_ids.push_back(a[0]);
        }
        else {
            task_ids = m.get_task_ids();
        }

        for(int id : task_ids) {
            auto t = m.get_task(id);
            std::cout << *t << std::endl;
        }
    }
};

void command_loop() {

    taskman::TaskMan man;

    while(true) {
        std::string command;
        std::vector<int> args;
        int arg;

        std::cin >> command;

        // There's more input
        if(std::cin.peek() != '\n') {
            std::cin >> arg;
            args.push_back(arg);
        }

        if(command == "help") {
            help();
        }
        else if(command == "start") {
            Action::start(man, args);
        }
        else if(command == "pause") {
            Action::pause(man, args);
        }
        else if(command == "resume") {
            Action::resume(man, args);
        }
        else if(command == "stop") {
            Action::stop(man, args);
        }
        else if(command == "status") {
            Action::status(man, args);
        }
        else if(command == "quit") {
            man.stop();
            break;
        }
        else {
            std::cout << "Command not recognized" << std::endl;
        }

        std::cout << std::endl;
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
