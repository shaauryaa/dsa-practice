// Problem  : 162. Find Peak Element
// Link     : https://leetcode.com/problems/find-peak-element/description/
// Difficulty: Medium
// Date     : 04/08/2026

/*Example 1:
Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.

Example 2:
Input: nums = [1,2,1,3,5,6,4]
Output: 5
Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.*/

#include <vector>
using namespace std;

// brute force approach using linear search
class Solution {
   public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if ((i == 0 || nums[i - 1] < nums[i]) && (i == n - 1 || nums[i] > nums[i + 1])) {
                return i;
            }
        }
        return -1;
    }
};

// brute force complexity
// Time complexity: O(n)
// Space complexity: O(1)

// optimal approach using binary search
class Solution {
   public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        // Handle edge cases for single element or peak at the boundaries
        if (n == 1) return 0;                         // Only one element, which is the peak
        if (nums[0] > nums[1]) return 0;              // Peak at the first element
        if (nums[n - 1] > nums[n - 2]) return n - 1;  // Peak at the last element
        int low = 1;
        int high = n - 2;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            // Check if mid is a peak element
            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
                return mid;
            }
            // If the left neighbor is greater, then the peak must be in the left half
            else if (nums[mid] > nums[mid - 1]) {
                low = mid + 1;
            }
            // If the right neighbor is greater, then the peak must be in the right half
            else {
                high = mid - 1;
            }
        }
        return -1;
    }
};

// optimal complexity
// Time complexity: O(log n)
// Space complexity: O(1)