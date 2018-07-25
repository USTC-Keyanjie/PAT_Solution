//
//  main.cpp
//  PAT_B_1019
//
//  Created by 柯延杰 on 2018/7/12.
//  Copyright © 2018 柯延杰. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

bool cmp1 (char a, char b) {return a >= b;}
bool cmp2 (char a, char b) {return a <= b;}

int main() {
    string N;
    cin >> N;
    
    string A, B;
    int result = stoi(N);
    N.insert(0, 4 - N.length(), '0');
    
   do {
       A = N;
       sort(A.begin(), A.end(), cmp1);
       B = N;
       sort(B.begin(), B.end(), cmp2);
       
       result = stoi(A) - stoi(B);
       N = to_string(result);
       N.insert(0, 4 - N.length(), '0');
       cout << A << " - " << B << " = " << N << endl;

   } while (result != 0 && result != 6174);
    
    return 0;
}
