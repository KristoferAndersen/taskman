#ifndef _taskman_TaskMan_h_
#define _taskman_TaskMan_h_

/*
* Local header files
*/

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
    int start();
    int start(int task_type_id);

    std::vector<int> get_task_ids();

private:

    std::vector<int> m_tasks;


};

} //taskman

#endif //_taskman_TaskMan_h_
