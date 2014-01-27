/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
		for (int i = 1; i <= 10; i ++) {
			for (int k = 0; k <= 10; k ++) {
				ListNode * la = this -> create(list_a, i);
				this -> print(la);
				la = this -> reverseKGroup(la, k);
				this -> print(la);
				this -> del(la);
			}
		}
	}

	ListNode *reverseKGroup(ListNode *head, int k) {
		if (head == NULL || k <= 1) {
			return head;
		}
		int list_len = this->get_list_len(head);
		int multi = list_len / k;
		vector<ListNode*> v;
		vector<int> v_len;
		ListNode *p = head, *q = head;
		for (int i = 0; i < multi; i ++) {
			v.push_back(p);
			v_len.push_back(k);
			for (int j = 0; j < k - 1; j ++) {
		//		cout << p -> val << " ";
				p = p -> next;
			}
		//	cout << p -> val << "\n";
			q = p -> next;
			p -> next = NULL;
			p = q;
		}
		if (p) {
			v.push_back(p);
			v_len.push_back(this->get_list_len(p));
		}
		int sz = v.size();
		//head = v[0];
		//this -> print(head);
		for (int i = 0; i < sz; i ++) {
		//	this -> print(v[i]);
			if (v_len[i] == k) {
				v[i] = this -> reorder(v[i]);
			}
		//	this -> print(v[i]);
			//cout << v_len[i] << "\n";
		}
		//head = v[0];
		//this -> print(head);
		for (int i = 0; i < sz - 1; i ++) {
			ListNode *p = v[i];
			while (p -> next) {
				p = p -> next;
			}
			p -> next = v[i + 1];
		}
		return v[0];
	}
};