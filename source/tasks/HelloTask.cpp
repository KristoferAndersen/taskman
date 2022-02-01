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

// HelloTask::~HelloTask() = default;

/*
* Public members
*/
void HelloTask::start() {
    std::cout << "Hello!" << std::endl;
}

/*
* Protected members
*/

/*
* Private members
*/

}  // namespace taskman
