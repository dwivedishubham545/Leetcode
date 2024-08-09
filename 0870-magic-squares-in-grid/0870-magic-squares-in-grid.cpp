class Solution {
public:
    bool isMagicSquare(vector<vector<int>> &grid, int r, int c){
        vector<bool> visited(10, false);  // To track visited numbers from 1 to 9
        
        // Check all values in the 3x3 square
        for(int i = 0; i < 3; ++i) {
            for(int j = 0; j < 3; ++j) {
                int val = grid[r + i][c + j];
                if (val < 1 || val > 9 || visited[val]) {
                    return false;
                }
                visited[val] = true;
            }
        }
        
        // Check sums of rows, columns, and diagonals
        int sum = grid[r][c] + grid[r][c+1] + grid[r][c+2]; // First row sum
        for(int i = 1; i < 3; ++i) {
            int rowSum = grid[r+i][c] + grid[r+i][c+1] + grid[r+i][c+2];
            if (rowSum != sum) {
                return false;
            }
        }
        
        for(int j = 0; j < 3; ++j) {
            int colSum = grid[r][c+j] + grid[r+1][c+j] + grid[r+2][c+j];
            if (colSum != sum) {
                return false;
            }
        }
        
        int diagonalSum1 = grid[r][c] + grid[r+1][c+1] + grid[r+2][c+2];
        int diagonalSum2 = grid[r][c+2] + grid[r+1][c+1] + grid[r+2][c];
        
        if (diagonalSum1 != sum || diagonalSum2 != sum) {
            return false;
        }
        
        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int cnt = 0;
        for(int i = 0; i <= rows - 3; ++i) {
            for(int j = 0; j <= cols - 3; ++j) {
                if(isMagicSquare(grid, i, j)) {
                    ++cnt;
                }
            }
        }
        return cnt;
    }
};
