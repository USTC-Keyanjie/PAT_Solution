//
//  main.cpp
//  PAT_B_1020
//
//  Created by 柯延杰 on 2018/7/12.
//  Copyright © 2018 柯延杰. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct moon_cake {
    double kc;
    double sj;
    double dwsj;
}moon_cake;

bool cmp (moon_cake m1, moon_cake m2) {return m1.dwsj > m2.dwsj;}

int main() {
    int N, D;
    cin >> N >> D;
    
    vector<moon_cake> v(N);
    
    for (int i = 0; i < N; i++) {
        cin >> v[i].kc;
    }
    
    for (int i = 0; i < N; i++) {
        cin >> v[i].sj;
        v[i].dwsj = v[i].sj/v[i].kc;
    }
    
    sort(v.begin(), v.end(), cmp);
    
    double money = 0;
    for (int i = 0; D > 0 && i < v.size(); i++) {
        if(D >= v[i].kc) money += v[i].sj;
        else money += D * v[i].dwsj;
        D -= v[i].kc;
    }
    
    printf("%.2lf", money);
    
    
    return 0;
}
