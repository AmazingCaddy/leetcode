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

	int check(ListNode * head) {
		if (head == NULL) {
			return 0;
		}
		ListNode*p = head, *q = head;
		int flag = 1;
		do {
			if (p->next) {
				p = p->next;
			//	cout << "p->val = " << p->val << "\n";
			} else {
				flag = 0;
				break;
			}
			if (p->next) {
				p = p->next;
			//	cout << "p->val = " << p->val << "\n";
			} else {
				flag = 0;
				break;
			}
			//cout << "\n";
			q = q->next;
		} while (p != q);
		return flag;
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
		int list_a[] = {1, 4, 3, 2, 5, 2};
		ListNode *la = this->create(list_a, 6);
		la = this->partition(la, 2);
		this->print(la);
		this->del(la);
	}

	void add(ListNode*& tail, ListNode* p) {
		if (tail == NULL) {
			tail = p;
			return;
		}
		tail->next = p;
		tail = p;
	}

	ListNode *partition(ListNode *head, int x) {
		if (head == NULL) {
			return head;
		}
		ListNode *p = head, *qh = NULL, *rh = NULL, *qt = NULL, *rt = NULL;
		while (p) {
			if (p->val < x) {
				if (qh == NULL) {
					qh = qt = p;
				} else {
					this->add(qt, p);
				}
			} else {
				if (rh == NULL) {
					rh = rt = p;
				} else {
					this->add(rt, p);
				}
			}
			p = p->next;
		}
		if (rt) {
			rt->next = NULL;
		}
		if (qh == NULL) {
			qh = rh;
		} else {
			qt->next = rh;
		}
		return qh;
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
