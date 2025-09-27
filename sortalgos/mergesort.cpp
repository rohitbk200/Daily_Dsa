class Solution {
public:

    // Merge two sorted halves arr[low..mid] and arr[mid+1..high] into arr[low..high].
    void merge(vector<int>& arr, int low, int mid, int high) {
        vector<int> temp;                 // buffer to hold merged elements
        int left  = low;                  // pointer into left half
        int right = mid + 1;              // pointer into right half

        // Take the smaller element from the front of each half
        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left++]);
            } else {
                temp.push_back(arr[right++]);
            }
        }

        // Append any leftovers (only one of these loops will run)
        while (left <= mid)  temp.push_back(arr[left++]);
        while (right <= high) temp.push_back(arr[right++]);

        // Copy merged result back into the original array segment
        for (int i = low; i <= high; ++i) {
            arr[i] = temp[i - low];
        }
    }

    // Standard top-down merge sort on arr[low..high]
    void ms(vector<int>& arr, int low, int high) {
        if (low >= high) return;          // base case: size 0 or 1 is already sorted
        int mid = low + (high - low) / 2; // safe mid to avoid overflow
        ms(arr, low, mid);                // sort left half
        ms(arr, mid + 1, high);           // sort right half
        merge(arr, low, mid, high);       // merge the two sorted halves
    }

    // Convenience wrapper: sort the first n elements of nums
    void mergesort(vector<int>& nums, int n) {
        if (n <= 1) return;
        ms(nums, 0, n - 1);
    }
};
