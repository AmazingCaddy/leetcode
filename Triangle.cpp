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

typedef long long ll;

const int maxn = 10004;
const int inf = 0x3f3f3f3f;
const double eps = 1e-8;
const double pi = acos(-1.0);

class Solution {
public:
	void test() {
		vector<vector<int> >triangle{{-1}, {-2, -3}};
		int ans = this->minimumTotal(triangle);
		cout << ans << "\n";
	}
	int minimumTotal(vector<vector<int> > &triangle) {
		int sz = triangle.size();
		vector<int> dp[2];
		dp[0] = dp[1] = vector<int>(sz);
		int flag = 0;
		dp[0][0] = triangle[0][0];
		for (int i = 1; i < sz; i ++) {
			flag = 1 - flag;
			dp[flag][0] = dp[1 - flag][0] + triangle[i][0];
			dp[flag][i] = dp[1 - flag][i - 1] + triangle[i][i];
			for (int j = 1; j < i; j ++) {
				dp[flag][j] = min(dp[1 - flag][j - 1], dp[1 - flag][j]) + triangle[i][j];
			}
		}
		int ans = 0x7fffffff;
		for (int j = 0; j < sz; j ++) {
			//cout << dp[flag][j] << " ";
			if (ans > dp[flag][j]) {
				ans = dp[flag][j];
			}
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
