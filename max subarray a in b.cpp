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
	int mx = 0;
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int m;
	cin >> m;
	vector<int> b(m + 1);
	for (int i = 1; i <= m; i++)
		cin >> b[i];

	vector<vector<int>> dp(m + 1, vector<int>(n + 1));
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (b[i] == a[j])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			dp[i][j] = max(dp[i][j], max(dp[i - 1][j], dp[i][j - 1]));
		}
	}
	cout << dp[m][n];
}


/*
5 20
1 2 3 4 5

*/

int main() {
	int t = 1;
	while (t--)
		solve();
}
