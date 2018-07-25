//
//  main.cpp
//  PAT_B_1006
//
//  Created by 柯延杰 on 2018/7/6.
//  Copyright © 2018 柯延杰. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;

bool judge_prime_number(int);
bool condition(int);
int main() {
    
    int n, count = 0;
    cin >> n;
    
    for (int i = 3; i < n - 1; i++) {
        if (condition(i)) {
            count++;
        }
    }
    
    cout << count;
    return 0;
}

bool judge_prime_number(int n) {
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

bool condition(int n1) {
    return judge_prime_number(n1) && judge_prime_number(n1 + 2);
}
