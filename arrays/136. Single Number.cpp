// Problem  : 136. Single Number
// Link     : https://leetcode.com/problems/single-number/
// Difficulty: Easy
// Date     : 19/06/2026

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

/*Example 1:
Input: nums = [2,2,1]
Output: 1

Example 2:
Input: nums = [4,1,2,1,2]
Output: 4

Example 3:
Input: nums = [1]
Output: 1*/

class Solution {
   public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;  // variable to store the single number
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            ans = ans ^ nums[i];  // XOR operation to find the single number
        }
        return ans;
    }
};

// Optimal Complexity
//   Time  : O(n)
//   Space : O(1)