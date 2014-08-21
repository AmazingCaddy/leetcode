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
#include <sstream>
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
public:
	void test () {
		int A[] = {0,1,0,2,1,0,1,3,2,1,2,1};
		int n = 12;
		int ans = this->trap(A, n);
		cout << ans << "\n";
	}
	int trap(int A[], int n) {
		int* l = new int[n], *r = new int[n];
		int l_max = A[0];
		for (int i = 0; i < n; i ++) {
			if (A[i] >= l_max) {
				l_max = A[i];
			}
			l[i] = l_max;
		}
		int r_max = A[n - 1];
		for (int i = n - 1; i >= 0; i --) {
			if (A[i] >= r_max) {
				r_max = A[i];
			}
			r[i] = r_max;
		}
		int ans = 0;
		for (int i = 0; i < n; i ++) {
			ans += (min(l[i], r[i]) - A[i]);
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
