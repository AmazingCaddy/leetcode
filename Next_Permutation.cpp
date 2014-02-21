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
		vector<int> num;
		num.push_back(1);
		num.push_back(1);
		num.push_back(2);
		num.push_back(3);
		//num.push_back(5);
		for (int j = 0; j < 20; j ++) {
			this -> nextPermutation(num);
			for (int i = 0; i < num.size(); i ++) {
				cout << num[i] << " ";
			}
			cout << "\n";	
		}
	}

	void nextPermutation(vector<int> &num) {
		int sz = num.size();
		vector<int>::iterator it_st = num.begin();
		it_st ++;
		if (it_st == num.end()) {
			return;
		}
		vector<int>::iterator it_ed = num.end(), it_pre;
		it_ed --;
		while (it_ed != num.begin()) {
			it_pre = it_ed;
			it_pre --;
			if (*it_pre < *it_ed) {
				break;
			}
			it_ed = it_pre;
		}
		if (it_ed == num.begin()) {
			reverse(num.begin(), num.end());
			return ;
		}
		it_ed = num.end();
		while (*(-- it_ed) <= *it_pre);
		iter_swap (it_pre, it_ed);
		it_pre ++;
		reverse(it_pre, num.end());
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