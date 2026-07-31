// Problem  : 540. Single Element in a Sorted Array
// Link     : https://leetcode.com/problems/single-element-in-a-sorted-array/description/
// Difficulty: Medium
// Date     : 31/07/2026

/*Example 1:
Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2

Example 2:
Input: nums = [3,3,7,7,10,11,11]
Output: 10*/

#include <vector>
using namespace std;

// brute force approach
class Solution {
   public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                if (nums[i] != nums[i + 1]) {
                    return nums[i];
                }
            } else if (i == n - 1) {
                if (nums[i] != nums[i - 1]) {
                    return nums[i];
                }
            } else {
                if (nums[i] != nums[i + 1] && nums[i] != nums[i - 1]) {
                    return nums[i];
                }
            }
        }
        return -1;
    }
};

// Brute Force Complexity
//   Time  : O(n)
//   Space : O(1)