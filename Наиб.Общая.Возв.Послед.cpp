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
	vector<ll> a(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int m;
	cin >> m;
	vector<ll> b(m + 1);
	for (int i = 1; i <= m; i++)
		cin >> b[i];

	map<pii, pii> prev;
	vector<vector<ll>> dp(n + 1, vector<ll>(m + 1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (b[j] == a[i]) {
				dp[i][j] = 1;
				prev[{i, j}] = { -1, -1 };
				for (int k = 1; k <= i - 1; k++) {
					if (a[k] < a[i]) {
						if (dp[i][j] < 1 + dp[k][j]) {
							dp[i][j] = 1 + dp[k][j];
							prev[{i, j}] = { k, j };
						}
					}
				}
				continue;
			}
			dp[i][j] = dp[i][j - 1];
			prev[{i, j}] = { i, j - 1 };
		}
	}
	ll mx = 0, mi = 0, mj = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			if (mx < dp[i][j])
				mi = i, mj = j, mx = dp[i][j];
	}
	cout << mx << "\n";
	if (mx == 0)
		return;
	pii stop = { -1, -1 };
	vector<int> ans;
	while (prev[{mi, mj}] != stop) {
		int tmi = mi, tmj = mj;
		mi = prev[{tmi, tmj}].first;
		mj = prev[{tmi, tmj}].second;
		if (mi != tmi)
			ans.push_back(a[tmi]);
	}
	ans.push_back(a[mi]);
	sort(ans.begin(), ans.end());
	for (auto i : ans)
		cout << i << " ";
}



/*
5
1 4 2 5 -12
4
-12 1 2 4

*/

int main() {
	int t = 1;
	while (t--)
		solve();
}
