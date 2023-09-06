#include <vector>
#include <iostream>
using namespace std;


// CONST WE CAN CHANGE
int k = 5;

int t = 0;
vector<int> tin; // time when we visited vertex
vector<int> tout; // time when we left vertex
vector<vector<int>> bup;

// pre-calc
void dfstime(int i, vector<bool>& used, vector<vector<int>>& e, int prev) {
    if (used[i])
	return;

    if (i != 0)
	bup[0][i] = prev;

    used[i] = true;
    tin[i] = t++;
    for (auto u : e[i]) {
	dfstime(u, used, e, i);
    }
    tout[i] = t++;
}

// main algorithm
int LCA(int u, int v) {
    if (tin[u] > tin[v])
	swap(u, v);
    if (tin[u] < tin[v] && tout[u] > tout[v])
	return u;
    for (int i = k; i >= 0; i--) {
	int w = bup[i][u];
	if (!(tin[w] < tin[v] && tout[w]>tout[v]))
	    u = w;
    }
    return bup[0][u];
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> e(n);
    // root - 0
    for (int i = 0; i < m; i++)
    {
	int x, y;
	cin >> x >> y;
	e[x].push_back(y);
	e[y].push_back(x);
    }

    tin.resize(n);
    tout.resize(n);
    vector<bool> used(n);
    
 
    bup.resize(k + 1, vector<int>(n));

    dfstime(0, used, e, -1);
    

    

    for (int i = 1; i <= k; i++) {
	for (int v = 0; v < n; v++) {
	    int u = bup[i - 1][v];
	    bup[i][v] = bup[i - 1][u];
	}
    }


    for (int i = 0; i <= k; i++) {
	cout << i << ":   ";
	for (int v = 0; v < n; v++) {
	    cout << v << ": " << bup[i][v] << "; ";
	}
	cout << "\n";
    }

    int req;
    cin >> req;
    for (int i = 0; i < req; i++) {
	int x, y;
	cin >> x >> y;
	cout << LCA(x, y) << "\n";
    }

}
/*
5 4
0 1
0 2
1 3
1 4


1
2 1

11 10
0 1
1 2
2 3
3 4
4 5
5 6
3 7
8 6
9 8
10 9
1
10 7

*/