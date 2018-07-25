/*
1001 A+B Format (20)（20 point(s)）

Calculate a + b and output the sum in standard format -- that is, the digits must be separated into groups of three by commas (unless there are less than four digits).

Input
Each input file contains one test case. Each case contains a pair of integers a and b where -1000000 <= a, b <= 1000000. The numbers are separated by a space.

Output
For each test case, you should output the sum of a and b in one line. The sum must be written in the standard format.

Sample Input
-1000000 9

Sample Output
-999,991

Thought: Before outputting each number, I will check whether the condition is met.
And the condition is (i % 3 == result.length() % 3 && i != 0 && i != result.length() - 1).
if i point to the first element or the last element, I won't output the ','
*/

#include <iostream>
using namespace std;

int main () {
    int a, b;
    cin >> a >> b;
    int c = a + b;
    if (c < 0) cout << '-';
    // the abs function unified positive and negative processing
    string result = to_string(abs(c));
    for (int i = 0; i < result.length(); i++) {
        if (i % 3 == result.length() % 3 && i != 0 && i != result.length() - 1) cout << ',';
        cout << result[i];
    }
    return 0;
}
