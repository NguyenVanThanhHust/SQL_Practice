#include <iostream>
#include <string>
#include "constant.h"

using std::cin;
using std::cout;
using std::endl;

void print_promt()
{
    cout<<"db > ";
};

int main()
{
    while (true)
    {
        std::string input_string;
        print_promt();
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
    return 0;
}