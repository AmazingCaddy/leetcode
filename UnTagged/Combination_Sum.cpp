#define DEBUG

#ifdef DEBUG
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
#endif

class Solution {
private:
	void dfs (int dep, int target, int sum, vector<int> num, const vector<int> &candidates, vector<vector<int> > &ans) {
		if (sum > target) {
			return;
		}
		if (sum == target) {
			ans.push_back(num);
			return ;
		}
		for (int i = dep; i < candidates.size(); i ++) {
			num.push_back(candidates[i]);
			this -> dfs(i, target, sum + candidates[i], num, candidates, ans);
			num.pop_back();
		}
	}
public:
	void test () {
		vector<int> num;
		// [8,7,4,3], 11
		num.push_back(8);
		num.push_back(7);
		num.push_back(4);
		num.push_back(3);
		vector<vector<int> > ans = this -> combinationSum(num, 11);
		for (int i = 0; i < ans.size(); i ++) {
			for (int j = 0; j < ans[i].size(); j ++) {
				cout << ans[i][j] << " ";
			}
			cout << "\n";
		}
	}

	vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
		vector<vector<int> > ans;
		vector<int> v;
		sort(candidates.begin(), candidates.end());
		this -> dfs(0, target, 0, v, candidates, ans);
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