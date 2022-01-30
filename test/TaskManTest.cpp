#include "TaskMan.h"
#include "gtest/gtest.h"

namespace taskman
{

class TaskManTest : public ::testing::Test {
    protected:
    void SetUp() override {
    }

    TaskMan man1_;
};

TEST_F(TaskManTest, start) {
    man1_.start();
    EXPECT_EQ(man1_.get_task_count(), 1);
}

}  // taskman