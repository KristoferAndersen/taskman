#ifndef _test_mock_MockTask_h_
#define _test_mock_MockTask_h_

/*
* Local header files
*/
#include "ITask.h"
#include "gmock/gmock.h"

/*
* System header files
*/

/*
* Forward declarations
*/

namespace taskman
{

class MockTask : public ITask
{
public:
    MockTask() : ITask("Mock task") {};
    ~MockTask() {};

    MOCK_METHOD(void, start, (), ());
    MOCK_METHOD(void, resume, (), ());
    MOCK_METHOD(void, pause, (), ());
    MOCK_METHOD(void, stop, (), ());

    MOCK_METHOD(void, set_id, (int task_id), ());
    MOCK_METHOD(int, get_id, (), ());
    MOCK_METHOD(std::string, get_name, (), ());
    MOCK_METHOD(int, get_status, (), ());
    MOCK_METHOD(std::string, get_status_string, (), ());
    MOCK_METHOD(int, get_progress, (), ());

    MOCK_METHOD(void, run, (), (override));
    MOCK_METHOD(void, do_work, (), (override));
};

} //taskman

#endif //_test_mock_MockTask_h_