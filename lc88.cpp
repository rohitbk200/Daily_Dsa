class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ans;  // Temporary vector to store merged result
        int i = 0, j = 0;

        // Merge elements from nums1 and nums2 in sorted order
        while (i < m && j < n) {
            if (nums1[i] <= nums2[j]) {
                ans.push_back(nums1[i]);  // Add nums1[i] if smaller or equal
                i++;
            } else {
                ans.push_back(nums2[j]);  // Add nums2[j] if smaller
                j++;
            }
        }

        // Add remaining elements from nums1 if any
        while (i < m) {
            ans.push_back(nums1[i]);
            i++;
        }

        // Add remaining elements from nums2 if any
        while (j < n) {
            ans.push_back(nums2[j]);
            j++;
        }

        // Copy merged elements back to nums1 (in-place)
        for (int k = 0; k < m + n; ++k) {
            nums1[k] = ans[k];
        }
    }
};
