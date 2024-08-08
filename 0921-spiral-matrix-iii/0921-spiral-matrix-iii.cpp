class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int totalcell = rows * cols;
        vector<vector<int>> result(totalcell, vector<int>(2));
        int r = rStart, c = cStart, direction = 0;
        int steps = 1;
        int cellcnt = 0;
        
        while (cellcnt < totalcell) {
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < steps; j++) {
                    if (r >= 0 && r < rows && c >= 0 && c < cols) {
                        result[cellcnt][0] = r;
                        result[cellcnt][1] = c;
                        cellcnt++;
                    }
                    r += dir[direction][0];
                    c += dir[direction][1];
                }
                direction = (direction + 1) % 4;
            }
            steps++;
        }
        return result;
    }
};
