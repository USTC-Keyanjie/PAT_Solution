//
//  main.cpp
//  PAT_B_1010
//
//  Created by 柯延杰 on 2018/7/10.
//  Copyright © 2018 柯延杰. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    int a, b;
    int flag = 0;
    while (cin >> a >> b) {
        if (b != 0) {
            if (flag == 1) cout << ' ';
            cout << a * b << ' ' << b - 1;
            flag = 1;
        }
    }
    if (flag == 0) cout << 0 << ' ' << 0;
    return 0;
}
