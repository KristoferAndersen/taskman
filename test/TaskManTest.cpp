#include "TaskMan.h"
#include "gtest/gtest.h"

namespace taskman
{

class TaskManTest : public ::testing::Test {

    protected:

    // ARRANGE
    void SetUp() override {
    }

    TaskMan man1_;
};

TEST_F(TaskManTest, no_initial_tasks) {
    EXPECT_EQ(man1_.get_task_count(), 0) << "Incorrect initial number of tasks";
}

TEST_F(TaskManTest, start_any) {

    // ACT
    man1_.start();

    // ASSERT
    EXPECT_EQ(man1_.get_task_count(), 1) << "Incorrect task count";
}

TEST_F(TaskManTest, start_type) {

    // ACT
    man1_.start(1);
    auto tasks = man1_.get_task_ids();

    // ASSERT
    ASSERT_EQ(tasks.size(), 1) << "Incorrect task count";
    EXPECT_EQ(tasks[0], 1) << "Unexpected task ID recorded";
}

}  // taskman