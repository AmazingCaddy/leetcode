class Solution {
public:
	void test() {
		string inputs[] = {
			"I",
			"IX",
			"MMCD"
		};
		for (int i = 0; i < 3; i ++) {
			cout << this->romanToInt(inputs[i]) << "\n";
		}
	}
	int romanToInt(string s) {
		int alphnum[128];
		alphnum['I'] = 1;
		alphnum['V'] = 5;
		alphnum['X'] = 10;
		alphnum['L'] = 50;
		alphnum['C'] = 100;
		alphnum['D'] = 500;
		alphnum['M'] = 1000;
		int sum = 0;
		for (int i = 0; i < s.size(); i ++) {
			sum += alphnum[s[i]];
			if (i > 0 && alphnum[s[i - 1]] < alphnum[s[i]]) {
				sum -= 2 * alphnum[s[i - 1]];
			}
		}
		return sum;
	}
};
