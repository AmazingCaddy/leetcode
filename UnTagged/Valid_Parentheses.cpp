class Solution {
public:
	void test () {
		string input[] = {
			"[({{}(){}[][()()()]([])})]",
			"{(}{)}[()]",
			"[]",
			"()",
			"{}",
			"{}[]()(((((((())))))))"
		};
		int n = 6;
		for (int i = 0; i < n; i ++) {
			cout << this -> isValid(input[i]) << endl;
		}
	}
	bool isValid(string s) {
		stack<char> parentheses_stack;
		parentheses_stack.push('#');
		int sz = s.size();
		for (int i = 0; i < sz; i ++) {
			char top_char = parentheses_stack.top();
			if (top_char == '#') {
				parentheses_stack.push(s[i]);
				continue;
			}
			if ((top_char == '(' && s[i] == ')') || 
				(top_char == '{' && s[i] == '}') ||
				(top_char == '[' && s[i] == ']')) {
				parentheses_stack.pop();
			} else {
				parentheses_stack.push(s[i]);
			}
		}
		return parentheses_stack.size() == 1;
	}
};