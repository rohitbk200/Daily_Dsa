class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];     // Initialize the minimum price with the first day's price
        int profit = 0;           // Variable to keep track of maximum profit
        int cost;                 // Temporary variable to store profit if we sell today

        // Traverse the price array starting from the second day
        for(int i = 1; i < prices.size(); i++) {
            cost = prices[i] - mini;            // Calculate today's profit if bought at 'mini'
            profit = max(profit, cost);         // Update profit if today's profit is higher
            mini = min(prices[i], mini);        // Update 'mini' if today's price is lower
        }

        return profit;  // Return the maximum profit found
    }
};
