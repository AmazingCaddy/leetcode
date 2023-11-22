#define DEBUG

#ifdef DEBUG
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
#endif

class Solution {
public:
	void test() {
		int v[20];
		int input[] = {1, 2, 3, 2, 3, 1, 3, 4, 2, 4, 5, 6, 3, 4, 0};
		int len = 15;
		for (int i = 0; i < len; i ++) {
			v[i] = input[i];
		}
		int n = this -> removeElement(v, len, 1);
		for (int i = 0; i < n; i ++) {
			cout << v[i] << " ";
		}
		cout << "\n";
	}


	int removeElement(int A[], int n, int elem) {
		int len = 0;
		for (int i = 0; i < n; i ++) {
			if (A[i] != elem) {
				A[len ++] = A[i];
			}
		}
		return len;
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