// Problem  : 81. Search in Rotated Sorted Array II
// Link     : https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/
// Difficulty: Medium
// Date     : 29/07/2026

/*Example 1:
Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true

Example 2:
Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false*/

#include <vector>
using namespace std;

// brute force solution will be using linear search using O(n) time

// optimal approach using binary search
class Solution {
   public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                return true;
            }
            if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
                low++;
                high--;
                continue;
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
        return false;
    }
};

// time compexity (average case) = O(logn)
// time compexity (worst case) = O(n)
// space compexity = O(1)