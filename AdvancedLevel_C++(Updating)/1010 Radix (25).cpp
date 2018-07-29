/*
1010 Radix (25)（25 point(s)）

Given a pair of positive integers, for example, 6 and 110, can this equation 6 = 110 be true? The answer is "yes", if 6 is a decimal number and 110 is a binary number.

Now for any pair of positive integers N1 and N2, your task is to find the radix of one number while that of the other is given.

Input Specification:
Each input file contains one test case. Each case occupies a line which contains 4 positive integers:\ N1 N2 tag radix\ Here N1 and N2 each has no more than 10 digits. A digit is less than its radix and is chosen from the set {0-9, a-z} where 0-9 represent the decimal numbers 0-9, and a-z represent the decimal numbers 10-35. The last number "radix" is the radix of N1 if "tag" is 1, or of N2 if "tag" is 2.

Output Specification:
For each test case, print in one line the radix of the other number so that the equation N1 = N2 is true. If the equation is impossible, print "Impossible". If the solution is not unique, output the smallest possible radix.

Sample Input 1:
6 110 1 10

Sample Output 1:
2

Sample Input 2:
1 ab 1 2

Sample Output 2:
Impossible

分析：
 1、输入n1、n2、tag、radix；
 2、将n1转为十进制，存储在n1_dec里
 3、二分搜索，求n，使得n2在n进制的表达方式下与n1_dec的值相同。搜索范围：下界是n2中最大的数，上界是n1_dec。找到就返回n，没有找到返回0；
 4、n不为0就打印n，为0就打印"Impossible"

ps.
 1、这题的数可能会很大很大，用int是不会通过的，所以要用long long的数据类型；
 2、convert函数还是有可能会产生溢出，当溢出时，结果会小于0，所以二分查找中，进制选大了会导致这个数比较大，也有可能会导致这个数过大都溢出小于0了。
 */
#include <iostream>
#include <algorithm>
using namespace std;

// 将字符c转为对应的数值
int ctoi (char c) {
    return isdigit(c) ? (c - '0') : (c - 'a' + 10);
}

//将字符串n内的数，按radix进制转为对应的数值，有可能会导致溢出
long long convert (string n, long long radix) {
    long long result = 0;
    long long power = 1;
    for (auto it = n.rbegin(); it < n.rend(); it++) {
        result += ctoi(*it) * power;
        power *= radix;
    }
    return result;
}

//找出一个进制，使得字符串n内的数按此进制转化刚好等于other_dec的值，如果找到就返回此进制，找不到返回0
long long find_radix (string n, long long other_dec) {
    
    long long low = ctoi(*(max_element(n.begin(), n.end()))) + 1;
    long long high = max(low, other_dec);
    long long mid, result;
    while (low <= high) {
        mid = (low + high) / 2;
        result = convert(n, mid);
        if (result == other_dec) {
            return mid;
        } else if (result > other_dec || result < 0) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return 0;
}

int main () {
    string n1, n2;
    int tag;
    long long radix, result_radix;
    cin >> n1 >> n2 >> tag >> radix;

    if (tag == 2) swap(n1, n2);
    result_radix = find_radix(n2, convert(n1, radix));

    if (result_radix != 0)
        cout << result_radix << endl;
    else
        cout << "Impossible";
    return 0;
}
