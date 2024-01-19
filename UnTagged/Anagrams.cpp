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
		vector<string> strs{"", "abc", "xxx", "yy", "tea", "ate", "sdsad"};
		vector<string> ans = this->anagrams(strs);
		for (int i = 0; i < ans.size(); i ++) {
			cout << ans[i] << "\n";
		}
	}

	vector<string> anagrams(vector<string> &strs) {
		vector<string> ans;
		map<string, int> visit;
		int sz = strs.size();
		for (int i = 0; i < sz; i ++) {
			string s = strs[i];
			sort(s.begin(), s.end());
			if (visit.find(s) == visit.end()) {
				visit[s] = i;
			} else {
				if (visit[s] >= 0) {
					ans.push_back(strs[visit[s]]);
					visit[s] = -1;
				}
				ans.push_back(strs[i]);
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
