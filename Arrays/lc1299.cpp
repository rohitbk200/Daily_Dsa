class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int currmax = -1; // Initialize current max to -1 as per the problem
        int n = arr.size();

        // Traverse from the end of the array
        for(int i = n - 1; i >= 0; i--) {
            int temp = arr[i];   // Store the current element temporarily
            arr[i] = currmax;    // Replace current element with current max
            currmax = max(currmax, temp); // Update current max if needed
        }

        return arr;
    }
};
