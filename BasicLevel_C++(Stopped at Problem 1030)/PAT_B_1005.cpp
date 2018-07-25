//
//  main.cpp
//  PAT_B_1005
//
//  Created by 柯延杰 on 2018/7/4.
//  Copyright © 2018 柯延杰. All rights reserved.
//

#include <iostream>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    map<int, int> map;
    int temp;
    
    for (int i = 0; i < n; i++) {
        cin >> temp;
        map[temp] = 1;
    }
    
    return 0;
}
