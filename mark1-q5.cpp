#include <bits/stdc++.h>
using namespace std;

int n, k; 

bool helper(int maxDiff, vector<pair<int, int>>& v){
    for(int i = 0; i<n; i++){
        vector<int> temp;
        
        for(int j = i; j<n && (v[j].first - v[i].first) <= maxDiff; j++){
            temp.push_back(v[j].second);
        }
        
        if(temp.size() < k) continue;
        
        sort(temp.begin(), temp.end());
        
        int st_idx = 0, ed_idx = k-1;
        
        while(ed_idx < temp.size()){
            if(temp[k-1] - temp[0] <= maxDiff){
                return true;
            }
            
            st_idx++;
            ed_idx++;
        }
    }
    
    return false;
}

void solve(){
    cin>>n>>k;
    
    vector<pair<int, int>> v(n); 
    
    for(int i = 0; i<n; i++) v[i].first;
    for(int i = 0; i<n; i++) v[i].second;
    
    sort(v.begin(), v.end());
    
    // binary search on answer 
    
    int lw = 0, hg = 1e9, ans = 1e9;
    
    while(lw <= hg){
        int mid = lw + (hg - lw)/2;
        
        if(helper(mid, v)){
            ans = mid;
            hg = mid - 1;
        }
        else lw = mid + 1;
    }
    
    cout<<ans<<endl;
}

int main(){
    solve();
    return 0;
}
