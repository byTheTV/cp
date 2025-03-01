
#include <vector>
#include<bitset>
#include <algorithm>
#include <map>
#include <cmath>
#include <iostream>
#include <set>
#include <queue>
#include <string>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;
const ll mod = 1e10 + 7;
const int N = 2e5 + 10;

ll n;
string s;
//


long long f(long long x, long long n, ll p) {
    if (n == 0)
	return 1;
    if (n % 2 == 1) {
	return (x * f(x, n - 1, p)) % p;
    }
    long long tmp = f(x, n / 2, p);
    return (tmp * tmp) % p;
}


ll tonum(string s, ll ones) {
    ll num = 0;
    for (ll i = 0; i < s.size(); i++) {
	if(s[i] == '1')
	    num += f(2, n - i - 1, ones), num %= ones;
    }
    return num;
}

ll tobit(ll num) {
    ll ones = 0;
    while (num > 0) {
	if (num & 1)
	  ones++;
	num /= 2;
    }
    return ones;
}

ll answ(ll num) {
    ll ans = 0;
    while (num > 0) {
	ll ones = tobit(num);
	num %= ones;
	ans++;
    }
    return ans;
}

void solve() {
    cin >> n >> s;
    ll ones = 0;
    for (int i = 0; i < n; i++)
	ones += s[i] == '1';
    vector<ll>m(2);
    m[0] = tonum(s, ones + 1);
    if(ones > 1)
	m[1] = tonum(s, ones - 1);

    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
	int t = s[i] == '1' ? -1 : 1;
	ll cone = ones + t;
	if (cone == 0)
	    continue;
	ll num = m[s[i] - '1' + 1];
	num += t * f(2, n - i - 1, cone);
	num += cone;
	num %= cone;
	ans[i] = answ(num) + 1;
    }

    for (int i = 0; i < n; i++)
	cout << ans[i] << '\n';
}

/*
3
111

*/

int main() {
    solve();
}










//
//int main()
//{
//    for (ll n = 2 * 1e5; n <= 1e7; n++) {
//	for (ll y = n / 2; y <= n; y++) {
//	    for (ll m = 1; m <= n; m++) {
//		cout << n << " " << y << " " << m << '\n';
//		if ((((n % m + y % m) % m - (y % m)) + m) % m != n % m) {
//		    cout << n << " " << y << " " << m << '\n';
////		    cout << n % m << " " << (n % m + y % m) % m << " " << (y % m);
//		    return 1;
//		}
//
//	    }
//	}
//    }
//}
