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
    void do_work() { std::cout << "Arbritrary tasks are also working!" << std::endl; }
};

} //examples

#endif //_examples_ArbritraryTask_h_