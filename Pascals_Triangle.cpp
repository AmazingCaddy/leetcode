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
private:
	void print(const vector<vector<int> > &v) {
		for (int i = 0; i < v.size(); i ++) {
			int szj = v[i].size();
			for (int j = 0; j < szj; j ++) {
				if (j) {
					cout << " ";
				}
				cout << v[i][j];
			}
			cout << "\n";
		}
	}
public:
	void test() {
		vector<int> nums{1, 2, 3, 10, 20};
		for (size_t i = 0; i < nums.size(); i ++) {
			vector<vector<int> > ans = generate(nums[i]);
			this->print(ans);
		}
	}

	vector<vector<int> > generate(int numRows) {
		vector<vector<int> > ans;
		for (int i = 0; i < numRows; i ++) {
			vector<int> tmp(i + 1);
			//cout << "size = " << tmp.size() << "\n";
			tmp[0] = tmp[i] = 1;
			for (int j = 1; j < i; j ++) {
			//	cout << "ans[i - 1] = " << ans[i - 1].size() << "\n";
				tmp[j] = ans[i - 1][j - 1] + ans[i - 1][j];
			}
			ans.push_back(tmp);
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
