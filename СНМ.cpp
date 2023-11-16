
vector<int> p;
vector<int> sz;
int get(int v) {
    if (p[v] == v)
	return v;
    p[v] = get(p[v]);
    return p[v];
}

void uni(int v, int u) {
    v = get(v);
    u = get(u);
    if (v == u)
	return;
    if (sz[u] > sz[v])
    {
	p[v] = u;
	sz[u] += sz[v];
    }
    else {
	p[u] = v;
	sz[v] += sz[u];
    }
}