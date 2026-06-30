// Problem  : 121. Best Time to Buy and Sell Stock
// Link     : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// Difficulty: Easy
// Date     : 30/06/2026

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

/*Example 1:
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

Example 2:
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.*/

// two pointer approach
class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int left = 0;   // pointer for the day to buy
        int right = 1;  // pointer for the day to sell
        int maxProfit = 0;
        int n = prices.size();
        while (right < n) {                      // iterate through the prices array with the right pointer
            if (prices[left] < prices[right]) {  // if the price at the left pointer is less than the price at the right pointer, we can calculate profit
                int profit = prices[right] - prices[left];
                maxProfit = max(maxProfit, profit);  // update maxProfit if the current profit is greater
            } else {
                left = right;  // if the price at the left pointer is greater than or equal to the price at the right pointer, move the left pointer to the right pointer
            }
            right++;  // move the right pointer to the next day
        }
        return maxProfit;
    }
};

// Optimal Complexity
//   Time  : O(n)
//   Space : O(1)

// dp approach
class DPSolution {
   public:
    int maxProfit(vector<int>& prices) {
        int minimum = prices[0];  // initialize minimum to the first price
        int maxProfit = 0;        // initialize maxProfit to 0
        int n = prices.size();
        for (int i = 1; i < n; i++) {
            int currentProfit = prices[i] - minimum;    // calculate the current profit if we sell at the current price
            maxProfit = max(maxProfit, currentProfit);  // update maxProfit if the current profit is greater
            minimum = min(minimum, prices[i]);          // update minimum if the current price is less than the minimum
        }
        return maxProfit;
    }
};

// Optimal Complexity
//   Time  : O(n)
//   Space : O(1)