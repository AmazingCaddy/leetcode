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
#include <stack>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#endif

const int inf = 0x3f3f3f3f;
const double eps = 1e-8;
const double pi = acos(-1.0);
const int maxn = 10004;
TreeNode* idx[maxn];

class Solution {
public:
	void test() {
		char const * str[] = {"     ", "a", "  asb s ", "hello world  "};
		int n = 4;
		for (int i = 0; i < n; i ++) {
			cout << this->lengthOfLastWord(str[i]) << "\n";
		}
	}
	int lengthOfLastWord(const char *s) {
		int len = 0;
		int last_len = 0;
		while (*s) {
			if (*s != ' ') {
				len ++;
				s ++;
			} else {
				last_len = len;
				while (*s == ' ') {
					s ++;
				}
				len = 0;
			}
		}
		s --;
		if (*s != ' ') {
			last_len = len;
		}
		return last_len;
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
