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
ll dp[100001][11][11];
ll f(ll index, char start, char end, vector<string> &v)
{
    if (index == v.size())
    {
        if (start == end)
        {
            return 0;
        }
        else
        {
            return -1e15;
        }
    }
    if (dp[index][(start == '@' ? 10 : start - '0')][(end == '@' ? 10 : end - '0')] != -1)
    {
        return dp[index][(start == '@' ? 10 : start - '0')][(end == '@' ? 10 : end - '0')];
    }
    ll ans = -1e15;
    ans = max(ans, f(index + 1, start, end, v));
    if (end == v[index][0] || end == '@')
    {
        ans = max(ans, (ll)v[index].size() + f(index + 1, (start == '@' ? v[index][0] : start), v[index][v[index].size() - 1], v));
    }
    return dp[index][(start == '@' ? 10 : start - '0')][(end == '@' ? 10 : end - '0')] = ans;
}
void solve()
{
    ll n;
    cin >> n;
    vector<string> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    ll ans = 0;
    memset(dp, -1, sizeof(dp));
    for (ll i = 0; i < n; i++)
    {
        ans = max(ans, f(i, '@', '@', v));
    }
    cout << (ans <= 0 ? 0 : ans) << "\n";
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
