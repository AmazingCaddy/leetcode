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

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

class Solution {
public:
	void print(const vector<vector<int> >&ans) {
		for (int i = 0; i < ans.size(); i ++) {
			for (int j = 0; j < ans[i].size(); j ++) {
				cout << ans[i][j] << " ";
			}
			cout << "\n";
		}
		cout << "\n";
	}

	void test() {
		vector<int> nums{1, 2, 3, 4};
		for (int i = 0; i < nums.size(); i ++) {
			vector<vector<int> > ans = this->generateMatrix(nums[i]);
			this->print(ans);
		}
	}

	vector<vector<int> > generateMatrix(int n) {
		vector<vector<int> > matrix;
		for (int i = 0; i < n; i ++) {
			matrix.push_back(vector<int>(n));
		}
		int total = n * n;
		int num = 1;
		int x = 0, y = -1;
		int dir = 0;
		while (num <= total) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if ((0 <= nx && nx < n) && (0 <= ny && ny < n) && !matrix[nx][ny]) {
				matrix[nx][ny] = num;
				x = nx;
				y = ny;
				num ++;
			} else {
				dir = (dir + 1) % 4;
			}
		}
		return matrix;
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
