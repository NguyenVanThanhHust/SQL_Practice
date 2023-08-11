#pragma once 
#include <string>

const std::string EXIT_DB = ".exit";
#define COLUMN_USERNAME_SIZE 32
#define COLUMN_EMAIL_SIZE    255

struct Row {
    uint32_t id;
    char username[COLUMN_USERNAME_SIZE];
    char email[COLUMN_EMAIL_SIZE];
};

enum MetaCommandResult {
    META_COMMAND_SUCCESS, 
    META_COMMAND_UNREGCONIZED_COMMAND
};

enum PrepareResult {
    PREPARE_SUCCESS,
    PREPARE_SYNTAX_ERROR, 
    PREPARE_UNRECOGNIZED_STATEMENT
};

enum CommandResult {
    COMMAND_SUCCESS,
    COMMAND_FAILED,
    UNRECOGNIZED_COMMAND,
};

enum ExecuteResult {
    EXECUTE_TABLE_FULL,
    EXECUTE_SUCCESS,
    EXECUTE_FAIL
};

enum StatementType {
    STATEMENT_INSERT, 
    STATEMENT_SELECT
};

struct Statement {
    StatementType type;
    Row row_to_insert;
};

// Define compact representation of a row
#define size_of_attribute(Struct, Attribute) sizeof(((Struct*)0)->Attribute)
const uint32_t ID_SIZE = size_of_attribute(Row, id);
const uint32_t USERNAME_SIZE = size_of_attribute(Row, username);
const uint32_t EMAIL_SIZE = size_of_attribute(Row, email);
const uint32_t ID_OFFSET = 0;
const uint32_t USERNAME_OFFSET = ID_OFFSET + ID_SIZE;
const uint32_t EMAIL_OFFSET = USERNAME_OFFSET + USERNAME_SIZE;
const uint32_t ROW_SIZE = ID_SIZE + USERNAME_SIZE + EMAIL_SIZE;

