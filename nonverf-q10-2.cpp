#include <bits/stdc++.h>
using namespace std;

int minGarbageCost(vector<int>& garbage, int m) {
    int n = garbage.size();
    vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

    dp[0][0] = m;  

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {  
            if (dp[i - 1][j] == INT_MAX) continue;  
            
            dp[i][j] = min(dp[i][j], dp[i - 1][j] + (i - j) * garbage[i]);

            dp[i][j] = min(dp[i][i], dp[i - 1][j] + m);
        }
    }

    int ans = INT_MAX;
    for (int j = 0; j < n; j++) {
        ans = min(ans, dp[n - 1][j]);
    }
    
    return ans;
}

int main() {
    vector<int> garbage = {3, 1, 4, 2}; 
    int m = 5;  

    cout<<minGarbageCost(garbage, m)<<endl;
    return 0;
}
