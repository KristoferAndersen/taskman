#include <TaskMan.h>

/*
* Local header files
*/

/*
* System header files
*/

namespace taskman {

/*
* Constructors & Destructor
*/

TaskMan::TaskMan() {}

/*
* Public members
*/
int TaskMan::start() {
    return start(0);
}

int TaskMan::start(int task_type_id) {
    m_tasks.push_back(task_type_id);
    return m_tasks[m_tasks.size()-1];  // TODO: Improve
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

}  // namespace taskman
