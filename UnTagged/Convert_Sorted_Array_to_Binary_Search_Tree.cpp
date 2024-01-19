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
	void print(const vector<int>& v) {
		for (int i = 0; i < v.size(); i ++) {
			if (i) {
				cout << " ";
			}
			cout << v[i];
		}
	}

	void treePrint(TreeNode* root) {
		if (root == NULL) {
			return;
		}
		treePrint(root->left);
		cout << root->val << "\n";
		treePrint(root->right);
	}

	int isBlanced(TreeNode* root) {
		if (root == NULL) {
			return 0;
		}
		int left = this->isBlanced(root->left);
		int right = this->isBlanced(root->right);
		if (left == -1 || right == -1) {
			return -1;
		}
		if (abs(left - right) > 1) {
			return -1;
		}
		return max(left, right) + 1;
	}

	void test() {
		vector<int> t1{1, 2, 4, 6, 7, 9, 11, 14, 20, 30};
		TreeNode* root = this->sortedArrayToBST(t1);
		//this->treePrint(root);
		int ans = this->isBlanced(root);
		cout << (ans == -1 ? "No": "Yes") << "\n";
	}
	
	TreeNode *make_tree(int l, int r, vector<int> &num) {
		if (r <= l) {
			return NULL;
		}
		if (l + 1 == r) {
			TreeNode *p = new TreeNode(num[l]);
			return p;
		}
		int mid = (l + r) / 2;
		TreeNode *left = this->make_tree(l, mid, num);
		TreeNode *right = this->make_tree(mid + 1, r, num);
		TreeNode *p = new TreeNode(num[mid]);
		p->left = left;
		p->right = right;
		return p;
	}

	TreeNode *sortedArrayToBST(vector<int> &num) {
		TreeNode *root = this->make_tree(0, num.size(), num);
		return root;
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
