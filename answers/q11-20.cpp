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

//question 14
//------------------------------------------------------------------------------
void q14Solve()
{
    long long currentMax = 0;
    long long currentNum = 0;
    long long currentCount = 0;
    long currentMaxVal = 0;

    for (long i = 1000000; i > 3; i--)
    {
        currentNum = i;
        currentCount = 1;
        for (int j = 0; currentNum > 1;)
        {
            if (currentNum % 2 == 0)
            {
                currentNum = currentNum / 2;
            }else{
                currentNum = (3 * currentNum) + 1;
            }
            currentCount++;
        }
        currentMaxVal = (currentCount > currentMax)? i : currentMaxVal;
        currentMax = (currentCount > currentMax)? currentCount : currentMax;
    }
    printAnswer2(currentMaxVal);
}

//question 15
//------------------------------------------------------------------------------
void q15Solve()
{
    // using bionomial coefficient (x+y; x)
    long double answer = 1;
    for (int i = 1; i <= 20; i++)
    {
        answer = answer * (i + 20);
        answer = answer / (i);
    }
    printAnswer2(answer);
}

//question 16
//------------------------------------------------------------------------------
void q16Solve()
{
    int numArr[350];
    int sum = 0;
    for (int i = 0; i < 350; i++)
    {
        numArr[i] = 0;
    }
    numArr[349] = 2;
    for (int i = 0; i < 999; i++)
    {
        cout << endl << "Here" << endl;
        for (int j = 0; j < 350; j++)
        {
            numArr[j] = (numArr[j] * 2) % 10;
            if (numArr[j + 1] >= 5 && j < 349)
            {
                numArr[j]++;
            }
        }
    }
    for (int i = 0; i < 350; i++)
    {
        sum = sum + numArr[i];
    }
    printAnswer2(sum);
}

//question 17
//------------------------------------------------------------------------------
void q17Solve()
{
    long letterCount = 0;
    int test = 0;
    int test2 = 0;
    int test3 = 0;

    for (int i = 1; i < 1000; i++)
    {
        test = i / 100;
        switch(test)
        {
            case(0):
                break;
            case(1):
                letterCount = letterCount + 10;
                break;
            case(2):
                letterCount = letterCount + 10;
                break;
            case(3):
                letterCount = letterCount + 12;
                break;
            case(4):
                letterCount = letterCount + 11;
                break;
            case(5):
                letterCount = letterCount + 11;
                break;
            case(6):
                letterCount = letterCount + 10;
                break;
            case(7):
                letterCount = letterCount + 12;
                break;
            case(8):
                letterCount = letterCount + 12;
                break;
            case(9):
                letterCount = letterCount + 11;
                break;
        }
        test = i - ((i / 100) * 100);
        test2 = i / 100;
        // and
        if (test > 0 && test2 > 0){letterCount = letterCount + 3;}
        
        // tens
        test2 = test / 10;

        // ones
        test3 = test % 10;

        switch(test2)
        {
            case(0):
                break;
            case(1):
            // teens
                switch(test3)
                {
                    case(0):
                        letterCount = letterCount + 3;
                        break;
                    case(1):
                        letterCount = letterCount + 6;
                        break;
                    case(2):
                        letterCount = letterCount + 6;
                        break;
                    case(3):
                        letterCount = letterCount + 8;
                        break;
                    case(4):
                        letterCount = letterCount + 8;
                        break;
                    case(5):
                        letterCount = letterCount + 7;
                        break;
                    case(6):
                        letterCount = letterCount + 7;
                        break;
                    case(7):
                        letterCount = letterCount + 9;
                        break;
                    case(8):
                        letterCount = letterCount + 8;
                        break;
                    case(9):
                        letterCount = letterCount + 8;
                        break;
                }
                break;
            case(2):
                letterCount = letterCount + 6;
                break;
            case(3):
                letterCount = letterCount + 6;
                break;
            case(4):
                letterCount = letterCount + 5;
                break;
            case(5):
                letterCount = letterCount + 5;
                break;
            case(6):
                letterCount = letterCount + 5;
                break;
            case(7):
                letterCount = letterCount + 7;
                break;
            case(8):
                letterCount = letterCount + 6;
                break;
            case(9):
                letterCount = letterCount + 6;
                break;
        }

        if (test2 != 1)
        {
            switch(test3)
            {
                case(0):
                    break;
                case(1):
                    letterCount = letterCount + 3;
                    break;
                case(2):
                    letterCount = letterCount + 3;
                    break;
                case(3):
                    letterCount = letterCount + 5;
                    break;
                case(4):
                    letterCount = letterCount + 4;
                    break;
                case(5):
                    letterCount = letterCount + 4;
                    break;
                case(6):
                    letterCount = letterCount + 3;
                    break;
                case(7):
                    letterCount = letterCount + 5;
                    break;
                case(8):
                    letterCount = letterCount + 5;
                    break;
                case(9):
                    letterCount = letterCount + 4;
                    break;
            }
        }
    }
    letterCount = letterCount + 11;
    printAnswer2(letterCount);
}

