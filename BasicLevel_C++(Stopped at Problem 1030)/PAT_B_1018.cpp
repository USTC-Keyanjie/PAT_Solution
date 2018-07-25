//
//  main.cpp
//  PAT_B_1018
//
//  Created by 柯延杰 on 2018/7/12.
//  Copyright © 2018 柯延杰. All rights reserved.
//

#include <iostream>
using namespace std;

// 0平 1甲胜 2乙胜
int judge (char a, char b) {
    int jia = 0, yi = 0;
    switch(a){
        case 'C': jia = 1;break;
        case 'J': jia = 2;break;
        case 'B': jia = 3;break;
        default:break;
    }
    switch(b){
        case 'C': yi = 1;break;
        case 'J': yi = 2;break;
        case 'B': yi = 3;break;
        default:break;
    }
    
    if (jia - yi == -1 || jia - yi == 2) return 1;
    else if (jia == yi) return 0;
    else return 2;
}

int main() {
    int N;
    cin >> N;
    char a, b;
    int jia_B = 0, jia_C = 0, jia_J = 0;
    int yi_B = 0, yi_C = 0, yi_J = 0;
    int jia_win = 0, yi_win = 0;
    
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        if (judge(a, b) == 1) {
            jia_win++;
            switch (a) {
                case 'B':jia_B++;break;
                case 'C':jia_C++;break;
                case 'J':jia_J++;break;
                default:break;
            }
        } else if (judge(a, b) == 2){
            yi_win++;
            switch (b) {
                case 'B':yi_B++;break;
                case 'C':yi_C++;break;
                case 'J':yi_J++;break;
                default:break;
            }
        }
    }
    
    cout << jia_win << ' ' << N - jia_win - yi_win << ' ' << yi_win << '\n';
    cout << yi_win << ' ' << N - jia_win - yi_win << ' ' << jia_win << '\n';
    
    if (jia_B >= jia_C && jia_B >= jia_J) {
        cout << 'B';
    } else if (jia_C >= jia_J) {
        cout << 'C';
    } else {
        cout << 'J';
    }
    cout << ' ';
    if (yi_B >= yi_C && yi_B >= yi_J) {
        cout << 'B';
    } else if (yi_C >= yi_J) {
        cout << 'C';
    } else {
        cout << 'J';
    }
    return 0;
}
