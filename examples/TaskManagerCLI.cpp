#include "TaskMan.h"
#include "ArbritraryTask.h"

#include <iostream>
#include <memory>

int main() {
    taskman::TaskMan man;
    man.start(0);
    man.start(0);
    man.start(0);

    taskman::ITask* my_task = new examples::ArbritraryTask(99, "My task");
    man.start(std::shared_ptr<taskman::ITask>{my_task});

    std::cout << "Running tasks:" << std::endl;
    
    for(int id: man.get_task_ids()) {
        std::cout << *man.get_task(id) << std::endl;
    }

    return 0;
}