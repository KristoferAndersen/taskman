#ifndef _examples_ArbritraryTask_h_
#define _examples_ArbritraryTask_h_

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

namespace examples
{

class ArbritraryTask : public taskman::ITask
{
public:
    ArbritraryTask() : taskman::ITask("Some other task") {};

    void run() {
        m_thread = std::thread(&ITask::do_work, this);
    }

    void do_work() {
        // The task completes instantly.
        // It just demonstrates that you can define
        //  your own tasks.
        std::cout << "Arbritrary work!" << std::endl;
        done();
    }
};

} //examples

#endif //_examples_ArbritraryTask_h_