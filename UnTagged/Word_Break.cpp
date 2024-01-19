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
private:
	int* dp;
public:
	~Solution() {
		delete []dp;
	}
	void test () {
		string s = "leetcode";
		unordered_set<string> dict{"lee", "leet", "code"};
		if (this->wordBreak(s, dict)) {
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}
	}

	bool wordBreak(string s, unordered_set<string> &dict) {
		int sz = s.size();
		int dp[sz + 5];
		// dp[i] = dp[j] && dict.find(s.substr(j, i - j)) (0 <= j <= i)
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		for (int i = 1; i <= sz; i ++) {
			for (int j = 0; j <= i; j ++) {
				string t = s.substr(j, i - j);
				if (dp[j] && dict.find(t) != dict.end()) {
					dp[i] = 1;
					break;
				}
			}
		}
		int ans = dp[sz];
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