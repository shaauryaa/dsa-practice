// Problem  : 189. Rotate Array
// Link     : https://leetcode.com/problems/rotate-array/
// Difficulty: Medium
// Date     : 14/06/2026

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

/*Example 1:
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]

Example 2:
Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation:
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]*/

class Solution {
   public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            swap(nums[left], nums[right]);
            left++;
            right--;
        }
        left = 0;
        right = k - 1;
        while (left < right) {
            swap(nums[left], nums[right]);
            left++;
            right--;
        }
        left = k;
        right = nums.size() - 1;
        while (left < right) {
            swap(nums[left], nums[right]);
            left++;
            right--;
        }
    }
};

// Optimal Complexity
//   Time  : O(n)
//   Space : O(1)

class Solution {
   public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};