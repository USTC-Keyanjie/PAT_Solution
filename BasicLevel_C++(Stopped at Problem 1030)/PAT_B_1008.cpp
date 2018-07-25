//
//  main.cpp
//  PAT_B_1008
//
//  Created by 柯延杰 on 2018/7/8.
//  Copyright © 2018 柯延杰. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    
    for (int i = 1; i <= m; i++) {
        int temp = v[n - 1];
        for (int j = n - 1; j > 0; j--) {
            v[j] = v[j - 1];
        }
        v[0] = temp;
    }
    
    cout << v[0];
    for (int i = 1; i < n; i++) cout << ' ' << v[i];
    return 0;
}
