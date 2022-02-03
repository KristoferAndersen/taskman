# Taskman
Taskman is an asynchronous task management library. It provides an API to control any task object that inherits from the `ITask` interface, which is defined in `include/ITask.h`. The library accepts both built-in and client-defined task types. Two example tasks are included:
- `ThinkTask` is built into the library. It prints thoughts into a text file in `/tmp/`. The task has a 50 second runtime.
- `AbritraryTask` is included in the `examples/` directory. `taskmanCLI` can submit this task as a demonstration of client-defined tasks. This task is trivial and finishes after one print command.

## Requirements
- CMake 3.14 or higher
- C++17 or higher
- GoogleTest 1.10.0 (Fetched automatically during build process. Just make sure your platform is compatible).

## Configure, build, run, and install
This is a CMake project.
Convenience scripts are available under `scripts/`.
A typical build process is as follows 

Start by configuring the project:

    mkdir -p build
    cd build
    cmake ..

Build the executables:

    pwd  # [project root]/build/
    cmake --build .

At this point, you should have built:
- The `taskman.so` shared library - Found in `build`.
- The `TaskManTest` unit test runner - Found in `build/test/`.
- The `taskmanCLI` command line interface application - Found in `/build/examples/`.

The latter two can be executed directly on the command line, but the shared `taskman.so` library must be linked into whichever application will make use of it.
This brings us to installation.

The following command can be used to install the library in `/usr/local/lib/`, although the path may differ depending on platform and CMake configuration.
This may require superuser access. Further arguments can be used to install the library elsewhere, refer to CMake documentation if required.

    pwd  # [project root]/build/
    cmake --install .

## taskmanCLI
The example directory contains a simple CLI program that demonstrates the library capabilities.
The program is built to `build/examples/taskmanCLI`.

`taskmanCLI` should be started without arguments, with the exception of `--help`.

Once started, the following commands are available:

    help
        List all available commands.
    list
        List all built-in task types and their task_type_id.
    start
        Submit and start the task defined in `examples/ArbritraryTask.h` to the library.
    start [task_type_id]
        Request that the library creates and starts a task with the given task_type_id.
    pause [task_id]
        Pause a task.
    resume [task_id]
        Resumes a paused task.
    stop
        Stops a task.
    status
        Report the status of all tasks.
    status [task_id]
        Report the status of a single task.
    quit
        Stop all tasks and exit.

## Client-defined tasks
Any application that uses `taskman` can define its own tasks for it to manage.
To do so, define a class which inherits from the `ITask` interface, found in `include/ITask.h`.

At minimum, the child class must override two methods:
- `ITask::do_work`

    The actual task function that shall be performed.
- `ITask::run`

    Defines how the do_work thread shall be executed.

The examples provided in this repository run tasks with simple `std::thread` objects, but overloading the `ITask::run` method allows the client to define their own asynchronous running foundation.

The `taskman` library manages tasks by setting control flags to their `m_command` private member variable.
These are defined in the `ITask` header file by the `TaskCommands` enum:
- `TaskCommands::Pause`
- `TaskCommands::Run`
- `TaskCommands::Stop`


These flags should be monitored in a task's working function with little latency.
After these commands have been set, the library waits a short while for the task to set its appropriate status flag in response..
The status flags are defined in the `ITask` header file by the `TaskStates` enum:
- `TaskStates::Paused`
- `TaskStates::Running`
- `TaskStates::Stopped`
- `TaskStates::Completed`

## Testing
Testing consists of unit testing with Google Test.
These are defined in the `test` directory.

The testing that is performed is a demonstration, only the `TaskController` is tested. Further unit tests for classes such as `TaskFactory` would be advisable for any serious project. Additionally, Google Test is not limited to just unit tests, adding integration tests would be a good idea.

The existing tests demonstrate how the `TaskController` becomes more testable through dependency injection.
A `Taskfactory` is simply provided during the controller's construction.
This allows a test to easily separate functionality and mock that which is not to the subject of the test.
