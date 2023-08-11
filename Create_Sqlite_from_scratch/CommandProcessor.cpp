#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cstring>

#include "CommandProcessor.h"

using std::cin;
using std::cout;
using std::endl;

CommandProcessor::CommandProcessor()
{
};

CommandProcessor::~CommandProcessor()
{
};

MetaCommandResult CommandProcessor::do_meta_command(std::string &input_string)
{
    int diff = input_string.compare(0, 5, EXIT_DB);
    if (diff == 0)
    {
        return META_COMMAND_SUCCESS;
    }
    else
    {
        return META_COMMAND_UNREGCONIZED_COMMAND;
    }
    
};

PrepareResult CommandProcessor::prepare_statement(std::string &input_string, Statement &statement)
{
    if (input_string.compare(0, 6, "insert") == 0)
    {
        statement.type = STATEMENT_INSERT;
        std::string buffer;
        std::vector<std::string> cmd;
        std::stringstream ss(input_string);
        while (getline(ss, buffer, ' '))
        {
            cmd.push_back(buffer);
        }
        if (cmd.size() < 3)
        {
            return PREPARE_SYNTAX_ERROR;
        }
        statement.row_to_insert.id = std::stoi(cmd[1]);
        std::strcpy(statement.row_to_insert.username, cmd[2].c_str());
        std::strcpy(statement.row_to_insert.email, cmd[3].c_str());
        
        return PREPARE_SUCCESS;
    }
    if (input_string.compare(0, 6, "select")==0)
    {
        statement.type = STATEMENT_SELECT;
        return PREPARE_SUCCESS;
    }
    return PREPARE_UNRECOGNIZED_STATEMENT;
};
ExecuteResult insert_statement(Statement &statement, Table &table)
{
    if (table.num_rows >= TABLE_MAX_ROWS)
    {
        return EXECUTE_TABLE_FULL;
    }
    Row row_to_insert = statement.row_to_insert;
    serialize_row(row_to_insert, row_slot(table, tal))
    
};

ExecuteResult select_statement(Statement &statement, Table &table)
{

};


ExecuteResult CommandProcessor::execute_statement(Statement &statement, Table &table)
{
    switch (statement.type)
    {
    case (STATEMENT_INSERT):
        return insert_statement(statement, table);
    case (STATEMENT_SELECT):
        return select_statement(statement, table);
    }
}
void CommandProcessor::getCommand()
{
    std::string input_string;
    while(true)
    {
        cout<<"db > ";
        std::getline(std::cin, input_string);
        
        if(input_string.at(0) == '.')
        {
            switch (do_meta_command(input_string))
            {
                case META_COMMAND_SUCCESS:
                    return ;
                    continue;
                case META_COMMAND_UNREGCONIZED_COMMAND:
                    cout<<"Unrecognized command"<<endl;
                    continue;
            }

        }
        Statement statement;
        switch (prepare_statement(input_string, statement))
        {
        case (PREPARE_SUCCESS):
            break;
        case (PREPARE_SYNTAX_ERROR):
            cout<<"Syntex error in command: "<<input_string<<endl;
            continue;
        case (PREPARE_UNRECOGNIZED_STATEMENT):
            cout<<"Can't recognize keyword "<<input_string<<endl;
            continue;
        }

        execute_statement(statement);

    }
}