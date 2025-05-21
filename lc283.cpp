class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = -1, temp;

        // First loop: Find the index of the first zero in the array
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                j = i; // Store the position of the first zero
                break; // Exit loop once first zero is found
            }
        }

        // If there are no zeros, array is already in desired state
        if (j == -1) return;

        // Second loop: Traverse the rest of the array from j+1
        for (int i = j + 1; i < nums.size(); i++) {
            if (nums[i] != 0) {
                // Swap current non-zero element with the element at position j
                temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;

                // Move j to the next position where a zero exists
                j++;
            }
        }
    }
};
