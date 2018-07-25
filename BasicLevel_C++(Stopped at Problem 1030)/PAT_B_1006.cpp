//
//  main.cpp
//  PAT_B_1006
//
//  Created by 柯延杰 on 2018/7/6.
//  Copyright © 2018 柯延杰. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    
    int n;
    cin >> n;
    
    int B, S, G;
    B = n / 100;
    for (int i = 0; i < B; i++) cout << 'B';
    S = (n - 100 * B) / 10;
    for (int i = 0; i < S; i++) cout << 'S';
    G = n % 10;
    for (int i = 1; i <= G; i++) cout << i;
    return 0;
}
