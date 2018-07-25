//
//  main.cpp
//  PAT_B_1022
//
//  Created by 柯延杰 on 2018/7/12.
//  Copyright © 2018 柯延杰. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;

int main() {
    int a, b, c, D;
    cin >> a >> b >> D;
    c = a + b;
    
    stack<int> s;
    while (c > 0) {
        s.push(c % D);
        c /= D;
    }
    
    if (s.empty()) {
        cout << 0;
    }
    
    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }
    
    return 0;
}
