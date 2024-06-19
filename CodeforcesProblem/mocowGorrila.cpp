#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> pos_a(n + 1);
    vector<int> pos_b(n + 1);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        pos_a[a] = i + 1;
    }
    for (int i = 0; i < n; i++) {
        int b;
        cin >> b;
        pos_b[b] = i + 1;
    }
    int la = n, ra = 1, lb = n, rb = 1, ans = 0;
    for (int i = 1; i + 1 <= n; i++) {
        la = min(la, pos_a[i]);
        ra = max(ra, pos_a[i]);
        lb = min(lb, pos_b[i]);
        rb = max(rb, pos_b[i]);
        int min_la, max_ra, min_lb, max_rb;
        if (pos_a[i + 1] < la) {
            min_la = pos_a[i + 1] + 1;
            max_ra = n;
        } else {
            min_la = 1;
            max_ra = pos_a[i + 1] - 1;
        }
        if (pos_b[i + 1] < lb) {
            min_lb = pos_b[i + 1] + 1;
            max_rb = n;
        } else {
            min_lb = 1;
            max_rb = pos_b[i + 1] - 1;
        }
        ans += max(min(la, lb) - max(min_la, min_lb) + 1, 0ll) * max(min(max_ra, max_rb) - max(ra, rb) + 1, 0ll);
    }
    ans += min(pos_a[1], pos_b[1]) * (min(pos_a[1], pos_b[1]) - 1) / 2;
    ans += (n - max(pos_a[1], pos_b[1])) * (n - max(pos_a[1], pos_b[1]) + 1) / 2;
    ans += abs(pos_a[1] - pos_b[1]) * (abs(pos_a[1] - pos_b[1]) - 1) / 2;
    ans++;
    cout << ans << endl;
}

signed main() {
    int q = 1;
    while (q--)
        solve();
    return 0;
}