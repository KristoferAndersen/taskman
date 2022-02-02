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
    ArbritraryTask(int id, std::string name) : taskman::ITask(id, name) {};
    void start() { std::cout << "Something else!" << std::endl; }
};

} //examples

#endif //_examples_ArbritraryTask_h_