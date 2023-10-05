#include <iostream>
#include "sha256.h"

using std::string;
using std::cout;
using std::endl;
 
int main(int argc, char *argv[])
{   

    string output1 = sha256("test44");
    string output2 = sha256("jenetestjamais");
    string output3 = sha256("Dfpmndh45ddas");
 
    cout << output1 << endl;
    cout << output2 << endl;
    cout << output3 << endl;

    return 0;
}
