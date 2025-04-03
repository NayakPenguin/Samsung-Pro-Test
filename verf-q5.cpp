#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <map>
#include <set>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
using namespace std;
using ll = long long;
ll n, k;
vector<pair<ll, ll>> v;
// TC -> O(log(maxdiff)*(N*N*log(N)))-> N^2log(N)log(maxdiffs)
bool check(ll mid)
{
    int j = 0;
    ll cnt = 0;
    for (int i = 0; i < n; i++) // N
    {
        while (j < i && (v[i].first - v[j].first > mid))
        {
            j++;
        }

        if (i - j + 1 >= k) // mid 4 -> k = 3 //  1 3 6 6 6 6 12 //
        {
            vector<int> width;
            for (int index = j; index <= i; index++)
            {
                width.push_back(v[index].second);
            }
            sort(width.begin(), width.end()); // NlogN
            for (int i = 0; i + k - 1 < width.size(); i++)
            {
                if (width[i + k - 1] - width[i] <= mid)
                {
                    return true;
                }
            }
        }
    }

    return false;
}
void solve()
{
    // first height, second is width
    cin >> n >> k;
    v.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end());
    ll lo = 0, hi = 1e15;
    ll ans = -1;
    while (lo <= hi)
    {
        ll mid = (lo + hi) / 2;
        if (check(mid))
        {
            ans = mid;
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }
    cout << ans << "\n";
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
}
