#include <vector>
#include <iostream>
#define ll long long
#define pii pair<int, int>
using namespace std;

vector<pii> tree;
vector<int> a;

ll mod = 1e10;

void build(int v, int tl, int tr) {
	if (tl >= tr)
		return;
	if (tl + 1 == tr) {
		tree[v] = { a[tl], tl };
		return;
	}
	int tm = (tl + tr) / 2;
	build(v * 2, tl, tm);
	build(v * 2 + 1, tm, tr);
	tree[v] = max(tree[v * 2], tree[v * 2 + 1]);
}

void update(int v, int tl, int tr, int pos, int new_elem) {
	if (tl >= tr)
		return;
	if (tl + 1 == tr) {
		tree[v] = { new_elem, pos };
		return;
	}
	int tm = (tl + tr) / 2;
	if (tm >= pos) {
		update(v * 2, tl, tm, pos, new_elem);
	} else {
		update(v * 2 + 1, tm, tr, pos, new_elem);
	}
	tree[v] = max(tree[v * 2], tree[v * 2 + 1]);
}

int find(int v, int tl, int tr, int left, int right) {
	if (tl >= tr || left >= right)
		return -mod;
	if (left <= tl && tr <= right) {
		return tree[v].first;
	}
	int tm = (tl + tr) / 2;
	return max(find(v * 2, tl, tm, left, min(tm, right)), find(v * 2 + 1, tm, tr, max(tm, left), right));
}

int main() {
	int n;
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	tree.resize(4 * n + 1);
	build(1, 0, n);
	ll k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		int l, r;
		cin >> l >> r;
		cout << find(1, 0, n, l - 1, r)<< "\n";
	}
}
/*
5
5 2 3 4 2
1
2 5

*/
