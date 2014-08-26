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
	bool isValidSudoku(vector<vector<char> > &board) {
		int n = board.size();
		for (int i = 0; i < n; i ++) {
			int m = board[i].size();
			for (int j = 0; j < m; j ++) {
				if (!check()) {
					return false;
				}
			}
		}
	}
	return true;
};

#ifdef DEBUG
int main(int argc, char const *argv[]) {
	Solution *sol = new Solution();
	sol -> test();
	delete sol;	
	return 0;
}
#endif