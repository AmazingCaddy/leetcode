class Solution {
public:
	void test() {
		std::vector<string> v;
		v.push_back("abcdef");
		v.push_back("abcde");
		v.push_back("abcdefghi");
		cout << this->longestCommonPrefix(v) << "\n";
	}
	string longestCommonPrefix(vector<string> &strs) {
		int ans = 0;
		string res = "";
		if (strs.size() == 0) {
			return res;
		}
		while (1) {
			if (strs[0].size() <= ans) {
				break;
			}
			char common = strs[0][ans];
			int flag = 0;
			for (int i = 1; i < strs.size(); i ++) {
				if (strs[i].size() <= ans || strs[i][ans] != common) {
					flag = 1;
					break;
				}
			}
			if (flag) {
				break;
			}
			res = res + common;
			ans ++;
		}
		return res;
	}
};