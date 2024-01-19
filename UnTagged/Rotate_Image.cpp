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
		vector<vector<int>> image{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
		this->rotate(image);
		for (int i = 0; i < image.size(); i ++) {
			for (int j = 0; j < image[i].size(); j ++) {
				cout << image[i][j] << " ";
			}
			cout << "\n";
		}
	}
	
	void rotate(vector<vector<int> > &matrix) {
		if (matrix.size() == 0) {
			return;
		}
		int temp = matrix[0][0];
		int n = matrix.size();
		for (int i = 0; i < n / 2; i ++) {
			for (int j = i; j < n - 1 - i; j ++) {
				int ni = i, nj = j;
				temp = matrix[ni][nj];
				//printf ("(%d, %d) = %d\n", ni, nj, temp);
				for (int k = 0; k < 3; k ++) {
					int x = n - 1 - nj, y = ni;
					//printf ("(%d, %d) -> (%d, %d)\n", x, y, ni, nj);
					matrix[ni][nj] = matrix[x][y];
					ni = x;
					nj = y;
				}
				//printf ("%d -> (%d, %d)\n", temp, ni, nj);
				matrix[ni][nj] = temp;
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
