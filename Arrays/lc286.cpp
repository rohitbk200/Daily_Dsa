class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xor1 = 0, xor2 = 0;
        int n = nums.size();

        // XOR all numbers from 0 to n
        for (int i = 0; i <= n; i++) {
            xor1 ^= i;
        }

        // XOR all elements in the array
        for (int i = 0; i < n; i++) {
            xor2 ^= nums[i];
        }

        // XOR of both gives the missing number
        return xor1 ^ xor2;
    }
};
