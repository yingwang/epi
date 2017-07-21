//
//  c9q1.h
//  epi
//
//  Created by Ying Wang on 2017-07-01.
//  Copyright © 2017 Ying. All rights reserved.
//

#ifndef c9q1_h
#define c9q1_h

#include <stack>

using namespace std;

class MaxStack {
public:
    bool Empty();
    int Max();
    int Top();
    void Pop();
    void Push(int x);
    void Test();
    
private:
    stack<int> stackElement;
    struct MaxWithCount {
        int max, count;
    };
    stack<MaxWithCount> stackMaxWithCount;
};

#endif /* c9q1_h */
