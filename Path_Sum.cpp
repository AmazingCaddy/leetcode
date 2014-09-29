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
	void test() {
		vector<int> t1{5, 4, 8, 11, -1, 13, 4, 7, 2, -1, -1, -1, -1, -1, 1};
//		vector<int> t1{1, 2};
		TreeNode* root = make_tree(t1);
		int sum = 22;
		cout << this->hasPathSum(root, sum) << "\n";
		this->del_tree(root);
	}

	void del_tree(TreeNode* root) {
		if (root == NULL) {
			return;
		}
		del_tree(root->left);
		del_tree(root->right);
		delete root;
	}

	TreeNode* make_tree(vector<int> nodes) {
		TreeNode* root = NULL;
		int sz = nodes.size();
		for (int i = 1; i <= sz; i ++) {
			if (nodes[i - 1] != -1) {
				TreeNode* p = new TreeNode(nodes[i - 1]);
				idx[i] = p;
				//cout << "nodes[i - 1]" << nodes[i - 1] << "\n";
				if (root == NULL) {
					root = p;
				} else {
					TreeNode *f = idx[i >> 1];
					//cout << i << " " << f->val << "\n";
					if (i % 2 == 1) {
						f->right = p;
					} else {
						f->left = p;
					}
				}
			}
		}
		return root;
	}

	bool hasPathSum(TreeNode *root, int sum) {
		if (root == NULL) {
			return false;
		}
		if (root->left == NULL && root->right == NULL && root->val == sum) {
			return true;
		}
		int rest = sum - root->val;
		return this->hasPathSum(root->left, rest) || this->hasPathSum(root->right, rest);
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
