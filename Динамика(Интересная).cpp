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
#include <string>
#include <stdio.h>
#define ll long long
using namespace std;

#define pii pair<int,int>

const int N = int(5e3) + 9;

int n;
int a[N];

vector<vector<int>> dp(N, vector<int>(N, -1));


int rec(int pos, int x) {
    // https://codeforces.com/contest/1400/problem/E

    int& res = dp[pos][x];
    if (res != -1)
        return res;
    if (pos == n)
        return 0;

    res = 1 + rec(pos + 1, n);
    res = min(res, rec(pos + 1, pos) + a[pos]);
    if (x != n) {
        if (a[x] >= a[pos]) {
            res = min(res, rec(pos + 1, pos));
        }
        else {
            res = min(res, 1 + rec(pos + 1, x));
            res = min(res, rec(pos + 1, pos) + a[pos] - a[x]);
            /*
            В чём прикол вообще? Если Аpos > Ax, тогда если мы его "берём":
            Мы просто начиная со след. элемента будем -Apos делать.
            Почему это оптимально? Если у нас были какие-то элементы до 
            Apos, которые >= его, тогда мы их же тоже посмотрим и если между ними нету элемента, который их меньше
            Тогда ответ будет оптимален для Aposprev == Apos, его мы итак посчитаем и ничего для него не изменится
            Если же у нас между ними есть элемент меньше Apos то так или иначе вычесть на отрезке [posprev, pos] - Apos не выйдет
            Тогда мы просто смотрим чё по следующим элементам.

            */
        }
    }
    return res;
}


void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    cout << rec(0, n);
 //   cout << calc(0, n);

}

/*
4
1 4 1 1

*/

int main() {
    int t = 1;
  //  cin >> t;
    while (t--)
        solve();
}
