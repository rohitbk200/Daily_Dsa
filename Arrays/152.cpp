class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // We track the best product seen so far in max1.
        // Initialize to INT_MIN so arrays of all negatives are handled.
        int max1 = INT_MIN;

        // prefix: running product from the left
        // suffix: running product from the right
        int prefix = 1;
        int suffix = 1;

        for (int i = 0; i < nums.size(); i++) {

            // If the current element on the LEFT is zero, we reset both runs.
            // (Note: this resets suffix too, even though suffix is built from the RIGHT.
            // A more precise approach is to reset each run when that run itself becomes 0.)
            if (nums[i] == 0) {
                prefix = 1;
                suffix = 1;
            }

            // Multiply into the forward (prefix) product with nums[i]
            prefix = prefix * nums[i];

            // Multiply into the backward (suffix) product with the mirrored element
            // nums[n-1-i] so that in one pass we simulate scanning from the right.
            suffix = suffix * nums[nums.size() - i - 1];

            // Update the answer with the best of the two running products.
            // Taking max of prefix and suffix helps handle odd/even negatives.
            max1 = max(max1, max(prefix, suffix));
        }

        // The maximum product of any contiguous subarray
        return max1;
    }
};
