// Problem  : 33. Search in Rotated Sorted Array
// Link     : https://leetcode.com/problems/search-in-rotated-sorted-array/description/
// Difficulty: Medium
// Date     : 29/07/2026

/*Example 1:
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Example 2:
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

Example 3:
Input: nums = [1], target = 0
Output: -1*/

#include <vector>
using namespace std;

// brute force approach using linaer search
class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == target) {
                return i;
            }
        }
        return -1;
    }
};

// Brute Force Approach Complexity
//   Time  : O(n)
//   Space : O(1)

// optimal solution using bs
class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[low] <= nums[mid]) {
                if (nums[low] <= target && nums[mid] >= target) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                if (nums[mid] <= target && nums[high] >= target) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};

// Optimal Approach Complexity
//   Time  : O(logn)
//   Space : O(1)