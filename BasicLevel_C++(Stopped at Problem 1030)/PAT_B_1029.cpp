//
//  main.cpp
//  PAT_B_1029
//
//  Created by 柯延杰 on 2018/7/14.
//  Copyright © 2018 柯延杰. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    string s1, s2, result;
    cin >> s1 >> s2;
    int i = 0, j = 0;
    
    while (i < s1.length() && j < s2.length()){
        if (s1[i] != s2[j]) {
            if (s1[i] >= 'a' && s1[i] <= 'z') {
                s1[i] -= ('a' - 'A');
            }
            if(result.find(s1[i]) == string::npos) result = result + s1[i];
            i++;
        } else {
            i++;
            j++;
        }
    }
    
    if (i < s1.length()) {
        while (i < s1.length()) {
            if (s1[i] >= 'a' && s1[i] <= 'z') {
                s1[i] -= ('a' - 'A');
            }
            if(result.find(s1[i]) == string::npos) result = result + s1[i];
            i++;
        }
    }
    
    cout << result << endl;
    
    return 0;
}
