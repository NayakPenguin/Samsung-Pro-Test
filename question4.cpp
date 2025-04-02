#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
#include <tuple>

using namespace std;

struct State {
    int x, y;
    int goods;
    int cost;
};

int maxUnloadedGoods(int h, int w, int C, vector<vector<int>>& grid) {
    // Find garage, warehouses, and airports
    vector<pair<int, int>> warehouses;
    vector<pair<int, int>> airports;
    pair<int, int> garage;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (grid[i][j] == 2) {
                garage = {i, j};
            } else if (grid[i][j] == 3) {
                warehouses.emplace_back(i, j);
            } else if (grid[i][j] == 4) {
                airports.emplace_back(i, j);
            }
        }
    }

    // Directions: up, down, left, right
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    // DP table: dp[x][y][goods] = min cost to reach (x,y) with 'goods' loaded
    vector<vector<vector<int>>> dp(h, vector<vector<int>>(w, vector<int>(14, INT_MAX)));
    dp[garage.first][garage.second][0] = 0;

    // Priority queue: (cost, x, y, goods)
    priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, greater<tuple<int, int, int, int>>> pq;
    pq.push({0, garage.first, garage.second, 0});

    int maxGoods = 0;

    while (!pq.empty()) {
        auto [currentCost, x, y, goods] = pq.top();
        pq.pop();

        if (currentCost > C) {
            continue;
        }

        // Check if current position is an airport and update maxGoods
        if (grid[x][y] == 4) {
            maxGoods = max(maxGoods, goods);
        }

        // If current cost is higher than recorded, skip
        if (currentCost > dp[x][y][goods]) {
            continue;
        }

        // Option to load goods if current position is a warehouse and goods can be increased
        if (grid[x][y] == 3 && goods < 13) {
            int newGoods = goods + 1;
            if (currentCost < dp[x][y][newGoods]) {
                dp[x][y][newGoods] = currentCost;
                pq.push({currentCost, x, y, newGoods});
            }
        }

        // Option to unload goods if current position is an airport and goods > 0
        if (grid[x][y] == 4 && goods > 0) {
            int newGoods = 0;
            if (currentCost < dp[x][y][newGoods]) {
                dp[x][y][newGoods] = currentCost;
                pq.push({currentCost, x, y, newGoods});
            }
        }

        // Move to adjacent cells
        for (auto [dx, dy] : directions) {
            int nx = x + dx;
            int ny = y + dy;
            if (nx >= 0 && nx < h && ny >= 0 && ny < w && grid[nx][ny] != 1) {
                int moveCost = 1 + goods;
                int newCost = currentCost + moveCost;
                if (newCost < dp[nx][ny][goods]) {
                    dp[nx][ny][goods] = newCost;
                    pq.push({newCost, nx, ny, goods});
                }
            }
        }
    }

    return maxGoods;
}
