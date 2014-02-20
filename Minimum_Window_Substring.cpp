#define DEBUG

#ifdef DEBUG
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <iomanip>
#include <map>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
#endif

class Solution {
public:
	void test () {
		string s = "a";
		string t = "b";
		cout << this -> minWindow(s, t) << "\n";
	}

	string minWindow(string S, string T) {
		int s_len = S.size(), t_len = T.size();
		if (s_len < t_len) {
			return "";
		}
		int hascnt[128], needcnt[128];
		//int cnt = t;
		memset(hascnt, 0, sizeof(hascnt));
		memset(needcnt, 0, sizeof(needcnt));
		for (int i = 0; i < t_len; i ++) {
			needcnt[T[i]] ++;
		}
		int cnt = 0;
		for (int i = 0; i < t_len; i ++) {
			hascnt[S[i]] ++;
			if (hascnt[S[i]] <= needcnt[S[i]]) {
				cnt ++;
			}
		}
		int st = 0, ed = t_len;
		int ans = s_len + 1, ans_st = 0;
		while (ed <= s_len) {
			if (cnt == t_len) {
				while (st < ed) {
					if (hascnt[S[st]] > needcnt[S[st]]) {
						hascnt[S[st]] --;
						st ++;
					} else {
						break;
					}
				}
				if (ans > ed - st) {
					ans = ed - st;
					ans_st = st;
				}
				hascnt[S[st]] --;
				cnt --;
				st ++;
			} else {
				hascnt[S[ed]] ++;
				if (hascnt[S[ed]] <= needcnt[S[ed]]) {
					cnt ++;
				}
				ed ++;
			}
		}
		if (ans == s_len + 1) {
			return "";
		}
		return S.substr(ans_st, ans);
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