// Problem  : 26. remove-duplicates-from-sorted-array
// Link     :
// https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
// Difficulty: Easy
// Date     : 12/06/2026

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

/*Example 1:
Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]
Explanation: Your function should return k = 2, with the first two elements of
nums being 1 and 2 respectively. It does not matter what you leave beyond the
returned k (hence they are underscores).

Example 2:
Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of
nums being 0, 1, 2, 3, and 4 respectively. It does not matter what you leave
beyond the returned k (hence they are underscores).*/

class Solution {
   public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;  // remember vecname.empty()

        int left = 1;  // start from 1, as the first element is always unique
        for (int right = 1; right < nums.size(); right++) {
            if (nums[right] !=
                nums[right - 1]) {  // check with the previous element
                nums[left] =
                    nums[right];  // place the unique element at index left
                left++;           // increment left for the next unique element
            }
        }
        return left;  // return the count of unique elements
    }
};

// Optimal Complexity
//   Time  : O(n)
//   Space : O(1)