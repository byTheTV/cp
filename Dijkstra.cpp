
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

//ассоциативный массив = dictionary = набор пар ключ-значение (key-value-pairs)

int n, b, s, t;

/*
5 10 1 3

1 2 3
1 3 20
2 4 5
4 3 1
2 3 8

*/

unordered_map<int, vector<pair<int, int>>> adjacency_list;
unordered_map <int, int> dist;
vector <bool> is_go;
priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> que;	

int dijkstra()
{
	//	set<int> visited;
	while (!que.empty())
	{
		int x = que.top().second;
		que.pop();

		if (is_go[x] == true)
		{
			continue;
		}
		is_go[x] = true;

		for (auto u : adjacency_list[x])
		{
			int b = u.second, w = u.first;

			if (dist[x] + w < dist[b])
			{
				dist[b] = dist[x] + w;
				que.push({ dist[b], b });
			}
		}

		
	}
	return 1;
}


int main()
{
	int max_value = 0;
	cin >> n >> b >> s >> t;

	for (int i = 0; i < n; i++)
	{
		int k1, k2, d;
		cin >> k1 >> k2 >> d;
		if (adjacency_list.find(k1) == adjacency_list.end()) {
			adjacency_list[k1] = {};
		}
		if (adjacency_list.find(k2) == adjacency_list.end()) {
			adjacency_list[k2] = {};
		}
		adjacency_list[k1].push_back({d, k2 });
		adjacency_list[k2].push_back({ d,k1 });
		dist[k1] = INT_MAX;
		dist[k2] = INT_MAX;
		max_value = max(max_value, max(k1, k2));
	}

	for (auto& it : adjacency_list) {
		cout << it.first << ": ";
		for (auto& value_it : it.second) {
			cout << "NUM: " << value_it.second << " DIST: " << value_it.first << " " ;
		}
		cout << "\n";
	}

	is_go.resize(max_value + 1);

	que.push({0, s});
	dist[s] = 0;
	dfs();


	for (auto& d : dist)
	{
		cout << d.first << ": " << d.second << "\n";
	}
	cout << dist[t] << "\n";

	if (dist[t] > b)
		cout << "NO\n";
	else
		cout << "YES\n";

	//	for (auto& it : adjacency_list)
	//	{
	//		que.push(it.first);
	//		dfs();
	//	}

}

/*

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

//ассоциативный массив = dictionary = набор пар ключ-значение (key-value-pairs)

int n;


unordered_map<int, vector<int>> adjacency_list;
unordered_map <int, int> dist;

queue <int> que;

int dfs()
{
//	set<int> visited;
	while (!que.empty())
	{
		int x = que.front();
		que.pop();
		
		cout << "X: " << x << " DIST:" << dist[x] << " ";

		for (auto& value : adjacency_list[x])
		{	
			if (dist[value] != INT_MAX)
				continue;
			que.push(value);		
			dist[value] = dist[x] + 1;		
		}
		cout << " Queue: " << " " << que.size() << " ";
//		cout << que.size();
		cout << "\n";
	}
	return 1;
}


int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int k1, k2;
		cin >> k1 >> k2;
		if (adjacency_list.find(k1) == adjacency_list.end()) {
			adjacency_list[k1] = {};
		}
		if (adjacency_list.find(k2) == adjacency_list.end()) {
			adjacency_list[k2] = {};
		}
		adjacency_list[k1].push_back(k2);
		adjacency_list[k2].push_back(k1);
		dist[k1] = INT_MAX;
		dist[k2] = INT_MAX;

	}

	for (auto& it : adjacency_list) {
		cout << it.first << ": ";
		for (auto& value_it : it.second) {
			cout << value_it << " ";
		}
		cout << "\n";
	}

	que.push(1);
	dist[1] = 0;
	dfs();

	for (auto& d : dist)
	{
		cout << d.first << ": " << d.second << "\n";
	}

//	for (auto& it : adjacency_list)
//	{
//		que.push(it.first);
//		dfs();
//	}

}

*/

/*
7
1 2
1 6
1 4
2 3
2 4
2 5
3 7

*/




/*


#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

//ассоциативный массив = dictionary = набор пар ключ-значение (key-value-pairs)

int n;


unordered_map<int, vector<int>> adjacency_list;
vector <bool> is_go;
stack <int> que;

int dfs()
{
	while (!que.empty())
	{
		int x = que.top();
		que.pop();
		

		if (is_go[x] == true)
		{
			continue;
		}
			
		is_go[x] = true;

		cout << x << " STACK ";

		for (auto& value : adjacency_list[x])
		{	
			que.push(value);
		}	
		cout << que.size();
		cout << "\n";
	}
	return 1;
}


int main()
{
	cin >> n;

		

	for (int i = 0; i < n; i++)
	{
		int k1, k2;
		cin >> k1 >> k2;
		if (adjacency_list.find(k1) == adjacency_list.end()) {
			adjacency_list[k1] = {};
		}
		if (adjacency_list.find(k2) == adjacency_list.end()) {
			adjacency_list[k2] = {};
		}
		adjacency_list[k1].push_back(k2);
		adjacency_list[k2].push_back(k1);
	}

	int max_value = 0;

	for (auto& it : adjacency_list) {
		cout << it.first << ": ";
		max_value = max(max_value, it.first);
		for (auto& value_it : it.second) {
			cout << value_it << " ";
		}
		cout << "\n";
	}



	cout << "MAX: " << max_value << "\n";


	is_go.resize(max_value + 1);
	
	for (auto& it : adjacency_list)
	{
		que.push(it.first);
		dfs();
	}
}
*/

/*
	que.push(1);
	dfs();
*/
//	cout << is_go.size() << "\n";

//	for (int i = 1; i < is_go.size(); i++)
//		cout << i << ": " << is_go[i] << "\n";






/*
7
1 2
1 3
1 4
2 3
2 4
2 5
3 7

*/













/*

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

//ассоциативный массив = dictionary = набор пар ключ-значение (key-value-pairs)

int n;


unordered_map<int, vector<int>> adjacency_list;
vector <bool> is_go;


int dfs(int x)
{
	if (is_go[x] == true)
		return 1;
	is_go[x] = true;
		
	for (auto& value : adjacency_list[x])
	{
		cout << value << "\n";
		dfs(value);
	}
	return 1;
}


int main()
{

	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		int k1, k2;
		cin >> k1 >> k2;
		if (adjacency_list.find(k1) == adjacency_list.end()) {
			adjacency_list[k1] = {};
		}
		if (adjacency_list.find(k2) == adjacency_list.end()) {
			adjacency_list[k2] = {};
		}
		adjacency_list[k1].push_back(k2);
		adjacency_list[k2].push_back(k1);
	}

	int max_value = 0;

	for (auto& it : adjacency_list) {
		cout << it.first << ": ";
		max_value = max(max_value, it.first);
		for (auto& value_it : it.second) {
			cout << value_it << " ";
		}
		cout << "\n";
	}
	
	

	cout << "MAX: " << max_value << "\n";


	is_go.resize(max_value + 1);
	

	dfs(1);

	cout << is_go.size() << "\n";

	for (int i = 1; i < is_go.size(); i++)
		cout << i << ": " << is_go[i] << "\n";

}

*/
/*
5
1 2
2 3
3 4
4 5
5 6

*/

