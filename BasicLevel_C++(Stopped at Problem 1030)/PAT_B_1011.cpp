//
//  main.cpp
//  PAT_B_1011
//
//  Created by 柯延杰 on 2018/7/10.
//  Copyright © 2018 柯延杰. All rights reserved.
//

#include <iostream>
using namespace std;

string judge (long a, long b, long c) {
    return (a + b > c) ? "true" : "false";
}

int main() {
    int T;
    cin >> T;
    long a[T][3];
    for (int i = 0; i < T; i++) cin >> a[i][0] >> a[i][1] >> a[i][2];
    for (int i = 0; i < T; i++) cout << "Case #" << i + 1 << ": " << judge(a[i][0], a[i][1], a[i][2]) << endl;
    return 0;
}
