#include <vector>
#include<bitset>
#include <algorithm>
#include <map>
#include <cmath>
#include <iostream>
#include <set>
#include <string>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;
const ll mod = 1e10 + 7;
const int N = 1e4 + 10;



void solve() {
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<vector<int>> pref(n + 1, vector<int>(n + 1));
    vector<vector<int>> suf(n + 1, vector<int>(n + 1));

    for (int l = 0; l < n; l++) {
	ll cnt = 0;
	for (int r = l + 1; r <= n; r++) {
	    if (s[r - 1] == '1')
		cnt++;
	    pref[r][cnt] = max(pref[r][cnt], r - l);
	    suf[l][cnt] = max(suf[l][cnt], r - l);
	}
    }

    for (int l = 0; l <= n; l++) {
	for (int cnt = 0; cnt <= n; cnt++) {
	    if (l)
		pref[l][cnt] = max(pref[l][cnt], pref[l - 1][cnt]);
	    if (cnt)
		pref[l][cnt] = max(pref[l][cnt], pref[l][cnt - 1]);
	}
    }

    for (int l = n; l >= 0; l--) {
	for (int cnt = 0; cnt <= n; cnt++) {
	    if (l + 1 <= n)
		suf[l][cnt] = max(suf[l][cnt], suf[l + 1][cnt]);
	    if (cnt)
		suf[l][cnt] = max(suf[l][cnt], suf[l][cnt - 1]);
	}
    }

    vector<int> segments(n + 1);
    for (int l = 0; l < n; l++) {
	int cnt = 0;
	for (int r = l; r <= n; r++) {
	    if(r > l)
		cnt += s[r - 1] == '0';
	    if (cnt > k)
		break;
	    segments[r - l] = max(pref[l][k - cnt], segments[r - l]);
	    segments[r - l] = max(suf[r][k - cnt], segments[r - l]);
	}
    }

    for (int i = 1; i <= n; i++) {
	int mx = 0;
	for (int a = 0; a <= n; a++) {
//	    cout << segments[a] * i + a << " ";
	    mx = max(segments[a] * i + a, mx);
	}
	cout << mx << " ";
    }
    cout << "\n";

}



/*
1
4 1
0110










*/

int main() {
    int t = 1;
    cin >> t;
    while (t--)
	solve();
}
