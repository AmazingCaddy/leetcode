#define DEBUG

#ifdef DEBUG
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <map>
#include <unordered_set>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
#endif

const int maxn = 104;
const int inf = 0x3f3f3f3f;

const double eps = 1e-8;
const double pi = acos(-1.0);

class Solution {
public:
	void test() {
		int num[] = {1, 1, 1, 0};
		int n = 4;
		int ans = this->canJump(num, n);
		cout << ans << "\n";
	}

	bool canJump(int A[], int n) {
		int r_max = A[0];
		for (int i = 1; i < n; i ++) {
			if (i <= r_max) {
				r_max = max(r_max, i + A[i]);
			}
		}
	//	cout << r_max << "\n";
		return r_max >= n - 1;
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
