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
	void test() {
		vector<vector<int> > grid{{0, 1, 2, 3}, {2, 3, 1, 5}, {0, 2, 3, 1}};
		cout << this->minPathSum(grid) << "\n";
		for (int i = 0; i < grid.size(); i ++) {
			for (int j = 0; j < grid[i].size(); j ++) {
				cout << grid[i][j] << " ";
			}
			cout << "\n";
		}
	}
	
	int minPathSum(vector<vector<int> > &grid) {
		int n = grid.size();
		if (n == 0) {
			return 0;
		}
		int m = grid[0].size();
		for (int j = 1; j < m; j ++) {
			grid[0][j] = grid[0][j - 1] + grid[0][j];
		}
		for (int i = 1; i < n; i ++) {
			grid[i][0] = grid[i - 1][0] + grid[i][0];
		}
		for (int i = 1; i < n; i ++) {
			for (int j = 1; j < m; j ++) {
				grid[i][j] = min(grid[i - 1][j], grid[i][j - 1]) + grid[i][j];
			}
		}
		return grid[n - 1][m - 1];
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
