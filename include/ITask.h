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
#include <map>

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
    ITask(std::string name) : m_name(name), m_status(TaskStates::Paused), m_command(TaskCommands::Pause) {
        m_status_strings[TaskStates::Paused] = "Paused";
        m_status_strings[TaskStates::Running] = "Running";
        m_status_strings[TaskStates::Stopped] = "Stopped";
        m_status_strings[TaskStates::Completed] = "Completed";
    }
    virtual ~ITask() { m_thread.join(); }

    // These methods are not to be overriden.
    void start() { m_command = TaskCommands::Run; run(); }
    void resume() { m_command = TaskCommands::Run; }
    void pause() { m_command = TaskCommands::Pause; }
    void stop() { m_command = TaskCommands::Stop; }

    void set_id(int task_id) { m_id = task_id; }
    int get_id() { return m_id; }
    std::string get_name() { return m_name; }
    int get_status() { return m_status; }
    std::string get_status_string() { return m_status_strings[m_status]; }

    // Runs "do_work" asynchronously. Can be overriden to use different threading approaches.
    virtual void run() {
        m_thread = std::thread(&ITask::do_work, this);
    }

    // The task. Must be defined by concrete task objects.
    // Must monitor m_command to enable task control functions.
    virtual void do_work() {};


    friend std::ostream& operator<<(std::ostream& os, ITask& t) {
        os << t.m_id << "\t" << t.m_name << '\t' << t.get_status_string() << "\t100%";
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

    std::map<int, std::string> m_status_strings;
};

} //taskman

#endif //_taskman_ITask_h_