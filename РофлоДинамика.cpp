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
    vector<ll> segments(n + 1, -1e9);
    vector<vector<ll>> pref(n + 1, vector<ll>(n + 1));
    vector<vector<ll>> suf(n + 1, vector<ll>(n + 1));

    for (ll l = 0; l < n; l++) {
	ll cnt = 0;
	for (ll r = l + 1; r <= n; r++) {
	    cnt += s[r - 1] == '1';
	    pref[r][cnt] = max(pref[r][cnt], r - l);
	    suf[l][cnt] = max(suf[l][cnt], r - l);
	}
    }

    for (ll r = 0; r <= n; r++) {
	for (ll cnt = 0; cnt <= n; cnt++) {
	    if (r)
		pref[r][cnt] = max(pref[r][cnt], pref[r - 1][cnt]);
	    if (cnt)
		pref[r][cnt] = max(pref[r][cnt], pref[r][cnt - 1]);
	}
    }

    for (ll l = n; l >= 0; l--) {
	for (ll cnt = 0; cnt <= n; cnt++) {
	    if (l + 1 <= n)
		suf[l][cnt] = max(suf[l][cnt], suf[l + 1][cnt]);
	    if (cnt)
		suf[l][cnt] = max(suf[l][cnt], suf[l][cnt - 1]);
	}
    }


    for (ll l = 0; l < n; l++) {
	ll cnt = 0;
	for (ll r = l; r <= n; r++) {
	    if (r > l)
		cnt += s[r - 1] == '0';
	    if (cnt > k)
		break;
	    segments[r - l] = max(pref[l][k - cnt], segments[r - l]);
	    segments[r - l] = max(suf[r][k - cnt], segments[r - l]);
	}
    }

    for (ll i = 1; i <= n; i++) {
	ll mx = 0;
	for (ll a = 0; a <= n; a++) {
	    //	    cout << segments[a] * i + a << " ";
	    mx = max(segments[a] * i + a, mx);
	}
	cout << mx << " ";
    }
    cout << "\n";

}

/*
1
1 0
0










*/

int main() {
    int t = 1;
    cin >> t;
    while (t--)
	solve();
}
