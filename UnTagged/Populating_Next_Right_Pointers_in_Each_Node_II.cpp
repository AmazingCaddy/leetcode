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

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
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
	}

	void connect(TreeLinkNode *root) {
		if (root == NULL) {
			return;
		}
		TreeLinkNode *rootNext = root->next;
		TreeLinkNode *next = NULL;
		while (rootNext) {
			if (rootNext->left) {
				next = rootNext->left;
				break;
			}
			if (rootNext->right) {
				next = rootNext->right;
				break;
			}
			rootNext=rootNext->next;
		}

		if (root->left) {
			if (root->right) {
				root->left->next = root->right;
			} else {
				root->left->next = next;
			}
		}
		if (root->right) {
			root->right->next = next;
		}
		// should do right first;
		this->connect(root->right);
		this->connect(root->left);
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
