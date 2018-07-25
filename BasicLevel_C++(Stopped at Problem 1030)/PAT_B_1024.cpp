//
//  main.cpp
//  PAT_B_1024
//
//  Created by 柯延杰 on 2018/7/12.
//  Copyright © 2018 柯延杰. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    
    size_t posDot = s.find('.');
    size_t posE = s.find('E');
    int zs = stoi(s.substr(posE + 1));
    int flag = 0;
    
    if (zs < 0) {
        while (zs != 0) {
            if (flag == 0) {
                swap(s[posDot], s[posDot - 1]);
                posDot--;
                if (s[posDot - 1] == '+' || s[posDot - 1] == '-') {
                    s.insert(posDot,1,'0');
                    posE++;
                    flag = 1;
                    posDot++;
                }
            } else {
                s.insert(posDot + 1, 1, '0');
                posE++;
            }
            zs++;
        }
    }
    else if (zs > 0) {
        while (zs != 0) {
            if (flag == 0) {
                swap(s[posDot], s[posDot + 1]);
                posDot++;
                if (posDot + 1 == posE) {
                    s.erase(posDot, 1);
                    posE--;
                    flag = 1;
                }
            } else {
                s.insert(posE, 1, '0');
                posE++;
            }
            
            zs--;
            
        }
    }
    
    s = (s[0] == '+') ? s.substr(1, posE - 1) : s.substr(0, posE);
    cout << s <<endl;

    return 0;
}
