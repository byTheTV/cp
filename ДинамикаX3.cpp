
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#define ll long long
#define pii pair<int,int>
using namespace std;



int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		char c;
		cin >> c;
		if (c == 'M')
			a[i] = 0;
		if (c == 'P')
			a[i] = 1;
		if (c == 'G')
			a[i] = 2;
	}
	vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(k + 1, vector<int>(3)));
	// dp[n][k][m]
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			dp[i][j][a[i]] = dp[i - 1][j][a[i]] + 1;

			for (int m = 0; m < 3; m++) {	
				if(j)
					dp[i][j][a[i]] = max(dp[i][j][a[i]], dp[i - 1][j - 1][m] + 1);
				
				dp[i][j][m] = max(dp[i][j][m], dp[i - 1][j][m]);
				if (j)
					dp[i][j][m] = max(dp[i][j - 1][m], dp[i][j][m]);
			}
		}
	}
	//for (int i = 1; i <= n; i++) {
	//	cout << i << ": ";
	//	for (int j = 0; j <= k; j++) {
	//		cout << j << ": ";
	//		for (int m = 0; m < 3; m++) {
	//			cout << dp[i][j][m] << " ";
	//		}
	//		cout << '\n';
	//	}
	//	cout << '\n';
	//}

	int ans = 0;
	for (int m = 0; m < 3; m++)
		ans = max(dp[n][k][m], ans);
	cout << ans << '\n';
}
