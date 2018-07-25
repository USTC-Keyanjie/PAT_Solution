//
//  main.cpp
//  PAT_B_1003
//
//  Created by 柯延杰 on 2018/7/3.
//  Copyright © 2018 柯延杰. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

bool judge(string);
bool judge1(string);
bool judge2(string);
bool judge3(string);
bool judge4(string, string);

int main(){
    string str;
    int count;
    cin >> count;
    int record[100] = {0};

    for (int i = 0; i < count; i++) {
        cin >> str;
        if (judge(str)) {
            record[i] = 1;
        } else {
            record[i] = 0;
        }
    }
    
    for (int i = 0; i < count; i++) {
        cout << (record[i] == 1 ? "YES" : "NO") << "\n";
    }
    
    return 0;
}

//总判断函数
bool judge(string str){
    if (judge1(str) && judge2(str)) {
        return true;
    } else {
        if (judge3(str)) {
            return true;
        } else {
            return false;
        }
    }
}

//判段是否仅有PAT三个字母
bool judge1(string str){
    for (int i = 0; i < str.length(); i++) {
        if (str.at(i) != 'P' && str.at(i) != 'A' && str.at(i) != 'T') {
            return false;
        }
    }
    return true;
}

//判断是否符合xPATx这个条件
//若符合条件，返回一个整数，表示'P'这个字母的pos
//若不符合条件，返回-1
bool judge2(string str){
    size_t posPAT = str.find("PAT");
    while(posPAT != string::npos) {
        string x1 = str.substr(0, posPAT);
        string x2 = str.substr(posPAT + 3);
        if (x1.compare(x2) == 0) {
            return true;
        } else {
            posPAT = str.find("PAT", posPAT + 1);
        }
    }
    return false;
}

//判断是否符合aPbATca这个条件
//若符合条件，返回判断aPbTc的结果
//若不符合条件，返回false
bool judge3(string str){
    size_t posP = str.find('P');
    while (posP != string::npos) {
        size_t posAT = str.find("AT", posP + 1);
        while (posAT != string::npos) {
            string a = str.substr(0, posP);
            string ca = str.substr(posAT + 2);
            if (judge4(a, ca)) {
                string m = str.substr(0, posAT) + str.substr(posAT + 1, ca.length() - a.length() + 1);
                if (judge(m)) {
                    return true;
                }
            }
            posAT = str.find("AT", posAT + 1);
        }
        posP = str.find('P', posP + 1);
    }
    return false;
}

//判断a是否是ca的末尾子串
bool judge4(string a, string ca) {
    if (a.length() <= ca.length()) {
        unsigned long offset = ca.length() - a.length();
        for(int i = a.length() - 1; i >= 0; i--) {
            if (a.at(i) != ca.at(i + offset)) {
                return false;
            }
        }
        return true;
    } else {
        return false;
    }
}
