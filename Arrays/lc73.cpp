class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int col0 = 1;
        int n = matrix.size(), m = matrix[0].size();

        // First pass: mark rows and columns that need to be zeroed
        for (int i = 0; i < n; i++) {
            if (matrix[i][0] == 0) col0 = 0; // If first column needs to be zeroed

            for (int j = 1; j < m; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;     // Mark the row
                    matrix[0][j] = 0;     // Mark the column
                }
            }
        }

        // Second pass: set matrix cells to 0 using marks
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Zero the first row if needed
        if (matrix[0][0] == 0) {
            for (int j = 0; j < m; j++) {
                matrix[0][j] = 0;
            }
        }

        // Zero the first column if needed
        if (col0 == 0) {
            for (int i = 0; i < n; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};
