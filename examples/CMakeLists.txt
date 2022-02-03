add_executable(taskmanCLI
               TaskManagerCLI.cpp
               ArbritraryTask.h)
target_link_libraries(taskmanCLI PUBLIC ${PROJECT_NAME})
target_link_libraries(taskmanCLI PRIVATE Threads::Threads)