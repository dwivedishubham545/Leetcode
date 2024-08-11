class Solution {
public:
    int minDays(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        auto countIslands = [&](vector<vector<int>>& grid) {
            vector<vector<int>> visited(m, vector<int>(n, 0));
            int islands = 0;
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (grid[i][j] == 1 && !visited[i][j]) {
                        islands++;
                        queue<pair<int, int>> q;
                        q.push({i, j});
                        visited[i][j] = 1;
                        while (!q.empty()) {
                            int x = q.front().first;
                            int y = q.front().second;
                            q.pop();
                            int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
                            for (auto& dir : dirs) {
                                int nx = x + dir[0];
                                int ny = y + dir[1];
                                if (nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] == 1 && !visited[nx][ny]) {
                                    visited[nx][ny] = 1;
                                    q.push({nx, ny});
                                }
                            }
                        }
                    }
                }
            }
            return islands;
        };
        if (countIslands(grid) != 1) return 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;
                    if (countIslands(grid) != 1) return 1;
                    grid[i][j] = 1; 
                }
            }
        }
        return 2;
    }
};