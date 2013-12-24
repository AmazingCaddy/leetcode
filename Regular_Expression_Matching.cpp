class Solution {
public:
	void test() {
		const char * ss[] = {"aa", "aa", "aaa", "aa", "aa", "ab", "aab"};
		const char * ps[] = {"a", "aa", "aa", "a*", ".*", ".*", "c*a*b"};
		bool res [] = {false, true, false, true, true, true, true};
		int n = 7;
		for (int i = 0; i < n; i ++) {
			bool ans = this->isMatch(ss[i], ps[i]);
			if (ans == res[i]) {
				cout << "YES\n";
			} else {
				cout << "NO\n";
				cout << ans << " " << res[i] << "\n";
			}
		}
	}

	bool isMatch(const char *s, const char *p) {
		if (*p == '\0') {
			return *s == '\0';
		}
		if (*(p + 1) != '*') {
			if(*p == *s || (*p == '.' && *s != '\0')) {
				return this -> isMatch(s + 1, p + 1);
			}
			return false;
		} else {
			while (*p == *s || (*p == '.' && *s != '\0')) {
				if (this -> isMatch(s, p + 2)) {
					return true;
				}
				s++;
			}
			return this -> isMatch(s, p + 2);
		}
	}
};