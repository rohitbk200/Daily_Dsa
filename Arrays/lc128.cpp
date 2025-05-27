class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> sett;  // Used to store unique elements for fast lookup
        int maxi = 1;  // Stores the maximum length of consecutive sequence

        // Insert all elements into the set
        for (int i = 0; i < nums.size(); i++) {
            sett.insert(nums[i]);
        }

        // Traverse each unique number
        for (auto it : sett) {
            // Check if it's the start of a sequence (i.e., previous number doesn't exist)
            if (sett.find(it - 1) == sett.end()) {
                int cnt = 1;
                int x = it;

                // Count the length of the consecutive sequence starting from `it`
                while (sett.find(x + 1) != sett.end()) {
                    x = x + 1;
                    cnt = cnt + 1;
                }

                // Update maximum if this sequence is longer
                maxi = max(maxi, cnt);
            }
        }

        // If input array is empty, return 0 instead of 1
        return nums.size() == 0 ? 0 : maxi;
    }
};
