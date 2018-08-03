
/*
1015 Reversible Primes (20)（20 point(s)）

A reversible prime in any number system is a prime whose "reverse" in that number system is also a prime. For example in the decimal system 73 is a reversible prime because its reverse 37 is also a prime.
Now given any two positive integers N (< 10^5^) and D (1 < D <= 10), you are supposed to tell if N is a reversible prime with radix D.

Input Specification:
The input file consists of several test cases. Each case occupies a line which contains two integers N and D. The input is finished by a negative N.

Output Specification:
For each test case, print in one line "Yes" if N is a reversible prime with radix D, or "No" if not.

Sample Input:
73 10
23 2
23 10
-2

Sample Output:
Yes
Yes
No

题目大意：
如果一个数本身是素数，而且在d进制下反转后的数在十进制下也是素数，就输出Yes，否则就输出No。

分析：
先判断这个数是否是素数，再将它以d进制反转一下，看反转好的数是否是素数。

*/
#include <iostream>
#include <vector>
using namespace std;

// 将数以d进制反转
int reverse (int n, int d) {
	// @vector<int> v：使用取余法，记录n转为d进制后的余数
	vector<int> v;		
	int reverse = 0;
	int pow = 1;
	while (n > 0) {
		v.push_back(n % d);
		n /= d;
	}

	for (int i = v.size() - 1; i >= 0; i--, pow *= d) {
		reverse += v[i] * pow;
	}
	return reverse;
}

// 判断是否为素数
bool is_prime (int num) {
	if (num == 1) return false;
	for (int i = 2; i * i <= num; i++) {
		if (num % i == 0) 
			return false;
	}
	return true;
}

int main () {
	
	int n, d;
	vector<bool> result;
	
	while(1){
		scanf("%d", &n);
		if (n < 0) break;
		scanf("%d", &d);
		
		if (!is_prime(n)) {
			result.push_back(false);
		} else {
			result.push_back(is_prime(reverse(n, d)));
		}
	}

	for (int i = 0; i < result.size(); i++) {
		string s = (result[i] == true) ? "Yes" : "No";
		cout << s << endl;
	}
	
	return 0;
}