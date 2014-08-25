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

typedef long long ll;

const int maxn = 10004;
const int inf = 0x3f3f3f3f;
const double eps = 1e-8;
const double pi = acos(-1.0);

class Solution {
private:
	ll gcd(ll a, ll b) {
		return b ? this->gcd(b, a % b): a;
	}
public:
	void test() {
		vector<pair<int, int> > kv{{1, 100}, {1, 1}, {4, 5}};
		for (int i = 0; i < kv.size(); i ++) {
			cout << this->uniquePaths(kv[i].first, kv[i].second) << "\n";
		}
		//cout << this->gcd(0, 25) << "\n";
	}
	
	int uniquePaths(int m, int n) {
		int N = n + m - 2;
		int K = n - 1;
		if (N - K < K) {
			K = N - K;
		}
		ll ans = 1;
		for (int i = 1; i <= K; i ++) {
			ans = ans * (N + 1 - i) / i;
		}
		return (int)ans;
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
