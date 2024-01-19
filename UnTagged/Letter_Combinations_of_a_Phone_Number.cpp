class Solution {
private:
	string num[10];
	void init() {
		num[2] = "abc";
		num[3] = "def";
		num[4] = "ghi";
		num[5] = "jkl";
		num[6] = "mno";
		num[7] = "pqrs";
		num[8] = "tuv";
		num[9] = "wxyz";
	}
	void dfs(vector<string> & ans, int dep, const string& str, const string &digits) {
		if (digits.size() == dep) {
			ans.push_back(str);
			return;
		}
		string temp = this -> num[digits[dep] - '0'];
		int sz = temp.size();
		for (int i = 0; i < sz; i ++) {
			this -> dfs(ans, dep + 1, str + temp[i], digits);
		}
	}
public:
	void test() {
		string input[] = {
			"23"
		};
		int n = 1;
		for (int i = 0; i < n; i ++) {
			vector<string> ans = this -> letterCombinations(input[i]);
			for (int j = 0; j < ans.size(); j ++) {
				cout << ans[j] << "\n";
			}
		}
	}
	vector<string> letterCombinations(string digits) {
		vector<string> ans;
		this -> init();
		this -> dfs(ans, 0, "", digits);
		return ans;
	}
};
