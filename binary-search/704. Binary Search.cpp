// Problem  : 704. Binary Search
// Link     : https://leetcode.com/problems/binary-search/
// Difficulty: Easy
// Date     : 24/07/2026

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

/*Example 1:
Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4

Example 2:
Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1*/

class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] < target) {
                low = mid + 1;
            } else if (nums[mid] > target) {
                high = mid - 1;
            } else {
                return mid;
            }
        }
        return -1;
    }
};

// Iterative Approach Complexity
//   Time  : O(log(n))
//   Space : O(1)

// Recursive Approach
class Solution {
   public:
    int binarySearch(vector<int>& nums, int low, int high, int target) {
        if (low > high) return -1;
        int mid = (low + high) / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] > target)
            return binarySearch(nums, low, mid - 1, target);
        else
            return binarySearch(nums, mid + 1, high, target);
    }

    int search(vector<int>& nums, int target) {
        return binarySearch(nums, 0, nums.size() - 1, target);
    }
};

// Recursive Approach Complexity
//   Time  : O(log(n))
//   Space : O(log(n))
