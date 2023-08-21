// ConsoleApplication20.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#define ll long long
#define pii pair<int,int>
using namespace std;

vector<int> tree;

void update(int v, int l, int r, int num) {
	if (l >= r)
		return;
	if (l + 1 == r) {
		tree[v] = 1;
		return;
	}
	int tm = (l + r) / 2;
	if (num >= tm)
		update(v * 2 + 1, tm, r, num);
	else
		update(v * 2, l, tm, num);
	tree[v] = tree[v * 2] + tree[v * 2 + 1];
}

ll find(int v, int tl, int tr, int l, int r) {
	if (tl >= tr || l >= r)
		return 0;
	if (l <= tl && tr <= r)
		return tree[v];
	int tm = (tr + tl) / 2;
	return find(v * 2, tl, tm, l, min(tm, r)) + find(v * 2 + 1, tm, tr, max(tm, l), r);
}

int main()
{
	int n;
	cin >> n;
	tree.resize(4 * n + 1);
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		update(1, 0, n, a[i]);
		int k = find(1, 0, n, 0, a[i]);
		k -= i;
//		cout << k << "\n";
		ans += k;
	}
	ans = abs(ans);
	cout << ans << '\n';
	for (int i = 0; i < n - 1; i++) {
		ans = ans - a[i] + (n - 1 - a[i]);
		cout << ans << '\n';
	}
}
