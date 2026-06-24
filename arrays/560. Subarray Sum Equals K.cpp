// Problem  : 560. Subarray Sum Equals K
// Link     : https://leetcode.com/problems/subarray-sum-equals-k/
// Difficulty: Medium
// Date     : 24/06/2026

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

/*Example 1:
Input: nums = [1,1,1], k = 2
Output: 2

Example 2:
Input: nums = [1,2,3], k = 3
Output: 2*/

class Solution {
   public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixCount;
        prefixCount[0] = 1;  // empty prefix, sum = 0 occurs once

        int sum = 0, count = 0;

        for (int num : nums) {
            sum += num;

            // if (sum - k) has occurred before, those subarrays sum to k
            if (prefixCount.find(sum - k) != prefixCount.end()) {
                count += prefixCount[sum - k];
            }

            prefixCount[sum]++;
        }

        return count;
    }
};

// Optimal Complexity
//   Time  : O(n)
//   Space : O(n)