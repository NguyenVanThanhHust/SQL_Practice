#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;

struct InputBuffer {
    std::string buffer;
    size_t buffer_length = 0;
};

enum StatementType
{
    STATEMENT_INSERT,
    STATEMENT_SELECT
};

struct Statement
{
    StatementType type;
};

enum MetaCommandResult {
    META_COMMAND_SUCCESS,
    META_COMMAND_UNRECOGNIZED_COMMAND
};

enum PrepareResult
{
    PREPARE_SUCCESS,
    PREPARE_UNRECOGNIZED_STATEMENT
};

void print_promt()
{
    cout << "db >";
};

void read_input(InputBuffer& input_buffer)
{
    std::getline(std::cin, input_buffer.buffer);
    input_buffer.buffer_length = input_buffer.buffer.size();
};

MetaCommandResult do_meta_command(InputBuffer &input_buffer)
{
    if (input_buffer.buffer.compare(0, 5, ".exit") == 0)
    {
        return META_COMMAND_SUCCESS;
    }
    return META_COMMAND_UNRECOGNIZED_COMMAND;
};

PrepareResult prepare_statement(InputBuffer& input_buffer, Statement& statement)
{
    if (input_buffer.buffer.compare(0, 6, "insert") == 0)
    {
        statement.type = STATEMENT_INSERT;
        return PREPARE_SUCCESS;
    }
    if (input_buffer.buffer.compare(0, 6, "select") == 0)
    {
        statement.type = STATEMENT_SELECT;
        return PREPARE_SUCCESS;
    }
    return PREPARE_UNRECOGNIZED_STATEMENT;
};

void execute_statement(Statement& statement)
{
    switch (statement.type)
    {
    case STATEMENT_INSERT:
        cout << "We do insert here" << endl;
        break;
    case STATEMENT_SELECT:
        cout << "We do select here" << endl;
        break;
    }
}

int main()
{
    InputBuffer input_buffer;
    while (true)
    {
        print_promt();
        read_input(input_buffer);
        if (input_buffer.buffer.compare(0, 1, ".") == 0)
        {
            switch (do_meta_command(input_buffer))
            {
            case (META_COMMAND_SUCCESS):
                continue;
            case (META_COMMAND_UNRECOGNIZED_COMMAND):
                cout << "Unrecognized command" << endl;
                continue;
            }
        }
        Statement statement;
        switch (prepare_statement(input_buffer, statement))
        {
        case(PREPARE_SUCCESS):
            break;
        case(PREPARE_UNRECOGNIZED_STATEMENT):
            cout << "Unrecogized keyword: " << input_buffer.buffer << endl;
            continue;
        }
        execute_statement(statement);
        cout << "Statement executed" << endl;
    }
    return 0;
}
