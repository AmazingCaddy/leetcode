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
		int num[] = {1, 1, 1, 2, 3, 2, 3};
		int n = 7;
		int ans = this->singleNumber(num, n);
		cout << ans << "\n";
	}

	int singleNumber(int A[], int n) {
		int sum = 0;
		for (int i = 0; i < n; i ++) {
			sum ^= A[i];
		}
		sum ^= 0;
		return sum;
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
