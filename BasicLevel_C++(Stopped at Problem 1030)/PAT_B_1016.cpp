//
//  main.cpp
//  PAT_B_1016
//
//  Created by 柯延杰 on 2018/7/12.
//  Copyright © 2018 柯延杰. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    string A, B;
    char DA, DB;
    cin >> A >> DA >> B >> DB;
    size_t posA = A.find(DA), posB = B.find(DB);
    int PA = 0, PB = 0;
    
    while (posA != string::npos) {
        PA = PA * 10 + (DA - '0');
        posA = A.find(DA, posA + 1);
    }
    
    while (posB != string::npos) {
        PB = PB * 10 + (DB - '0');
        posB = B.find(DB, posB + 1);
    }
    
    cout << PA + PB << endl;
    
    return 0;
}
