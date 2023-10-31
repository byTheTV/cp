#include <vector>
#include <iostream>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <unordered_map>
#include <stack>
#define ll long long
using namespace std;
#define pll pair<ll,ll>


int n;

const double EPS = 1e-7;


vector <double> a;
vector <double> b;
vector <double> c;
double resz;
double resy;
double resx;


double find(double x, double y, double z) {
		double p = 0;
		for (int i = 0; i < n; i++) {
				p = max(p, sqrt((a[i] - x) * (a[i] - x) + (b[i] - y) * (b[i] - y) + (c[i] - z) * (c[i] - z)));
		}
		return p;
}

double solvez(double y, double x) {
		double ret = 1e+50;

		double left = -1e5, right = 1e5;
		while (right - left >= EPS)
		{
				// cout << left << " " << right << '\n';
				double h = (right - left) / 3;
				double m1 = left + h, m2 = right - h;
				double f1 = find(x, y, m1);
				double f2 = find(x, y, m2);
				if (f1 < f2)
						right = m2;
				else
						left = m1;
				ret = f1;
		}
		resz = left;
		return ret;
}

double solvey(double x) {
		double ret = 1e+50;

		double left = -1e5, right = 1e5;
		while (right - left >= EPS)
		{
				// cout << left << " " << right << '\n';
				double h = (right - left) / 3;
				double m1 = left + h, m2 = right - h;
				double f1 = solvez(m1, x);
				double f2 = solvez(m2, x);
				if (f1 < f2)
						right = m2;
				else
						left = m1;
				ret = f1;
		}
		resy = left;
		return ret;
}

double solve1() {
		double ret = 1e+50;

		double left = -1e5, right = 1e5;
		while (right - left >= EPS)
		{
				// cout << left << " " << right << '\n';
				double h = (right - left) / 3;
				double m1 = left + h, m2 = right - h;
				double f1 = solvey(m1);
				double f2 = solvey(m2);
				if (f1 < f2)
						right = m2;
				else
						left = m1;
				ret = f1;
		}
		resx = left;
		return ret;
		//cout << setprecision(8) << fixed <<left << ' ';
}



void solve() {
		cin >> n;
		a.resize(n);
		b.resize(n);
		c.resize(n);
		for (int i = 0; i < n; i++) {
				cin >> a[i] >> b[i] >> c[i];
		}

		solve1();
		cout << setprecision(7) << fixed << resx << " " << resy << " " << resz << '\n';
		
		
	//	cout << '\n';


}


/*
5
5 -5 4 3 2
*/

int main()
{
  
    int t = 1;
   // cin >> t;
    while (t--) {
        solve();
    }
}
