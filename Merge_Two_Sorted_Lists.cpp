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
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
#endif

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

	ListNode *merge_list(ListNode *p, ListNode *q) {
		ListNode *head = NULL, *r;
		while(p && q) {
			if (p -> val < q -> val) {
				if (head == NULL) {
					r = head = p;
				} else {
					r -> next = p;
					r = p;
				}
				p = p -> next;
			} else {
				if (head == NULL) {
					r = head = q;
				} else {
					r -> next = q;
					r = q;
				}
				q = q -> next;
			}
		}
		if (p) {
			if (head == NULL) {
				head = p;
			} else {
				r -> next = p;
			}
		}
		if (q) {
			if (head == NULL) {
				head = q;
			} else {
				r -> next = q;
			}
		}
		return head;
	}

public:
	void test () {
		int list_a[] = {0, 1, 3, 9, 100};
		int list_b[] = {-2, 20, 80, 90};
		ListNode *la = this -> create (list_a, 5);
		ListNode *lb = this -> create (list_b, 4);
		ListNode *l = this -> mergeTwoLists(la, lb);
		this -> print(l);
	}

	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
		ListNode *head = this->merge_list(l1, l2);
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