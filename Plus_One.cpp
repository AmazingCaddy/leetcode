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
		vector<int> nums{9};
		vector<int> ans = this->plusOne(nums);
		for (int i = 0; i < ans.size(); i ++) {
			cout << ans[i];
		}
		cout << "\n";
	}

	vector<int> plusOne(vector<int> &digits) {
		vector<int> ans;
		reverse(digits.begin(), digits.end());
		int cal = 0;
		digits[0] += 1;
		for (int i = 0; i < digits.size(); i ++) {
			cal = digits[i] / 10;
			if (i + 1 < digits.size()) {
				digits[i + 1] += cal;
			}
			digits[i] %= 10;
		}
		ans = digits;
		if (cal) {
			ans.push_back(1);
		}
		reverse(ans.begin(), ans.end());
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
