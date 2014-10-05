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
		vector<int> s{1, 2, 3};
		vector<vector<int> > ans = this->subsets(s);
		for (int i = 0; i < ans.size(); i ++) {
			cout << "[ ";
			for (int j = 0; j < ans[i].size(); j ++) {
				cout << ans[i][j] << " ";
			}
			cout << "]\n";
		}
	}
	vector<vector<int> > subsets(vector<int> &S) {
		vector<vector<int> > ans;
		sort(S.begin(), S.end());
		int sz = S.size();
		ans.push_back(vector<int>());
		for (int i = 0; i < sz; i ++) {
			int ansSize = ans.size();
			for (int j = 0; j < ansSize; j ++) {
				ans.push_back(ans[j]);
				ans.back().push_back(S[i]);
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
