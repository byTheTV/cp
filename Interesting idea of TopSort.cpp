#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#define pii pair<int,int>
#define pll pair<ll,ll>

#define ll long long

using namespace std;

ll mx = -1e10;
int n, m;
ll k;

vector<vector<ll>> e;
vector<ll> a;

vector<ll> dis;
vector<ll> deg;
vector<bool> used;
vector<int> topsort;

// TopSort from start to end (without reverse)
void TopSort(int v, ll m) {
    if (used[v])
	return;
    used[v] = 1;
    topsort.push_back(v);
    for (auto i : e[v]) {
	if (a[i] > m)
	    continue;
	deg[i]--;
	dis[i] = max(dis[i], dis[v] + 1);
	if (!deg[i])
	    TopSort(i, m);
    }
}



bool check(ll m) {
    topsort.clear();
    used.clear();
    used.resize(n);
    dis.clear();
    dis.resize(n);
    deg.clear();
    deg.resize(n);
    for (int i = 0; i < n; i++) {
	if (a[i] > m)
	    continue;
	for (auto v : e[i])
	    if (a[v] <= m)
		deg[v]++;
    }

    for (int i = 0; i < n; i++) {
	if (!used[i] && a[i] <= m && !deg[i])
	    TopSort(i, m);
    }

    for (int i = 0; i < n; i++)
	if (a[i] <= m && (dis[i] == k - 1 || deg[i] == 1))
	    return 1;
    return 0;
}


void solve()
{
    cin >> n >> m >> k;
    a.resize(n);
    e.resize(n);

    for (int i = 0; i < n; i++)
	cin >> a[i];

    for (int i = 0; i < n; i++)
	e[i].clear();

    for (int i = 0; i < m; i++) {
	int x, y;
	cin >> x >> y;
	x--, y--;

	e[x].push_back(y);
    }


    ll l = -1, r = 1e11;
    while (r - l > 1) {
	ll m = (r + l) / 2;
	if (check(m))
	    r = m;
	else
	    l = m;
//	cout << l << " " << r << '\n';
    }
    if (r == 1e11)
	r = -1;
    cout << r << '\n';
}


/*
1
4
1 -2 3 -4


*/


int main()
{

    int test = 1;
//    cin >> test;
    while (test--)
    {
	solve();
    }
}
