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
		vector<int> nums{1, 2, 3, 4, 5};
		for (int i = 0; i < nums.size(); i ++) {
			int ans = this->numTrees(nums[i]);
			cout << ans << "\n";
		}
	}

	vector<vector<long long> > init() {
		vector<vector<long long > > C;
		for (int i = 0; i < 50; i ++) {
			vector<long long> tmp(i + 1);
			tmp[0] = tmp[i] = 1;
			for (int j = 1; j < i; j ++) {
				tmp[j] = C[i - 1][j - 1] + C[i - 1][j];
			}
			C.push_back(tmp);
		}
		return C;
	}

	// Catalan Numbers
	int numTrees(int n) {
		vector<vector<long long> > C = this->init();
		//cout << "OK\n";
		return C[n << 1][n] / (n + 1);
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
