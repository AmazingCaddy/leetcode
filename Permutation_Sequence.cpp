class Solution {
public:
	void test() {
		cout << this->getPermutation(3, 5) << "\n";
		cout << this->getPermutation(4, 5) << "\n";
	}

	string getPermutation(int n, int k) {
		int order[10], vis[10];
		order[0] = 1;
		for (int i = 1; i < 10; i ++){
			order[i] = order[i - 1] * i;
		}
		memset(vis, 0, sizeof(vis));
		k --;
		string res = "";
		int top = n - 1, data;
		while (top >= 0) {
			int first_k = k / order[top];
			for (int i = 1; i <= n; i ++) {
				if (!vis[i]) {
					first_k --;
				}
				if (first_k < 0) {
					vis[i] = 1;
					res += (i + '0');
					break;
				}
			}
			k %= order[top];
			top --;
		}
		return res;
	}
};
