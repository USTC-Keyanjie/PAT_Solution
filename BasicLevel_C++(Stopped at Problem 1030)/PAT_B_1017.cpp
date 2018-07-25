//
//  main.cpp
//  PAT_B_1017
//
//  Created by 柯延杰 on 2018/7/12.
//  Copyright © 2018 柯延杰. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    string A, Q = "0";
    int B;
    cin >> A >> B;

    int bcs, shang, R = 0;

    for (int i = 0; i < A.length(); i++) {
        bcs = R * 10 + (A[i] - '0');
        shang = bcs / B;
        R = bcs % B;
        Q = Q + (char)(shang + '0');
    }

    size_t pos = Q.find_first_not_of('0');
    Q = (pos != string::npos) ? Q.substr(pos) : "0";

    cout << Q << ' ' << R << endl;
    
    return 0;
}
