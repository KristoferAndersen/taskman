#include "TaskMan.h"
#include "ArbritraryTask.h"

#include <iostream>
#include <iomanip>
#include <memory>
#include <string.h>


class Format {
public:
    Format(std::string option, std::string comment) : s1(option), s2(comment) {}
    friend std::ostream& operator<<(std::ostream& out, const Format& h) {
        out << '\t' << std::setw(20) << std::left << h.s1 << '\t' << h.s2 << std::endl;
        return out;
    };

    std::string s1, s2;
};

void help() {
    std::cout << "Usage:" << std::endl
        << "Launch the application without arguments." << std::endl
        << "Once running, the following commands are accepted:" << std::endl << std::endl
        << Format("Command", "Description")
        << Format("help", "Display this message")
        << Format("list", "List built in task types")
        << Format("start", "Starts our own example task and prints its ID")
        << Format("start [task_type_id]", "Starts a task of a given type and prints its ID")
        << Format("pause [task_id]", "Pause a task")
        << Format("resume [task_id]", "Resume a paused task")
        << Format("stop [task_id]", "Stop a task")
        << Format("status", "Report the status of all tasks")
        << Format("status [task_id]", "Report the status of a single task")
        << Format("quit", "Stop all tasks and exit application")
        << std::endl;
}

struct Action {
    typedef taskman::TaskMan& M;
    typedef std::vector<int>& Arg;

    static void list(M m, Arg a) {
        std::cout << Format("task_type_id", "task_type");
        for(const auto& [id, type] : m.get_task_types()) {
            std::cout << Format(std::to_string(id), type);
        }
    }

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

        if(id != -1) {
            auto task = m.get_task(id);
            std::cout << "Started a '" << task->get_name() <<  "' with id " << id << std::endl;
        }
        else {
            std::cout << "Failed to start task. Type \"help\" to see accepted command formats" << std::endl;
        }
    }

    static void pause(M m, Arg a) {
        if(a.size() != 1) {
            std::cout << "Task ID expected. Type \"help\" to see accepted command formats" << std::endl;
            return;
        }

        bool success = m.pause(a[0]);
        if(success) std::cout << "Paused task " << a[0] << std::endl;
        else std::cout << "Failed to pause task " << a[0] << std::endl;
    }

    static void resume(M m, Arg a) {
        if(a.size() != 1) {
            std::cout << "Task ID expected. Type \"help\" to see accepted command formats" << std::endl;
            return;
        }

        bool success = m.resume(a[0]);
        if(success) std::cout << "Resumed task " << a[0] << std::endl;
        else std::cout << "Failed to resume task " << a[0] << std::endl;
    }

    static void stop(M m, Arg a) {
        if(a.size() != 1) {
            std::cout << "Task ID expected. Type \"help\" to see accepted command formats" << std::endl;
            return;
        }

        bool success = m.stop(a[0]);
        if(success) std::cout << "Stopped task " << a[0] << std::endl;
        else std::cout << "Failed to stop task " << a[0] << std::endl;
    }

    static void status(M m, Arg a) {
        std::vector<int> task_ids;

        if(a.size() == 1) {
            task_ids.push_back(a[0]);
        }
        else {
            task_ids = m.get_task_ids();
        }

        // Using a formatter would be nice,
        //  but I'll let this suffice.
        std::cout << std::setw(12) << "task_id"
                  << std::setw(32) << "Task name"
                  << std::setw(12) << "Task state"
                                   << "Progress" << std::endl;;

        for(int id : task_ids) {
            auto t = m.get_task(id);
            if(t == nullptr) {
                return;
            }
            
            std::cout << std::setw(12) << t->get_id()
                  << std::setw(32) << t->get_name()
                  << std::setw(12) << t->get_status_string()
                                   << t->get_progress() << "%" << std::endl;
        }
    }
};

void command_loop() {

    taskman::TaskMan man;

    while(true) {
        std::string command;
        std::vector<int> args;
        int arg;

        std::cout << "Enter command:" << std::endl;
        std::cin >> command;

        // There's more input
        if(std::cin.peek() != '\n') {
            std::cin >> arg;
            args.push_back(arg);
        }

        // Clear any garbage input
        std::cin.clear();
        std::fflush(stdin);

        if(command == "help") {
            help();
        }
        else if(command == "list") {
            Action::list(man, args);
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
            std::cout << "Command not recognized. Type \"help\" to see accepted command formats" << std::endl;
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
