// Problem  : 268. Missing Number
// Link     : https://leetcode.com/problems/missing-number/
// Difficulty: Easy
// Date     : 23/06/2026

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

/*Example 1:
Input: nums = [3,0,1]
Output: 2
Explanation:
n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.

Example 2:
Input: nums = [0,1]
Output: 2
Explanation:
n = 2 since there are 2 numbers, so all numbers are in the range [0,2]. 2 is the missing number in the range since it does not appear in nums.

Example 3:
Input: nums = [9,6,4,2,3,5,7,0,1]
Output: 8
Explanation:
n = 9 since there are 9 numbers, so all numbers are in the range [0,9]. 8 is the missing number in the range since it does not appear in nums.*/

class Solution {
   public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int result = n;  // initialize result with n, as the missing number could be n itself
        for (int i = 0; i < n; i++) {
            result ^= i ^ nums[i];  // XOR all indices and numbers together. The missing number will be the only one left after all pairs cancel out.
        }
        return result;
    }
};

// Optimal Complexity
//   Time  : O(n)
//   Space : O(1)

// Sum Approach
class Solution {
   public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        long long expected = 1LL * n * (n + 1) / 2;  // calculate the expected sum of numbers from 0 to n using the formula n*(n+1)/2
        long long actual = 0;                        // variable to store the actual sum of numbers in the input vector
        for (int i = 0; i < n; i++) {
            actual += nums[i];  // accumulate the sum of numbers in the input vector
        }
        return expected - actual;  // the missing number is the difference between the expected sum and the actual sum
    }
};
// Optimal Complexity
//   Time  : O(n)
//   Space : O(1)