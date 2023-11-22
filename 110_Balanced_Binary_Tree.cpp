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
	int is_balanced(TreeNode* root) {
		if (root == NULL) {
			return 0;
		}
		int left = this->is_balanced(root->left);
		int right = this->is_balanced(root->right);
		if (left == -1 || right == -1) {
			return -1;
		}
		if (abs(left - right) > 1) {
			return -1;
		}
		return max(left, right) + 1;
	}

	void test() {
	}
	
	bool isBalanced(TreeNode *root) {
		return this->is_balanced(root) != -1;
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
