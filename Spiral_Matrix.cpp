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
	void print(const vector<int> &ans) {
		for (int i = 0; i < ans.size(); i ++) {
			if (i) {
				cout << " ";
			}
			cout << ans[i];
		}
		cout << "\n";
	}

	void test() {
		vector<vector<int> > g{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
		vector<int> ans = this->spiralOrder(g);
		this->print(ans);
		vector<vector<int> > f{{2, 3}};
		this->print(this->spiralOrder(f));
	}

	vector<int> spiralOrder(vector<vector<int> > &matrix) {
		vector<int> ans;
		vector<vector<int> > visit;
		int n = matrix.size();
		if (n == 0) {
			return ans;
		}
		int m = matrix[0].size();
		//cout << n << " " << m << "\n";
		for (int i = 0; i < n; i ++) {
			visit.push_back(vector<int>(m));
		}
		int total = n * m;
		int x = 0, y = -1;
		int dir = 0;
		while (total > 0) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if ((0 <= nx && nx < n) && (0 <= ny && ny < m) && !visit[nx][ny]) {
				visit[nx][ny] = 1;
				//cout << matrix[nx][ny] << "\n";
				ans.push_back(matrix[nx][ny]);
				x = nx;
				y = ny;
				total --;
			} else {
				dir = (dir + 1) % 4;
			}
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
