// Problem  : 485. Max Consecutive Ones
// Link     : https://leetcode.com/problems/max-consecutive-ones/
// Difficulty: Easy
// Date     : 18/06/2026

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

/*Example 1:
Input: nums = [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s.
The maximum number of consecutive 1s is 3.

Example 2:
Input: nums = [1,0,1,1,0,1]
Output: 2*/

class Solution {
   public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maximum =
            0;  // variable to keep track of the maximum count of consecutive 1s
        int count =
            0;  // variable to count the current number of consecutive 1s
        for (int i = 0; i < nums.size();
             i++) {  // iterate through the input vector
            if (nums[i] == 1) {
                count++;  // increment the count if the current element is 1
                maximum = max(maximum, count);  // update the maximum count if
                                                // the current count is greater
            } else {
                count = 0;  // reset the count if the current element is 0
            }
        }
        return maximum;
    }
};

// Optimal Complexity
//   Time  : O(n)
//   Space : O(1)