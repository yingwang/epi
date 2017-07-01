//
//  c9q1.cpp
//  epi
//
//  Created by Ying Wang on 2017-06-30.
//  Copyright © 2017 Ying. All rights reserved.
//

// implement a stack with max API

#include "c9q1.h"
#include <iostream>

bool MaxStack::Empty()
{
    return stackElement.empty();
}

int MaxStack::Max()
{
    return stackMaxWithCount.top().max;
}

int MaxStack::Top()
{
    return stackElement.top();
}

void MaxStack::Pop()
{
    int x = stackElement.top();
    if (x == stackMaxWithCount.top().max)
    {
        if (stackMaxWithCount.top().count > 1)
        {
            stackMaxWithCount.top().count--;
        }
        else
        {
            stackMaxWithCount.pop();
        }
    }
    stackElement.pop();
}

void MaxStack::Push(int x)
{
    stackElement.push(x);
    if (stackMaxWithCount.empty() || x > stackMaxWithCount.top().max)
    {
        stackMaxWithCount.push(MaxWithCount{x , 1});
    }
    else if (x == stackMaxWithCount.top().max)
    {
        stackMaxWithCount.top().count++;
    }
}

void MaxStack::Test()
{
    MaxStack ms;
    int input[] = {1, 6, 5, 5, 9, 9, 10, 3, 6};
    for (const auto& i : input)
    {
        ms.Push(i);
        cout << ms.Max() << endl;
    }
}
