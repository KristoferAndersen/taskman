#ifndef _taskman_TaskController_h_
#define _taskman_TaskController_h_

/*
* Local header files
*/
#include "tasks/TaskFactory.h"
#include "ITask.h"

/*
* System header files
*/
#include <vector>
#include <map>
#include <memory>
#include <string>

/*
* Forward declarations
*/

namespace taskman
{

class TaskController
{
public:
    TaskController();
    TaskController(const std::shared_ptr<TaskFactory> &task_factory, int task_limit);
    ~TaskController();

    int start(int task_type_id);
    int start(std::shared_ptr<ITask> task);
    bool pause(int task_id);
    bool resume(int task_id);
    bool stop(int task_id);
    std::shared_ptr<ITask> get_task(int task_id);
    std::map<int, std::string> get_task_types();
    std::vector<int> get_task_ids();

private:
    int create_id();
    
    std::shared_ptr<TaskFactory> m_task_factory;
    const int TASK_LIMIT;
    std::vector<int> task_whitelist;
    std::vector<int> m_task_ids;
    std::map<int, std::shared_ptr<ITask>> m_tasks;
};

} //taskman

#endif //_taskman_TaskController_h_