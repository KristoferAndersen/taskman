#ifndef _taskman_ThinkTask_h_
#define _taskman_ThinkTask_h_

/*
* Local header files
*/
#include <ITask.h>
#include <thread>
#include <chrono>

/*
* System header files
*/

/*
* Forward declarations
*/

namespace taskman
{

class ThinkTask : public ITask
{
 public:
    ThinkTask();
    ~ThinkTask();

    // Tasks like these can be inherited further to re-use the async approach
    void run();
    void do_work();
};

} //taskman

#endif //_taskman_ThinkTask_h_