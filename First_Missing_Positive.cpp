#define DEBUG

#ifdef DEBUG
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
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
		int num[] = {3, 4, -1, 1};
		int n = 4;
		cout << this -> firstMissingPositive(num, n) << "\n";
	}

	int firstMissingPositive(int A[], int n) {
		for (int i = 0; i < n; i ++) {
			if (A[i] > 0 && A[i] < n) {
				if (A[A[i] - 1] != A[i]) {
					swap(A[A[i] - 1], A[i]);
					i --;
				}
			}
		}
		for (int i = 0; i < n; i ++) {
			if (A[i] - 1 != i) {
				return i + 1;
			}
		}
		return n + 1;
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