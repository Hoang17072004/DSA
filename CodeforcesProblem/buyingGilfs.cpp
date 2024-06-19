#include <bits/stdc++.h>

using namespace std;

template<typename T>
bool smin(T& a, const T& b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

template<typename T>
bool smax(T& a, const T& b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

const int INF = 0x3f3f3f3f;
const int N = 500100;

std::pair<int, int> a[N];

void run() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &a[i].first, &a[i].second);
    }

    sort(a, a + n, [&](const pair<int, int>& p1, 
                            const pair<int, int>& p2) {
        return p1.second > p2.second || (p1.second == p2.second && p1.first < p2.first);
    });

    multiset<int> setik;
    for (int i = 0; i < n; ++i) {
        setik.insert(a[i].first);
    }

    int mx = -INF;
    int ans = INF;
    
    for (int i = 1; i < n; ++i) {
        smin(ans, abs(a[i].first - a[0].second));
    }
    
    for (int i = 0; i < n; ++i) {
        setik.erase(setik.find(a[i].first));
        if (i == 0) {
            mx = a[i].first;
            continue;
        }

        smin(ans, abs(mx - a[i].second));
        auto it = setik.lower_bound(a[i].second);
        if (it != setik.end() && *it >= mx) {
            smin(ans, abs(*it - a[i].second));
        }
        if (it != setik.begin() && *std::prev(it) >= mx) {
            smin(ans, abs(*prev(it) - a[i].second));
        }

        smax(mx, a[i].first);
    }

    printf("%d\n", ans);
}

int main(void) {
    int t;
    scanf("%d", &t);
    while (t--) {
        run();
    }
    return 0;
}