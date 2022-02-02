#include "TaskController.h"
#include <tasks/TaskFactory.h>
#include "MockFactory.h"
#include "MockTask.h"

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include <vector>
#include <memory>


// TODO: REMOVE ME
#include <iostream>

namespace taskman {

class TaskControllerTest : public ::testing::Test {
// Unit testing logic-free controllers can be a poor time investment.
// Think about why we are testing, and try to focus on test value.


 protected:
    // ARRANGE
    void SetUp() override {
        EXPECT_CALL(*start_task_factory_, create_task(testing::_, testing::_)).WillRepeatedly(testing::Return(mock_task_));
    }

    void TearDown() override {
    }

    std::shared_ptr<MockTask> mock_task_{new MockTask(1, "Mock task")};
    std::shared_ptr<MockFactory> start_task_factory_{new MockFactory()};
    TaskController c{start_task_factory_, 10};
};

TEST_F(TaskControllerTest, no_initial_tasks) {
    EXPECT_EQ(c.get_task_ids().size(), 0) << "Incorrect initial number of tasks";
}

TEST_F(TaskControllerTest, start_any_records_task) {
    // ACT
    int expected = c.start();
    auto tasks = c.get_task_ids();

    // ASSERT
    ASSERT_EQ(tasks.size(), 1) << "Incorrect task count";
    EXPECT_EQ(tasks[0], expected) << "Returned ID does not match recorded ID";
}

TEST_F(TaskControllerTest, start_by_type_records_task) {
    // ACT
    int expected_id = c.start(1);
    auto tasks = c.get_task_ids();

    // ASSERT
    ASSERT_EQ(tasks.size(), 1) << "Incorrect task count";
    EXPECT_EQ(tasks[0], expected_id) << "Returned ID does not match recorded ID";
}

TEST_F(TaskControllerTest, start_by_type_starts_factory_task) {
    // ARRANGE
    EXPECT_CALL(*mock_task_, start())
        .Times(1);

    // ACT
    int id = c.start(1);

    // ASSERT
    EXPECT_EQ(c.get_task(id).get(), mock_task_.get());
    EXPECT_EQ(c.get_task_ids().size(), 1);
}
}  // namespace taskman
