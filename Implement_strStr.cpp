#define DEBUG

#ifdef DEBUG
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
#endif

class Solution {
private:
	int *flink;
	void faillink (char p[], int flink[], int m) {
		int j,k;
		flink[0] = -1;
		j = 1;
		while (j < m) {
			k = flink[j - 1];
			while (k != -1 && p[k] != p[j - 1]) {
				k = flink[k];
			}
			flink[j] = k + 1;
			j ++;
		}
	}
	int kmp_match (char t[], char p[], int flink[], int n, int m) {
		int i, j;
		i = 0; j = 0;
		while (i < n) {
			while (j != -1 && p[j] != t[i]) {
				j = flink[j];
			}
			if (j == m - 1){
				return (i - m + 1);
			}
			i ++;
			j ++;
		}
		return -1;
	}
public:
	void test() {
		char * haystack[] = {
			"abcdef",
			"sdassdasd"
		};
		char * needle[] = {
			"def",
			""
		};
		int n = 2;
		for (int i = 0; i < n; i ++) {
			cout << (this -> strStr(haystack[i], needle[i]) - haystack[i]) << "\n";
		}
	}

	char *strStr(char *haystack, char *needle) {
		int n_len = strlen(needle);
		int h_len = strlen(haystack);
		if (n_len == 0) {
			return haystack;
		}
		if (h_len == 0) {
			return NULL;
		}
		this -> flink = new int [n_len + 1];
		this -> faillink(needle, this -> flink, n_len);
		int ans = this -> kmp_match(haystack, needle, this -> flink, h_len, n_len);
		delete [] this -> flink;
		if (ans == -1) {
			return NULL;
		}
		return haystack + ans;
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