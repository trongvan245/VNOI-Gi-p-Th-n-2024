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
const int mbit = 30;

using namespace std;

int n;
int d[mbit], c[mbit];
void xuly() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;

        int maxx = 0;
        for (int j = 0; j < mbit; ++j) {
            if (!BIT(x, j))
                continue;
            ++d[j];
            maxx = j;
        }
        ++c[maxx];
        --d[maxx];

        bool ans = true;
        for (int j = 0; j < mbit; ++j) {
            if (c[j] - 1 > d[j])
                ans = false;
        }

        cout << (ans ? "YES" : "NO") << '\n';
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
