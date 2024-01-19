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
private:
	ll gcd(ll a, ll b) {
		return b ? this->gcd(b, a % b): a;
	}
public:
	void test() {
		vector<vector<int> > obstacleGrid {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
		cout << this->uniquePathsWithObstacles(obstacleGrid) << "\n";
	}
	
	int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
		int n = obstacleGrid.size();
		if (n == 0) {
			return 0;
		}
		int m = obstacleGrid[0].size();
		vector<vector<int> > dp;
		for (int i = 0; i < n; i ++) {
			dp.push_back(vector<int>(m));
		}
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < m; j ++) {
				if (obstacleGrid[i][j]) {
					dp[i][j] = 0;
					continue;
				}
				if (i == 0 && j == 0) {
					dp[i][j] = 1;
					continue;
				}
				if (i == 0) {
					dp[i][j] = dp[i][j - 1];
					continue;
				}
				if (j == 0) {
					dp[i][j] = dp[i - 1][j];
					continue;
				}
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
		return dp[n - 1][m - 1];
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
