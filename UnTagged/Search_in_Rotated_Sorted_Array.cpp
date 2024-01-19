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
private:
	int mod(int a, int p) {
		return a % p;
	}
public:
	void test () {
		int num[] = {4, 5, 6, 7, 0, 1, 2};
		int found[] = {4, 5, 6, 7, 0, 1, 2, -1, 9};
		int n = 9, m = 7;
		for (int i = 0; i < n; i ++) {
			cout << this -> search(num, m, found[i]) << "\n";
		}
	}

	int search(int A[], int n, int target) {
		int reverse_dot = 0;
		for (int i = 1; i < n; i ++) {
			if (A[i - 1] > A[i]) {
				reverse_dot = i;
				break;
			}
		}
		//reverse_dot = n - reverse_dot;
		//cout << "reverse_dot = " << reverse_dot << "\n";
		int l = 0, r = n - 1;
		while (l <= r) {
			int mid = (l + r) / 2;
			//cout << "mid =" << mid << "\n";
			int mmid = this -> mod(mid + reverse_dot, n);
			//cout << "mmid =" << mmid << "\n";
			if (A[mmid] == target) {
				return mmid;
			} else if (A[mmid] > target) {
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		return -1;
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