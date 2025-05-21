class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ans;  // Temporary vector to store the union without duplicates
        int i = 0, j = 0; // Pointers for nums1 and nums2 respectively

        // Traverse both arrays until one is exhausted
        while (i < m && j < n) {
            if (nums1[i] <= nums2[j]) {
                // Add nums1[i] if ans is empty or last element is different (to avoid duplicates)
                if (ans.size() == 0 || ans.back() != nums1[i]) {
                    ans.push_back(nums1[i]);
                }
                i++;
            } else {
                // Add nums2[j] if ans is empty or last element is different (to avoid duplicates)
                if (ans.size() == 0 || ans.back() != nums2[j]) {
                    ans.push_back(nums2[j]);
                }
                j++;
            }
        }

        // Add remaining elements from nums1 (if any), skipping duplicates
        while (i < m) {
            if (ans.size() == 0 || ans.back() != nums1[i]) {
                ans.push_back(nums1[i]);
            }
            i++;
        }

        // Add remaining elements from nums2 (if any), skipping duplicates
        while (j < n) {
            if (ans.size() == 0 || ans.back() != nums2[j]) {
                ans.push_back(nums2[j]);
            }
            j++;
        }

        // Replace nums1 with the union stored in ans
        nums1 = ans;
    }
};
