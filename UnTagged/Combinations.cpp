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
		int n = 4, k = 2;
		vector<vector<int> > ans = this->combine(n, k);
		for (int i = 0; i < ans.size(); i ++) {
			for (int j = 0; j < ans[i].size(); j ++) {
				cout << ans[i][j] << " ";
			}
			cout << "\n";
		}
	}

	void dfs(int dep, int k, int n, vector<int> &num, vector<vector<int> > & ans) {
		if (!k) {
			ans.push_back(num);
			return ;
		}
		for (int i = dep; i <= n; i ++) {
			num.push_back(i);
			this->dfs(i + 1, k - 1, n, num, ans);
			num.pop_back();
		}
	}

	vector<vector<int> > combine(int n, int k) {
		vector<vector<int> > ans;
		vector<int> num;
		this->dfs(1, k, n, num, ans);
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
