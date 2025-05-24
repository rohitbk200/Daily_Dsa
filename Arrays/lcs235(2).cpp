class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int i = 0, j = 0, sum = 0, maxL = 0;
        int n = nums.size();

        while (j < n) {
            sum += nums[j];

            while (i <= j && sum > k) {
                sum -= nums[i];
                i++;
            }

            if (sum == k) {
                maxL = max(maxL, j - i + 1);
            }

            j++;
        }

        return maxL;
    }
};
