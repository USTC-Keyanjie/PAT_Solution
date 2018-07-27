/*
1007 Maximum Subsequence Sum (25)（25 point(s)）

Given a sequence of K integers { N~1~, N~2~, ..., N~K~ }. A continuous subsequence is defined to be { N~i~, N~i+1~, ..., N~j~ } where 1 <= i <= j <= K. The Maximum Subsequence is the continuous subsequence which has the largest sum of its elements. For example, given sequence { -2, 11, -4, 13, -5, -2 }, its maximum subsequence is { 11, -4, 13 } with the largest sum being 20.
Now you are supposed to find the largest sum, together with the first and the last numbers of the maximum subsequence.

Input Specification:
Each input file contains one test case. Each case occupies two lines. The first line contains a positive integer K (<= 10000). The second line contains K numbers, separated by a space.

Output Specification:
For each test case, output in one line the largest sum, together with the first and the last numbers of the maximum subsequence. The numbers must be separated by one space, but there must be no extra space at the end of a line. In case that the maximum subsequence is not unique, output the one with the smallest indices i and j (as shown by the sample case). If all the K numbers are negative, then its maximum sum is defined to be 0, and you are supposed to output the first and the last numbers of the whole sequence.

Sample Input:
10
-10 1 2 3 4 -5 -23 3 7 -21

Sample Output:
10 1 4

分析：
这题是经典的最大和子序列问题，最直接暴力的思路可能就是双层循环，将每一种情况都列举出来。
这种思路肯定是可行的。However, can be better?
其实你不妨画个柱状图，纵坐标代表数值，横坐标就代表第几个数。
求最大和子序列就像是求这个图的一个积分区间，使得这块面积最大。
我们通过一次遍历解决这个问题。
一开始，我们将子序列的左端点尝试性的放在第一个数那里，然后让工作指针向下遍历，尝试扩大这个子序列。
首先，如果把下一个数加进来，那么子序列的总和会增加，那么会有两种情况出现：
1、现在的子序列总和已经超过目前为止所找到的最大和子序列的总和了，那么我就认为现在的子序列才是最大和子序列；
2、现在的子序列总和没有超过最大和子序列，那么不做任何处理，继续向下遍历。 
其次，我们要想通一点，如果此时的和已经为负数了，那么就要果断舍弃前面所有的数，从下一个数开始。
因为带着一个负值继续向下求和，还不如从0开始呢。所以在遍历时，一旦sum小于0了，就将所尝试的子序列左端点设在下一个数。
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    /*
    @left: 目前最大和子序列的左端点
    @right: 目前最大和子序列的右端点
    @i: 搜索子序列的左端点
    @p: 搜索指针/搜索子序列的右端点
    @sum: 搜索子序列的和
    @maxsum: 目前最大和子序列的和
    */
    int left = 0, right = n - 1, i = 0, sum = 0, maxsum = -1;
    for (int p = 0; p < n; p++) {
        cin >> v[p];
        sum += v[p];
        if (sum > maxsum) {
            left = i;
            right = p;
            maxsum = sum;
        } else if (sum < 0) {
            i = p + 1;
            sum = 0;
        }
    }

    maxsum = maxsum < 0 ? 0 : maxsum;
    cout << maxsum << ' ' << v[left] << ' ' << v[right] << endl;
    return 0;
}
