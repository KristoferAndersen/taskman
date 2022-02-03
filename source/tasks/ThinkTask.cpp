#include "ThinkTask.h"

/*
* Local header files
*/

/*
* System header files
*/
// #include <iostream>
#include <fstream>

namespace taskman
{

/*
* Constructors & Destructor
*/

ThinkTask::ThinkTask(): ITask("ThinkTask") {}

// ThinkTask::~ThinkTask() = default;

/*
* Public members
*/
void ThinkTask::do_work() {

    // Dummy taks, keep it simple
    int thinking_time = 500;
    std::string thinking_file = "../../logs/thoughts" + std::to_string(get_id()) + ".txt";
    std::ofstream file(thinking_file);

    for(int i = 0; i < 100; i++) {
        std::this_thread::sleep_for(std::chrono::milliseconds(thinking_time));

        if(file.is_open()) {
            file << "HMM" << std::endl;
        }
        else {
            std::cerr << "Could not open file '" << thinking_file << std::endl;
            return;
        }
        
    }

    file.close();
}

/*
* Protected members
*/

/*
* Private members
*/

}  // namespace taskman
