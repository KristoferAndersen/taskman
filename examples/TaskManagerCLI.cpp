#include "TaskMan.h"
#include "ArbritraryTask.h"

#include <iostream>
#include <memory>

int main() {
    taskman::TaskMan man;
    man.start(0);
    man.start(0);
    man.start(0);

    taskman::ITask* my_task = new examples::ArbritraryTask();
    man.start(std::shared_ptr<taskman::ITask>{my_task});


    std::cout << "Built-in task types:" << std::endl;
    for(const auto& [task_type_id, task_name] : man.get_task_types()) {
        std::cout << task_type_id << '\t' << task_name << std::endl;
    }

    std::cout << "Running tasks:" << std::endl;
    for(int id: man.get_task_ids()) {

        // Demonstrate ITask's ostream feature
        std::cout << *man.get_task(id) << std::endl;
    }

    return 0;
}