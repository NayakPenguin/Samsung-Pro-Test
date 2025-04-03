#include <bits/stdc++.h>
using namespace std;

int main(){
    string s; cin>>s;
    int n = s.length();
    
    int a = 0, b = 0;
    
    map<int, int> mpp, vis;
    
    vis[0] = 1;
    mpp[0] = -1;
    
    int ans = n;
    
    for(int i = 0; i < n; i++){
        if(s[i] == 'R'){
            a++;
        }
        else b++;
        
        int val = a - b;
        
        if(vis[val]){
            ans = min(ans, n - (i - mpp[val]));
        }   
        else {
            vis[val] = 1;
            mpp[val] = i;
        }
        
    }
    
    cout<<ans<<endl;
    
    return 0;
}
