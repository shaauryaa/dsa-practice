// Problem  : 152. Maximum Product Subarray
// Link     : https://leetcode.com/problems/maximum-product-subarray/
// Difficulty: Medium
// Date     : 17/07/2026

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

/*Example 1:
Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.

Example 2:
Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.*/

// brute force approach
class Solution {
   public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maximum = INT_MIN;                  // to store the maximum product found so far
        for (int i = 0; i < n; i++) {           // loop through each element in the array
            for (int j = i; j < n; j++) {       // loop through each subarray starting from the current element
                int product = 1;                // to store the product of the current subarray
                for (int k = i; k <= j; k++) {  // loop through the current subarray and calculate the product
                    product *= nums[k];
                }
                maximum = max(maximum, product);  // update the maximum product found so far
            }
        }
        return maximum;
    }
};

// brute force complexity
//   Time  : O(n^3)
//   Space : O(1)

// better approach
class Solution {
   public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maximum = INT_MIN;                    // to store the maximum product found so far
        for (int i = 0; i < n; i++) {             // loop through each element in the array
            int product = 1;                      // to store the product of the current subarray
            for (int j = i; j < n; j++) {         // loop through each subarray starting from the current element
                product *= nums[j];               // calculate the product of the current subarray
                maximum = max(maximum, product);  // update the maximum product found so far
            }
        }
        return maximum;
    }
};

// better approach complexity
//   Time  : O(n^2)
//   Space : O(1)

// optimal approach
class Solution {
   public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maximum = INT_MIN;  // to store the maximum product found so far
        int prefix = 1;         // to store the product of the current prefix subarray
        int suffix = 1;         // to store the product of the current suffix subarray
        for (int i = 0; i < n; i++) {
            if (prefix == 0) prefix = 1;                  // reset prefix to 1 if it becomes 0
            if (suffix == 0) suffix = 1;                  // reset suffix to 1 if it becomes 0
            prefix *= nums[i];                            // calculate the product of the current prefix subarray
            suffix *= nums[n - i - 1];                    // calculate the product of the current suffix subarray
            maximum = max(maximum, max(prefix, suffix));  // update the maximum product found so far
        }
        return maximum;
    }
};

// optimal approach complexity
//   Time  : O(n)
//   Space : O(1)