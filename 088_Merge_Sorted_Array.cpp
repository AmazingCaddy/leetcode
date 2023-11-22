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
public:
	void test() {
		int A[] = {-1, 4, 8, 10, 0, 0, 0};
		int B[] = {-4, 2, 3};
		int m = 4, n = 3;
		this->merge(A, m, B, n);
		for (int i = 0; i < n + m; i ++) {
			cout << A[i] << "\n";
		}
	}

	void merge(int A[], int m, int B[], int n) {
		int i, j, k;
		for (i = m - 1, j = n - 1, k = n + m - 1; k >= 0; k --) {
			if (i >= 0 && j >= 0) {
				if (A[i] < B[j]) {
					A[k] = B[j];
					j --;
				} else {
					A[k] = A[i];
					i --;
				}
			} else if (j >= 0) {
				A[k] = B[j];
				j --;
			}
		}
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
