class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ansmat;
        long long ans = 1;  // First element is always 1
        ansmat.push_back(1);

        for(int i = 1; i <= rowIndex; i++) {
            // Use previous value to calculate current value using binomial coefficient
            ans = ans * (rowIndex - i + 1) / i;
            ansmat.push_back(ans);
        }

        return ansmat;
    }
};
