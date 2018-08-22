/*
1019 General Palindromic Number (20)（20 point(s)）

A number that will be the same when it is written forwards or backwards is known as a Palindromic Number. For example, 1234321 is a palindromic number. All single digit numbers are palindromic numbers.

Although palindromic numbers are most often considered in the decimal system, the concept of palindromicity can be applied to the natural numbers in any numeral system. Consider a number N > 0 in base b >= 2, where it is written in standard notation with k+1 digits a~i~ as the sum of (a~i~b^i^) for i from 0 to k. Here, as usual, 0 <= a~i~ < b for all i and a~k~ is non-zero. Then N is palindromic if and only if a~i~ = a~k-i~ for all i. Zero is written 0 in any base and is also palindromic by definition.

Given any non-negative decimal integer N and a base b, you are supposed to tell if N is a palindromic number in base b.

Input Specification:

Each input file contains one test case. Each case consists of two non-negative numbers N and b, where 0 <= N <= 10^9^ is the decimal number and 2 <= b <= 10^9^ is the base. The numbers are separated by a space.

Output Specification:

For each test case, first print in one line "Yes" if N is a palindromic number in base b, or "No" if not. Then in the next line, print N as the number in base b in the form "a~k~ a~k-1~ ... a~0~". Notice that there must be no extra space at the end of output.

Sample Input 1:
27 2

Sample Output 1:
Yes
1 1 0 1 1

Sample Input 2:
121 5

Sample Output 2:
No
4 4 1

题目大意：
给出一个数，并且要求按一定进制转换，判断转换好的数是否是回文数

分析：
很简单的进制转换题，只是题目给的数据量还有进制数范围很大，所以我选择用long long数据类型来存储稳妥一些。
这题还要考虑一下0这个数，0是回文数，所以转换函数里我使用do-while循环体，先执行一次循环体内容，可以将0与其他数统一处理。
*/
#include <iostream>
#include <vector>
using namespace std;

string is_palin(vector<long long> result) {
    for(auto i = result.begin(), j = result.end() - 1; i < j; i++, j--)
        if (*i != *j)
            return "No";
    return "Yes";
}

vector<long long> f (long long num, long long base) {
    vector<long long> result;
    long long temp;
    do {
        temp = num % base;
        num /= base;
        result.push_back(temp);
    } while (num > 0);
    return result;
}

int main () {
    long long num, base;
    scanf("%lld%lld", &num, &base);
    vector<long long> result = f(num, base);
    cout << is_palin(result) << endl;
    cout << result[result.size() - 1];
    for (int i = result.size() - 2; i >= 0; i--) {
        printf(" %lld", result[i]);
    }
    
    return 0;
}
