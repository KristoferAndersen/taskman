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
    void start() { std::cout << "Something else!" << std::endl; }
};

} //examples

#endif //_examples_ArbritraryTask_h_