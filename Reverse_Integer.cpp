#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
	void test() {
		int number[] = {0, 1, -1202132005, 1000, -987};
		int n = 5;
		for (int i = 0; i < n; i ++) {
			cout << this -> reverse(number[i]) << "\n";
		}
	}
	int reverse(int x) {
		int ans = 0;
		while (x) {
			ans = ans * 10 + (x % 10);
			x /= 10;
		}
		return ans;
	}
};

int main (int argc, char *argv[]) {
	Solution * sol = new Solution();
	sol -> test();
	delete sol;
	return 0;
}