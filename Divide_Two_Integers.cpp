#define DEBUG

#ifdef DEBUG
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <iomanip>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
#endif

class Solution {
public:
	void test () {
		int dividend[] = {-1, 0, 10, 10000};
		int divisor[] = {2, -100, -2, -9};
		int n = 4;
		for (int i = 0; i < n; i ++) {
			cout << this -> divide(dividend[i], divisor[i]) << "\n";
		}
	}

	int divide(int dividend, int divisor) {
		//cout << "start\n";
		if (dividend == 0 || divisor == 0) {
			return 0;
		}
		int negative = 0;
		if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)) {
			negative = 1;
		}
		long long c = dividend;
		long long d = divisor;
		long long a = abs (c);
		long long b = abs (d);
		//cout << "a = " << a << " b = " << b << " c = " << c << " d = " << d << "\n";
		if (a < b) {
			return 0;
		}
		int ans = 0;
		while (a >= b) {
			int cnt = 1;
			long long sum = b;
			while (sum + sum <= a) {
				sum += sum;
				cnt += cnt;
			}
			a -= sum;
			//cout << "OK\n";
			ans += cnt;
		}
		if (negative) {
			ans = -ans;
		}
		return ans;
	}
};

#ifdef DEBUG
int main(int argc, char const *argv[]) {
	Solution *sol = new Solution();
	sol -> test();
	delete sol;	
	return 0;
}
#endif