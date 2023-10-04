#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>
using namespace std;

vector<vector<int>> a, t;
vector<int> order;
vector<int> used;
vector<int> cmp;
int sum = 1;
bool cycle = 0;

void dfs1(int v) {
    used[v] = 1;
    for (int u : t[v]) {
        if (used[u] == 0)
            dfs1(u);
        if (used[u] == 1) {
            cycle = 1;
        }
    }
    used[v] = 2;
    order.push_back(v);
}

void dfs2(int v) {
    cmp[v] = sum;
    for (int u : a[v])
        if (cmp[u] == 0)
            dfs2(u);
}


/*
12 16
1 8
8 7
7 2
7 1
2 10
10 5
5 3
12 3
3 10
12 10
3 11
12 6
11 9
9 6
4 9
6 4
6 11
*/

void solve() {
    int n, m;
    cin >> n >> m;
    a.resize(n);
    cmp.resize(n);
    t.resize(n);
    used.resize(n);

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        a[x].push_back(y);
    }
    for (int v = 0; v < n; v++)
        for (int u : a[v])
            t[u].push_back(v);

    for (int i = 0; i < n; i++)
        if (used[i] == 0)
            dfs1(i);

    reverse(order.begin(), order.end());

    //for (auto i : order)
    //    cout << i << " ";
    //cout << "\n";

    for (int v : order)
        if (cmp[v] == 0)
            dfs2(v), sum++;
    cout << sum - 1 << '\n';
    for (int i = 0; i < n; i++)
        cout << cmp[i] << " ";
    cout << '\n';
}

int main() {
    solve();
}
