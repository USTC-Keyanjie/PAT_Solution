/*
1008 Elevator (20)（20 point(s)）

The highest building in our city has only one elevator. A request list is made up with N positive numbers. The numbers denote at which floors the elevator will stop, in specified order. It costs 6 seconds to move the elevator up one floor, and 4 seconds to move down one floor. The elevator will stay for 5 seconds at each stop.

For a given request list, you are to compute the total time spent to fulfill the requests on the list. The elevator is on the 0th floor at the beginning and does not have to return to the ground floor when the requests are fulfilled.

Input Specification:
Each input file contains one test case. Each case contains a positive integer N, followed by N positive numbers. All the numbers in the input are less than 100.

Output Specification:
For each test case, print the total time on a single line.

Sample Input:
3 2 3 1

Sample Output:
41

分析：顺序执行，累计时间就好了～
*/
#include <iostream>
using namespace std;

int main () {
    /*
    @n: 停靠楼层数
    @f_now: 当前电梯楼层
    @f_next: 要到达的楼层
    @total: 总时间
    */
    int n, f_now = 0, f_next, total = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> f_next;
        total += (f_next > f_now) ? (f_next - f_now) * 6 : (f_now - f_next) * 4;
        total += 5;
        f_now = f_next;
    }
    cout << total << endl;
    return 0;
}
