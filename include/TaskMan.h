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
#include <memory>
#include <string>

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

    int start(int task_type_id);
    int start(std::shared_ptr<ITask> task);
    bool pause(int task_id);
    bool resume(int task_id);
    bool stop();
    bool stop(int task_id);

    std::shared_ptr<ITask> get_task(int task_id);
    std::vector<int> get_task_ids();
    std::map<int, std::string> get_task_types();

private:
    TaskController m_task_controller;
};

} //taskman

#endif //_taskman_TaskMan_h_
