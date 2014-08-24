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
private:
	vector<int> row;
	bool isValid(int dep) {
		for (int i = 0; i < dep; i ++) {
			// two queues in the same column or diagonal
			if (row[i] == row[dep] || abs(row[i] - row[dep]) == dep - i) {
				return false;
			}
		}
		return true;
	}
public:
	void test() {
		int num[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
		int n = 9;
		int ans = this->maxSubArray(num, n);
		cout << ans << "\n";
	}

	int maxSubArray(int A[], int n) {
		vector<int>dp(n + 1);
		dp[0] = A[0];
		int ans = dp[0];
		for (int i = 1; i < n; i ++) {
			dp[i] = max(dp[i - 1] + A[i], A[i]);
			ans = max(ans, dp[i]);
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
