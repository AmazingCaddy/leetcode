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
private:
	bool check(map<string, int> &hashMap, const string &S, int start, int len, int sz) {
		//cout << "len = " << len << " sz = " << sz << "\n";
		map<string, int> cur;
		for (int j = 0; j < len * sz; j += len) {
			//cout << start + j << "\n";
			string sub_str = S.substr(start + j, len);
			//cout << sub_str << "\n";
			if (hashMap.find(sub_str) == hashMap.end()) {
				return false;
			}
			cur[sub_str] ++;
			if (cur[sub_str] > hashMap[sub_str]) {
				return false;
			}
		}
		return true;
	}
public:
	void test () {
		string S = "barfoothefoobarman";
		//cout << S.size() << "\n";
		vector<string> L;
		L.push_back("foo");
		L.push_back("bar");
		vector<int> ans = this -> findSubstring(S, L);
		for (int i = 0; i < ans.size(); i ++) {
			cout << ans[i] << " ";
		}
		cout << "\n";
	}

	vector<int> findSubstring(string S, vector<string> &L) {
		int sz = L.size();
		vector<int> ans;
		if (sz == 0) {
			return ans;
		}
		int len = L[0].size();
		int s_len = S.size();
		if (s_len < len * sz) {
			return ans;
		}
		map<string, int> hashMap;
		for (int i = 0; i < sz; i ++) {
			hashMap[L[i]] ++;
		}
		//for (map<string, int>::iterator iter = hashMap.begin(); iter != hashMap.end(); iter ++) {
		//	cout << iter->first << " " << iter-> second << "\n";		
		//}
		for (int i = 0; i + len * sz - 1 < s_len; i ++) {
			if (this -> check(hashMap, S, i, len, sz)) {
				ans.push_back(i);
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