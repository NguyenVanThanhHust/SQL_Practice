#include <iostream>
#include <string>

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

MetaCommandResult CommandProcessor::do_meta_command(std::string* input_string)
{
    int diff = input_string->compare(0, 5, EXIT_DB);
    if (diff == 0)
    {
        return META_COMMAND_SUCCESS;
    }
    else
    {
        return META_COMMAND_UNREGCONIZED_COMMAND;
    }
    
};

PrepareResult CommandProcessor::prepare_statement(std::string* input_string, Statement* statement)
{
    if (input_string->compare(0, 6, "insert") == 0)
    {
        statement->type = STATEMENT_INSERT;
        return PREPARE_SUCCESS;
    }
    if (input_string->compare(0, 6, "select")==0)
    {
        statement->type = STATEMENT_SELECT;
        return PREPARE_SUCCESS;
    }
    return PREPARE_UNRECOGNIZED_STATEMENT;
};

void CommandProcessor::execute_statement(Statement* statement)
{
    switch (statement->type)
    {
    case (STATEMENT_INSERT):
        cout<<"Insert something"<<endl;
        break;
    case (STATEMENT_SELECT):
        cout<<"Select something"<<endl;
        break;
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
            switch (do_meta_command(&input_string))
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
        switch (prepare_statement(&input_string, &statement))
        {
        case (PREPARE_SUCCESS):
            break;
        case (PREPARE_UNRECOGNIZED_STATEMENT):
            cout<<"Can't recognize keyword"<<input_string<<endl;
            continue;
        }

        execute_statement(&statement);

    }
}