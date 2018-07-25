//
//  main.cpp
//  PAT_B_1002
//
//  Created by 柯延杰 on 2018/7/3.
//  Copyright © 2018 柯延杰. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int main ()
{
    string str[]= {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
    
    string numberStr;
    cin >> numberStr;
    
    int total = 0;
    for (int i = 0; i < numberStr.length(); i++) {
        total += numberStr[i] - '0';
    }
    
    string result = to_string(total);
    
    for (int i = 0; i < result.length(); i++) {
        cout << str[result.at(i) - '0'];
        if (i != result.length() - 1) {
            cout << ' ';
        }
    }

    return 0;
}
