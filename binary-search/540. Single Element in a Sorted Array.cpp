// Problem  : 540. Single Element in a Sorted Array
// Link     : https://leetcode.com/problems/single-element-in-a-sorted-array/description/
// Difficulty: Medium
// Date     : 31/07/2026

/*Example 1:
Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2

Example 2:
Input: nums = [3,3,7,7,10,11,11]
Output: 10*/

#include <vector>
using namespace std;

// brute force approach
class Solution {
   public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                if (nums[i] != nums[i + 1]) {
                    return nums[i];
                }
            } else if (i == n - 1) {
                if (nums[i] != nums[i - 1]) {
                    return nums[i];
                }
            } else {
                if (nums[i] != nums[i + 1] && nums[i] != nums[i - 1]) {
                    return nums[i];
                }
            }
        }
        return -1;
    }
};

// Brute Force Complexity
//   Time  : O(n)
//   Space : O(1)

// optimal approach using binary search
class Solution {
   public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        // if the array has only one element, return that element
        if (n == 1) return nums[0];
        // if the first element is not equal to the second element, return the first element
        if (nums[0] != nums[1]) return nums[0];
        // if the last element is not equal to the second last element, return the last element
        if (nums[n - 1] != nums[n - 2]) return nums[n - 1];
        int low = 1;
        int high = n - 2;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            // if the mid element is not equal to its previous and next element, return the mid element
            if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) {
                return nums[mid];
            }
            // if the mid element is equal to its previous element and the mid index is odd, or if the mid element is equal to its next element and the mid index is even, then the single element is in the right half of the array
            if ((mid % 2 == 1 && nums[mid] == nums[mid - 1]) || (mid % 2 == 0 && nums[mid] == nums[mid + 1])) {
                low = mid + 1;
            }
            // else, the single element is in the left half of the array
            else {
                high = mid - 1;
            }
        }
        return -1;
    }
};

// Optimal Complexity
//   Time  : O(log n)
//   Space : O(1)