class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size() - 1;

        while (mid <= high) {
            if (nums[mid] == 0) {
                // Swap 0 to the beginning
                std::swap(nums[low], nums[mid]);
                low++;
                mid++;
            } 
            else if (nums[mid] == 1) {
                // 1 is in the correct middle zone
                mid++;
            } 
            else {
                // Swap 2 to the end, but do NOT move mid yet
                std::swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};
