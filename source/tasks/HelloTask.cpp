#include "HelloTask.h"

/*
* Local header files
*/

/*
* System header files
*/
#include <iostream>

namespace taskman
{

/*
* Constructors & Destructor
*/

HelloTask::HelloTask(): ITask("HelloTask") {}

// HelloTask::~HelloTask() = default;

/*
* Public members
*/
void HelloTask::do_work() {
    std::cout << "Hey, I'm working!" << std::endl;
}

/*
* Protected members
*/

/*
* Private members
*/

}  // namespace taskman
