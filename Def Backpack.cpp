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
const int N = 1e6 + 100;

void solve() {
	int n, w;
	cin >> n >> w;
	vector<pii> a(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> a[i].first;
	for (int i = 1; i <= n; i++)
		cin >> a[i].second;
	vector<vector<int>> dp(n + 1, vector<int>(w + 1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= w; j++) {
			dp[i][j] = dp[i - 1][j];
			if (a[i].first <= j)
				dp[i][j] = max(dp[i][j], dp[i - 1][j - a[i].first] + a[i].second);
		}
	}
	vector<int> ans;
	while (n > 0) {
		if (dp[n - 1][w] == dp[n][w]) {
			n--;
			continue;
		}
		ans.push_back(n);
		w -= a[n].first;
		n--;
	}
	cout << ans.size() << "\n";
	for (auto i : ans)
		cout << i << " ";
}



/*
5
10 11 2 40 8
3

*/

int main() {
	int t = 1;
	while (t--)
		solve();
}
