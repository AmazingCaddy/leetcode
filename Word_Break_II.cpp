#define DEBUG

#ifdef DEBUG
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
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

class Solution {
public:
	void test () {
		string s = "catsanddog";
		unordered_set<string> dict{"cat", "cats", "and", "sand", "dog"};
		vector<string> ans = this->wordBreak(s, dict);
		for (int i = 0; i < ans.size(); i ++) {
			cout << ans[i] << "\n";
		}
	}

	void init(string s, int dp[], unordered_set<string> &dict) {
		// dp[i] = dp[j] && dict.find(s.substr(i, j - i)) (i < j <= n)
		int sz = s.size();
		for (int i = 0; i <= sz; i ++) {
			dp[i] = 0;
		}
		dp[sz] = 1;
		for (int i = sz - 1; i >= 0; i --) {
			for (int j = sz; j > i; j --) {
				string t = s.substr(i, j - i);
				if (dp[j] && dict.find(t) != dict.end()) {
					dp[i] = 1;
					break;
				}
			}
		}
	}

	void dfs(string s, string cur, int st, int dp[], vector<string> &ans, unordered_set<string> &dict) {
		int sz = s.size();
		if (st >= sz) {
			ans.push_back(cur.substr(1));
			//cout << "yes\n";
			return;
		}
		for (int i = st + 1; i <= sz; i ++) {
			string t = s.substr(st, i - st);
			//cout << "t = " << t << "\n";
			if (dict.find(t) != dict.end() && dp[i]) {
				dfs(s, cur + " " + t, i, dp, ans, dict);
			}
		}
	}

	vector<string> wordBreak(string s, unordered_set<string> &dict) {
		int sz = s.size();
		int dp[sz + 5];
		vector<string> ans;
		init(s, dp, dict);
		/*
		for (int i = 0; i <= sz; i ++) {
			cout << "dp[" << i << "] = " << dp[i] << "\n";
		}
		*/
		dfs(s, "", 0, dp, ans, dict);
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