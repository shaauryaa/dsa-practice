// Problem  : 88. Merge Sorted Array
// Link     : https://leetcode.com/problems/merge-sorted-array/
// Difficulty: Easy
// Date     : 22/06/2026

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

/*Example 1:
Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.

Example 2:
Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
Explanation: The arrays we are merging are [1] and [].
The result of the merge is [1].

Example 3:
Input: nums1 = [0], m = 0, nums2 = [1], n = 1
Output: [1]
Explanation: The arrays we are merging are [] and [1].
The result of the merge is [1].
Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.*/

class Solution {
   public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int last = m + n - 1;                   // index of the last element in nums1 after merge
        while (m > 0 && n > 0) {                // loop until we have elements in both arrays
            if (nums1[m - 1] > nums2[n - 1]) {  // compare the last elements of both arrays and place the larger one at the end of nums1
                nums1[last] = nums1[m - 1];
                m--;
            } else {  // if nums2's last element is larger or equal, place it at the end of nums1
                nums1[last] = nums2[n - 1];
                n--;
            }
            last--;  // move the last index to the left for the next placement
        }
        while (n > 0) {  // if there are still elements in nums2, place them in nums1
            nums1[last] = nums2[n - 1];
            n--;
            last--;
        }
    }
};

// Optimal Complexity
//   Time  : O(m+n)
//   Space : O(1)

class BruteForceSolution {
   public:
    vector<int> unionArray(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        int i = 0;
        int j = 0;
        vector<int> unionArr;
        while (i < size1 && j < size2) {
            if (nums1[i] <= nums2[j]) {
                if (unionArr.size() == 0 || unionArr.back() != nums1[i]) {
                    unionArr.push_back(nums1[i]);
                }
                i++;
            } else {
                if (unionArr.size() == 0 || unionArr.back() != nums2[j]) {
                    unionArr.push_back(nums2[j]);
                }
                j++;
            }
        }
        while (j < size2) {
            if (unionArr.size() == 0 || unionArr.back() != nums2[j]) {
                unionArr.push_back(nums2[j]);
            }
            j++;
        }
        while (i < size1) {
            if (unionArr.size() == 0 || unionArr.back() != nums1[i]) {
                unionArr.push_back(nums1[i]);
            }
            i++;
        }
        return unionArr;
    }
};

// Brute Force Complexity
//   Time  : O(m+n)
//   Space : O(m+n)