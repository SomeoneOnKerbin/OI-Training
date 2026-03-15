#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e5 + 5;

vector<int> a[N];
bool exists[N];

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int get_exists(int n) {
    int x = rng() % n + 1;
    while (!exists[x]) {
        x = rng() % n + 1;
    }
    return x;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n = 10;
    for (int i = 1; i <= n; i++) {
        exists[i] = true;
    }

    for (int i = 1; i <= n; i++) {
        int len = rng() % 10 + 1;
        cout << len << " ";

        for (int j = 0; j < len; j++) {
            a[i].push_back(rng() % 10 + 1);
            cout << a[i].back() << " ";
        }

        cout << "\n";
    }

    int q = 5;
    cout << q << "\n";

    while (q--) {
        int op = rng() % 4 + 1;
        cout << op << " ";

        if (op == 1) {
            int x = get_exists(n);
            int y = rng() % 10 + 1;

            a[x].push_back(y);
            cout << x << " " << y << "\n";
        } else if (op == 2) {
            int x = get_exists(n);
            cout << x << "\n";

            a[x].pop_back();
        } else if (op == 3) {
            int m = rng() % n + 1;
            cout << m << " ";

            vector<int> seq(m);
            for (auto &x : seq) {
                x = get_exists(n);
                cout << x << " ";
            }

            cout << "\n";
        }

        return 0;
    }