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
	void print(const vector<int>& v) {
		for (int i = 0; i < v.size(); i ++) {
			if (i) {
				cout << " ";
			}
			cout << v[i];
		}
	}

	vector<TreeNode *> dfs(int left, int right) {
		if (left > right) {
			return vector<TreeNode *>(1, NULL);
		}
		vector<TreeNode *> res;

		for (int k = left; k <= right; k ++) {
			vector<TreeNode *> lt = this->dfs(left, k - 1);
			vector<TreeNode *> rt = this->dfs(k + 1, right);

			for (int i = 0; i < lt.size(); i ++) {
				for (int j = 0; j < rt.size(); j ++) {
					TreeNode *root = new TreeNode(k);
					root->left = lt[i];
					root->right = rt[j];
					res.push_back(root);
				}
			}
		}
		return res;
	}

public:
	void test() {
		vector<TreeNode *> ans = this->generateTrees(3);
		cout << ans.size() << "\n";
	}

	vector<TreeNode *> generateTrees(int n) {
		vector<TreeNode *> ans = this->dfs(1, n);
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
