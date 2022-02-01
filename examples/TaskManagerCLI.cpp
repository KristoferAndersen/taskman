#include <TaskMan.h>
#include <iostream>

int main() {
    taskman::TaskMan man;
    man.start(1);
    man.start(2);
    man.start(3);

    std::cout << "Running tasks:" << std::endl;
    
    for(int id: man.get_task_ids()) {
        std::cout << id << std::endl;
    }

    return 0;
}