//question 18
//------------------------------------------------------------------------------
void q18Solve()
{
    // this is basically binary max path
    string line[15];
    char trash;
    long numArr[15][15];
    long maxPath[15][15];
    long uno = 0;
    long dos = 0;

    ifstream myfile ("q18.txt");

    for (int i = 0; i < 15; i++)
    {
        getline(myfile, line[i]);
        //myfile.get(trash);
        for (int j = 0; j < 15; j++)
        {
            numArr[i][j] = -1;
            maxPath[i][j] = 0;
        }
    }
    myfile.close();

    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            numArr[i - j][j] = (line[i][3 * j] - '0') * 10 
            + (line[i][3 * j + 1] - '0');
            
        }
        
    }

    // compute incremental max path
    maxPath[0][0] = numArr[0][0];
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            if (numArr[i - j][j] >= 0 && (i > 0 || j > 0))
            {
                // number above
                uno = (i - j > 0)? maxPath[i - j - 1][j] : 0;
                // number left
                dos = (j > 0)? maxPath[i - j][j - 1] : 0;
                
                maxPath[i - j][j] = (uno > dos)? uno : dos;
                maxPath[i - j][j] = maxPath[i - j][j] + numArr[i - j][j];
            }
        }
    }
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            // this finds largest incremental path
            // in this case no negative number so it finds absolute full path
            cout << maxPath[i][j] << ", ";
            maxPath[14][14] = (maxPath[i][j] > maxPath[14][14])?
            maxPath[i][j] : maxPath[14][14];
        }
        cout << endl;
    }
    printAnswer2(maxPath[14][14]);
}

//question 19
//------------------------------------------------------------------------------
void q19Solve()
{
    // year, month, day
    int sundays = 0;
    int dayCount = 0;
    int days[200][12][31];
    for (int i = 0; i < 200; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            for (int k = 0; k < 31; k++)
            {
                days[i][j][k] = -1;
            }
        }
    }

    for (int i = 0; i < 200; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            for (int k = 0; k < 31; k++)
            {
                switch (j)
                {
                    // less than 31 days
                    case(3):
                        days[i][j][k] = (k < 30)? 1 : -1;
                        break;
                    case(5):
                        days[i][j][k] = (k < 30)? 1 : -1;
                        break;
                    case(8):
                        days[i][j][k] = (k < 30)? 1 : -1;
                        break;
                    case(10):
                        days[i][j][k] = (k < 30)? 1 : -1;
                        break;
                    // feb
                    case(1):
                        days[i][j][k] = (k < 28)? 1 : -1;
                        // 29th of feb on leap or every 400 yr century
                        if (k == 29 && ((i + 1900)  % 400 == 0 || 
                        ((i + 1900) % 100 != 0 && (i + 1900) % 4 == 0)))
                        {
                            days[i][j][k] = 1;
                        }
                        break;
                    // 31 days
                    default:
                        days[i][j][k] = 1;
                        break;
                }
                
            }
        }
    }

    for (int i = 0; i < 200; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            for (int k = 0; k < 31; k++)
            {
                if(days[i][j][k] > 0)
                {
                    dayCount = dayCount + days[i][j][k];
                    if(dayCount % 7 > 0)
                    {
                        days[i][j][k] = 0;
                    }
                }
                
            }
        }
    }

    for (int i = 1; i < 101; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            if (days[i][j][0] > 0)
            {
                sundays = sundays + days[i][j][0];
            }
        }
    }
    printAnswer2(sundays);
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
        case(14):
            q14Solve();
            break;
        case(15):
            q15Solve();
            break;  
        case(16):
            q16Solve();
            break;
        case(17):
            q17Solve();
            break; 
        case(18):
            q18Solve();
            break; 
        case(19):
            q19Solve();
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