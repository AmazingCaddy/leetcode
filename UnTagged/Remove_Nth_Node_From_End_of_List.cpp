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

	ListNode * reorder(ListNode *head) {
		ListNode * r = NULL, *p = head, *q = NULL;
		while (p) {
			q = p -> next;
			p -> next = r;
			r = p;
			p = q;
		}
		return r;
	}
public:
	void test () {
		int list_a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
		for (int i = 6; i <= 10; i ++) {
			ListNode * la = this -> create(list_a, i);
			this -> print(la);
			la = this -> removeNthFromEnd(la, 6);
			this -> print(la);
			this -> del(la);
		}
	}

	ListNode *removeNthFromEnd(ListNode *head, int n) {
		int list_len = this -> get_list_len(head);
		if (list_len < n) {
			return head;
		}
		int k = list_len - n;
		ListNode *p = head, *q;
		if (!k) {
			head = p -> next;
			delete p;
			return head;
		}
		for (int i = 0; i < k - 1; i ++) {
			p = p -> next;
		}
		q = p -> next;
		p -> next = q -> next;
		delete q;
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