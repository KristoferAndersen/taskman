#include <TaskMan.h>
#include <gtest/gtest.h>

#include <vector>

namespace taskman {

class TaskManTest : public ::testing::Test {
 protected:
    // ARRANGE
    void SetUp() override {
    }

    TaskMan man1_;
    TaskMan man2_;
};

TEST_F(TaskManTest, no_initial_tasks) {
    EXPECT_EQ(man1_.get_task_ids().size(), 0) << "Incorrect initial number of tasks";
}

TEST_F(TaskManTest, start_any) {
    // ACT
    int expected = man1_.start();
    auto tasks = man1_.get_task_ids();

    // ASSERT
    ASSERT_EQ(tasks.size(), 1) << "Incorrect task count";
    EXPECT_EQ(tasks[0], expected) << "Returned ID does not match recorded ID";
}

TEST_F(TaskManTest, start_type) {
    // ACT
    man1_.start(1);
    auto tasks = man1_.get_task_ids();

    // ASSERT
    ASSERT_EQ(tasks.size(), 1) << "Incorrect task count";
    EXPECT_EQ(tasks[0], 1) << "Unexpected task ID recorded";

    // ACT
    std::vector<int> expected{1, 2, 3};
    for(int id : expected) {
        man2_.start(id);
    }

    tasks = man2_.get_task_ids();

    // ASSERT
    EXPECT_EQ(tasks, expected) << "Unexpected task IDs recorded";
}

}  // namespace taskman
