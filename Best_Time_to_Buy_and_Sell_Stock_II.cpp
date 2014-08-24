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
#include <stack>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#endif

const int inf = 0x3f3f3f3f;
const double eps = 1e-8;
const double pi = acos(-1.0);
const int maxn = 10004;
TreeNode* idx[maxn];

class Solution {
public:
	void test() {
		vector<int> t1{1, -1, 2, -1, -1, 3};
		int ans = this->maxProfit(t1);
		cout << ans << "\n";
	}

	// greedy
	int maxProfit(vector<int> &prices) {
		int sum = 0;
		if (prices.size() <= 1) {
			return sum;
		}
		for (int i = 1; i < prices.size(); i ++) {
			if (prices[i] > prices[i - 1]) {
				sum += (prices[i] - prices[i - 1]);
			}
		}
		return sum;
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
