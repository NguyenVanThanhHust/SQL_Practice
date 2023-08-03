#pragma once
#include "constant.h"

#include <thread>

enum CommandResult{
    COMMAND_SUCCESS,
    COMMAND_FAILED,
    UNRECOGNIZED_COMMAND,
};

class CommandProcessor
{
public:
    CommandProcessor();
    ~CommandProcessor();

    void getCommand();
};