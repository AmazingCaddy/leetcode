#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
	void test() {
		std::vector<int> v;
		// -1 0 1 2 -1 -4
		v.push_back(-1);
		v.push_back(0);
		v.push_back(1);
		v.push_back(2);
		v.push_back(-1);
		v.push_back(-4);
		vector<vector<int> > res = this->threeSum(v);
		for (int i = 0; i < res.size(); i ++) {
			cout << "[" << res[i][0] << "," << res[i][1] << "," << res[i][2] << "]\n";
		}
	}

	vector<vector<int> > threeSum(vector<int> &num) {
		vector<vector<int> > res;
		sort(num.begin(), num.end());
		int sz = num.size();
		for (int i = 0; i < sz; i ++) {
			if (i > 0 && num[i] == num[i - 1]) {
				continue;
			}
			int l = i + 1, r = sz - 1;
			while (l < r) {
				if (num[i] + num[l] + num[r] == 0) {
					vector<int> ans(3);
					ans[0] = num[i];
					ans[1] = num[l];
					ans[2] = num[r];
					res.push_back(ans);
					int ll = num[l];
					while (l < r && num[l] == ll) {
						l ++;
					}
					int rr = num[r];
					while (l < r && num[r] == rr) {
						r --;
					}
				} else if (num[i] + num[l] + num[r] < 0) {
					l ++;
				} else {
					r --;
				}
			}
		}
		return res;
	}
};

int main (int argc, char *argv[]) {
	Solution *sol = new Solution();
	sol->test();
	delete sol;
	return 0;
}