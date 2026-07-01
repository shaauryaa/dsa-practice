// Problem  : 31. Next Permutation
// Link     : https://leetcode.com/problems/next-permutation/
// Difficulty: Medium
// Date     : 01/07/2026

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

/*Example 1:
Input: nums = [1,2,3]
Output: [1,3,2]

Example 2:
Input: nums = [3,2,1]
Output: [1,2,3]

Example 3:
Input: nums = [1,1,5]
Output: [1,5,1]*/

class Solution {
   public:
    void nextPermutation(vector<int>& nums) {
        int index = -1;  // initialize index to -1 to indicate that no decreasing element has been found yet
        int n = nums.size();
        for (int i = n - 2; i >= 0; i--) {  // traverse the array from the second last element to the first element
            if (nums[i] < nums[i + 1]) {    // find the first decreasing element from the right
                index = i;
                break;
            }
        }
        if (index == -1) {  // if no decreasing element is found, it means the array is in descending order
            reverse(nums.begin(), nums.end());
            return;
        }
        for (int i = n - 1; i > index; i--) {  // traverse the array from the last element to the index of the first decreasing element
            if (nums[i] > nums[index]) {
                swap(nums[i], nums[index]);  // swap the first decreasing element with the next larger element found
                break;
            }
        }
        reverse(nums.begin() + index + 1, nums.end());  // reverse the elements to the right of the index to get the next permutation
        return;
    }
};

// Optimal Complexity
//   Time  : O(3n) as we are traversing the array three times in worst case
//   Space : O(1) as we are not using any extra space