#define DEBUG

#ifdef DEBUG
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
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
		string input[] = {
			"()()))))()()(",
			"()()()()()",
			"()",
			"",
			")()())",
			"))))()()()()(((()"
		};
		int n = 6;
		for (int i = 0; i < n; i ++) {
			cout << this -> longestValidParentheses(input[i]) << "\n";
		}
	}

	int longestValidParentheses(string s) {
		int sz = s.size();
		if (sz == 0) {
			return 0;
		}
		int *dp = new int[sz + 1];
		int ans = 0;
		dp[0] = 0;
		for (int i = 1; i < sz; i ++) {
			if (s[i] == ')') {
				int j = i - dp[i - 1] - 1;
				if (j >= 0 && s[j] == '(') {
					dp[i] = dp[i - 1] + 2;
					if (j > 0) {
						dp[i] += dp[j - 1];
					}
				} else {
					dp[i] = 0;
				}
			} else {
				dp[i] = 0;
			}
			//cout << "dp[" << i << "] = " << dp[i] << "\n";
			ans = max (ans, dp[i]);
		}
		delete [] dp;
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