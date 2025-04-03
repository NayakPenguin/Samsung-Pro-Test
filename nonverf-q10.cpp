#include <bits/stdc++.h>
using namespace std;

// if last robot taken position doesn't matter

int main(){
    int n, m; cin>>n>>m;
    
    vector<int> v(n, 0); 
    
    for(int i = 0; i<n; i++) cin>>v[i];
    
    vector<int> prefixSum(n, 0);
    prefixSum[0] = v[0];
    for (int i = 1; i < n; i++) {
        prefixSum[i] = prefixSum[i - 1] + v[i];
    }
    
    vector<vector<int>> dp(n+1, vector<int>(n+1, INT_MAX));
    
    dp[0][1] = v[0] + m;
    dp[0][2] = v[0] + m;
    
    for(int i = 0; i<n; i++){
        for(int j = 1; j<=i + 1; j++){
            dp[i][j] = dp[i-1][j] + v[i];
            
            for (int k = 0; k < i; k++) {
                dp[i][j] = min(dp[i][j], dp[k][j-1] + m + (prefixSum[i-1] - prefixSum[k]));
            }
        }
    }
    
    int ans = INT_MAX;
    for(int i = 0; i<n; i++){
        ans = min(ans, dp[n-1][i]);
    }
    
    cout<<ans<<endl;
    
    return 0;
}
