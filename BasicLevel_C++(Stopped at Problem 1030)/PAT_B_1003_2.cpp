//
//  main.cpp
//  PAT_B_1003_2
//
//  Created by 柯延杰 on 2018/7/4.
//  Copyright © 2018 柯延杰. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

bool judge1(string str);

int main() {
    
    int count = 0;
    cin >> count;
    for (int i = 0; i < count; i++) {
        string str;
        cin >> str;
        size_t posP = str.find('P');
        if (posP != string::npos) {
            size_t posT = str.find('T');
            if (posT != string::npos) {
                string a = str.substr(0, posP);
                string aa = str.substr(posT + 1, str.length());
                string A = str.substr(posP + 1, posT - posP - 1);
                
                if (judge1(a) && judge1(aa) && judge1(A)) {
                    if (A.length() == 0){
                        cout << "NO" << "\n";
                    } else if(A.length() * a.length() == aa.length()) {
                        cout << "YES" << "\n";
                    } else {
                        cout << "NO" << "\n";
                    }
                    
                } else {
                    cout << "NO" << "\n"; //不都是A
                }
            } else {
                cout << "NO" << "\n"; // 就没有一个T的出口
            }
        } else {
            cout << "NO" << "\n"; // 就没有一个P的出口
        }
    }
    return 0;
}

bool judge1(string str){
    for (int i = 0; i < str.length(); i++) {
        if (str.at(i) != 'A') {
            return false;
        }
    }
    return true;
}
