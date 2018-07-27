/*
1009 Product of Polynomials (25)（25 point(s)）Questions

This time, you are supposed to find A*B where A and B are two polynomials.

Input Specification:
Each input file contains one test case. Each case occupies 2 lines, and each line contains the information of a polynomial: K N1 a~N1~ N2 a~N2~ ... NK a~NK~, where K is the number of nonzero terms in the polynomial, Ni and a~Ni~ (i=1, 2, ..., K) are the exponents and coefficients, respectively. It is given that 1 <= K <= 10, 0 <= NK < ... < N2 < N1 <=1000.

Output Specification:
For each test case you should output the product of A and B in one line, with the same format as the input. Notice that there must be NO extra space at the end of each line. Please be accurate up to 1 decimal place.

Sample Input
2 1 2.4 0 3.2
2 2 1.5 1 0.5

Sample Output
3 3 3.6 2 6.0 1 1.6

分析：
用float数组可以存储好所有的信息，存储方式是第i个单元存放指数为i的系数。我们只需要像正常计算一样对两个数组进行遍历，将结果存储到第三个数组中就好了。
ps. 由于p1p2p3都有点大，所以我们要想办法优化。我们发现对三个数组进行处理的时候，不需要全部遍历。
由于输入的时候是降幂顺序输入的，所以可以得到多项式的最大次幂（也可以得到最小次幂），所以可以缩小遍历范围。
*/
#include <iostream>
using namespace std;

int main () {
    /*
    @k: 多项式中非0项数
    @n: 这一项的指数
    @a: 这一项的系数
    @max_expo1: 第一个多项式中的最大次幂
    @max_expo2: 第二个多项式中的最大次幂
    @max_expo3: 运算结果的多项式中的最大次幂
    */
    int k, n, max_expo1, max_expo2, max_expo3 = 0;
    float a;
    float p1[1001] = {0.0}, p2[1001] = {0.0}, p3[1000001] = {0.0};
    
    cin >> k;
    
    scanf("%d%f", &n, &a);
    max_expo1 = n;
    p1[n] = a;
    
    for (int i = 1; i < k; i++) {
        scanf("%d%f", &n, &a);
        p1[n] = a;
    }
    
    cin >> k;
    
    scanf("%d%f", &n, &a);
    max_expo2 = n;
    p2[n] = a;
    
    for (int i = 1; i < k; i++) {
        scanf("%d%f", &n, &a);
        p2[n] = a;
    }
    
    for (int i = max_expo1; i >= 0; i--) {
        if (p1[i] == 0) continue;
        for (int j = max_expo2; j >= 0; j--) {
            if (p2[j] == 0) continue;
            p3[i + j] += p1[i] * p2[j];
        }
    }

    
    max_expo3 = max_expo1 + max_expo2;
    
    int count = 0;
    for (int i = 0; i <= max_expo3; i++) {
        if (p3[i] != 0) count++;
    }
    
    cout << count;
    for (int i = max_expo3; i >= 0; i--) {
        if (p3[i] != 0) {
            printf(" %d %.1f", i, p3[i]);
        }
    }
    return 0;
}
