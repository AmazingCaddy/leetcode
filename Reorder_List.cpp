class Solution {
public:
	void test () {
		int list_a[] = {0, 1, 2, 3, 4, 5, 6};
		ListNode * la = this -> create(list_a, 7);
		this -> print(la);
		this -> reorderList(la);
		this -> print(la);
		this -> del(la);
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
			q = p;
			p = p->next;
			q->next = r;
			r = q;
		}
		return r;
	}

	void mergeTwoList(ListNode * head1, ListNode * head2) {
		if (head1 == NULL || head2 == NULL) {
			return ;
		}
		ListNode *p = head1, *q = head2;
		ListNode *r = NULL, *s = NULL;
		while (p) {
			r = p;
			p = p -> next;
			r -> next = q;
			s = q;
			if (q == NULL) {
				break;
			}
			q = q -> next;
			s -> next = p;
		}
//		return head1;
	}

	void reorderList(ListNode *head) {
		if (head == NULL) {
			return;
		}
		int cnt = 0;
		ListNode *p = head;
		while (p) {
			p = p -> next;
			cnt++;
		}
		ListNode * q = head, *r;
		for (int i = 0; i < (cnt - cnt / 2) - 1; i ++) {
			q = q -> next;
		}
		r = q -> next;
		q -> next = NULL;
		p = head;
		//this->print(p);
		//this->print(r);
		r = this->reorder(r);
		//this->print(r);
		this->mergeTwoList(p, r);
		head = p;
		//this->print(p);
	}
};
