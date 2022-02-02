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

class ITask
{
public:
    ITask(int id, std::string name) : m_id(id), m_name(name) {};
    //  virtual ~ITask();
    virtual void start() = 0;
    int get_id() { return m_id; }
    friend std::ostream& operator<<(std::ostream& os, const ITask& t) {
        std::cout << t.m_id << "\t" << t.m_name << "\tRUNNING" << "\t100%";
        return os;
    }


private:
    ITask();  // Prevent use of default constructor
    int m_id;
    std::string m_name;
};

} //taskman

#endif //_taskman_ITask_h_