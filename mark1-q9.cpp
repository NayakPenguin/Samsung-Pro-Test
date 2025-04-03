#include <bits/stdc++.h>
using namespace std;

int calcDist(pair<int, int> p1, pair<int, int> p2){
    return (max(p1.first, p2.first) - min(p1.first, p2.first)) + (max(p1.second, p2.second) - min(p1.second, p2.second));
}

void solve(){
    int n, m; cin>>n>>m;
    
    pair<int, int> dest; cin>>dest.first>>dest.second;
    
    vector<pair<int, int>> cars(n);
    
    for(int i = 0; i<n; i++) cin>>cars[i].first>>cars[i].second;
    
    int maxDist = 0;
    
    int parity = -1;
    
    for(int i = 0; i<n; i++) {
        int dist = calcDist(cars[i], dest);
        
        maxDist = max(maxDist, dist);
        
        int currParity = dist % 2;
        
        if(parity == -1 || parity == currParity) parity = currParity;
        else{
            cout<<-1<<endl;
            return;
        }
    }
    
    
    // now t(t+1)/2 >= maxDist && the (totalTime - maxDist) % 2 == parity should hold
    
    int lw = 0, hg = 10000, ans = hg; 
    
    while(lw <= hg){
        int mid = lw + (hg - lw)/2;
        
        int val = (mid * (mid + 1))/2;
        
        if(val >= maxDist) {
            ans = mid;
            hg = mid - 1;
        }
        else {
            lw = mid + 1;
        }
    }
    
    int totalTime = (ans * (ans + 1))/2;
    
    while(totalTime % 2 != parity){
        ans++;
        totalTime = (ans * (ans + 1))/2;
    }
    
    cout<<ans<<endl;
}

int main(){
    solve();
    return 0;
}
