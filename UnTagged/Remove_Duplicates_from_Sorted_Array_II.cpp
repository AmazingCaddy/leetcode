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
		int num[] = {1, 1, 1, 2, 2, 3};
		int n = 6;
		int len = this->removeDuplicates(num, n);
		for (int i = 0; i < len; i ++) {
			cout << num[i] << " ";
		}
		cout << "\n";
	}

	int removeDuplicates(int A[], int n) {
		if (n == 0) {
			return 0;
		}
		int cnt = 1;
		vector<int> nums, cnts;
		for (int i = 1; i < n; i ++) {
			if (A[i] != A[i - 1]) {
				nums.push_back(A[i - 1]);
				cnts.push_back(cnt);
				cnt = 1;
			} else {
				cnt ++;
			}
		}
		nums.push_back(A[n - 1]);
		cnts.push_back(cnt);
		int len = 0;
		for (int i = 0; i < nums.size(); i ++) {
			int up = min(cnts[i], 2);
			for (int j = 0; j < up; j ++) {
				A[len ++] = nums[i];
			}
		}
		return len;
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
