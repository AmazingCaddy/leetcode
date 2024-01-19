/**
 *	当height[i] <= height[j]时，为什么是i++，而不是j++来获取可能更多的水？
 *	假设j' > j，之所以j'往左移，是因为存在height[i'] > height[j'] (i’ <= i), 而那时area' = (j' - i') * min(height[i'], height[j'])，
 *	因为height[j'] == min(height[i'], height[j'])，所以area' = (j' - i') * height[j']。
 *	而i 和 j'构成的面积area = (j' - i) * min(height[i], height[j'])。
 *	area' >= area，所以j不需要往右移。
**/
class Solution {
public:
	int maxArea(vector<int> &height) {
		int l = 0, r = height.size() - 1;
		int ans = 0;
		while (l < r) {
			ans = max (ans, (r - l) * min(height[l], height[r]));
			if (height[l] < height[r]) {
				l ++;
			} else {
				r --;
			}
		}
		return ans;
	}
};