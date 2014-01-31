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
	void dfs (int dep, int target, vector<int> num, const vector<int> &candidates, vector<vector<int> > &ans) {
		if (target < 0 || dep > candidates.size()) {
			return;
		}
		if (target == 0) {
			ans.push_back(num);
			return ;
		}
		//this -> dfs(dep + 1, target, sum, num, candidates, ans);
		num.push_back(candidates[dep]);
		this -> dfs(dep + 1, target - candidates[dep], num, candidates, ans);
		num.pop_back();
		while(dep + 1 < candidates.size() && candidates[dep + 1] == candidates[dep]) {
			dep ++;
		}
		this -> dfs (dep + 1, target, num, candidates, ans);	
	}
public:
	void test () {
		vector<int> num;
		// 10,1,2,7,6,1,5
		num.push_back(10);
		num.push_back(1);
		num.push_back(2);
		num.push_back(7);
		num.push_back(6);
		num.push_back(1);
		num.push_back(5);
		vector<vector<int> > ans = this -> combinationSum2(num, 8);
		for (int i = 0; i < ans.size(); i ++) {
			for (int j = 0; j < ans[i].size(); j ++) {
				cout << ans[i][j] << " ";
			}
			cout << "\n";
		}
	}
	vector<vector<int> > combinationSum2(vector<int> &num, int target) {
		vector<std::vector<int> > ans;
		vector<int> v;
		sort(num.begin(), num.end());
		this -> dfs(0, target, v, num, ans);
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