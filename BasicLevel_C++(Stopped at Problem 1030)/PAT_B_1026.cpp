//
//  main.cpp
//  PAT_B_1026
//
//  Created by 柯延杰 on 2018/7/13.
//  Copyright © 2018 柯延杰. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double c1, c2;
    cin >> c1 >> c2;
    int time = round((c2 - c1) / 100);
    
    int second = time % 60;
    time /= 60;
    int minute = time % 60;
    time /= 60;
    int hour = time;
    
    printf("%02d:%02d:%02d", hour, minute, second);
    return 0;
}
