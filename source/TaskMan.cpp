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

TaskMan::~TaskMan() {}

/*
* Public members
*/

int TaskMan::start(int task_type_id) {
    return m_task_controller.start(task_type_id);
}

int TaskMan::start(std::shared_ptr<ITask> task) {
    return m_task_controller.start(task);
}

bool TaskMan::pause(int task_id) {
    return m_task_controller.pause(task_id);
}

bool TaskMan::resume(int task_id) {
    return m_task_controller.resume(task_id);
}

bool TaskMan::stop() {
    bool success = true;

    for(int task_id : m_task_controller.get_task_ids()) {
        success &= stop(task_id);
    }

    return success;
}

bool TaskMan::stop(int task_id) {
    return m_task_controller.stop(task_id);
}

std::shared_ptr<ITask> TaskMan::get_task(int task_id) {
    return m_task_controller.get_task(task_id);
}

std::vector<int> TaskMan::get_task_ids() {
    return m_task_controller.get_task_ids();
}

std::map<int, std::string> TaskMan::get_task_types() {
    return m_task_controller.get_task_types();
}

/*
* Protected members
*/

/*
* Private members
*/

}  // namespace taskman
