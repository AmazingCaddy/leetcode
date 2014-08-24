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
		vector<int> num{1, 1, 2, 3, 3};
		vector<vector<int> > ans = this->permuteUnique(num);
		for (int i = 0; i < ans.size(); i ++) {
			for (int j = 0; j < ans[i].size(); j ++) {
				cout << ans[i][j] << " ";
			}
			cout << "\n";
		}
	}

	int check(int st, int ed, vector<int>& num) {
		for (int i = st; i < ed; i ++) {
			if (num[i] == num[ed]) {
				return 0;
			}
		}
		return 1;
	}

	void dfs(int dep, vector<int> &num, vector<vector<int> > &ans) {
		if (dep == num.size()) {
			ans.push_back(num);
			return;
		}
		for (int i = dep; i < num.size(); i ++) {
			if (check(dep, i, num)) {
				swap(num[dep], num[i]);
				dfs(dep + 1, num, ans);
				swap(num[dep], num[i]);
			}
		}
	}
	
	vector<vector<int> > permuteUnique(vector<int> &num) {
		vector<vector<int> > ans;
		this->dfs(0, num, ans);
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
