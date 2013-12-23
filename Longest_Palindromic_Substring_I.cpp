class Solution {
public:
	void test () {
		string strs[] = {
			"abduyba",
			"xxabccbayy",
			"abssdba",
		};
		for (int i = 0; i < 3; i ++) {
			string long_s = this -> longestPalindrome(strs[i]);
			cout << long_s << "\n";
		}
	}

	int get_longest(const string &str, int center, int n, int &start) {
		int l1 = center, r1 = center;
		while (l1 >= 0 && r1 < n) {
			if (str[l1] == str[r1]) {
				l1 --;
				r1 ++;
			} else {
				break;
			}
		}
		l1 ++;
		r1 --;
		int len1 = r1 - l1 + 1;
		//cout << "len1 = " << len1 << "\n";
		int l2 = center, r2 = center + 1;
		while (l2 >= 0 && r2 < n) {
			if (str[l2] == str[r2]) {
				l2 --;
				r2 ++;
			} else {
				break;
			}
		}
		l2 ++;
		r2 --;
		int len2 = r2 - l2 + 1;
		//cout << "len2 = " << len2 << "\n";
		if (len1 > len2) {
			start = l1;
			return len1;
		}
		start = l2;
		return len2;
	}

	string longestPalindrome(string s) {
		const int maxn = 1024;
		int ans = 0, ans_start;
		int sz = s.size();
		for (int i = 0; i < sz; i ++) {
			int start;
			int len = this -> get_longest(s, i, sz, start);
			//cout << "start = " << start << "\n";
			if (len > ans) {
				ans = len;
				ans_start = start;
			}
		}
		//cout << "end: "<< ans_start << " " << ans << endl;
		return s.substr(ans_start, ans);
	}
};