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
		vector<vector<int> > matrix{{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 50}};
		vector<int> needle{0, 1, 9, 20, 60};
		for (int i = 0; i < needle.size(); i ++) {
			cout << this->searchMatrix(matrix, needle[i]) << "\n";
		}
	}
	
	bool searchMatrix(vector<vector<int> > &matrix, int target) {
		if (matrix.size() == 0 || matrix[0].size() == 0) {
			return false;
		}
		int l = 0, r = matrix.size() - 1;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (matrix[mid][0] == target) {
				return true;
			}
			if (matrix[mid][0] > target) {
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		int row = r;
		//cout << "row = " << row << "\n";
		if (row < 0) {
			return false;
		}
		l = 0, r = matrix[row].size() - 1;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (matrix[row][mid] == target) {
				return true;
			}
			if (matrix[row][mid] > target) {
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		return false;
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
