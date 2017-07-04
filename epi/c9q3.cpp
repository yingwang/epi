//
//  c9q3.cpp
//  epi
//
//  Created by Ying Wang on 2017-07-04.
//  Copyright © 2017 Ying. All rights reserved.
//

#include "c9q3.hpp"
#include <stack>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

bool IsWellFormed(const string& str)
{
    stack<char> leftStack;
    for (const char& c : str)
    {
        if (c == '[' || c == '(' || c == '{')
        {
            leftStack.emplace(c);
        }
        else
        {
            if (leftStack.empty()) return false;
            if ((c == ']' && leftStack.top() != '[') ||
                (c == '}' && leftStack.top() != '{') ||
                (c == ')' && leftStack.top() != '('))
            {
                return false;
            }
            else
            {
                leftStack.pop();
            }
        }
    }
    return leftStack.empty();
}

void c9q3::Run()
{
    const char* input[] = {"[](){[()]}[]", "[]()[()]}[]", "[](){[[](){[()]}[]([](){[()]}[])]}[]", ""};
    vector<string> v(input, input + 4);
    for (auto const& i : input)
    {
        cout << IsWellFormed(i) << endl;
    }
}
