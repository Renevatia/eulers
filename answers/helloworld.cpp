// just a test file
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    int x = 0;
    ofstream myfile;
    cout << "Hello World";
    cout << endl;
    
    myfile.open ("helloworld-output.txt");
    myfile << "Hello World";
    myfile.close();

    cin >> x;
    
    return 0;
}