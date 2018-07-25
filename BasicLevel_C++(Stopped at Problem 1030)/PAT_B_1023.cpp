//
//  main.cpp
//  PAT_B_1023
//
//  Created by 柯延杰 on 2018/7/12.
//  Copyright © 2018 柯延杰. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    int a[10] = {0};
    int flag = 0;
    
    for (int i = 0; i < 10; i++) {
        cin >> a[i];
    }
    
    for (int i = 1; i < 10; i++) {
        if (a[i] != 0) {
            cout << i;
            a[i]--;
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        cout << 0;
        return 0;
    }
    
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < a[i]; j++) {
            cout << i;
        }
    }
    return 0;
}
