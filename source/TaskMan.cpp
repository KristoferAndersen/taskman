#include "TaskMan.h"

/*
* Local header files
*/

/*
* System header files
*/

namespace taskman
{

/*
* Constructors & Destructor
*/

TaskMan::TaskMan() {}

/*
* Public members
*/
void TaskMan::start() {
    start(0);
}

void TaskMan::start(int task_type_id) {
    m_tasks.push_back(task_type_id);
}

int TaskMan::get_task_count() {
    return static_cast<int>(m_tasks.size());
}

std::vector<int> TaskMan::get_task_ids() {
    return m_tasks;
}

/*
* Protected members
*/

/*
* Private members
*/

}  // taskman
