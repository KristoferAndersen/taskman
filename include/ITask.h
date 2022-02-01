#ifndef _taskman_ITask_h_
#define _taskman_ITask_h_

/*
* Local header files
*/

/*
* System header files
*/

/*
* Forward declarations
*/

namespace taskman
{

class ITask
{
 public:
    ITask(int id) : m_id(id) {};
   //  virtual ~ITask();
    virtual void start() = 0;
    int get_id() { return m_id; }

 private:
    ITask();  // Inheriting classes are forced to implement the public constructor
    int m_id;
};

} //taskman

#endif //_taskman_ITask_h_