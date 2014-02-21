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

const int maxn = 750;
const int maxm = 5;
const int maxt = 750 * 4;

class Solution {
private:
	int S[maxn], O[maxn]; // S[] 列链表中结点的总数  O[] 记录搜索结果
	int L[maxt], R[maxt], U[maxt], D[maxt];  // 四个方向
	int C[maxt], W[maxt];  // C[]列指针头  W[]行指针头
	int mat[maxn][maxm];  // 稀疏矩阵
	int present[maxn];
	int ANS;
	// 邻接矩阵的build函数
	void build (int n, int m) {
		int i, j, t, tot = m, first;
		R[0] = 1; L[0] = m;
		for (i = 1; i <= m; i ++) {
			L[i] = i - 1; R[i] = (i + 1) % (m + 1);
			U[i] = D[i] = C[i] = i; S[i] = 0;
		}
		for (i = 1; i <= n; i ++) {
			first = 0;
			for (j = 1; j <= mat[i][0]; j ++) {
				tot ++;
				t = mat[i][j];
				U[tot] = U[t]; D[tot] = t;
				D[U[t]] = tot; U[t] = tot;
				if (first == 0) first = L[tot] = R[tot] = tot;
				else {
					L[tot] = L[first]; R[tot] = first;
					R[L[first]] = tot; L[first] = tot;
				}
				W[tot] = i; C[tot] = t; S[t]++;
			}
		}
	}

	void remove (int c) {
		int i, j;
		//remove column c and all row i that A[i][c] == 1
		L[R[c]] = L[c];
		R[L[c]] = R[c];
		//remove column c;
		for (i = D[c]; i != c; i = D[i]) {
			//remove i that A[i][c] == 1
			for (j = R[i]; j != i; j = R[j]) {
				U[D[j]] = U[j];
				D[U[j]] = D[j];
				S[C[j]]--;
				//decrease the count of column C[j];
			}
		}
	}

	void resume (int c) {
		int i, j;
		for (i = U[c]; i != c; i = U[i]) {
			for (j = L[i]; j != i; j = L[j]) {
				S[C[j]] ++;
				U[D[j]] = j;
				D[U[j]] = j;
			}
		}
		L[R[c]] = c;
		R[L[c]] = c;
	}

	int dfs (int k) {
		int i, j, t, m = maxn, mn;
		if (R[0] == 0) {
			//One of the answers has been found.
			ANS = k;
			return 1;
		}
		for (t = R[0]; t != 0; t = R[t]) {
			if (S[t] < m) {
				m = S[t];
				mn = t;
			}			
		}
		remove (mn);
		for (i = D[mn]; i != mn; i = D[i]) {
			O[k] = i;//record the answer.
			for (j = R[i]; j != i; j = R[j]) {
				remove (C[j]);
			}
			if (dfs (k + 1)) {
				return 1;
			}
			for (j = L[i]; j != i; j = L[j]) {
				resume (C[j]);
			}
		}
		resume (mn);
		return 0;
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
			this -> solveSudoku(board);
			for (int i = 0; i < 9; i ++) {
				for (int j = 0; j < 9; j ++) {
					cout << board[i][j];
				}
				cout << "\n";
			}
			cout << "\n";
		}
	}

	void solveSudoku(vector<vector<char> > &board) {
		memset (mat, 0, sizeof (mat));
		int len = 0;
		for (int i = 0; i < 9; i ++) {
			for (int j = 0; j < 9; j ++) {
				int k = i * 9 + j;
				int p = k * 9;
				if (board[i][j] == '.') {
					for (int q = 1; q < 10; q ++) {
						len ++;
						mat[len][0] = 4;
						mat[len][1] = q + i * 9; 							// Row
						mat[len][2] = 81 + q + j * 9;						// Column
						mat[len][3] = 162 + q + (i / 3 * 3 + j / 3) * 9;	// Block
						mat[len][4] = 243 + 1 + k;							// Grid
						present[len] = q;
					}
				} else {
					int q = board[i][j] - '0';
					len ++;
					mat[len][0] = 4;
					mat[len][1] = q + i * 9; 							// Row
					mat[len][2] = 81 + q + j * 9;						// Column
					mat[len][3] = 162 + q + (i / 3 * 3 + j / 3) * 9;	// Block
					mat[len][4] = 243 + 1 + k;							// Grid
					present[len] = q;
				}
			}
		}
		build (len, 324);
		dfs (0);
		int ret[81];
		for (int i = 0; i < ANS; i ++){
			ret[i] = W[O[i]];
		}
		sort (ret, ret + ANS);
		for (int i = 0; i < ANS; i++ ) {
			int row = i / 9, col = i % 9;
			board[row][col] = present[ret[i]] + '0';
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
