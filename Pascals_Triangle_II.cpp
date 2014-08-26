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

const int maxn = 10004;
const int inf = 0x3f3f3f3f;

const double eps = 1e-8;
const double pi = acos(-1.0);

class Solution {
public:
	void print(const vector<int> &v) {
		for (int i = 0; i < v.size(); i ++) {
			if (i) {
				cout << " ";
			}
			cout << v[i];
		}
		cout << "\n";
	}
	void test() {
		vector<int> nums{0, 1, 2, 3, 10, 20};
		for (size_t i = 0; i < nums.size(); i ++) {
			vector<int> ans = getRow(nums[i]);
			this->print(ans);
		}
	}
	vector<int> getRow(int rowIndex) {
		vector<vector<int> > dp(2);
		rowIndex ++;
		dp[0].resize(rowIndex);
		dp[1].resize(rowIndex);
		int flag = 0;
		for (int i = 1; i <= rowIndex; i ++) {
			dp[flag][0] = dp[flag][i - 1] = 1;
			for (int j = 1; j < i; j ++) {
				dp[flag][j] = dp[1 - flag][j - 1] + dp[1 - flag][j];
			}
			flag = 1 - flag;
		}
		return dp[1 - flag];
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
