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
private:
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
public:
	void test() {
		vector<int> preorder{1, 2, 3, 9, 4, 5, 6, 7, 8};
		vector<int> inorder{3, 9, 2, 1, 5, 7, 6, 8, 4};
		TreeNode* root = this->buildTree(preorder, inorder);
		this->postorder(root);
		cout << "\n";
		this->del_tree(root);
	}

	void postorder(TreeNode *root) {
		if (root == NULL) {
			return;
		}
		this->postorder(root->left);
		this->postorder(root->right);
		cout << root->val << " ";
	}

	TreeNode * dfs(const vector<int> &preorder, const vector<int> &inorder, int &depth_pre, int &depth_in, TreeNode* end) {
		if (depth_pre >= preorder.size()) {
			return NULL;
		}
		TreeNode *parent = new TreeNode(preorder[depth_pre ++]);
		if (inorder[depth_in] != parent->val) {
			parent->left = this->dfs(preorder, inorder, depth_pre, depth_in, parent);
		}
		depth_in ++;
		if (end == NULL || inorder[depth_in] != end->val) {
			parent->right = this->dfs(preorder, inorder, depth_pre, depth_in, end);
		}
		return parent;
	}

	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
		int depth_pre = 0, depth_in = 0;
		return this->dfs(preorder, inorder, depth_pre, depth_in, NULL);
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
