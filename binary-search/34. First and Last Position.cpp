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

#include <algorithm>  // to use lb and ub functions
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

// optimal approach
class Solution {
   private:
    int lowerbound(vector<int>& nums, int target, int n) {
        int low = 0;
        int high = n - 1;
        int lower = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] >= target) {
                lower = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return lower;
    }

   private:
    int upperbound(vector<int>& nums, int target, int n) {
        int low = 0;
        int high = n - 1;
        int upper = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] > target) {
                upper = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return upper;
    }

   public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int lb = lowerbound(nums, target, n);
        if (lb == n || nums[lb] != target) return {-1, -1};
        return {lb, upperbound(nums, target, n) - 1};
    }
};

// Optimal Approach Complexity
//   Time  : 2 * O(logn)
//   Space : O(1)

// same solution (and same compexity) using STL function of lb and ub
class Solution {
   public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lb = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        if (lb == nums.size() || nums[lb] != target) return {-1, -1};
        int ub = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
        return {lb, ub};
    }
};
// checking if lb exits first might save log n time as if it doesnt exist then ub also doesnt exist so we dont need to waste time calculating it

// binary search approach using 2 bs functions to find first and last index
class Solution {
   private:
    int firstindex(vector<int>& nums, int target, int n) {
        int low = 0;
        int high = n - 1;
        int first = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                first = mid;
                high = mid - 1;
            } else if (nums[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return first;
    }

   private:
    int lastindex(vector<int>& nums, int target, int n) {
        int low = 0;
        int high = n - 1;
        int last = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                last = mid;
                low = mid + 1;
            } else if (nums[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return last;
    }

   public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int lower = firstindex(nums, target, n);
        if (lower == -1) return {-1, -1};
        int upper = lastindex(nums, target, n);
        return {lower, upper};
    }
};

// BS Approach Complexity (same complexity as lb ub apprach)
//   Time  : 2 * O(logn)
//   Space : O(1)