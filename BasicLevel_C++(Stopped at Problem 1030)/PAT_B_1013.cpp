//
//  main.cpp
//  PAT_B_1013
//
//  Created by 柯延杰 on 2018/7/10.
//  Copyright © 2018 柯延杰. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

bool is_prime (int a) {
    for (int i = 2; i * i <= a; i++) {
        if (a % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int count = 0;
    int M, N;
    int num = 2;
    cin >> M >> N;
    vector<int> v;
    int flag = 0;
    
    while (count < N) {
        if (is_prime(num)) {
            count++;
            if (count >= M) {
                v.push_back(num);
            }
        }
        num++;
    }
    
    count = 0;
    for (int i = 0; i < v.size(); i++) {
        if (flag != 0) {
            cout << ' ';
        }
        cout << v[i];
        count++;
        flag = 1;
        if (count % 10 == 0) {
            flag = 0;
            cout << '\n';
        }
    }
    return 0;
}
