#include "TaskController.h"

/*
* Local header files
*/

/*
* System header files
*/
// TODO: Remove
#include <iostream>

namespace taskman
{

/*
* Constructors & Destructor
*/

TaskController::TaskController()
    : m_task_factory(nullptr), TASK_LIMIT(10000) {

    }

TaskController::TaskController(const std::shared_ptr<TaskFactory> &task_factory, int task_limit)
    : m_task_factory(task_factory), TASK_LIMIT(task_limit) {
}

TaskController::~TaskController() {
}

/*
* Public members
*/

int TaskController::start() {
    return start(0);
}

int TaskController::start(int task_type_id) {

    // TODO: ID generator
    int task_id = create_id();

    // Create and remember task
    std::shared_ptr<ITask> task = m_task_factory->create_task(task_type_id, task_id);

    return start(task);
}

int TaskController::start(std::shared_ptr<ITask> task) {
    int task_id = task->get_id();
    m_task_ids.push_back(task_id);
    m_tasks[task_id] = task;

    task->start();

    // Return ID of new task
    return task_id;
}

std::shared_ptr<ITask> TaskController::get_task(int task_id) {
    return m_tasks[task_id]; // TODO: Bad key check
}

std::vector<int> TaskController::get_task_ids() {
    return m_task_ids;
}

/*
* Protected members
*/

/*
* Private members
*/
int TaskController::create_id() {
    // Initial functionality just increments from 0
    return m_task_ids.size() == 0 ? 0 : m_task_ids[m_task_ids.size()-1]+1;
}

} //taskman