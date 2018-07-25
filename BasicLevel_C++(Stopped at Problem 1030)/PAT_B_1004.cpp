//
//  main.cpp
//  PAT_B_1004
//
//  Created by 柯延杰 on 2018/7/4.
//  Copyright © 2018 柯延杰. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int main() {
    
    int n;
    cin >> n;
    
    int score, max = -1, min = 101;
    string name, ID;
    string maxname, minname, maxID, minID;
    
    for (int i = 0; i < n; i++) {
        cin >> name >> ID >> score;
        if (score > max){
            max = score;
            maxname = name;
            maxID = ID;
        }
        if (score < min) {
            min = score;
            minname = name;
            minID = ID;
        }
    }
    
    cout << maxname << ' ' << maxID << '\n';
    cout << minname << ' ' << minID << '\n';
    
    
    return 0;
}
