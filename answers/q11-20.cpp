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
void printAnswer3(string aStr);

//question 11
//------------------------------------------------------------------------------
void q11Solve()
{
    string line;
    char trash;
    int numArr[20][20];
    long currentMax = 0;
    long currentTest1 = 1;
    long currentTest2 = 1;
    long currentTest3 = 1;
    long currentTest4 = 1;

    ifstream myfile ("q11.txt");

    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            myfile >> numArr[i][j];
            //cout << numArr[i][j] << " ";
        }
        myfile.get(trash);
        //cout << endl;
    }
    myfile.close();

    for (int i = 0; i < 20 - 4; i++)
    {
        for (int j = 0; j < 20 - 4; j++)
        {
            // iterating the 20x20

            currentTest1 = 1;
            currentTest2 = 1;
            currentTest3 = 1;
            currentTest4 = 1;

            for (int k = 0; k < 4; k++)
            {
                // iterating offset
                currentTest1 = currentTest1 * numArr[i + k][j];
                currentTest2 = currentTest2 * numArr[i + k][j + k];
                currentTest3 = currentTest3 * numArr[i][j + k];
                currentTest4 = currentTest4 * numArr[i + 4 - k][j + k];

            }
            // compare
            currentMax = (currentMax < currentTest1)? currentTest1 : currentMax;
            currentMax = (currentMax < currentTest2)? currentTest2 : currentMax;
            currentMax = (currentMax < currentTest3)? currentTest3 : currentMax;
            currentMax = (currentMax < currentTest4)? currentTest4 : currentMax;
        }
    }

    printAnswer2(currentMax);
}

//question 12
//------------------------------------------------------------------------------
void q12Solve()
{
    long int currentTri = 1;
    long int currentNum = 2;
    int divisorCount = 0;
    int currentMaxD = 0;
    long int answer = 0;
    int answer2 = 0;


    for (currentNum = 2; currentNum < 100000; currentNum++)
    {
        divisorCount = 0;
        currentTri = currentTri + currentNum;
        // checking divisors
        // assuming that it will at least have 2 2 3 5
        if (currentTri % 60 == 0)
        {
            for (int i = 1; i <= currentTri; i++)
            {
                if (currentTri % i == 0)
                {
                    divisorCount++;
                }
            }
        }
        currentMaxD = (currentMaxD < divisorCount)? divisorCount : currentMaxD;
        if (divisorCount > 500)
        {
            answer2 = currentNum;
            currentNum = 9999999;
            answer = currentTri;
        }

        if (currentNum % 1000 < 1)
        {
            cout << endl << currentNum / 1000 << " % " << currentMaxD;
        }
    }
    cout << endl << "the " << answer2 << "th triangle";
    printAnswer2(answer);
}

//question 13
//------------------------------------------------------------------------------
void q13Solve()
{
    string line[100];
    char trash;
    int numArr[101][52];
    string answer = "";

    ifstream myfile ("q13.txt");

    for (int i = 0; i < 100; i++)
    {
        getline(myfile, line[i]);
        //myfile.get(trash);
        
    }
    myfile.close();
    for (int j = 0; j < 101; j++)
    {
        for (int i = 0; i < 52; i++)
        {
            numArr[j][i] = 0;
        }
    }
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 50; j++)
        {
            // leave 2 spaces in front of array by row for additions later
            // char is an additional dimension in an array of strings
            // taking the char - '0' in ascii order gives true int
            // otherwise it gives char code in ascii
            numArr[i][j + 2] = (line[i][j] - '0');
        }
    }
    
    
    for (int i = 51; i >= 0; i--)
    {
        for (int j = 0; j < 100; j++)
        {
            numArr[100][i] = numArr[100][i] + numArr[j][i];
        }
        if (i > 0)
        {
            numArr[100][i - 1] = numArr[100][i] / 10;
            numArr[100][i] = numArr[100][i] % 10;
        }
        cout << endl << "i = " << i << ", "<< numArr[98][i];
    }
    
    answer = 
    to_string(numArr[100][0]) +
    to_string(numArr[100][1]) +
    to_string(numArr[100][2]) +
    to_string(numArr[100][3]) +
    to_string(numArr[100][4]) +
    to_string(numArr[100][5]) +
    to_string(numArr[100][6]) +
    to_string(numArr[100][7]) +
    to_string(numArr[100][8]) +
    to_string(numArr[100][9]);

    printAnswer3(answer);
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
        case(11):
            q11Solve();
            break;
        case(12):
            q12Solve();
            break;
        case(13):
            q13Solve();
            break;
        case(4):
            break;
        case(5):
            break;  
        case(6):
            break;
        case(7):
            break; 
        case(8):
            break; 
        case(9):
            break; 
        case(10):
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
    cout << endl << "Answer = ";
    cout << aNum;
}

void printAnswer3(string aStr)
{
    cout << endl << "Answer = " << aStr;
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