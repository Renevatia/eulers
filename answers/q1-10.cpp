/// STC Euler
/// Question 1-10 solutions
/// 05/18/2020

#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <unistd.h>

using namespace std;

// Protoype
//------------------------------------------------------------------------------
int prompt();
void questionSelect(int qNum);
void printAnswer1(int aNum);

void q1Solve();
void q2Solve();
void q3Solve();
void q4Solve();

//question 1
//------------------------------------------------------------------------------
void q1Solve()
{
    int j = 0;
    for (int i = 1; i < 1000; i++)
    {
        if(i % 3 == 0 || i % 5 == 0)
        {
            j = j + i;
        }
    }
    printAnswer1(j);
}

//question 2
//------------------------------------------------------------------------------
void q2Solve()
{
    int j = 1;
    int current = 0;
    int sum = 0;

    for (int i = 1; current < 4000000;)
    {
        current = i + j;
        i = j;
        j = current;
        if (current % 2 == 0)
        {
            sum = sum + current;
        }
    }
    printAnswer1(sum);
}

//question 3
//------------------------------------------------------------------------------
void q3Solve()
{
    long primeArray[64];
    long long int currentNum = 600851475143;

    for (int i = 0; i < 64; i++)
    {
        primeArray[i] = 0;
    }

    for (int i = 0; i < 64; i++)
    {
        for (int j = 2; j <= currentNum; j++)
        {
            if (currentNum % j == 0)
            {
                if (j == currentNum)
                {
                    i = 999;
                    printAnswer1(j);
                }
                currentNum = currentNum / j;
                // this is not necesarry as if loop runs to currentNum it
                // will be the largest prime number factor = the answer.
                primeArray[i] = j;
                
                j == currentNum + 1;
            }
        }
    }
}

//question 4
//------------------------------------------------------------------------------
void q4Solve()
{
    string currentStr = "abcdef";
    string flipStr = "";
    int strLen = 0;
    int currentMax = 0;
    int loopCount = 0;

    for (int i = 100; i < 1000; i++)
    {

        for (int j = 100; j < 1000; j++)
        {
            // no need to repeat ji, ij
            currentStr = to_string(j * i);

            strLen = currentStr.length();
            flipStr = currentStr.substr(2, 1) + currentStr.substr(1, 1)
                + currentStr.substr(0, 1);

            if (flipStr == currentStr.substr((strLen - 3), 3))
            {

                if (currentMax < (j * i))
                {
                    currentMax = j * i;
                    cout << endl << j << " x " << i ;
                }
            }
        }

    }
    printAnswer1(currentMax);

}
// menu
//------------------------------------------------------------------------------
int prompt()
{
    int qNum = 0;
    cout << endl;
    cout << "Select the question# : ";

    cin >> qNum;
    return qNum;
}

void questionSelect(int qNum)
{
    switch(qNum)
    {
        case(1):
            q1Solve();
            break;
        case(2):
            q2Solve();
            break;
        case(3):
            q3Solve();
            break;
        case(4):
            q4Solve();
            break;
        case(5):
            cout << "232792560, logic QED";
            break;  
        default:
            cout << "Select a valid question";
            cout << endl;
            break;      
    }
}

void printAnswer1(int aNum)
{
    cout << aNum;
}
//------------------------------------------------------------------------------
int main()
{
    int status = 0;
    int qNum = 0;
    int i = 0;

    qNum = prompt();
    auto startTime = chrono::steady_clock::now();
    questionSelect(qNum);
    auto endTime = chrono::steady_clock::now();

    // time elapsed for a single question computation
    cout << endl << "Time it took to run = ";
    cout << chrono::duration_cast<chrono::microseconds>(endTime - startTime).count();
    cout << "microseconds" << endl;
    cin >> i;

    return status;
}