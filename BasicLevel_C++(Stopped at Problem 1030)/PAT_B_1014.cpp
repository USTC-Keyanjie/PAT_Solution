//
//  main.cpp
//  PAT_B_1014
//
//  Created by 柯延杰 on 2018/7/11.
//  Copyright © 2018 柯延杰. All rights reserved.
//

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
    string s1, s2, s3, s4;
    cin >> s1 >> s2 >> s3 >> s4;
    int i = 0;
    string week[] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    
    char c = 0;
    
    for (i = 0; i < min(s1.length(), s2.length()); i++) {
        c = s1.at(i);
        
        if (c >='A' && c <= 'G' && s1.at(i) == s2.at(i)) {
            break;
        }
    }
    
    cout << week[c - 'A'] << ' ';
    
    for (i++; i < s1.length(); i++) {
        c = s1.at(i);
        if (((c >= '0' && c <= '9') || (c >= 'A' && c <= 'N')) && s1.at(i) == s2.at(i)) {
            break;
        }
    }
    
    if (c >= '0' && c <= '9') cout << '0' << c - '0';
    else cout << c - '0' - 7;
    cout << ':';
    
    for (i = 0; i < min(s3.length(), s4.length()); i++) {
        if (s3.at(i) == s4.at(i) &&
            ((s3.at(i) >= 'A' && s3.at(i) <= 'Z') || (s3.at(i) >= 'a' && s3.at(i) <= 'z'))) {
            printf("%02d", i);
            break;
        }
    }
    
    
    return 0;
}
