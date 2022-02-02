#include "TaskFactory.h"

/*
* Local header files
*/
#include <ITask.h>
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
}

/*
* Public members
*/
std::shared_ptr<ITask> TaskFactory::create_task(int task_type_id, int task_id) {
    ITask* t;

    switch(task_type_id) {
        case TaskTypes::HelloTask:
            t = new taskman::HelloTask(task_id, "Hello task");
            break;
    }

    return std::shared_ptr<ITask>(t);
}

/*
* Protected members
*/

/*
* Private members
*/

} //taskman
