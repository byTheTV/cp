#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <cmath>
#define ll long long
using namespace std;


vector<ll> tree;
vector<ll> a;



void build(int v, int tl, int tr) {
    if (tl >= tr)
	return;
    if (tl + 1 == tr) {
	tree[v] = a[tl];
	return;
    }
    int tm = (tl + tr) / 2;
    build(v * 2, tl, tm);
    build(v * 2 + 1, tm, tr);
    tree[v] = tree[v * 2] ^ tree[v * 2 + 1];
}

ll find(int v, int tl, int tr, int left, int right) {
    if (tl >= tr || left >= right)
	return 0;
    if (left <= tl && tr <= right) {
	return tree[v];
    }
    int tm = (tl + tr) / 2;
    return find(v * 2, tl, tm, left, min(tm, right)) ^ find(v * 2 + 1, tm, tr, max(tm, left), right);
}


void solve() {
    int n;
    cin >> n;
    a.resize(n);
    tree.resize(4 * n + 1);
    string s;
    for (int i = 0; i < n; i++)
	cin >> a[i];
    cin >> s;

    vector<ll> xors(2);

    for (int i = 0; i < n; i++) {
	if (s[i] == '1')
	    xors[1] ^= a[i];
	else
	    xors[0] ^= a[i];
    }

    build(1, 0, n);

    vector<ll> ans;
    int q;
    cin >> q;
    while (q--)
    {
	int k;
	cin >> k;
	if (k == 1) {
	    int l, r;
	    cin >> l >> r;
	    ll xore = find(1, 0, n, l - 1, r);
	    xors[0] ^= xore;
	    xors[1] ^= xore;
	    continue;
	}
	cin >> k;
	ans.push_back(xors[k]);
    }
    for (auto i : ans)
	cout << i << ' ';
    cout << '\n';
}

int main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
	solve();
    }
}
