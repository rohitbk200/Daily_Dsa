class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = (int)nums.size();
        int ans = INT_MIN;     // best seen so far
        int prefix = 1;        // product from the left
        int suffix = 1;        // product from the right

        for (int i = 0; i < n; ++i) {
            prefix *= nums[i];
            suffix *= nums[n - 1 - i];

            ans = max(ans, max(prefix, suffix));

            // reset each run independently if it becomes zero
            if (prefix == 0) prefix = 1;
            if (suffix == 0) suffix = 1;
        }
        return ans;
    }
};

