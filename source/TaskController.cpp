#include "TaskController.h"

/*
* Local header files
*/

/*
* System header files
*/
#include <thread>
#include <chrono>

namespace taskman
{

/*
* Constructors & Destructor
*/

TaskController::TaskController()
    : TaskController(nullptr, 10000)
{
}

TaskController::TaskController(const std::shared_ptr<TaskFactory> &task_factory, int task_limit)
    : m_task_factory(task_factory), TASK_LIMIT(task_limit)
{

    // We're not using this
    // I'm leaving it as an example
    task_whitelist = {
        m_task_factory->ThinkTask
    };
}

TaskController::~TaskController() {
    const auto& task_ids = get_task_ids();

    for(int id : task_ids) {
        get_task(id)->stop();
    }
}

/*
* Public members
*/

int TaskController::start(int task_type_id) {

    // Create and remember task
    std::shared_ptr<ITask> task = m_task_factory->create_task(task_type_id);
    return start(task);
}

int TaskController::start(std::shared_ptr<ITask> task) {
    if(task == nullptr) { return -1; }

    int task_id = create_id();

    m_task_ids.push_back(task_id);
    m_tasks[task_id] = task;

    task->set_id(task_id);
    task->start();

    // Return ID of new task
    return task_id;
}

bool TaskController::pause(int task_id) {
    if(!task_exists(task_id)) { return false; }

    auto task = get_task(task_id);
    task->pause();

    return wait_for_status(task, TaskStates::Paused, 2000);
}

bool TaskController::resume(int task_id) {
    if(!task_exists(task_id)) { return false; }

    auto task = get_task(task_id);
    task->resume();

    return wait_for_status(task, TaskStates::Running, 2000);
}

bool TaskController::stop(int task_id) {
    if(!task_exists(task_id)) { return false; }

    auto task = get_task(task_id);
    task->stop();

    return wait_for_status(task, TaskStates::Stopped, 2000);
}

std::shared_ptr<ITask> TaskController::get_task(int task_id) {
    if(!task_exists(task_id)) { return nullptr; }

    return m_tasks[task_id];
}

std::vector<int> TaskController::get_task_ids() {
    return m_task_ids;
}

std::map<int, std::string> TaskController::get_task_types() {
    // We can add the whitelist here.
    return m_task_factory->m_named_tasks;
}

bool TaskController::task_exists(int task_id) {
    return m_tasks.count(task_id) > 0;
}
/*
* Protected members
*/

/*
* Private members
*/
int TaskController::create_id() {
    // Basic incrementing functionality
    return m_task_ids.size() == 0 ? 0 : m_task_ids[m_task_ids.size()-1]+1;
}

bool TaskController::wait_for_status(std::shared_ptr<ITask> task, int status, int timeout)
{
    int waited = 0;
    int wait_step = 50;
    while(waited < timeout) {
        if(task->get_status() == status) {
            return true;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(wait_step));  
        waited += wait_step;
    }

    return false;
}


} //taskman