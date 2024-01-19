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
		vector<int> inorder{3, 9, 2, 1, 5, 7, 6, 8, 4};
		vector<int> postorder{9, 3, 2, 7, 8, 6, 5, 4, 1};
		TreeNode* root = this->buildTree(inorder, postorder);
		this->preorder(root);
		cout << "\n";
		this->del_tree(root);
	}

	void preorder(TreeNode *root) {
		if (root == NULL) {
			return;
		}
		cout << root->val << " ";
		this->preorder(root->left);
		this->preorder(root->right);
	}

	TreeNode * dfs(const vector<int> &inorder, const vector<int> &postorder, int &depth_in, int &depth_post, TreeNode* end) {
		if (depth_post < 0) {
			return NULL;
		}
		TreeNode *parent = new TreeNode(postorder[depth_post --]);
		if (inorder[depth_in] != parent->val) {
			parent->right = this->dfs(inorder, postorder, depth_in, depth_post, parent);
		}
		depth_in --;
		if (end == NULL || (inorder[depth_in] != end->val)) {
			parent->left = this->dfs(inorder, postorder, depth_in, depth_post, end);
		}
		return parent;
	}

	TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
		int depth_in = postorder.size() - 1, depth_post = depth_in;
		return this->dfs(inorder, postorder, depth_in, depth_post, NULL);
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
