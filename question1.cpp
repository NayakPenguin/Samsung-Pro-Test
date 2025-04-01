#include <bits/stdc++.h>
using namespace std;

unordered_map<int, vector<pair<int, int>>> verticalSegments;   // x -> list of (y1, y2)
unordered_map<int, vector<pair<int, int>>> horizontalSegments; // y -> list of (x1, x2)

void addSegment(int x1, int y1, int x2, int y2) {
    if (x1 == x2) {  // Vertical segment
        int ymin = min(y1, y2), ymax = max(y1, y2);
        verticalSegments[x1].push_back({ymin, ymax});
    } else {  // Horizontal segment
        int xmin = min(x1, x2), xmax = max(x1, x2);
        horizontalSegments[y1].push_back({xmin, xmax});
    }
}

bool isPointOnPath(int qx, int qy) { // we can try BINARY SEARCH for searching as well
    // Check vertical segments
    if (verticalSegments.count(qx)) {
        for (auto &seg : verticalSegments[qx]) {
            if (seg.first <= qy && qy <= seg.second) return true;
        }
    }

    // Check horizontal segments
    if (horizontalSegments.count(qy)) {
        for (auto &seg : horizontalSegments[qy]) {
            if (seg.first <= qx && qx <= seg.second) return true;
        }
    }

    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> px(n), py(n), sx(m), sy(m);

    // Input the n query points
    for (int i = 0; i < n; i++) cin >> px[i];
    for (int i = 0; i < n; i++) cin >> py[i];

    // Input the m path points (turning points)
    for (int i = 0; i < m; i++) cin >> sx[i];
    for (int i = 0; i < m; i++) cin >> sy[i];

    // Build the path segments
    for (int i = 1; i < m; i++) {
        addSegment(sx[i - 1], sy[i - 1], sx[i], sy[i]);
    }

    // Sort segments for binary search
    for (auto &kv : verticalSegments) 
        sort(kv.second.begin(), kv.second.end());

    for (auto &kv : horizontalSegments) 
        sort(kv.second.begin(), kv.second.end());

    // Answer queries
    for (int i = 0; i < n; i++) {
        cout << (isPointOnPath(px[i], py[i]) ? "YES" : "NO") << endl;
    }

    return 0;
}
