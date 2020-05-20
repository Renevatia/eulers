/// STC Euler
/// Question 1-10 solutions
/// 05/18/2020

#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <unistd.h>
#include <cmath>

using namespace std;

// Protoype
//------------------------------------------------------------------------------
int prompt();
void questionSelect(int qNum);
void printAnswer1(int aNum);
void printAnswer2(long long aNum);
void q1Solve();
void q2Solve();
void q3Solve();
void q4Solve();
void q6Solve();
void q7Solve();
void q8Solve();
void q9Solve();

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

//question 6
//------------------------------------------------------------------------------
void q6Solve()
{
    int sum1 = 0;
    int sum2 = 0;
    for (int i = 1; i <= 100; i++)
    {
        sum1 = sum1 + pow(i, 2);
        sum2 = sum2 + i;
    }
    sum2 = pow(sum2, 2);
    printAnswer1(sum2-sum1);
}

//question 7
//------------------------------------------------------------------------------
void q7Solve()
{
    long currentPrime = 2;
    long currentTest = 3;
    for (int i = 1; i < 10000; i++)
    {
        for (currentTest = currentPrime + 1; currentTest > 0; currentTest++)
        {
            for (long j = 2; j <= (currentTest / 2) + 2; j++)
            {
                if (currentTest % j == 0)
                {
                    // not prime
                    j = currentTest;
                }else if (j == (currentTest / 2) + 2){
                    //prime
                    currentPrime = currentTest;
                    currentTest = -999;
                }
            }
        }
    }
    printAnswer1(currentPrime);
}

void q8Solve()
{
    string line;
    long long currentMax = 1;
    long long answer = 0;
    ifstream myfile ("q8.txt");

    getline(myfile, line);
      
    myfile.close();
    
    for (int i = 0; i < 1000-13; i++)
    {
        answer = 1;
        for (int j = 0; j < 13; j++)
        {
            //cout << line.substr(i + j, 1);
            answer = answer * stoi(line.substr(i + j, 1));
        }
        if (currentMax < answer)
        {
            currentMax = answer;
        }
    }
    printAnswer2(currentMax);
}

void q9Solve()
{
    long answer;
    // H has to be (414, 500)
    for (int i = 414; i < 500; i++)
    {
        for (int j = 293; j >= 1; j--)
        {
            if (pow(j, 2) + pow(1000 - j - i, 2) == pow(i, 2))
            {
                answer = i * j * (1000 - j - i);
            }
        }
    }
    printAnswer2(answer);
}

void q10Solve()
{
    long long sum = 2;
    for (long i = 3; i < 2000000; i = i + 2)
    {
        //cout << endl << "sqrt of " << i << " = " << static_cast<long>(sqrt(i));
        for (long j = 2; j <= static_cast<long>(sqrt(i)) + 1; j++)
        {
            
            if (i % j == 0)
            {
                // not prime
                j = i;
            }else if (j == static_cast<long>(sqrt(i)) + 1){
                //prime
                sum = sum + i;
                j = i;
                
            }

        }
        //if (i % 100000 <= 1){
        //    cout << endl << 5 * i / 100000 << " %";
        //}
    }
    printAnswer2(sum);
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
        case(6):
            q6Solve();
            break;
        case(7):
            q7Solve();
            break; 
        case(8):
            q8Solve();
            break; 
        case(9):
            q9Solve();
            break; 
        case(10):
            q10Solve();
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

void printAnswer2(long long aNum)
{
    cout << aNum;
}

void printAnswer3()
{}
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