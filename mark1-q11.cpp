#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int s; 
string A; 

int helper(int pos, int sum, int tight, vector<vector<vector<int>>>& dp){
    // base 
    if(pos == A.length()){
        if(sum == s) return 1;
        else return 0;
    }
    
    if(dp[pos][sum][tight] != -1) return dp[pos][sum][tight];
    
    int res = 0, limit = 9;
    // transition
    if(tight == 1){
        limit = A[pos] - '0';
    }
    
    for(int i = 0; i <= limit; i++){
        res += (helper(pos + 1, sum + i, tight && (i == limit), dp) % mod);
    }

    return dp[pos][sum][tight] = res % mod;
}

int main(){
    cin>>s;
    cin>>A;
    
    vector<vector<vector<int>>> dp(101, vector<vector<int>>(901, vector<int>(2, -1)));
    
    int ans = helper(0, 0, 1, dp);
    
    cout<<ans<<endl;
    
    return 0;
}
