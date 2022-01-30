#include <TaskMan.h>
#include <iostream>

int main() {
    taskman::TaskMan t;
    t.start(1);
    t.start(2);
    t.start(3);

    std::cout << "Running tasks:" << std::endl;
    
    for(auto task : t.get_task_ids()) {
        std::cout << task << std::endl;
    }

    return 0;
}