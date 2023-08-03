#include <vector>
#include <algorithm>
#include <set>
#include <iomanip>
#include <cmath>
#include <iostream>
#include <stack>
#define ll long long
#define pii pair<int, int>
using namespace std;


vector<set<int>> edges;
vector<bool> used;

void dfs(int v) {
	if (used[v])
		return;
	used[v] = 1;
	for (auto& i : edges[v])
		dfs(i);
}


void solve() {
	int n, m;
	cin >> n >> m;
	edges.resize(n);
	used.resize(n);
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		edges[x].insert(y);
		edges[y].insert(x);
	}

	vector<int> odd;
	for (int i = 0; i < n; i++)
		if (edges[i].size() & 1)
			odd.push_back(i);

	if (odd.size() != 2 && odd.size() != 0) {
		cout << "NO\n";
		return;
	}

	if (odd.size() == 0)
		odd.push_back(0);


	dfs(0);
	for (int i = 0; i < n; i++)
		if (!used[i]) {
			cout << "NO\n";
			return;
		}

	stack<int> q;
	q.push(odd[0]);
	while (!q.empty()) {
		int v = q.top();
		
		if (edges[v].empty()) {
			cout << v << " ";
			q.pop();
			continue;
		}

		for (auto i : edges[v]) {
			edges[i].erase(v);
			edges[v].erase(i);
			q.push(i);
			break;
		}
	}
