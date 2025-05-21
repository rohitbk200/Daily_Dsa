class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<long long, int> PreSumMap;  // Stores first occurrence index of each prefix sum
        long long sum = 0;
        int maxLen = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];  // Compute running prefix sum

            if (sum == k) {
                // If total sum from start to current index is k
                maxLen = max(maxLen, i + 1);
            }

            long long rem = sum - k;  // Look for (sum - k) in map

            if (PreSumMap.find(rem) != PreSumMap.end()) {
                int len = i - PreSumMap[rem];  // Subarray from rem's index + 1 to i
                maxLen = max(maxLen, len);
            }

            // Only store the first occurrence of a particular prefix sum
            if (PreSumMap.find(sum) == PreSumMap.end()) {
                PreSumMap[sum] = i;
            }
        }

        return maxLen;
    }
};
