#include <vector>
#include<bitset>
#include <algorithm>
#include <map>
#include <cmath>
#include <iostream>
#define ll long long
#define pii pair<int, int>
using namespace std;
const ll mod = pow(10, 9) + 7;
const int N = 1e4 + 10;

void solve() {
	int n;
	cin >> n;
	int mx = 0;
	vector<ll> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	vector<int> dp(n);
	for (int i = 0; i < n; ++i) {
		dp[i] = 1;
		for (int j = 0; j < i; ++j)
		if (a[j] < a[i])
			dp[i] = max(dp[i], 1 + dp[j]), mx = max(dp[i], mx);
	}
	cout << mx << '\n';
	vector<int> ans;
	for (int i = n - 1; i >= 0; i--) {
		if (mx == 0)
			break;
		if (dp[i] == mx) {
			ans.push_back(a[i]);
			mx--;
		}
	}
	sort(ans.begin(), ans.end());
	for (auto i : ans)
		cout << i << ' ';
}



/*
4
-100 101 2 101

*/

int main() {
	int t = 1;
	while (t--)
		solve();
}
