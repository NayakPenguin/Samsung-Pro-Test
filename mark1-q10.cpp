#include<bits/stdc++.h> 
using namespace std;

int n, m; 
int dp[1001][1001];

int helper(int idx, int lastRobot, vector<int>& v){
    // base case
    if(idx == v.size()){
        return 0;
    }
    
    // check cached value 
    if(dp[idx][lastRobot] != -1) return dp[idx][lastRobot];
    
    // transition 
    int usePrevRobot = (idx - lastRobot)*v[idx] + helper(idx + 1, lastRobot, v);
    
    int newRobot = m + helper(idx + 1, idx, v);
    
    // cache and return
    return dp[idx][lastRobot] = min(usePrevRobot, newRobot);
}

int main(){
    cin>>n>>m;
    
    vector<int> v(n, 0);
    for(int i = 0; i<n; i++) cin>>v[i];
    
    memset(dp, -1, sizeof(dp));
    
    int firstnonzero = -1;
    for(int i = 0; i<n; i++) if(v[i] != 0) {
        firstnonzero = i;
        break;
    }
    
    
    int ans = 0;
    if(firstnonzero != -1) {
        ans = m + helper(firstnonzero + 1, firstnonzero, v);
    }
    
    cout<<ans<<endl;
    
    return 0;
}
