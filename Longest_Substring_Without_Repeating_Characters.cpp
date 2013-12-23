#include <string>
#include <algorithm>
#include <iostream>
#include <string.h>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int hash[128];
		memset(hash, -1, sizeof(hash));
		int start = 0, ans = 0;
		//cout << s.size();
		for (int i = 0; i < s.size(); i ++) {
			if (hash[s[i]] == -1) {
				hash[s[i]] = i;
			} else {
				//cout << "start = " << start << " i = " << i << " hash[s[i]] = " << hash[s[i]] << endl;
				for (int j = start; j < hash[s[i]]; j ++) {
					hash[s[j]] = -1;
				}
				start = hash[s[i]] + 1;
				hash[s[i]] = i;
			}
			ans = max (ans, i - start + 1);
		}
		return ans;
	}
};

int main () {
	string s;
	cin >> s;
	Solution * solution = new Solution();
	cout << solution -> lengthOfLongestSubstring(s) << endl;
	delete solution;
	return 0;
}