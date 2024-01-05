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

using namespace std;

#define ll long long
#define pll pair<ll,ll>



vector<ll> sz;
vector<ll> pr;
vector<pair<ll, pll>> e;

int n, m;


int get(int v) {
    if (pr[v] == v)
        return v;
    pr[v] = get(pr[v]);
    return pr[v];
}

void unite(int v, int u) {
    v = get(v);
    u = get(u);
    if (v == u)
        return;
    if (sz[v] >= sz[u]) {
        pr[u] = v;
        sz[v] += sz[u];
    }
    else {
        pr[v] = u;
        sz[u] += sz[v];
    }
}

bool chck(int x) {
    for (int i = 0; i < n; i++)
        sz[i] = 1, pr[i] = i;
    int l, r = 0;
    while (r < m && 2 * e[r].first < x)
        r++;
    if (r == m)
        return 0;
    l = r - 1;
    while (r < m) {
        while (l >= 0 && e[l].first + e[r].first >= x) {
            unite(e[l].second.first, e[l].second.second);
            l--;
        }
        if (get(e[r].second.first) == get(e[r].second.second))
            return 1;
        unite(e[r].second.first, e[r].second.second);
        r++;
    }
    return 0;
}


void solve() {
    cin >> n >> m;
    e.resize(m);

    sz.resize(n);
    pr.resize(n);

    ll mx = 0, prmx = 0;
    for (int i = 0; i < m; i++) {
        ll v, u, d;
        cin >> v >> u >> d;
        if (d >= mx) {
            prmx = mx;
            mx = d;
        }
        else {
            if (d >= prmx)
                prmx = d;
        }
        v--, u--;
        e[i] = {d, {v,u}};
    }
    sort(e.begin(), e.end());
    ll l = 0, r = mx + prmx + 1;
    while (r - l > 1) {
        ll m = (r + l) / 2;
        if (chck(m))
            l = m;
        else
            r = m;
    }
    cout << l;
}   

/*
1 2 3 3
*/

int main() {
    int t = 1;
   // cin >> t;
    while (t--)
        solve();
}

