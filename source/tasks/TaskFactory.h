#ifndef _taskman_TaskFactory_h_
#define _taskman_TaskFactory_h_

/*
* Local header files
*/
#include <ITask.h>

/*
* System header files
*/
#include <vector>
#include <memory>
#include <map>
#include <string>

/*
* Forward declarations
*/

namespace taskman
{

class TaskFactory
{
public:
    TaskFactory();
    virtual std::shared_ptr<ITask> create_task(int task_type_id);
    std::map<int, std::string> available_tasks();  // Return a vector of task_type_id-task_name pairs

    enum TaskTypes{
        HelloTask
    } m_task_types;


    // TODO: Consider renaming
    std::map<int, std::string> m_named_tasks;
};

} //taskman

#endif //_taskman_TaskFactory_h_
