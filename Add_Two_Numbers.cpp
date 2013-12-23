class Solution {
public:
	void test () {
		int list_a[] = {5, 9, 9, 9};
		int list_b[] = {5, 9, 3, 2, 1, 4};
		ListNode * la = this -> create(list_a, 1);
		ListNode * lb = this -> create(list_b, 1);
		this -> print(la);
		this -> print(lb);
		ListNode * l = this -> addTwoNumbers(la, lb);
		this -> print(l);
		this -> del(la);
		this -> del(lb);
		this -> del(l);
	}

	void del(ListNode * head) {
		while (head) {
			ListNode *p = head -> next;
			delete head;
			head = p;
		}
	}

	ListNode* addNode(ListNode *p, int val) {
		ListNode *q = new ListNode(val);
		p -> next = q;
		p = q;
		return p;
	}

	ListNode * create (int list[], int n) {
		int val;
		ListNode *p = NULL, *q = NULL, *head = NULL;
		for (int i = 0; i < n; i ++) {
			//scanf ("%d", &val);
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

	ListNode *addTwoNode(ListNode *p, ListNode *q, int &bonus) {
		int val = p->val + q->val + bonus;
		if (val >= 10) {
			val = val - 10;
			bonus = 1;
		} else {
			bonus = 0;
		}
		ListNode * r = new ListNode(val);
		return r;
	}

	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		ListNode *l = NULL, *ll = NULL, *head;
		ListNode *p1 = l1, *p2 = l2;
		int bonus = 0;
		ListNode zero(0);
		while (p1 && p2) {
			ll = addTwoNode(p1, p2, bonus);
			if (l == NULL) {
				l = ll;
				head = l;
			} else {
				l -> next = ll;
				l = ll;
			}
			p1 = p1 -> next;
			p2 = p2 -> next;
		}
		while (p1) {
			ll = addTwoNode(p1, &zero, bonus);
			if (l == NULL) {
				l = ll;
				head = l;
			} else {
				l -> next = ll;
				l = ll;	
			}
			p1 = p1 -> next;
		}
		while (p2) {
			ll = addTwoNode(p2, &zero, bonus);
			if (l == NULL) {
				l = ll;
				head = l;
			} else {
				l -> next = ll;
				l = ll;	
			}
			p2 = p2 -> next;
		}
		if (bonus) {
			ll = addTwoNode(&zero, &zero, bonus);
			l -> next = ll;
			l = ll;
		}
		return head;
	}
};
