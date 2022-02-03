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
// Unit testing logic-free controllers can be a poor time investment.
// Think about why we are testing, and try to focus on test value.

class TaskControllerTest : public ::testing::Test {
// Base class testing
 protected:
    // ARRANGE
    std::shared_ptr<MockTask> mock_task{new MockTask()};
    std::shared_ptr<MockFactory> start_task_factory{new MockFactory()};
    TaskController c{start_task_factory, 10};
};

class TaskControllerStartsTest : public TaskControllerTest {
// Tests where tasks should be successfully started
protected:
    // ARRANGE
    void SetUp() override {
        // ASSERT

        // Return the mock task
        EXPECT_CALL(*start_task_factory, create_task(testing::_)).WillRepeatedly(testing::Return(mock_task));

        // Returned task should always be started, and its ID should be set.
        EXPECT_CALL(*mock_task, start()).Times(1);
        EXPECT_CALL(*mock_task, stop()).Times(1);
    }
};

TEST_F(TaskControllerTest, no_initial_tasks) {
    EXPECT_EQ(c.get_task_ids().size(), 0) << "Incorrect initial number of tasks";
}

TEST_F(TaskControllerTest, start_task_null_returns_non_id) {
    // ACT
    int id = c.start(std::shared_ptr<ITask>(nullptr));

    // ASSERT
    EXPECT_EQ(id, -1) << "Controller returned valid ID for an invalid task";
}

TEST_F(TaskControllerTest, pause_invalid_id) {
    // ACT
    bool success = c.pause(-1);

    // ASSERT
    EXPECT_EQ(success, false) << "Controller paused invalid ID";
}

TEST_F(TaskControllerTest, resume_invalid_id) {
    // ACT
    bool success = c.resume(-1);

    // ASSERT
    EXPECT_EQ(success, false) << "Controller resumed invalid ID";
}

TEST_F(TaskControllerTest, stop_invalid_id) {
    // ACT
    bool success = c.stop(-1);

    // ASSERT
    EXPECT_EQ(success, false) << "Controller stopped invalid ID";
}

TEST_F(TaskControllerTest, get_task_invalid_id) {
    // ACT
    auto task = c.get_task(99);

    // ASSERT
    EXPECT_EQ(task.get(), nullptr) << "Controller returned a task with a bad ID request";
}

TEST_F(TaskControllerTest, start_type_invalid_returns_non_id) {
    // ARRANGE & ASSERT
    EXPECT_CALL(*start_task_factory, create_task(testing::_)).WillOnce(testing::Return(nullptr));

    // ACT
    int id = c.start(-1);

    // ASSERT
    EXPECT_EQ(id, -1) <<"Controller returned valid ID for an invalid task type";
}

TEST_F(TaskControllerStartsTest, start_type_records_task) {
    // ACT
    int expected_id = c.start(1);
    auto tasks = c.get_task_ids();

    // ASSERT
    ASSERT_EQ(tasks.size(), 1) << "Incorrect task count";
    EXPECT_EQ(tasks[0], expected_id) << "Returned ID does not match recorded ID";
}

TEST_F(TaskControllerStartsTest, start_type_starts_factorytask) {
    // ACT
    int id = c.start(1);

    // ASSERT
    EXPECT_EQ(c.get_task(id).get(), mock_task.get());
    EXPECT_EQ(c.get_task_ids().size(), 1);
}

}  // namespace taskman