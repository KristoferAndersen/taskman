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
    MOCK_METHOD(void, start, (), ());
    MOCK_METHOD(int, pause, (), ());
    MOCK_METHOD(int, stop, (), ());
    MOCK_METHOD(void, set_id, (int task_id), ());
    MOCK_METHOD(int, get_id, (), ());

    MOCK_METHOD(void, run, (), ());
    MOCK_METHOD(void, do_work, (), ());
};

} //taskman

#endif //_test_mock_MockTask_h_