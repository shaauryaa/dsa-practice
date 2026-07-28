// Problem  : 34. Find First and Last Position of Element in Sorted Array
// Link     : https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
// Difficulty: Medium
// Date     : 28/07/2026

/*Example 1:
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

Example 3:
Input: nums = [], target = 0
Output: [-1,-1]*/

#include <vector>
using namespace std;

// brute force approach
class Solution {
   public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int first = -1;
        int last = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i] == target) {
                if (first == -1) first = i;
                last = i;
            }
        }
        return {first, last};
    }
};

// Brute Force Approach Complexity
//   Time  : O(n)
//   Space : O(1)