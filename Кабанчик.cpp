#include <vector>
#include<bitset>
#include <algorithm>
#include <map>
#include <cmath>
#include <iostream>
#include <set>
#include <queue>
#include <string>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;
const ll mod = 1e10 + 7;
const int N = 1e4 + 10;
//
int n;

int func(vector<int> a) {
    int xr = 0; // xor
    int ans = n;
    for (int i = 0; i < (n + 1) / 2; i++) {
	if (xr) {
	    if ((a[i] ^ 1) == 0) {
		xr ^= 1;
		ans = min(ans, n - i);
	    }
	}
	else {
	    if (a[i] == 0) {
		xr ^= 1;
		ans = min(ans, n - i);
	    }
	}
    }

    int sub = 0;
    for (int i = (n + 1) / 2; i < n; i++) {
	if (xr) {
	    if ((a[i] ^ 1) != 0)
		sub = i + 1;
	    else
		break;
	}
	else {
	    if (a[i] != 0)
		sub = i + 1;
	    else
		break;
	}
    }
    if (!sub)
	ans = min(ans, (n + 1) / 2);
    else
	ans = min(ans, sub);
    return ans;
}

void solve() {
    string s;
    cin >> s;
    n = s.size();
    vector<int> a(n);
    for (int i = 0; i < n; i++)
	a[i] = s[i] == 'A';
    int ans = func(a);
    reverse(a.begin(), a.end());
    ans = max(ans, func(a));

    cout << ans << '\n';
}

/*

ANNNA
*/

int main() {
    int t = 1;
 //   cin >> t;
    while (t--)
	solve();
}







/*
Есть такой уважаемый кабанчик — Бузинесмен Пиджакович, для друзей коротко Бузя. И он, увы, самый настоящий арбузер. Своих друзей он делает несчастными, когда те счастливы, а когда те несчастны — наоборот, пытается сделать их счастливыми. Арбузы тут тоже неспроста — друг Бузи счастлив тогда и только тогда, когда у него есть арбуз!

Бузя — кабанчик на подскоке. А именно, у Бузи может быть одно натуральное число
k
 — сила подскока, его он выберет самостоятельно.

Друзья Бузи выстроились в шеренгу один за другим. Про каждого известно есть у него арбуз или нет. Когда он выберет силу подскока, он будет надоедать своим друзьям. А именно, он может делать следующее действие столько раз, сколько захочет:

Встать рядом с любым из своих друзей

Подскочить и пробежать прямо (не сворачивая и не разворачиваясь; по направлении к правому концу шеренги) вдоль не менее чем
k
 своих друзей (напоминаем:
k
 это заранее выбранное число — сила подскока). Естественно, он не может этого сделать, если с начального места далее в шеренге меньше чем
k
 друзей (более подробно посмотрите в примечании).

Пробегая вдоль каждого из своих друзей, Бузя посмотрит — был ли у друга арбуз или нет. Если был — Бузя его разобьет, и у друга арбуза больше не будет. Если же в данный момент арбуза у друга не было — Бузя даст ему арбуз, таким образом у друга теперь будет арбуз.

Бузя конечно проблемный, но хочет, чтобы у всех его друзей в итоге были арбузы. При этом он хочет выбрать наибольшую силу подскока. Но, конечно же, сила подскока не должна превышать количества друзей у Бузи (кабанчик хоть и уважаемый, но не выскочка).




*/
