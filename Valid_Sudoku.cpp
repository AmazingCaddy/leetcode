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
private:
	bool isValid(int x, int y, vector<vector<char> > &board) {
	}
public:
	void test () {
		vector<vector<char> > board;
		string ch[] = {
			".2738..1..1...6735.......293.5692.8...........6.1745.364.......9518...7..8..6534.", 
			"......52..8.4......3...9...5.1...6..2..7........3.....6...1..........7.4.......3."
		};
		int n = 2;
		for (int t = 0; t < n; t ++) {
			board.clear();
			for (int i = 0; i < 9; i ++) {
				vector<char> v;
				for (int j = 0; j < 9; j ++) {
					v.push_back(ch[t][i * 9 + j]);
				}
				board.push_back(v);
			}
			cout << (this->isValidSudoku(board) ? "Yes": "No") << "\n";
		}
	}

	bool isValidSudoku(vector<vector<char> > &board) {
		// check every row
		for (int i = 0; i < 9; i ++) {
			int cnt[10];
			memset(cnt, 0, sizeof(cnt));
			for (int j = 0; j < 9; j ++) {
				if (board[i][j] != '.') {
					int num = board[i][j] - '0';
					if (num > 9 || num < 1 || cnt[num]) {
						return false;
					}
					cnt[num] ++;
				}
			}
		}
		// check every column
		for (int j = 0; j < 9; j ++) {
			int cnt[10];
			memset(cnt, 0, sizeof(cnt));
			for (int i = 0; i < 9; i ++) {
				if (board[i][j] != '.') {
					int num = board[i][j] - '0';
					if (num > 9 || num < 1 || cnt[num]) {
						return false;
					}
					cnt[num] ++;
				}
			}
		}
		// check every block
		for (int i = 0; i < 3; i ++) {
			for (int j = 0; j < 3; j ++) {
				int s = i * 3, t = j * 3;
				int cnt[10];
				memset(cnt, 0, sizeof(cnt));
				for (int p = 0; p < 3; p ++) {
					for (int q = 0; q < 3; q ++) {
						if (board[s + p][t + q] != '.') {
							int num = board[s + p][t + q] - '0';
							if (num > 9 || num < 1 || cnt[num]) {
								return false;
							}
							cnt[num] ++;
						}
					}
				}
			}
		}
		return true;
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
