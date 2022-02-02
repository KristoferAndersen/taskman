#include <TaskMan.h>
#include <iostream>

int main() {
    taskman::TaskMan man;
    man.start(0);
    man.start(0);
    man.start(0);

    std::cout << "Running tasks:" << std::endl;
    
    for(int id: man.get_task_ids()) {
        std::cout << *man.get_task(id) << std::endl;
    }

    return 0;
}