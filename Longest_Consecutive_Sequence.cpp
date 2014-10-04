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
#include <unordered_map>
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
		std::vector<int> num{100, 4, 200, 1, 3, 2};
		cout << this->longestConsecutive(num) << "\n";
	}
	int longestConsecutive(vector<int> &num) {
		int sz = num.size();
		unordered_set<int> hash_table;
		for (int i = 0; i < sz; i ++) {
			hash_table.insert(num[i]);
		}
		int ans = 0;
		for (int i = 0; i < sz; i ++) {
			if (hash_table.find(num[i]) != hash_table.end()) {
				int cnt = 1;
				int cur = num[i] + 1;
				while (hash_table.find(cur) != hash_table.end()) {
					hash_table.erase(cur);
					cnt ++;
					cur ++;
				}
				cur = num[i] - 1;
				while (hash_table.find(cur) != hash_table.end()) {
					hash_table.erase(cur);
					cnt ++;
					cur --;
				}
				hash_table.erase(num[i]);
				ans = max(ans, cnt);
			}
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
