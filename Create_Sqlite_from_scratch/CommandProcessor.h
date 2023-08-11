#pragma once
#include "constant.h"
#include "Pager.h"
#include <thread>

class CommandProcessor
{
private:
    MetaCommandResult do_meta_command(std::string &input_string);
    PrepareResult prepare_statement(std::string &input_string, Statement &statement);
    ExecuteResult execute_statement(Statement &statement, Table &table);
    ExecuteResult insert_statement(Statement &statement, Table &table);
    ExecuteResult select_statement(Statement &statement, Table &table);
    
public:
    CommandProcessor();
    ~CommandProcessor();

    void getCommand();
};