#include <vector>
#include<bitset>
#include <algorithm>
#include <map>
#include <cmath>
#include <iostream>
#define ll long long
using namespace std;
const ll mod = pow(10, 9) + 7;
const int N = 100100;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<char>s(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> s[i];
	vector<vector<ll>> dp(n + 1, vector<ll>(n + 1));

	// i - length of word, j - first indx
	for (int i = 0; i <= n; i++) {
		for (int j = 1; j <= min(j + i, n); j++) {
			if (j + i > n)
				break;
			if (j + 1 > n)
				continue;
			ll mn = min(j + i, n);
			dp[j][mn] = dp[j + 1][mn - 1];
			if (s[j] != s[mn])
				dp[j][mn]++;
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j++)
			if (dp[i][j] <= k)
				ans++;
	cout << ans;
}


/*
5 1
abcde

*/

int main() {
	int t = 1;
	while (t--)
		solve();
}
