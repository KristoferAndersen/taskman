#include "TaskMan.h"

/*
* Local header files
*/
#include "TaskController.h"

/*
* System header files
*/

namespace taskman {

/*
* Constructors & Destructor
*/

TaskMan::TaskMan()
    : m_task_controller(std::shared_ptr<TaskFactory>(new TaskFactory()), 10000) {
}

TaskMan::~TaskMan() {
    // Task controller claims ownership of the taskfactory
}

/*
* Public members
*/
int TaskMan::start() {
    return start(0);
}

int TaskMan::start(int task_type_id) {
    return m_task_controller.start(task_type_id);
}

std::shared_ptr<ITask> TaskMan::get_task(int task_id) {
    return m_task_controller.get_task(task_id);
}

std::vector<int> TaskMan::get_task_ids() {
    return m_task_controller.get_task_ids();
}

/*
* Protected members
*/

/*
* Private members
*/

}  // namespace taskman
