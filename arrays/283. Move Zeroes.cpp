// Problem  : 283. Move Zeroes
// Link     : https://leetcode.com/problems/move-zeroes/
// Difficulty: Easy
// Date     : 16/06/2026

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

/*Example 1:
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]

Example 2:
Input: nums = [0]
Output: [0]*/

class Solution {
   public:
    void moveZeroes(vector<int>& nums) {
        int left =
            0;  // pointer for the position to place the next non-zero element
        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] != 0) {  // if the current element is non-zero
                swap(nums[left],
                     nums[right]);  // swap it with the element at left pointer
                left++;  // move the left pointer to the next position
            }
        }
    }
};

// Optimal Complexity
//   Time  : O(n)
//   Space : O(1)