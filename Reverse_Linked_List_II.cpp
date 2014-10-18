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

const int maxn = 10004;
const int inf = 0x3f3f3f3f;

const double eps = 1e-8;
const double pi = acos(-1.0);

class Solution {
public:
	void test () {
		int list_a[] = {0, 1, 2, 3, 4, 5, 6};
		ListNode * la = this -> create(list_a, 2);
		this->print(la);
		la = this->reverseBetween(la, 1, 2);
		this->print(la);
		this->del(la);
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
	}

	ListNode * reorder(ListNode *head) {
		ListNode * r = NULL, *p = head, *q = NULL;
		while (p) {
			q = p->next;
			p->next = r;
			r = p;
			p = q;
		}
		return r;
	}

	ListNode *reverseBetween(ListNode *head, int m, int n) {
		if (head == NULL || head->next == NULL) {
			return head;
		}
		ListNode *prehead = new ListNode(-1);
		prehead->next = head;
		//this->print(prehead);
		ListNode *p = prehead;
		for (int i = 1; i < m; i ++) {
			p = p->next;
		}
		ListNode *q = p->next, *r = q;
		for (int i = m; i < n; i ++) {
			r = q->next;
			q->next = r->next;
			r->next = p->next;
			p->next = r;
			//this->print(prehead);
		}
		head=prehead->next;
		delete prehead;
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

