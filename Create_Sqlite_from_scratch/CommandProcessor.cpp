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

void CommandProcessor::getCommand()
{
    std::string input_string;
    while(true)
    {
        cout<<"db > ";
        std::getline(std::cin, input_string);
        int diff = input_string.compare(EXIT_DB);
        if (diff != 0)
        {
            cout<<"Unrecognized command "<<input_string<<" for now"<<endl;
        }
        else
        {
            cout<<"Existing"<<endl;
            break;
        }
    }
}