#ifndef _taskman_HelloTask_h_
#define _taskman_HelloTask_h_

/*
* Local header files
*/
#include <ITask.h>

/*
* System header files
*/

/*
* Forward declarations
*/

namespace taskman
{

class HelloTask : public ITask
{
 public:
    HelloTask(int id, std::string name) : ITask(id, name) {};
    void start();
};

} //taskman

#endif //_taskman_HelloTask_h_