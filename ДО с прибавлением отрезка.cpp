vector<ll> tree;
vector<ll> own;

void update(int v, int tl, int tr, int left, int right, int add) {
		if (tl >= tr || left >= right)
				return;
		if (left <= tl && tr <= right) {
				if (tr == tl)
						own[v] += add;
				else
						own[v] += (tr - tl) * add;
				return;
		}
		int tm = (tl + tr) / 2;
		update(v * 2, tl, tm, left, min(tm, right),add);
		update(v * 2 + 1, tm, tr, max(tm, left), right, add);
	  tree[v] = tree[v * 2] + tree[v * 2 + 1] + own[v * 2] + own[v * 2 + 1];
}


ll find(int v, int tl, int tr, int left, int right) {
		if (tl >= tr || left >= right)
				return 0;
		if (left <= tl && tr <= right) {
				return tree[v] + own[v];
		}
		int tm = (tl + tr) / 2;
		return own[v] + find(v * 2, tl, tm, left, min(tm, right)) + find(v * 2 + 1, tm, tr, max(tm, left), right);
}

void solve() {
		int k, n;
		cin >> k >> n;
		tree.resize(4 * k + 1);
		own.resize(4 * k + 1);

		vector <pair<pair<ll, ll>, pair<ll, ll>>> a(n);
		for (int i = 0; i < n; i++)
				cin >> a[i].second.first >> a[i].second.second >> a[i].first.first >> a[i].first.second;
		int m;
		cin >> m;
		vector <pair<int, pair<int, int>>> q(m);
		for (int i = 0; i < m; i++)
				cin >> q[i].second.first >> q[i].second.second >> q[i].first;
		sort(a.begin(), a.end());
		sort(q.begin(), q.end());


		int l1 = 0, l2 = 0;
		while (l2 < m) {
				if (l1 < n && a[l1].first.first <= q[l2].first) {
						update(1, 0, k, a[l1].second.first - 1, a[l1].second.second, a[l1].first.second);
						l1++;
				}
				else {
						cout << find(1, 0, k, q[l2].second.first - 1, q[l2].second.second) << "\n";
						l2++;
				}
		}
}