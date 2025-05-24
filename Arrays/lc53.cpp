class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];     // Initialize with the first element
        int currentSum = nums[0]; // Track current subarray sum

        for (int i = 1; i < nums.size(); ++i) {
            // Either extend the current subarray or start a new one
            currentSum = max(nums[i], currentSum + nums[i]);
            maxSum = max(maxSum, currentSum);  // Update max if needed
        }

        return maxSum;
    }
};
