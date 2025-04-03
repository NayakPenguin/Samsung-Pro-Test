#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n; 
    
    vector<int> a(n), b(n), all;
    
    for(int i = 0; i<n; i++) cin>>a[i], all.push_back(a[i]);
    for(int i = 0; i<n; i++) cin>>b[i], all.push_back(b[i]);
    
    int m = all.size();
    
    int ans = 0;
    
    for(int i = 0; i<m; i++){
        int x, y;
        int val1 = upper_bound(a.begin(), a.end(), all[i]) - a.begin();
        int val2 = upper_bound(b.begin(), b.end(), all[i]) - b.begin();
        
        if(val1 == n) x = 0;
        else x = n + 1 - val1;
        
        if(val2 == n) y = 0;
        else y = n + 1 - val2;
        
        // cout<<all[i]<<" : "<<x<<" "<<y<<endl;
        
        ans = max(ans, x - y);
    }
    
    cout<<ans<<endl;
    
    
    return 0;
}
