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
		double x[] = {1.0, 12.2, 2.3, 10, 20, 3.34};
		int n[] = {-2147483648, 2, 3, 4, 6, 10};
		int len = 6;
		for (int i = 0; i < len; i ++) {
			cout << setiosflags(ios::fixed) << setprecision(6) << this -> pow(x[i], n[i]) << "\n";
		}
	}

	double pow(double x, int n) {
		long long ln = n;
		if (ln < 0) {
			x = 1 / x;
			ln = -ln;
		}
		double ans = 1, d = x;
		while (ln) {
			if (ln & 1) {
				ans *= d;
			}
			d *= d;
			ln >>= 1;
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