#include "TaskFactory.h"

/*
* Local header files
*/
#include <tasks/HelloTask.h>

/*
* System header files
*/

namespace taskman
{

/*
* Constructors & Destructor
*/

TaskFactory::TaskFactory() {
    // Pair enum values with strings
    m_named_tasks[TaskTypes::HelloTask] = "HelloTask";
}

/*
* Public members
*/
std::shared_ptr<ITask> TaskFactory::create_task(int task_type_id) {
    ITask* t;

    switch(task_type_id) {
        case TaskTypes::HelloTask:
            t = new taskman::HelloTask();
            break;
    }

    return std::shared_ptr<ITask>(t);
}

std::map<int, std::string> TaskFactory::available_tasks() {
    return m_named_tasks;
}

/*
* Protected members
*/

/*
* Private members
*/

} //taskman
