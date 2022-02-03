#include "TaskFactory.h"

/*
* Local header files
*/
#include <tasks/ThinkTask.h>

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
    m_named_tasks[TaskTypes::ThinkTask] = "ThinkTask";
}

/*
* Public members
*/
std::shared_ptr<ITask> TaskFactory::create_task(int task_type_id) {
    ITask* t = nullptr;

    switch(task_type_id) {
        case TaskTypes::ThinkTask:
            t = new taskman::ThinkTask();
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
