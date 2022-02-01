#ifndef _taskman_TaskMan_h_
#define _taskman_TaskMan_h_

/*
* Local header files
*/
#include "ITask.h"
#include "TaskController.h"

/*
* System header files
*/
#include <vector>

/*
* Forward declarations
*/

namespace taskman
{

class TaskMan
{
public:
    TaskMan();
    ~TaskMan();

    int start();
    int start(int task_type_id);

    std::vector<int> get_task_ids();

private:
    std::vector<int> m_task_ids;
    TaskController m_task_controller;
};

} //taskman

#endif //_taskman_TaskMan_h_
