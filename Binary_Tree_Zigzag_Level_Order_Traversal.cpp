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
		vector<int> t1{3, 9, 20, -1, -1, 15, 7};
		TreeNode* root = make_tree(t1);
		vector<vector<int> > ans = this->zigzagLevelOrder(root);
		for (int i = 0; i < ans.size(); i ++) {
			for (int j = 0; j < ans[i].size(); j ++) {
				cout << ans[i][j] << " ";
			}
			cout << "\n";
		}
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

	vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
		vector<vector<int> > ans;
		if (root == NULL) {
			return ans;
		}
		stack<TreeNode *> travel;
		travel.push(root);
		int level = 0;
		while (!travel.empty()) {
			ans.push_back(vector<int>());
			stack<TreeNode *> tmp_stack;
			while (!travel.empty()) {
				TreeNode* cur = travel.top();
			//	cout << "cur->val = " << cur->val << "\n";
				ans.back().push_back(cur->val);
				travel.pop();
				if (level % 2) {
					if (cur->right) {
						tmp_stack.push(cur->right);
					}
					if (cur->left) {
						tmp_stack.push(cur->left);
					}
				} else {
					if (cur->left) {
						tmp_stack.push(cur->left);
					}
					if (cur->right) {
						tmp_stack.push(cur->right);
					}
				}
			}
			travel = tmp_stack;
			level ++;
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
