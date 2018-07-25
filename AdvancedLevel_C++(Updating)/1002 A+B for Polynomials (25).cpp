/*
1002 A+B for Polynomials (25)（25 point(s)）

This time, you are supposed to find A+B where A and B are two polynomials.

Input
Each input file contains one test case. Each case occupies 2 lines, and each line contains the information of a polynomial: K N1 a~N1~ N2 a~N2~ ... NK a~NK~, where K is the number of nonzero terms in the polynomial, Ni and a~Ni~ (i=1, 2, ..., K) are the exponents and coefficients, respectively. It is given that 1 <= K <= 10，0 <= NK < ... < N2 < N1 <=1000.

Output
For each test case you should output the sum of A and B in one line, with the same format as the input. Notice that there must be NO extra space at the end of each line. Please be accurate to 1 decimal place.

Sample Input
2 1 2.4 0 3.2
2 2 1.5 1 0.5

Sample Output
3 2 1.5 1 2.9 0 3.2

Thought: I use an array of length 1001 to represent the sum of the coefficients, and finally only need to process the information in this array.
*/

#include <iostream>
using namespace std;

int main () {
    int k, key, count = 0;
    double value;
    double N[1001] = {0};
    
    for (int i = 0; i < 2; i++) {
        cin >> k;
        for (int j = 0; j < k; j++) {
            cin >> key >> value;
            N[key] += value;
        }
    }
    
    for (int i = 0; i < 1001; i++) if (N[i] != 0) count++;
    cout << count;
    for (int i = 1000; i >= 0; i--) {
        if (N[i] != 0) {
            printf(" %d %.1lf", i, N[i]);
        }
    }
    
    return 0;
}
