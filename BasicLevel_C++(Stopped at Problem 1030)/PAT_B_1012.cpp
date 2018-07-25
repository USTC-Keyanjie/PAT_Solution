//
//  main.cpp
//  PAT_B_1012
//
//  Created by 柯延杰 on 2018/7/10.
//  Copyright © 2018 柯延杰. All rights reserved.
//

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    int number, a;
    cin >> number;
    int A1 = 0, A2 = 0, A3 = 0, A5 = 0;
    double A4 = 0;
    int flag = 0, count = 0;
    double avg_A4 = 0;
    int flag2 = 0;
    
    for (int i = 0; i < number; i++) {
        cin >> a;
        switch (a % 5) {
            case 0: if (a % 2 == 0) A1 += a; break;
            case 1:
                if (flag == 0) {
                    A2 += a;
                    flag = 1;
                } else {
                    A2 -= a;
                    flag = 0;
                }
                flag2 = 1;
                break;
            case 2: A3++;break;
            case 3: A4 += a;count++;break;
            case 4: if (a > A5) A5 = a;break;
            default: break;
        }
    }
    
    if (count == 0) avg_A4 = 0; else avg_A4 = A4 / count;
    if (A1 == 0) cout << 'N'; else cout << A1;
    if (flag2 == 0) cout << ' ' << 'N'; else cout << ' ' << A2;
    if (A3 == 0) cout << ' ' << 'N'; else cout << ' ' << A3;
    if (avg_A4 == 0) cout << ' ' << 'N'; else cout << ' ' << fixed << setprecision(1) << avg_A4;
    if (A5 == 0) cout << ' ' << 'N'; else cout << ' ' << A5;

    return 0;
}
