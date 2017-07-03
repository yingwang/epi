//
//  c9q2.cpp
//  epi
//
//  Created by Ying Wang on 2017-07-01.
//  Copyright © 2017 Ying. All rights reserved.
//

// evaluate RPN expressions0.202.n

#include "c9q2.hpp"
#include <string>
#include <stack>
#include <sstream>
#include <vector>
#include <iostream>

using namespace std;

int Eval(const string& rpn)
{
    stack<int> intermediate;
    stringstream ss(rpn);
    string token;
    const char delimiter = ',';
    
    while (getline(ss, token, delimiter))
    {
        if (token == "+" || token == "-" || token == "*" || token == "/")
        {
            int y = intermediate.top();
            intermediate.pop();
            int x = intermediate.top();
            intermediate.pop();
            
            switch (token.front()) {
                case '+':
                    intermediate.emplace(x + y);
                    break;
                case '-':
                    intermediate.emplace(x - y);
                    break;
                case '*':
                    intermediate.emplace(x * y);
                    break;
                case '/':
                    intermediate.emplace(x / y);
                    break;
            }
        }
        else
        {
            intermediate.emplace(stoi(token));
        }
    }
    return intermediate.top();
}

void c9q2::Run()
{
    vector<string> tests;
    tests.push_back("1729");
    tests.push_back("3,4,+,2,*,1,+");
    tests.push_back("1,1,+,-2,*");
    for (const auto& t : tests)
    {
        cout << t << " " << Eval(t) <<endl;
    }
}


