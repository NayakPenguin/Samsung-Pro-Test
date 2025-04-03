#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vector<string> v(n);
        for (auto &s : v) cin >> s;
       
        vector<vector<ll>> mp(10, vector<ll>(10, 0));
       
        for (ll i = n - 1; i >= 0; i--) {
            int first = v[i][0] - '0', last = v[i].back() - '0';
            for (ll j = 0; j <= 9; j++) {
                if (mp[last][j] != 0) {
                    mp[first][j] = max(mp[first][j], mp[last][j] + (ll)v[i].length());
                }
            }
            mp[first][last] = max(mp[first][last], (ll)v[i].length());
        }
       
        ll res = 0;
        for (ll i = 0; i <= 9; i++) {
            res = max(res, mp[i][i]);
        }
       
        cout << res << "\n";
    }
    return 0;
}
