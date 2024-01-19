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

#define RED 0
#define WHITE 1
#define BLUE 2

class Solution {
public:
	void test() {
		int nums[] = {2, 0, 0, 2};
		int n = 4;
		this->sortColors(nums, n);
		for (int i = 0; i < n; i ++) {
			cout << nums[i] << " ";
		}
		cout << "\n";
	}
	
	int sortColors(int A[], int n) {
		int white_start = 0, white_end = 0, blue_start = n - 1;
		while (white_end <= blue_start) {
			if (A[white_end] == RED) {
				// 保证交换过来的是 white 也就是 1
				swap(A[white_end], A[white_start]);
				white_start ++;
				white_end ++;
			} else if (A[white_end] == BLUE) {
				// white_end 保持不动，因为不确定blue_start位置交换过来的内容
				swap(A[white_end], A[blue_start]);
				blue_start --;
			} else {
				white_end ++;
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
