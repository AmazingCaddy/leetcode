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
	int lower_bound(int A[], int l, int r, int target) {
		int ans = -1;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (A[mid] >= target) {
				ans = mid;
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		if (ans == -1) {
			ans = r + 1;
		}
		return ans;
	}

	int upper_bound(int A[], int l, int r, int target) {
		int ans = -1;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (A[mid] > target) {
				ans = mid;
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		if (ans == -1) {
			ans = r + 1;
		}
		return ans;
	}
public:
	void test () {
		int num[] = {5, 7, 7, 8, 8, 8, 8, 10};
		int num_len = 8;
		int found[] = {-1, 5, 7, 8, 10, 11};
		int found_len = 6;
		for (int i = 0; i < found_len; i ++) {
			vector<int> ans = this -> searchRange(num, num_len, found[i]);
			cout << "[" << ans[0] << ", " << ans[1] << "]\n";
		}
	}

	vector<int> searchRange(int A[], int n, int target) {
		vector<int> ans;
		int l = this -> lower_bound(A, 0, n - 1, target);
		int r = this -> upper_bound(A, 0, n - 1, target);
		if (A[l] != target) {
			l = -1;
			r = 0;
		}
		ans.push_back(l);
		ans.push_back(r - 1);
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