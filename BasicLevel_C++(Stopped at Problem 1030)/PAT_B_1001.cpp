//
//  main.cpp
//  PAT_B_1001
//
//  Created by 柯延杰 on 2018/7/3.
//  Copyright © 2018 柯延杰. All rights reserved.
//

#include <iostream>
using namespace std;

int main()
{
    int a;
    cin>>a;
    
    int count = 0;
    
    if(a > 0)
        while(a != 1)
        {
            if ((a & 1) == 1)
                a = (a * 3 + 1) / 2;
            else
                a /= 2;
            
            count++;
        }
    
    cout<<count<<endl;
    return 0;
}
