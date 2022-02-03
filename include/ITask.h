#ifndef _taskman_ITask_h_
#define _taskman_ITask_h_

/*
* Local header files
*/

/*
* System header files
*/
#include <iostream>

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

class ITask
{
public:
    ITask(std::string name) : m_name(name), m_status(TaskStates::Paused) {}
    //  virtual ~ITask();

    // These methods are not to be overriden.
    void start() { run(); }
    void pause() { m_status = TaskStates::Paused; }
    void stop() { m_status = TaskStates::Stopped; }
    void set_id(int task_id) { m_id = task_id; }
    int get_id() { return m_id; }

    // Runs do_work asynchronously. Can be overriden to use different threading approaches.
    virtual void run() {
        for(int i = 0; i < 3; i++) {
            do_work();
        }
    }

    // The task. Must be defined by concrete task objects.
    virtual void do_work() = 0;


    friend std::ostream& operator<<(std::ostream& os, const ITask& t) {
        os << t.m_id << "\t" << t.m_name << "\tRUNNING" << "\t100%";
        return os;
    }


private:
    ITask();  // Prevent use of default constructor
    ITask(int id);

    int m_id;
    std::string m_name;
    int m_status;
};

} //taskman

#endif //_taskman_ITask_h_