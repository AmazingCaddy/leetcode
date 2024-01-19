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
		vector<int> num{4, 5, 6};
		for (int i = 0; i < num.size(); i ++) {
			vector<vector<string>> ans = this->solveNQueens(num[i]);
			for (int i = 0; i < ans.size(); i ++) {
				for (int j = 0; j < ans[i].size(); j ++) {
					cout << ans[i][j] << "\n";
				}
				cout << "\n";
			}
			cout << "\n";
		}
	}

	void dfs(int dep, int n, vector<vector<int> >& ans) {
		if (dep == n) {
			ans.push_back(row);
			return;
		}
		for (int i = 0; i < n; i ++) {
			row[dep] = i;
			if (this->isValid(dep)) {
				dfs(dep + 1, n, ans);
			}
		}
	}

	vector<vector<string> > solveNQueens(int n) {
		row.resize(n);
		vector<vector<int> > ans;
		this->dfs(0, n, ans);
		vector<vector<string> > boards;
		for (int i = 0; i < ans.size(); i ++) {
			vector<string> board;
			for (int j = 0; j < n; j ++) {
				board.push_back(string(n, '.'));
				board[j][ans[i][j]] = 'Q';
			}
			boards.push_back(board);
		}
		return boards;
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
