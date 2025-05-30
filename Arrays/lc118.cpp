class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> fans;  // This will store the final Pascal's Triangle
        
        // Loop through each row from 0 to numRows - 1
        for(int i = 0; i < numRows; i++) {   
            vector<int> ansmat;     // To store the current row
            long long ans = 1;      // First element of each row is always 1
            ansmat.push_back(1);    // Add the first element

            // Compute the rest of the elements using binomial coefficients
            for(int j = 1; j <= i; j++) {
                // Calculate next element using previous element
                ans = ans * (i - j + 1) / j;
                ansmat.push_back(ans);  // Add computed value to current row
            }

            // Add the current row to the result
            fans.push_back(ansmat);
        }

        return fans;  // Return the full Pascal's Triangle
    }
};
