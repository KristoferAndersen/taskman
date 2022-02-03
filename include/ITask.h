#ifndef _taskman_ITask_h_
#define _taskman_ITask_h_

/*
* Local header files
*/

/*
* System header files
*/
#include <iostream>
#include <thread>

/*
* Forward declarations
*/

namespace taskman
{

enum TaskStates {
    Paused,
    Running,
    Stopped,
    Completed
};

enum TaskCommands {
    Pause,
    Run,
    Stop
};

class ITask
{
public:
    ITask(std::string name) : m_name(name), m_status(TaskStates::Paused), m_command(TaskCommands::Pause) {}
    virtual ~ITask() { m_thread.join(); }

    // These methods are not to be overriden.
    void start() { m_command = TaskCommands::Run; run(); }
    void resume() { m_command = TaskCommands::Run; }
    void pause() { m_command = TaskCommands::Pause; }
    void stop() { m_command = TaskCommands::Stop; }
    void set_id(int task_id) { m_id = task_id; }
    int get_id() { return m_id; }

    // Runs "do_work" asynchronously. Can be overriden to use different threading approaches.
    virtual void run() {
        m_thread = std::thread(&ITask::do_work, this);
    }

    // The task. Must be defined by concrete task objects.
    // Must monitor m_command
    // ITask::do_work is not purely virtual so that this dud can be called by the default runner
    virtual void do_work() {};


    friend std::ostream& operator<<(std::ostream& os, const ITask& t) {
        os << t.m_id << "\t" << t.m_name << "\tRUNNING" << "\t100%";
        return os;
    }


protected:
    ITask();  // Prevent use of default constructor
    ITask(int id);

    int m_id;
    std::string m_name;
    int m_status;
    int m_command;
    std::thread m_thread;
};

} //taskman

#endif //_taskman_ITask_h_