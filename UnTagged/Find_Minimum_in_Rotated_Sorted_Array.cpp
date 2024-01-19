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
		vector<int> num {10, 18, 0, 1, 2, 3, 5};
		cout << this->findMin(num) << "\n";
	}

	int findMin(vector<int> &num) {
		int sz = num.size();
		int l = 0, r = sz - 1, mid;
		while (l <= r) {
			if (num[l] < num[r]) {
				return num[l];
			}
			if (l == r) {
				return num[l];
			}
			if (l + 1 == r) {
				return num[l] < num[r] ? num[l] : num[r];
			}
			mid = (l + r) / 2;
			if (num[mid] <= num[r]) {
				r = mid;
			} else {
				l = mid;
			}
		}
		return num[l];
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
