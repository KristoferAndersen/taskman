#include "ThinkTask.h"

/*
* Local header files
*/

/*
* System header files
*/
#include <iostream>
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
    int target_thoughts = 100;
    int thoughts = 0;
    std::string thinking_file = "/tmp/thoughts" + std::to_string(get_id()) + ".txt";
    std::ofstream file(thinking_file);

    while(m_command != TaskCommands::Stop && thoughts < target_thoughts){
        if(m_command == TaskCommands::Pause) { std::this_thread::sleep_for(std::chrono::milliseconds(100)); }

        if(m_command == TaskCommands::Run) {
            std::this_thread::sleep_for(std::chrono::milliseconds(thinking_time));

            if(file.is_open()) {
                file << "HMM" << std::endl;
                thoughts++;
            }
            else {
                std::cerr << "Could not open file '" << thinking_file << std::endl;
                return;
            }
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
