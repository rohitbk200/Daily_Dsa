/*
 * Problem: Count Inversions
 * -----------------------------------------
 * Goal: Given an array nums, count the number of pairs (i, j) such that
 *       i < j and nums[i] > nums[j].
 *
 * Approach: Merge Sort with counting during the merge step.
 *   - Recursively sort left and right halves.
 *   - While merging two sorted halves [low..mid] and [mid+1..high]:
 *       * If left value <= right value, take left (no new inversions).
 *       * Else (left value > right value), take right and add
 *         (mid - left + 1) to the count, because all remaining elements
 *         in the left half (from 'left' to 'mid') are > right value.
 *
 * Complexity:
 *   - Time:  O(n log n)  (merge sort)
 *   - Space: O(n)        (temporary buffer during merge)
 *
 * Notes:
 *   - 'cnt' is long long to avoid overflow on large arrays, and is cast
 *     back to int on return to match common LeetCode signatures.
 */

class Solution {
public:
    long long cnt = 0;  // total number of inversions accumulated across merges

    // Wrapper called by the judge; returns the inversion count.
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        mergesort(nums, n);     // sorts nums in-place and updates 'cnt'
        return (int)cnt;        // cast for return type; safe for typical constraints
    }

    // Merge two sorted ranges arr[low..mid] and arr[mid+1..high] into arr[low..high],
    // counting cross-inversions where an element from the left half exceeds an element
    // from the right half.
    void merge(vector<int>& arr, int low, int mid, int high) {
        vector<int> temp;       // temporary buffer to build merged output
        int left  = low;        // pointer into left half
        int right = mid + 1;    // pointer into right half

        // Merge while both halves have remaining elements
        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                // No new inversions; take from left
                temp.push_back(arr[left]);
                left++;
            } else {
                // arr[left] > arr[right]:
                // All elements from arr[left..mid] are > arr[right] (since left half is sorted),
                // so they each form an inversion with arr[right].
                temp.push_back(arr[right]);
                cnt += (mid - left + 1);  // count these inversions in one shot
                right++;
            }
        }

        // Append any remaining elements from left or right
        while (left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }
        while (right <= high) {
            temp.push_back(arr[right]);
            right++;
        }

        // Copy merged result back into the original array slice [low..high]
        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
    }

    // Standard top-down merge sort over arr[low..high].
    void ms(vector<int>& arr, int low, int high) {
        if (low >= high) return;        // base case: 0 or 1 element
        int mid = (low + high) / 2;     // split range
        ms(arr, low, mid);              // sort left half
        ms(arr, mid + 1, high);         // sort right half
        merge(arr, low, mid, high);     // merge and count cross-inversions
    }

    // Convenience wrapper to sort the first n elements and count inversions.
    void mergesort(vector<int>& nums, int n) {
        if (n > 1) ms(nums, 0, n - 1);
    }
};
