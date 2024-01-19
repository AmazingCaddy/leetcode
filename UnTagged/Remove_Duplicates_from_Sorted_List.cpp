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
private:
	int get_list_len (ListNode *head) {
		int list_len = 0;
		ListNode *p = head;
		while (p) {
			list_len ++;
			p = p -> next;
		}
		return list_len;
	}
	
	void del(ListNode * head) {
		while (head) {
			ListNode *p = head -> next;
			delete head;
			head = p;
		}
	}

	ListNode * create (int list[], int n) {
		int val;
		ListNode *p = NULL, *q = NULL, *head = NULL;
		for (int i = 0; i < n; i ++) {
			val = list[i];
			if (p == NULL) {
				p = new ListNode(val);
				head = p;
			} else {
				q = new ListNode(val);
				p -> next = q;
				p = q;
			}
		}
		return head;
	}

	void print (ListNode * head) {
		int cnt = 0;
		ListNode *p = head;
		while (head) {
			if (cnt) {
				cout << " -> " << head -> val;
			} else {
				cnt = 1;
				cout << head -> val;
			}
			head = head -> next;
		}
		cout << "\n";
		head = p;
	}

	ListNode* tail(ListNode* head) {
		ListNode * p = head;
		while (p->next) {
			p = p->next;
		}
		return p;
	}

public:
	void test() {
		int list_a[] = {1, 1, 1, 2, 2, 4, 4};
		int list_b[] = {-2, 20, 80, 90};
		ListNode *la = this -> create (list_a, 7);
		ListNode *lb = this -> create (list_b, 4);
		this->deleteDuplicates(la);
		this->deleteDuplicates(lb);
		this->print(la);
		this->print(lb);
		this->del(la);
		this->del(lb);
	}

	ListNode *deleteDuplicates(ListNode *head) {
		if (head == NULL) {
			return head;
		}
		ListNode *p = head, *q, *r;
		while (p->next) {
			q = p->next;
			if (!q) {
				break;
			}
			if (p->val == q->val) {
				r = q;
				p->next = q->next;
				delete r;
			} else {
				p=q;
			}
		}
		return head;
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
