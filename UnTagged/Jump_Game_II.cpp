#define DEBUG

#ifdef DEBUG
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <iomanip>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
#endif

class Solution {
public:
	void test () {
		int num[] = {2, 3, 1, 1, 4};
		int n = 5;
		int num1[] = {1, 5, 2, 7, 1, 1, 6, 2, 4};
		int n1 = 9;
		cout << this -> jump(num, n) << "\n";
		cout << this -> jump(num1, n1) << "\n";
	}

	int jump(int A[], int n) {
		int ans = 0, last = 0, current = 0;
		for (int i = 0; i < n; i ++) {
			if (i > last) {
				last = current;
				ans ++;
			}
			current = max (current, i + A[i]);
		}
		return ans;
	}
};

#ifdef DEBUG
int main(int argc, char const *argv[]) {
	Solution *sol = new Solution();
	sol -> test();
	delete sol;	
	return 0;
}
#endif