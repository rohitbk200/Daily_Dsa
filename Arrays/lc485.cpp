class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCount = 0;  // To keep track of the maximum count of 1s
        int currentCount = 0;  // To count the current streak of 1s

        // Loop through each element in the array
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                // If current element is 1, increase current streak
                currentCount++;
            } else {
                // If it's 0, update maxCount if needed and reset current streak
                maxCount = max(maxCount, currentCount);
                currentCount = 0;
            }
        }

        // Final check in case the array ends with 1s
        maxCount = max(maxCount, currentCount);

        return maxCount;
    }
};
