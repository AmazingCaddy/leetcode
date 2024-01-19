#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
	vector<vector<int> > fourSum(vector<int> &num, int target) {
		vector<vector<int> > res;
		unordered_map<string, int> hash_map;
		sort(num.begin(), num.end());
		int sz = num.size();
		if (sz < 4) {
			return res;
		}
		int l, r;
		for (int i = 0; i < sz; i ++) {
			for (int j = i + 1; j < sz; j ++) {
				int l = j + 1, r = sz - 1;
				while (l < r) {
					int sum = num[i] + num[j] + num[l] + num[r];
					if (sum == target) {
						vector<int> temp(4);
						temp[0] = num[i];
						temp[1] = num[j];
						temp[2] = num[l];
						temp[3] = num[r];
						string key;
						key += to_string(num[i]);
						key += to_string(num[j]);
						key += to_string(num[l]);
						key += to_string(num[r]);
						if (!hash_map.count(key)) {
							hash_map[key] = 1;
							res.push_back(temp);
						}
						l ++;
						r --;
					} else if (sum < target) {
						l ++;
					} else {
						r --;
					}
				}
			}
		}
		return res;
	}
};

int main(int argc, char const *argv[]) {
	/* code */
	return 0;
}