#include <vector>
#include<bitset>
#include <algorithm>
#include <map>
#include <cmath>
#include <iostream>
#include <set>
#include <string>
#define ll long long
#define pii pair<int, int>
using namespace std;
const ll mod = 1e9 + 7;
const int N = 1e4 + 10;

struct node
{
	node* next[2] = { nullptr, nullptr };
	bool blocked = false;
};

void build(node *v, string s, int bl) {
	string str = "";
	int i = 0;
	while (i < bl) {
		if (v->next[s[i] - '0'] == nullptr) {
			v->next[s[i] - '0'] = new node();
		}
		v = v->next[s[i] - '0'];
		str += s[i];
		i++;
	}
//	cout << str << " " << str.size() << "\n";
	v->blocked = true;
}

bool finds(node* v, string s) {
	int i = 0;
	string str = "";
	while (i < s.size()) {
		if (v->blocked)
			return true;
		if (v->next[s[i] - '0'] == nullptr)
			return false;
		str += s[i];
		v = v->next[s[i] - '0'];
//		cout << str << " " << str.size() << "\n";
		i++;
	}
	if (v->blocked)
		return true;
	return false;
}

string tobits(int num) {
	string s = "";
	int i = 0;
	while (i < 8) {
		if (num & 1)
			s += "1";
		else
			s += "0";
		num /= 2;
		i++;
	}
	reverse(s.begin(), s.end());
	return s;
}

void solve() {
	node* root = new node();
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		char c;
		cin >> c;
		string s;
		cin >> s;
		int blnum = 0;
		vector<int> ip(4);
		int j = 0, ind = 0;
		string tmp = "";
		if (c != 'b')
			s += '.';
		while (j < 4) {
			if (s[ind] == '.' || s[ind] == '/') {
				ip[j] = stoi(tmp);
				tmp = "";
				j++;
				if (s[ind] == '/') {
					ind++;
					while (ind < s.size())
						tmp += s[ind], ind++;
					blnum = stoi(tmp);
					break;
				}
				ind++;
			}
			if (ind >= s.size())
				break;
			tmp += s[ind];
			ind++;
		}
		string bitip = "";
		for (int j = 0; j < 4; j++)
			bitip += tobits(ip[j]);
//		cout << bitip << '\n';

		if (c == 'b')
			build(root, bitip, blnum);
		else {
			if (finds(root, bitip))
				cout << "Yes\n";
			else
				cout << "No\n";
		}

		/*cout << bitip;
		cout << blnum;*/
	}
}



/*
3
b 0.0.0.3/31
b 0.0.0.1/32
? 0.0.0.3



*/

int main() {
	int t = 1;
	while (t--)
		solve();
}
