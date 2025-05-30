class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();         // Number of rows
        int m = matrix[0].size();      // Number of columns
        int left = 0, right = m - 1;
        int top = 0, bottom = n - 1;
        vector<int> ans;

        while (left <= right && top <= bottom) {
            // Traverse from left to right
            for (int i = left; i <= right; i++) {
                ans.push_back(matrix[top][i]);
            }
            top++; // Move top boundary down

            // Traverse from top to bottom
            for (int i = top; i <= bottom; i++) {
                ans.push_back(matrix[i][right]);
            }
            right--; // Move right boundary left

            // Check if there is still a row to process
            if (top <= bottom) {
                // Traverse from right to left
                for (int i = right; i >= left; i--) {
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--; // Move bottom boundary up
            }

            // Check if there is still a column to process
            if (left <= right) {
                // Traverse from bottom to top
                for (int i = bottom; i >= top; i--) {
                    ans.push_back(matrix[i][left]);
                }
                left++; // Move left boundary right
            }
        }

        return ans;
    }
};
