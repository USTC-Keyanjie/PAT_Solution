//
//  main.cpp
//  PAT_B_1028
//
//  Created by 柯延杰 on 2018/7/14.
//  Copyright © 2018 柯延杰. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct person {
    string name;
    int birthday;
};
bool cmp (person p1, person p2) {return p1.birthday < p2.birthday;}
int main() {
    int n;
    cin >> n;
    string birth;
    ios::sync_with_stdio(false);
    vector<person> v;
    for (int i = 0; i < n; i++) {
        person p;
        cin >> p.name >> birth;
        birth.erase(4, 1);
        birth.erase(6, 1);
        p.birthday = stoi(birth);
        if (p.birthday >= 18140906 && p.birthday <= 20140906) v.push_back(p);
    }
    sort(v.begin(), v.end(), cmp);
    if (v.size() != 0) cout << v.size() << ' ' << v[0].name << ' ' << v[v.size() - 1].name << endl;
    else cout << 0 << endl;
    return 0;
}
