// Problem  : 4. Median of Two Sorted Arrays
// Link     : https://leetcode.com/problems/median-of-two-sorted-arrays/description/
// Difficulty: Hard
// Date     : 27/08/2026

/*Example 1:
Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000

Example 2:
Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000*/

#include <algorithm>
#include <vector>
using namespace std;

// brute force approach using merge sort
class Solution {
   public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums3;
        int n1 = nums1.size();
        int n2 = nums2.size();
        int i = 0;
        int j = 0;
        while (i < n1 && j < n2) {
            if (nums1[i] < nums2[j]) {
                nums3.push_back(nums1[i++]);
            } else {
                nums3.push_back(nums2[j++]);
            }
        }
        while (i < n1) nums3.push_back(nums1[i++]);
        while (j < n2) nums3.push_back(nums2[j++]);
        int n = n1 + n2;
        if (n % 2 == 1) {
            return nums3[n / 2];
        } else {
            return (nums3[n / 2 - 1] + nums3[n / 2]) / 2.0;
        }
    }
};

// Brute Force Approach Complexity
//   Time  : O(n1 + n2) as we are merging two sorted arrays of size n1 and n2
//   Space : O(n1 + n2) as we are using an extra array to store the merged array

// better approach using no extra space
class Solution {
   public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int i = 0;
        int j = 0;
        int n = n1 + n2;
        int index1 = n / 2;
        int index2 = n / 2 - 1;
        int count = 0;
        int element1 = 0;
        int element2 = 0;
        while (i < n1 && j < n2) {
            if (nums1[i] < nums2[j]) {
                if (count == index1) element1 = nums1[i];
                if (count == index2) element2 = nums1[i];
                count++;
                i++;
            } else {
                if (count == index1) element1 = nums2[j];
                if (count == index2) element2 = nums2[j];
                count++;
                j++;
            }
        }
        while (i < n1) {
            if (count == index1) element1 = nums1[i];
            if (count == index2) element2 = nums1[i];
            count++;
            i++;
        }
        while (j < n2) {
            if (count == index1) element1 = nums2[j];
            if (count == index2) element2 = nums2[j];
            count++;
            j++;
        }
        if (n % 2 == 1) {
            return element1;
        } else {
            return (element1 + element2) / 2.0;
        }
    }
};

// Better Approach Complexity
//   Time  : O(n1 + n2) as we are iterating through both arrays
//   Space : O(1) as we are not using any extra space

// optimal approach using binary search
class Solution {
   public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        if (n1 > n2) return findMedianSortedArrays(nums2, nums1);
        int low = 0;
        int high = n1;
        int left = (n1 + n2 + 1) / 2;
        int n = n1 + n2;
        while (low <= high) {
            int mid1 = low + (high - low) / 2;
            int mid2 = left - mid1;
            int left1 = INT_MIN;
            int left2 = INT_MIN;
            int right1 = INT_MAX;
            int right2 = INT_MAX;
            if (mid1 < n1) right1 = nums1[mid1];
            if (mid2 < n2) right2 = nums2[mid2];
            if (mid1 - 1 >= 0) left1 = nums1[mid1 - 1];
            if (mid2 - 1 >= 0) left2 = nums2[mid2 - 1];
            if (left1 <= right2 && left2 <= right1) {
                if (n % 2 == 1) {
                    return max(left1, left2);
                } else {
                    return (max(left1, left2) + min(right1, right2)) / 2.0;
                }
            } else if (left1 > right2) {
                high = mid1 - 1;
            } else {
                low = mid1 + 1;
            }
        }
        return 0;
    }
};

// Optimal Approach Complexity
//   Time  : O(log(min(n1, n2))) as we are performing binary search on the smaller array
//   Space : O(1) as we are not using any extra space