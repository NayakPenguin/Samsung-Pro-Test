#include <bits/stdc++.h>
using namespace std;


// Function to check if a value lies within any segment
bool isInSegment(const set<pair<int, int>> &segments, int val) {
    if (segments.empty()) return false;
   
    auto it = segments.upper_bound({val, INT_MAX});
    if (it != segments.begin()) {
        --it;
        if (it->first <= val && val <= it->second)
            return true;
    }
    return false;
}


// Function to merge overlapping segments in a single linear pass
void mergeOverlappingSegments(vector<pair<int, int>> &rawSegments, set<pair<int, int>> &mergedSegments) {
    if (rawSegments.empty()) return;
   
    // Sort segments by start position
    sort(rawSegments.begin(), rawSegments.end());
   
    // Initialize with first segment
    int start = rawSegments[0].first;
    int end = rawSegments[0].second;
   
    // Process all segments in a linear pass
    for (int i = 1; i < rawSegments.size(); i++) {
        if (rawSegments[i].first <= end + 1) {
            // Current segment overlaps or is adjacent, extend end
            end = max(end, rawSegments[i].second);
        } else {
            // No overlap, insert previous merged segment and start new one
            mergedSegments.insert({start, end});
            start = rawSegments[i].first;
            end = rawSegments[i].second;
        }
    }
   
    // Insert the last merged segment
    mergedSegments.insert({start, end});
}


int countPointsOnPath(vector<int> &Xq, vector<int> &Yq, vector<int> &Xp, vector<int> &Yp) {
    int M = Xp.size(), N = Xq.size();
   
    // Store raw segments first
    map<int, vector<pair<int, int>>> rawVertical, rawHorizontal;
    map<int, set<pair<int, int>>> vertical, horizontal;


    // Collect all segments
    for (int i = 1; i < M; ++i) {
        int x1 = Xp[i - 1], y1 = Yp[i - 1];
        int x2 = Xp[i], y2 = Yp[i];


        if (x1 == x2) // Vertical segment
            rawVertical[x1].push_back({min(y1, y2), max(y1, y2)});
        else // Horizontal segment
            rawHorizontal[y1].push_back({min(x1, x2), max(x1, x2)});
    }
   
    // Process all segments to merge overlapping ones
    for (auto &pai : rawVertical) {
        auto key=pai.first;
        auto segments=pai.second;
        mergeOverlappingSegments(segments, vertical[key]);
    }
   
    for (auto &pai : rawHorizontal) {
        auto key=pai.first;
        auto segments=pai.second;
        mergeOverlappingSegments(segments, horizontal[key]);
    }


    // Check query points
    int count = 0;
    for (int i = 0; i < N; ++i) {
        if (isInSegment(vertical[Xq[i]], Yq[i]) || isInSegment(horizontal[Yq[i]], Xq[i]))
            count++;
    }


    return count;
}


int main() {
    int T;
    cin >> T;
   
    while (T--) {
        int N, M;
        cin >> N >> M; // Number of query points and path points
       
        vector<int> Xq(N), Yq(N), Xp(M), Yp(M);
       
        for (int i = 0; i < N; i++) cin >> Xq[i];
        for (int i = 0; i < N; i++) cin >> Yq[i];
        for (int i = 0; i < M; i++) cin >> Xp[i];
        for (int i = 0; i < M; i++) cin >> Yp[i];
       
        cout <<"#"<<countPointsOnPath(Xq, Yq, Xp, Yp) << endl;
    }
   
    return 0;
}
