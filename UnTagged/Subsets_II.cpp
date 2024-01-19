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
		vector<int> s{1, 2, 2, 2, 3, 3};
		vector<vector<int> > ans = this->subsetsWithDup(s);
		for (int i = 0; i < ans.size(); i ++) {
			cout << "[ ";
			for (int j = 0; j < ans[i].size(); j ++) {
				cout << ans[i][j] << " ";
			}
			cout << "]\n";
		}
	}
	vector<vector<int> > subsetsWithDup(vector<int> &S) {
		vector<vector<int> > ans;
		int sz = S.size();
		if (sz == 0) {
			return ans;
		}
		sort(S.begin(), S.end());
		ans.push_back(vector<int>());
		int last = S[0], opNumber = 1;
		for (int i = 0; i < sz; i ++) {
			if (S[i] != last) {
				last = S[i];
				opNumber = ans.size();
			}
			int ansSize = ans.size();
			for (int j = ansSize - opNumber; j < ansSize; j ++) {
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
