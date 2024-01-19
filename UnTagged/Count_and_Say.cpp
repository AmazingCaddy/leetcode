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
	void test() {
		vector<int> ns{0, 1, 2, 3, 4, 5};
		for (int i = 0; i < ns.size(); i ++) {
			cout << this->countAndSay(ns[i]) << "\n";
		}
	}

	string gao(string in) {
		int sz = in.size();
		stringstream ss;
		int cnt = 0;
		char last = in[0];
		for (int i = 0; i < sz; i ++) {
			if (in[i] != last) {
				ss << cnt << last;
				last = in[i];
				cnt = 1;
			} else {
				cnt ++;
			}
		}
		ss << cnt << last;
		//cout << ss.str() << "\n";
		return ss.str();
	}

	string countAndSay(int n) {
		string s = "1";
		for (int i = 1; i < n; i ++) {
			s = this->gao(s);
		}
		return s;
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
