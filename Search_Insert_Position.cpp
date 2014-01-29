#define DEBUG

#ifdef DEBUG
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
#endif

class Solution {
public:
	void test() {
		int num[] = {1, 3, 5, 6};
		int found[] = {1, -1, 5, 2, 7, 0};
		int n = 6;
		for (int i = 0; i < n; i ++) {
			cout << this -> searchInsert(num, 4, found[i]) << "\n";
		}
	}

	int searchInsert(int A[], int n, int target) {
		for (int i = 0; i < n; i ++) {
			if (A[i] >= target) {
				return i;
			}
		}
		return n;
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