// Problem  : 1752. Check if Array Is Sorted and Rotated
// Link     :https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/
// Difficulty: Easy
// Date     : 08/06/2026

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

/*Example 1:
Input: nums = [3,4,5,1,2]
Output: true
Explanation: [1,2,3,4,5] is the original sorted array.
You can rotate the array by x = 2 positions to begin on the element of value 3:
[3,4,5,1,2].

Example 2:
Input: nums = [2,1,3,4]
Output: false
Explanation: There is no sorted array once rotated that can make nums.

Example 3:
Input: nums = [1,2,3]
Output: true
Explanation: [1,2,3] is the original sorted array.
You can rotate the array by x = 0 positions (i.e. no rotation) to make nums.*/

class Solution {
   public:
    bool check(vector<int>& nums) {
        int N = nums.size();
        if (N == 1) return true;  // single element is always valid

        int count = 1;

        for (int i = 1; i < 2 * N; i++) {
            if (nums[(i - 1) % N] <= nums[i % N]) {
                count++;
            } else {
                count = 1;
            }
            if (count == N) return true;
        }

        return false;
    }
};

// Optimal Complexity
//   Time  : O(n)
//   Space : O(1)