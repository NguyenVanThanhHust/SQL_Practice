#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;

struct InputBuffer {
    std::string buffer;
    size_t buffer_length=0; 
};

void print_promt()
{
    cout<<"db >";
};

void read_input(InputBuffer &input_buffer)
{
    std::getline(std::cin, input_buffer.buffer);
    input_buffer.buffer_length = input_buffer.buffer.size();
};

int main()
{
    InputBuffer input_buffer;
    while (true)
    {
        print_promt();
        read_input(input_buffer);
        if (input_buffer.buffer.compare(0, 5, ".exit") == 0)
        {
            cout<<"Exiting."<<endl;
            break;
        }
        else
        {
            cout<<"Unrecognize command"<<endl;
        }
    }
    return 0;
}