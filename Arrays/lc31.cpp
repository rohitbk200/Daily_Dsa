class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int ind = -1; // Index of the first decreasing element from the end
        int n = nums.size();

        // Step 1: Find the first index from the end where nums[i] < nums[i + 1]
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                ind = i;
                break;
            }
        }

        // Step 2: If no such index found, the array is in descending order
        // Reverse it to get the smallest permutation
        if (ind == -1) {
            sort(nums.begin(), nums.end());
            return;
        }

        // Step 3: Find the next greater element to the right of index 'ind' and swap
        for (int i = n - 1; i > ind; i--) {
            if (nums[i] > nums[ind]) {
                swap(nums[i], nums[ind]);
                break;
            }
        }

        // Step 4: Reverse the subarray to the right of 'ind' to get the next smallest lexicographic permutation
        reverse(nums.begin() + ind + 1, nums.end());
    }
};
