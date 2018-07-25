//
//  main.cpp
//  PAT_B_1027
//
//  Created by 柯延杰 on 2018/7/13.
//  Copyright © 2018 柯延杰. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    int n, i, pre_i = 0, a = 3, count = 0;
    char c;
    cin >> n >> c;
    for (i = 1; i <= n; i += a * 2, a += 2) {
        count++;
        pre_i = i;
    }
    
    for (int j = 0; j < count - 1; j++) {
        for (int k = 0; k < j; k++) {
            cout << ' ';
        }
        for (int k = 0; k < (count - j) * 2 - 1; k++) {
            cout << c;
        }
        cout << endl;
    }
    
    for (int j = 0; j < count - 1; j++) {
        cout << ' ';
    }
    cout << c << endl;
    
    for (int j = 0; j < count - 1; j++) {
        for (int k = 0; k < count - j - 2; k++) {
            cout << ' ';
        }
        for (int k = 0; k < (j + 1) * 2 + 1; k++) {
            cout << c;
        }
        cout << endl;
    }
    cout << n - pre_i;
    return 0;
}
