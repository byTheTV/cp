#include <string>
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
#define ll long long
using namespace std;
#define pll pair<ll,ll>



void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<string>> dp(n, vector<string>(n));
    for (int len = 1; len <= n; len++) {
        if (len == n)
            cout << "";
        for (int left = 0; left + len <= n; left++) {
            int right = left + len - 1;
            string min = s.substr(left, len);
            if (len > 4) {
                for (int i = left; i < right; i++) {
                    string t = dp[left][i] + dp[i + 1][right];
                    if (t.size() < min.size())
                        min = t;
                }

                for (int p = 1; p < len; p++) {
                    if (len % p != 0)
                        continue;
                    bool is = 1;
                    for (int i = left + p; i <= right; i++) {
                        if (s[i] != s[i - p])
                            is = 0;
                    }
                    if (is) {
                        string t = to_string(len / p) + '(' + dp[left][left + p - 1] + ')';
                        if (t.size() < min.size())
                            min = t;
                    }

                }
            }
            dp[left][right] = min;
        }
    }

    cout << dp[0][n - 1];
}

/*
NYEYEYENYEYEYE
*/

int main()
{
   int t = 1;
    // cin >> t;
    while (t--)
        solve();
}