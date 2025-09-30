class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
    int n=nums.size(),low = 0, high = n - 1;
    int ans = n;                           // default: not found → position n

    while (low <= high) {
        int mid = (low + high) / 2;  // avoid overflow
        if (nums[mid] >=target) {               // maybe an answer
            ans = mid;
            high = mid - 1;                // look for a smaller index on the left
        } else {
            low = mid + 1;                 // look on the right
        }
    }
    return ans;

    }
};