#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool cmp (int a, int b) {return a > b;}
int main () {
    ios::sync_with_stdio(false);
    int n;
    long long p;
    cin >> n >> p;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    
    sort(v.begin(), v.end());
//    sort(v.begin(), v.end(), cmp);
    int temp = 0, max_size = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = i + max_size; j < n; j++) {
            if (v[j] <= v[i] * p) {
                temp = j - i + 1;
                if (temp > max_size) max_size = temp;
            } else {
                break;
            }
        }
    }
//
// 这个方法逻辑上也可以，只要把上面的两重for循环变成这个就好
// 上面的是从小往大试着扩展，这个是从大往小试着缩起来
// 但是这个方法必须是让数组从大往小排，要自己写cmp排序规则
// 在pat里这个方法有个测试用例会出现TLE，实在不知道什么情况，求求各路大神解答一下～
//    for (int i = 0; n - i > max_size; i++) {
//        for (int j = n - 1; (j - i + 1) > max_size; j--) {
//            if (v[i] <= v[j] * p) {
//                max_size = j - i + 1;
//                break;
//            }
//        }
//    }
    
    cout << max_size << endl;
    return 0;
}
