#define DEBUG

#ifdef DEBUG
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <map>
#include <unordered_set>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
#endif

const int maxn = 10004;
const int inf = 0x3f3f3f3f;

const double eps = 1e-8;
const double pi = acos(-1.0);

class Solution {
private:
	int mod(int a, int p) {
		return a % p;
	}
public:
	void test () {
		int num[] = {3, 3, 3};
		int found[] = {3, 5, 6, 7, 0, 1, 2, -1, 9};
		int n = 9, m = 2;
		for (int i = 0; i < n; i ++) {
			cout << this -> search(num, m, found[i]) << "\n";
		}
	}

	bool search(int A[], int n, int target) {
		int reverse_dot = 0;
		for (int i = 1; i < n; i ++) {
			if (A[i - 1] > A[i]) {
				reverse_dot = i;
				break;
			}
		}
		//cout << "dot = " << reverse_dot << "\n";
		//if (reverse_dot == -1) {
		//	return A[0] ==target;
		//}
		//reverse_dot = n - reverse_dot;
		//cout << "reverse_dot = " << reverse_dot << "\n";
		int l = 0, r = n - 1;
		while (l <= r) {
			int mid = (l + r) / 2;
			//cout << "mid =" << mid << "\n";
			int mmid = this -> mod(mid + reverse_dot, n);
			//cout << "mmid =" << mmid << "\n";
			if (A[mmid] == target) {
				return true;
			} else if (A[mmid] > target) {
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		return false;
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
