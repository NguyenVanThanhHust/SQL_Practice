#pragma once 
#include <string>

const std::string EXIT_DB = ".exit";

enum MetaCommandResult {
    META_COMMAND_SUCCESS, 
    META_COMMAND_UNREGCONIZED_COMMAND
};

enum PrepareResult {
    PREPARE_SUCCESS, 
    PREPARE_UNRECOGNIZED_STATEMENT
};

enum CommandResult{
    COMMAND_SUCCESS,
    COMMAND_FAILED,
    UNRECOGNIZED_COMMAND,
};

enum StatementType {
    STATEMENT_INSERT, 
    STATEMENT_SELECT
};

struct Statement {
    StatementType type;
};