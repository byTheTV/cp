#include <vector>
#include <iostream>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <unordered_map>
#include <stack>
#include <string>
#include <bitset>
#include <stdio.h>
#define ll long long
using namespace std;

#define pii pair<int,int>

const int maxn = 2005;
int T, n, d, p[maxn];
bitset<maxn> g[maxn], dp;
void solve() {
		int n, d;
		cin >> n >> d;
		for (int i = 1; i <= n; ++i)cin >> p[i];
		sort(p + 1, p + n + 1);
		if (p[n] + p[n - 1] > d) {
				cout << "No\n";
				return;
		}
		if (p[n] > d / 2) {
				dp.reset();
				dp[0] = 1;
				for (int i = 1; i < n; ++i)dp |= (dp << p[i]);
				if (dp[d - p[n]]) {
						cout << "Yes\n";
				}
				else cout << "No\n";
				return;

		}
		for (int i = 0; i <= d; ++i)g[i].reset();
		g[0][0] = 1;
		for (int i = 1; i <= n; ++i) {
				for (int j = d; j >= 0; --j) {
						g[j] |= (g[j] << p[i]); // all nums in j
						if (j >= p[i])g[j] |= g[j - p[i]]; // what nums we can reach in g[j]
				}
		}

		int flag = 0;
		for (int i = p[n]; i <= d / 2; ++i)
				if (g[i][d - i]) {
				flag = 1;
				break;
		}
		if (flag)cout << "Yes\n";
		else cout << "No\n";

}

/*
4
5 70
23 20 15 20 15

*/

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}
