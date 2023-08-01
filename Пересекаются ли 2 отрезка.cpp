#include <vector>
#include <algorithm>
#include <set>
#include <iomanip>
#include <cmath>
#include <iostream>
#include <stack>
#define ll long long
#define pii pair<ll, ll>
using namespace std;

#define ff first
#define ss second


pii& operator+=(pii& a, pii& b) { a.first += b.first, a.second += b.second; return a; }
pii& operator-=(pii& a, pii& b) { a.first -= b.first, a.second -= b.second; return a; }
pii operator+(pii a, pii b) { a += b; return a; }
pii operator-(pii a, pii b) { a -= b; return a; }
ll operator*(pii a, pii b) { return a.first * b.first + a.second * b.second; }
ll operator%(pii a, pii b) { return a.first * b.second - a.second * b.first; }

ll sign(ll x) { return (x < 0 ? -1 : x > 0); }


bool exc(int x1, int x2, int x3, int x4) {
	if (x1 > x2)
		swap(x1, x2);
	if (x3 > x4)
		swap(x3, x4);
	return max(x1, x3) <= min(x2, x4);
	
}


bool peres(pair<pii, pii>a, pair<pii, pii> b) {
	// a.first - 1v1coord, a.second - 1v2coord, b.first - 2v1coord, b.second - 2v2coord
	
	if (((b.second - b.first)%(a.second - a.first)) == 0) {
		int x1 = a.first.first, y1 = a.first.second;
		int x2 = a.second.first, y2 = a.second.second;
		int x3 = b.first.first, y3 = b.first.second;
		int x4 = b.second.first, y4 = b.second.second;

		int A = (y4 - y3);
		int B = (x3 - x4);
		int C = -(x3 * y4) + x4 * y3;

		if (A * x1 + B * y1 + C == 0 && exc(x1, x2, x3, x4) && exc(y1, y2, y3, y4)) {
			return true;
		}
		else
			return false;

	}
	
	
	// 1 check
	pii vn = a.second - a.first;
	pii v1 = b.second - a.first;
	pii v2 = b.first - a.first;
	ll pr1 = vn % v1, pr2 = vn % v2;
	if (sign(pr1) == 0 || sign(pr2) == 0)
		return 1;
	if (sign(pr1) == sign(pr2))
		return 0;

	// 2 check
	vn = b.second - b.first;
	v1 = a.second - b.first;
	v2 = a.first - b.first;
	pr1 = vn % v1, pr2 = vn % v2;
	if (sign(pr1) == 0 || sign(pr2) == 0)
		return 1;
	if (sign(pr1) == sign(pr2))
		return 0;



	return 1;
}

void solve() {
	int n = 2;
//	cin >> n;
	vector<pair<pii, pii>> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first.first >> a[i].first.second;
		cin >> a[i].second.first >> a[i].second.second;
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i - 1; j >= 0; j--) {
			ans += peres(a[i], a[j]);
		}
	}
	if (ans)
		cout << "Yes\n";
	else
		cout << "No\n";
//	cout << ans << '\n';
}

/*
0 0
2 2
1 1
-10 -10
*/


int main()
{
	solve();
}
