class Solution {
public:
	void test () {
		int a[] = {1, 2, 3, 4, 5, 10, 2, 3, 1, 20, 1};
		int n = 11;
		int ans[] = {1, 2, 3, 4, 5, 10, 20};
		int ans_n = 7;
		sort (a, a + n);
		int len = this -> removeDuplicates(a, n);
		for (int i = 0; i < len; i ++) {
			cout << a[i] << " ";
		}
		cout << "\n";
	}
	int removeDuplicates(int A[], int n) {
		if (n <= 1) {
			return n;
		}
		int len = 1;
		for (int i = 1; i < n; i ++) {
			if (A[i] != A[i - 1]) {
				A[len ++] = A[i];
			}
		}
		return len;
	}
};