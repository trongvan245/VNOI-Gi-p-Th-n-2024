// Hello I'm Nekan
//
#include <bits/stdc++.h>
#define Nekan "test"
#define fi first
#define se second
#define pb push_back
#define zs(v) ((int)(v).size())
#define BIT(x, i) (((x) >> (i)) & 1)
#define pii pair<int, int>

typedef long double ld;
typedef long long ll;

const int N = 4e6 + 5;
const long long mod = 1e9 + 7; // 998244353;
const int LIM = 4e6;

using namespace std;

int n;
ll f[N], ans[N];
vector<int> d[N];

void build() {
    for (int i = 1; i <= LIM; ++i)
        f[i] = i - 1;

    for (int i = 1; i <= LIM; ++i)
        for (int j = i * 2; j <= LIM; j += i)
            f[j] -= f[i];

    for (int i = 1; i <= LIM; ++i)
        for (int j = i * 2; j <= LIM; j += i)
            ans[j] += f[j / i - 1];
}

void xuly() {
    build();
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        cout << ans[x] << ' ';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    if (fopen(Nekan ".inp", "r")) {
        freopen(Nekan ".inp", "r", stdin);
        freopen(Nekan ".out", "w", stdout);
    }
    int t = 1;
    // cin >> t;
    while (t--)
        xuly();
}

// Surely nothing could go wrong.
