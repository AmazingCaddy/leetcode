class Solution {
public:
	void test () {
		const char *strs[] = {
			"1221423423423424234234324324",
			"-122342342343",
			"0",
			"1",
			"-1",
			"sads000",
			"sadskf213232sdsfer",
			"sadskf-213232sdsfer",
			"+2147483647",
			"-2147483648",
			"spd2147483647asds",
			".,.-2147483648sadas",
			"+2147483648",
			"-2147483680",
			" b11228552307"
		};
		int expected[] = {
			INT_MAX,
			INT_MIN,
			0,
			1,
			-1,
			0,
			0,
			0,
			INT_MAX,
			INT_MIN,
			0,
			0,
			INT_MAX,
			INT_MIN,
			0
		};
		int n = 15;
		for (int i = 0; i < n; i ++) {
			int ans = this -> atoi (strs[i]);
			if (ans == expected[i]) {
				cout << "YES\n";
			} else {
				cout << "NO\n";
				cout << ans << " " << expected[i] << "\n";
			}
		}
	}

	int atoi(const char *str) {
		int sz = strlen (str);
		int i = 0;
		while (i < sz) {
			if (!isspace(str[i])) {
				break;
			}
			i ++;
		}
		if (i == sz) {
			return 0;
		}
		int flag;
		if (str[i] >= '0' && str[i] <= '9') {
			flag = 1;
		} else if (str[i] == '-') {
			flag = -1;
			i ++;
		} else if (str[i] == '+') {
			flag = 1;
			i ++;
		} else {
			return 0;
		}
		long long ans = 0;
		int vis = 0;
		while (i < sz) {
			if (str[i] >= '0' && str[i] <= '9') {
				ans = ans * 10 + str[i] - '0';
			} else {
				vis = 1;
			}
			if (ans * flag > INT_MAX) {
				return INT_MAX;
			}
			if (ans * flag < INT_MIN) {
				return INT_MIN;
			}
			if (vis) {
				return ans * flag;
			}
			i++;
		}
		return ans * flag;
	}
};
