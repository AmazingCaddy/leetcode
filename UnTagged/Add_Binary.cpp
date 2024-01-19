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
	void print(const vector<int>& v) {
		for (int i = 0; i < v.size(); i ++) {
			if (i) {
				cout << " ";
			}
			cout << v[i];
		}
	}
	void test() {
		const string a[] = {"11"};
		const string b[] = {"1"};
		int n = 1;
		for (int i = 0; i < n; i ++) {
			cout << this->addBinary(a[i], b[i]) << "\n";
		}
		cout << "\n";
	}
	string addBinary(string a, string b) {
		int len1 = a.size();
		int len2 = b.size();
		int max_len = max(len1, len2);
		vector<int> aa, bb;
		for (int i = len1 - 1; i >= 0; i --) {
			aa.push_back(a[i] - '0');
		}
		for (int i = max_len; i > len1; i --) {
			aa.push_back(0);
		}
		for (int i = len2 - 1; i >= 0; i --) {
			bb.push_back(b[i] - '0');
		}
		for (int i = max_len; i > len2; i --) {
			bb.push_back(0);
		}
		int carry = 0;
		vector<int> c;
		for (int i = 0; i < max_len; i ++) {
			c.push_back(0);
			c[i] = c[i] + aa[i] + bb[i] + carry;
			carry = c[i] / 2;
			c[i] %= 2;
		}
		if (carry) {
			c.push_back(carry);
		}
		string ans = "";
		int sz = c.size();
		for (int i = 0; i < sz; i ++) {
			ans += (c[sz - 1 - i] + '0');
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
