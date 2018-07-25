//
//  main.cpp
//  PAT_B_1021
//
//  Created by 柯延杰 on 2018/7/12.
//  Copyright © 2018 柯延杰. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    string N;
    cin >> N;
    int a[10] = {0};
    
    for (int i = 0; i < N.length(); i++) {
        a[N[i]-'0']++;
    }
    
    for (int i = 0; i < 10; i++) {
        if (a[i] > 0) {
            cout << i << ":" << a[i] << "\n";
        }
    }
    return 0;
}
