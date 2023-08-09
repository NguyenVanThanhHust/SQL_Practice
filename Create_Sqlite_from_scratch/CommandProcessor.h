#pragma once
#include "constant.h"

#include <thread>

class CommandProcessor
{
private:
    MetaCommandResult do_meta_command(std::string* input_string);
    PrepareResult prepare_statement(std::string* input_string, Statement* statement);
    void execute_statement(Statement* statement);

public:
    CommandProcessor();
    ~CommandProcessor();

    void getCommand();
};