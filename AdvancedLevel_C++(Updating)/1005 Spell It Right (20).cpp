/*
1005 Spell It Right (20)（20 point(s)

Given a non-negative integer N, your task is to compute the sum of all the digits of N, and output every digit of the sum in English.

Input Specification:
Each input file contains one test case. Each case occupies one line which contains an N (<= 10^100^).

Output Specification:
For each test case, output in one line the digits of the sum in English words. There must be one space between two consecutive words, but no extra space at the end of a line.

Sample Input:
12345

Sample Output:
one five

思路：
1、由于数字很大，我会用字符串接受输入信息；
2、逐字符地遍历此字符串，所得到的字符由于都是数字，所以将字符的ASCII码减去0的ASCII码即可得到它所代表的数值，相加可得各位数字之和；
3、建立一个长度为10的字符串数组，第i个单元表示第i个数字的英文单词；
4、将和转为字符串，逐个字符查表并输出。

Thought: 
Firstly, considerd the number is very large, I will input the number in a string.
Secondly, I would get the sum value by traversing this string character by character. I could get the integer value of this character by subtracting the ASCLL code of 0 from the ASCII code of this character.
Thirdly, I could create an array to represent the English words of each number.
Lastly, I could transfer the sum value to string and traverse the string, and then wo have gotten all the answer by looking up the array.
p.s. This question is similiar with the PAT_B_1002.
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
    string str[]= {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    
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
