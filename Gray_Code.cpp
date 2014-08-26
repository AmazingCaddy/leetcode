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
		vector<int> nums{0, 1, 2, 3};
		for (int i = 0; i < nums.size(); i ++) {
			vector<int> ans = this->grayCode(nums[i]);
			for (int j = 0; j < ans.size(); j ++) {
				cout << ans[j] << " ";
			}
			cout << "\n";
		}
	}

	vector<int> grayCode(int n) {
		vector<int> ans{0};
		for (int i = 0; i < n; i ++) {
			int mask = 1 << i;
			for (int j = 0; j < mask; j ++) {
				ans.push_back(ans[mask - 1 - j] | mask);
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
