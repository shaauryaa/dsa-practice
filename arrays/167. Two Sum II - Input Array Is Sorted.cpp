// Problem  : 167. Two Sum II - Input Array Is Sorted
// Link     : https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
// Difficulty: Medium
// Date     : 21/06/2026

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

/*Example 1:
Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].

Example 2:
Input: numbers = [2,3,4], target = 6
Output: [1,3]
Explanation: The sum of 2 and 4 is 6. Therefore index1 = 1, index2 = 3. We return [1, 3].

Example 3:
Input: numbers = [-1,0], target = -1
Output: [1,2]
Explanation: The sum of -1 and 0 is -1. Therefore index1 = 1, index2 = 2. We return [1, 2].*/

class Solution {
   public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;                    // initialize left pointer at the beginning of the array
        int right = numbers.size() - 1;  // initialize right pointer at the end of the array

        while (left < right) {                         // loop until the two pointers meet
            int sum = numbers[left] + numbers[right];  // calculate the sum of the two numbers at the pointers

            if (sum == target) {  // if the sum equals the target, return the indices (1-based)
                return {left + 1, right + 1};
            } else if (sum < target) {  // if the sum is less than the target, move the left pointer to the right to increase the sum
                left++;
            } else {  // if the sum is greater than the target, move the right pointer to the left to decrease the sum
                right--;
            }
        }
        return {};  // return an empty vector if no solution is found
    }
};

// Optimal Complexity
//   Time  : O(n)
//   Space : O(1)