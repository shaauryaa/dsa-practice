// Problem  : 154. Find Minimum in Rotated Sorted Array II
// Link     : https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/description/
// Difficulty: Hard
// Date     : 02/08/2026

/*Example 1:
Input: nums = [1,3,5]
Output: 1

Example 2:
Input: nums = [2,2,2,0,1]
Output: 0*/

#include <climits>
#include <vector>
using namespace std;

// brute force approach will obviously be linear search taking O(n) time

// optimal solution using binary search (with duplicate elements)
class Solution {
   public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int minimum = INT_MAX;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[low] == nums[mid] && nums[mid] == nums[high]) {  // if all three elements are equal, we cannot determine the minimum, so we reduce the search space
                minimum = min(minimum, nums[low]);                    // update the minimum value
                low++;
                high--;
                continue;  // continue to the next iteration
            }
            if (nums[low] < nums[high]) {  // if the subarray is sorted, the minimum is the first element
                minimum = min(minimum, nums[low]);
                break;
            }
            if (nums[low] <= nums[mid]) {  // if the left half is sorted, the minimum is in the right half
                minimum = min(minimum, nums[low]);
                low = mid + 1;
            } else if (nums[mid] <= nums[high]) {  // if the right half is sorted, the minimum is in the left half
                minimum = min(minimum, nums[mid]);
                high = mid - 1;
            }
        }
        return minimum;
    }
};

// Optimal Approach Complexity
//   Time  : O(logn) in average case, O(n) in worst case
//   Space : O(1)