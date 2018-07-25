//
//  main.cpp
//  PAT_B_1009
//
//  Created by 柯延杰 on 2018/7/8.
//  Copyright © 2018 柯延杰. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void split (const string & s, vector<string> & v, const string & c) {
    size_t pos1 = 0, pos2;
    pos2 = s.find(c);
    while (pos2 != string::npos) {
        v.push_back(s.substr(pos1, pos2 - pos1));
        pos1 = pos2 + c.length();
        pos2 = s.find(c, pos2 + 1);
    }
    if (pos1 != s.length()) {
        v.push_back(s.substr(pos1));
    }
}

int main() {
    string s;
    getline(cin, s);
    vector<string> v;
    split(s, v, " ");
    reverse(begin(v), end(v));
    
    cout << v[0];
    for (int i = 1; i < v.size(); i++) cout << ' ' << v[i];
    
    
    return 0;
}
