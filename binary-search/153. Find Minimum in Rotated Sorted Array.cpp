// Problem  : 153. Find Minimum in Rotated Sorted Array
// Link     : https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
// Difficulty: Medium
// Date     : 30/07/2026

/*Example 1:
Input: nums = [3,4,5,1,2]
Output: 1
Explanation: The original array was [1,2,3,4,5] rotated 3 times.

Example 2:
Input: nums = [4,5,6,7,0,1,2]
Output: 0
Explanation: The original array was [0,1,2,4,5,6,7] and it was rotated 4 times.

Example 3:
Input: nums = [11,13,15,17]
Output: 11
Explanation: The original array was [11,13,15,17] and it was rotated 4 times.*/

// brute force solution is linear search taking O(n) time

#include <climits>
#include <vector>
using namespace std;

// optimal solution using binary search (with unique elements)
class Solution {
   public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int minimum = INT_MAX;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[low] <= nums[high]) {
                minimum = min(minimum, nums[low]);
                break;
            }
            if (nums[low] <= nums[mid]) {
                minimum = min(minimum, nums[low]);
                low = mid + 1;
            } else {
                minimum = min(minimum, nums[mid]);
                high = mid - 1;
            }
        }
        return minimum;
    }
};

// Optimal Approach Complexity
//   Time  : O(logn)
//   Space : O(1)

// Find out how many times the array is rotated

/*Example 1
Input : nums = [4, 5, 6, 7, 0, 1, 2, 3]
Output: 4
Explanation: The original array should be [0, 1, 2, 3, 4, 5, 6, 7]. So, we can notice that the array has been rotated 4 times.

Example 2
Input: nums = [3, 4, 5, 1, 2]
Output: 3
Explanation: The original array should be [1, 2, 3, 4, 5]. So, we can notice that the array has been rotated 3 times.*/

// optimal solution is a small modification of the find minimum code
// we track the index of the minimum element as its index is equal to the number of times the array is roatated as we can see from the above examples
// again this code is for unique elements and not for duplicates
class Solution {
   public:
    int findKRotation(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int minimum = INT_MAX;
        int index = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[low] <= nums[high]) {
                if (nums[low] < minimum) {
                    minimum = nums[low];
                    index = low;
                    break;
                }
            }
            if (nums[low] <= nums[mid]) {
                if (nums[low] < minimum) {
                    minimum = nums[low];
                    index = low;
                }
                low = mid + 1;
            } else if (nums[mid] <= nums[high]) {
                if (nums[mid] < minimum) {
                    minimum = nums[mid];
                    index = mid;
                }
                high = mid - 1;
            }
        }
        return index;
    }
};

// Optimal Approach Complexity
//   Time  : O(logn)
//   Space : O(1)