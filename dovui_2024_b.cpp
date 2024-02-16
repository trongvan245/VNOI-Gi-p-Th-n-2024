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

struct Segment_Tree {
    vector<int> st, lazy;
    int n;
    Segment_Tree(int x) {
        n = x;
        st.resize(4 * x + 5);
        lazy.resize(4 * x + 5);
    }

    void down(int id, int l, int r) {
        if (!lazy[id])
            return;

        int mid = (l + r) / 2;
        st[id * 2] = mid - l + 1 - st[id * 2];
        st[id * 2 + 1] = r - mid - st[id * 2 + 1];
        lazy[id * 2] ^= 1;
        lazy[id * 2 + 1] ^= 1;

        lazy[id] = 0;
    }
    void upd(int u, int v) { upd(1, 1, n, u, v); }
    void upd(int id, int l, int r, int u, int v) {
        if (l > v || r < u)
            return;
        if (l >= u && r <= v) {
            st[id] = r - l + 1 - st[id];
            lazy[id] ^= 1;
            return;
        }

        down(id, l, r);
        int mid = (l + r) / 2;
        upd(id * 2, l, mid, u, v);
        upd(id * 2 + 1, mid + 1, r, u, v);
        st[id] = st[id * 2] + st[id * 2 + 1];
    }

    int get(int u, int v) { return get(1, 1, n, u, v); }
    int get(int id, int l, int r, int u, int v) {
        if (l > v || r < u)
            return 0;
        if (l >= u && r <= v)
            return st[id];
        down(id, l, r);
        int mid = (l + r) / 2;

        return get(id * 2, l, mid, u, v) + get(id * 2 + 1, mid + 1, r, u, v);
    }
};

void xuly() {
    int n, q;
    cin >> n >> q;
    Segment_Tree st(n);

    while (q--) {
        int t, l, r;
        cin >> t >> l >> r;
        ++l, ++r;
        if (t == 0) {
            st.upd(l, r);
        } else
            cout << st.get(l, r) << '\n';
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
