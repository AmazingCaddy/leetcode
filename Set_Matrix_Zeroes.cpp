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
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
#endif

const int maxn = 10004;
const int inf = 0x3f3f3f3f;

const double eps = 1e-8;
const double pi = acos(-1.0);

class Solution {
public:
	void test() {
		vector<vector<int> > matrix {
			vector<int>{1, 0, 2, 3, 4, 5},
			vector<int>{2, 2, 3, 4, 5, 6},
			vector<int>{3, 1, 3, 5, 7, 8}
		};
		this->setZeroes(matrix);
		for (int i = 0; i < matrix.size(); i ++) {
			for (int j = 0; j < matrix[i].size(); j ++) {
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	void setZeroes(vector<vector<int> > &matrix) {
		int n = matrix.size();
		if (n == 0) {
			return ;
		}
		int m = matrix[0].size();
		bool row = false, col = false;
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < m; j ++) {
				if (matrix[i][j] == 0) {
					matrix[i][0] = 0;
					matrix[0][j] = 0;
					if (i == 0) {
						row = true;
					}
					if (j == 0) {
						col = true;
					}
				}
			}
		}
		for (int i = 1; i < n; i ++) {
			for (int j = 1; j < m; j ++) {
				if (matrix[i][0] == 0 || matrix[0][j] == 0) {
					matrix[i][j] = 0;
				}
			}
		}
		if (row) {
			for (int j = 0; j < m; j ++) {
				matrix[0][j] = 0;
			}
		}
		if (col) {
			for (int i = 0; i < n; i ++) {
				matrix[i][0] = 0;
			}
		}
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
