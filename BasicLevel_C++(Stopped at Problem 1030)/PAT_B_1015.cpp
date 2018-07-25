//
//  main.cpp
//  PAT_B_1015
//
//  Created by 柯延杰 on 2018/7/11.
//  Copyright © 2018 柯延杰. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct student {
    int id;
    int d_score;
    int c_score;
};

bool cmp (student a, student b) {
    if (a.d_score + a.c_score != b.d_score + b.c_score)
        return a.d_score + a.c_score > b.d_score + b.c_score;
    else if (a.d_score != b.d_score)
        return a.d_score > b.d_score;
    else
        return a.id < b.id;
}

int main() {
    int N, L, H;
    scanf("%d %d %d", &N, &L, &H);
    vector<student> result[4];
    int total = N;
    student s;
    
    ios::sync_with_stdio(false);
    
    for (int i = 0; i < N; i++) {
        cin >> s.id >> s.d_score >> s.c_score;
        if (s.d_score < L || s.c_score < L)
            total--;
        else if (s.d_score >= H && s.c_score >= H)
            result[0].push_back(s);
        else if (s.d_score >= H && s.c_score < H)
            result[1].push_back(s);
        else if (s.d_score < H && s.c_score < H && s.d_score >= s.c_score)
            result[2].push_back(s);
        else
            result[3].push_back(s);
    }
    
    cout << total << '\n';
    for (int i = 0; i < 4; i++) {
        sort(result[i].begin(), result[i].end(), cmp);
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j].id << ' ' << result[i][j].d_score << ' ' << result[i][j].c_score << '\n';
        }
    }
    
    return 0;
}
