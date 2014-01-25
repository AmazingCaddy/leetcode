class Solution {
public:
	int threeSumClosest(vector<int> &num, int target) {
		sort(num.begin(), num.end());
		int sz = num.size();
		int ans = 0x3f3f3f3f;
		for (int i = 0; i < sz; i ++) {
			int l = i + 1, r = sz - 1;
			while (l < r) {
				int sum = num[i] + num[l] + num[r];
				if (sum == target) {
					return sum;
				}
				if (sum < target) {
					if (abs(sum - target) < abs(ans - target)) {
						ans = sum;
					}
					l ++;
				} else {
					if (abs(sum - target) < abs(ans - target)) {
						ans = sum;
					}
					r --;
				}
			}
		}
		return ans;
	}
};
