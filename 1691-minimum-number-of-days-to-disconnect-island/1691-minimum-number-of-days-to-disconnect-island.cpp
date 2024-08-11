class Solution {
    vector<int> xDir = {0, 0, -1, 1};
    vector<int> yDir = {-1, 1, 0, 0};

    bool IsSafe(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& visited) {
        return (i >= 0 && j >= 0 && i < grid.size() && j < grid[0].size() && !visited[i][j] && grid[i][j] == 1);
    }

    void IslandCount(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& visited) {
        visited[i][j] = true;
        for (int k = 0; k < 4; k++) {
            int newRow = i + xDir[k];
            int newCol = j + yDir[k];
            if (IsSafe(grid, newRow, newCol, visited)) {
                IslandCount(grid, newRow, newCol, visited);
            }
        }
    }

    int CountLand(vector<vector<int>>& grid, vector<vector<bool>>& visited) {
        int count = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    IslandCount(grid, i, j, visited);
                    count++;
                }
            }
        }
        return count;
    }

public:
    int minDays(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        int count = CountLand(grid, visited);
        if (count > 1 || count == 0) return 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;
                    vector<vector<bool>> mat(rows, vector<bool>(cols, false));
                    int count2 = CountLand(grid, mat);
                    grid[i][j] = 1;
                    if (count2 > 1 || count2 == 0) {
                        return 1;
                    }
                }
            }
        }

        return 2;
    }
};
