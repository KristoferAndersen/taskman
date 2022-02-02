#ifndef _taskman_TaskFactory_h_
#define _taskman_TaskFactory_h_

/*
* Local header files
*/
#include <ITask.h>

/*
* System header files
*/
#include <memory>

/*
* Forward declarations
*/

namespace taskman
{

class TaskFactory
{
public:
   TaskFactory();
   virtual std::shared_ptr<ITask> create_task(int task_type_id, int task_id);

   enum TaskTypes {
      HelloTask
   } m_tasks;
};

} //taskman

#endif //_taskman_TaskFactory_h_
