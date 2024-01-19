//#define DEBUG

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

	ListNode *merge(vector<ListNode*> v, int l, int r) {
		if (l == r) {
			return v[l];
		}
		if (l + 1 == r) {
			return this -> merge_list (v[l], v[r]);
		}
		int mid = (l + r) / 2;
		ListNode * ll = this -> merge(v, l, mid);
		ListNode * rr = this -> merge(v, mid + 1, r);
		return this -> merge_list (ll, rr);
	}

public:
	void test () {
		int list_a[] = {0, 1, 3, 9, 100};
		int list_b[] = {-2, 20, 80, 90};
		int list_c[] = {5, 6, 7, 8};
		int list_d[] = {0, 2, 3, 4, 6};
		int list_e[] = {-10, 2, 10, 203, 2345};
		ListNode *la = this -> create (list_a, 5);
		ListNode *lb = this -> create (list_b, 4);
		ListNode *lc = this -> create (list_c, 4);
		ListNode *ld = this -> create (list_d, 5);
		ListNode *le = this -> create (list_e, 5);
		vector<ListNode*> v;
		v.push_back(la);
		v.push_back(lb);
		v.push_back(lc);
		v.push_back(ld);
		v.push_back(le);
		ListNode *l = this -> mergeKLists(v);
		this -> print(l);
	}

	ListNode *mergeKLists(vector<ListNode *> &lists) {
		int sz = lists.size();
		if (sz == 0) {
			return NULL;
		}
		ListNode *head = this -> merge(lists, 0, sz - 1);
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