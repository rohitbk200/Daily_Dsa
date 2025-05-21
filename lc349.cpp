class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;
        vector<int> ans;

        // Make sure the arrays are sorted
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) {
                i++;
            }
            else if (nums1[i] > nums2[j]) {
                j++;
            }
            else { // nums1[i] == nums2[j]
                if (ans.empty() || ans.back() != nums1[i]) // avoid duplicates
                    ans.push_back(nums1[i]);
                i++;
                j++;
            }
        }

        return ans;
    }
};
