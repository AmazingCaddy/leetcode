/*
 *	卡特兰数，出栈的顺序总数，使用一个栈来模拟，求得所有的括号匹配情况
 **/
class Solution {
private:
	int length;
	void dfs(vector<string> &ans, int dep, string str, stack<char> ch_stack) {
		if (dep == this -> length) {
			while (!ch_stack.empty()) {
				str += ch_stack.top();
				ch_stack.pop();
			}
			ans.push_back(str);
			return;
		}
		ch_stack.push(')');
		dfs (ans, dep + 1, str + '(', ch_stack);
		ch_stack.pop();
		string tmp_str = str;
		while (!ch_stack.empty()) {
			tmp_str += ')';
			ch_stack.pop();
			stack<char> tmp_stack = ch_stack;
			tmp_stack.push(')');
			dfs (ans, dep + 1, tmp_str + '(', tmp_stack);
		}
	}
public:
	void test() {
		int n = 5;
		for (int t = 1; t <= n; t ++) {
			vector<string> ans = this->generateParenthesis(t);
			int sz = ans.size();
			cout << "sz = " << sz << "\n";
			for (int i = 0; i < sz; i ++) {
				cout << ans[i] << "\n";
			}
			cout << "\n";
		}
	}
	vector<string> generateParenthesis(int n) {
		this -> length = n;
		std::vector<string> ans;
		stack<char> ch_stack;
		this -> dfs(ans, 0, "", ch_stack);
		return ans;
	}
};
