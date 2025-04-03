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
/*There are 'n' stones in a row from 0 to n-1. For every ith stone , there are 2 values associated with it, a[i] and b[i] . You have to remove all the stones from the row one by one. Removing the ith stone follows the rule :

 If (i-1)th and (i+1)th stones are still present , then , cost of removing the ith stone is b[i].

 if either (i-1)th or (i+1)th stone is present , then cost of removing the ith stone is a[i].

 if neither (i-1)th nor (i+1)th stone is present , the cost of removing the ith stone is 0.

 Find the minimum total cost of removing all the stones.

 Constraints : 1 <= n <= 50000 1 <= a[i] , b[i] <= 1000 */
ll n;
ll a[50001], b[50001];
ll dp[50001][2];
void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    memset(dp, 0, sizeof(dp));
    // dp[i][0] -> i+1 first, then i
    // dp[i][0] -> i first then i+1
    dp[0][0] = 0;
    dp[0][1] = a[0];
    for (int i = 1; i < n; i++)
    {
        dp[i][0] = min(dp[i - 1][0] + a[i], dp[i - 1][1] + 0);
        dp[i][1] = min(dp[i - 1][0] + b[i], dp[i - 1][1] + a[i]);
    }
    cout << dp[n - 1][0] << "\n";
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
