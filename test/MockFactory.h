#ifndef _test_mock_MockFactory_h_
#define _test_mock_MockFactory_h_

/*
* Local header files
*/
#include "ITask.h"
#include "tasks/TaskFactory.h"
#include "gmock/gmock.h"

/*
* System header files
*/
#include <memory>

/*
* Forward declarations
*/

namespace taskman
{

class MockFactory : public TaskFactory
{
public:
    MOCK_METHOD(std::shared_ptr<ITask>, create_task, (int task_type_id, int task_id), (override));
};

} //taskman

#endif //_test_mock_MockFactory_h_