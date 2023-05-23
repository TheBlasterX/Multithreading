//
//  main.cpp
//  Multithreading
//
//  Created by Ștefan Jipa on 23.05.2023.
//

/*
 * Ways to create threads in c++ (11)
 * 1) Funtion pointers
 * 2) Lambda functions
 * 3) Functors
 * 4) Member functions
 * 5) Static member functions
 */

// Check sum of all odd & even numbers separately between 1 to 1900000000

#include <iostream>
#include <thread>

using namespace std;
using namespace std::chrono;

typedef unsigned long long ull;

static ull oddSum = 0;
static ull evenSum = 0;

void checkEvenSum(ull start, ull end) {
    for (ull i = start; i <= end; i++)
    {
        if ( 0 == (i & 1))
        {
            evenSum += i;
        }
    }
}

void checkOddSum(ull start, ull end) {
    for (ull i = start; i <= end; i++)
    {
        if ( 1 == (i & 1))
        {
            oddSum += i;
        }
    }
}

int main(int argc, const char * argv[]) {

    ull start = 0, end = 1900000000;
    auto startTime = high_resolution_clock::now();
    
    thread t1(checkEvenSum, start, end);
    thread t2(checkOddSum, start, end);
    
    t1.join();
    t2.join();
    //checkSum(start, end);
    
    auto stopTime = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stopTime - startTime);
    
    cout << " OddSum is: " << oddSum << "\nEvenSum is: " << evenSum << "\n";
    
    cout << "Seconds: " << duration.count() / 1000000 << " \n";
    
    return 0;
}
