class Solution {
public:
	void test () {
		int numbers [] = {
			0,
			1,
			-1,
			22,
			1000001,

		};
		int expected [] = {
			true,
			true,
			false,
			true,
			true
		};
		int n = 5;
		for (int i = 0; i < n; i ++) {
			bool ans = this -> isPalindrome (numbers[i]);
			if (ans == expected[i]) {
				cout << "YES\n";
			} else {
				cout << "NO\n";
				cout << ans << " " << expected[i] << "\n";
			}
		}
	}

	bool isPalindrome(int x) {
		if (x < 0) {
			return false;
		}
		if (x == 0) {
			return true;
		}
		long long palindrome = 0;
		int y = x;
		while (x) {
			palindrome = palindrome * 10 + x % 10;
			x /= 10;
		}
		return palindrome == y;
	}
};
