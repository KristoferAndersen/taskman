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
        << Helper("quit", "Shut down")
        << std::endl;
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

    // taskman::TaskMan man;
    // man.start(0);
    // man.start(0);
    // man.start(0);

    // taskman::ITask* my_task = new examples::ArbritraryTask();
    // man.start(std::shared_ptr<taskman::ITask>{my_task});


    // std::cout << "Built-in task types:" << std::endl;
    // for(const auto& [task_type_id, task_name] : man.get_task_types()) {
    //     std::cout << task_type_id << '\t' << task_name << std::endl;
    // }

    // std::cout << "Running tasks:" << std::endl;
    // for(int id: man.get_task_ids()) {

    //     // Demonstrate ITask's ostream feature
    //     std::cout << *man.get_task(id) << std::endl;
    // }

    return 0;
}
