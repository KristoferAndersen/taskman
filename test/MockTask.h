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
    MOCK_METHOD(void, start, (), (override));
    MOCK_METHOD(int, set_id, (int task_id), ());
    MOCK_METHOD(int, get_id, (), ());
};

} //taskman

#endif //_test_mock_MockTask_h_