class Solution {
public:
	void test () {
		string strs[] = {
			"PAYPALISHIRING",
			"ABCDEFGHIJKLMNOPQR",
			"ABCDEFGHIJKLMNOPQR",
			"ABCDE"
		};
		int len[] = {
			3,
			5,
			1,
			2
		};
		string expected[] = {
			"PAHNAPLSIIGYIR",
			"AIQBHJPRCGKODFLNEM",
			"ABCDEFGHIJKLMNOPQR",
			"ACEBD"
		};
		int n = 4;
		for (int i = 0; i < n; i ++) {
			string ans = this -> convert(strs[i], len[i]);
			if (ans == expected[i]) {
				cout << "YES\n";	
			} else {
				cout << ans << "\n";
				cout << expected[i] << "\n";
				cout << "NO\n";
			}
		}
	}
	string convert(string s, int nRows) {
		if (nRows == 1) {
			return s;
		}
		int sz = s.size();
		string result(sz, ' ');
		int len = 0;
		for (int i = 0; i < nRows; i ++) {
			int step[] = {(nRows - 1 - i) * 2, i * 2};
			//cout << "step[0] = " << step[0] << " step[1] = " << step[1] << "\n";
			int flag = 1;
			for (int j = i; j < sz; j += step[flag]) {
				flag = 1 - flag;
				if (step[flag]) {
					result[len ++] = s[j];
				}
			}
		}
		return result;
	}
};