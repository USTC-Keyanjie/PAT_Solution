//
//  main.cpp
//  PAT_B_1025
//
//  Created by 柯延杰 on 2018/7/13.
//  Copyright © 2018 柯延杰. All rights reserved.
//

//这个解法有一个测试用例会TLE，但是感觉这个解法写的还不错，应用型挺强的
#include <iostream>
#include <map>
using namespace std;

struct node {
    int data;
    string next;
};

int main() {
    string first_adr;
    int n, k, count = 0;
    ios::sync_with_stdio(false);
    cin >> first_adr >> n >> k;
    
    map<string, node> m;
    node head_node;
    
    head_node.next = first_adr;
    m.insert(pair<string, node>("head_adr", head_node));
    
    for (int i = 0; i < n; i++) {
        string adr;
        node n;
        cin >> adr >> n.data >> n.next;
        m.insert(pair<string, node>(adr, n));
    }
    
    string head_adr = "head_adr", p = first_adr, p_next, head_next;
    
    for (string pc = first_adr; pc != "-1"; pc = m.find(pc)->second.next) {
        count++;
        if (count == k) {
            count = 0;
            
            m.find(head_adr)->second.next = m.find(pc)->second.next;
            head_next = p;
            
            for (int i = 0; i < k; i++) {
                p_next = m.find(p)->second.next;
                m.find(p)->second.next = m.find(head_adr)->second.next;
                m.find(head_adr)->second.next = p;
                p = p_next;
            }
            
            head_adr = head_next;
            pc = head_adr;
        }
    }
    
    first_adr = m.find("head_adr")->second.next;
    m.erase("head_adr");
    
    map<string, node>::iterator it;
    for (string s = first_adr; s != "-1"; s = m.find(s)->second.next) {
        it = m.find(s);
        cout << it->first << ' ' << it->second.data << ' ' << it->second.next << endl;
    }
    
    return 0;
}
