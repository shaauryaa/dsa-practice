// Problem  : 2149. Rearrange Array Elements by Sign
// Link     : https://leetcode.com/problems/rearrange-array-elements-by-sign/
// Difficulty: Medium
// Date     : 30/06/2026

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

/*Example 1:
Input: nums = [3,1,-2,-5,2,-4]
Output: [3,-2,1,-5,2,-4]
Explanation:
The positive integers in nums are [3,1,2]. The negative integers are [-2,-5,-4].
The only possible way to rearrange them such that they satisfy all conditions is [3,-2,1,-5,2,-4].
Other ways such as [1,-2,2,-5,3,-4], [3,1,2,-2,-5,-4], [-2,3,-5,1,-4,2] are incorrect because they do not satisfy one or more conditions.

Example 2:
Input: nums = [-1,1]
Output: [1,-1]
Explanation:
1 is the only positive integer and -1 the only negative integer in nums.
So nums is rearranged to [1,-1].*/

class Solution {
   public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> answer(nums.size());  // create a new vector to store the rearranged elements
        int positive = 0;                 // initialize index for positive numbers at even indices
        int negative = 1;                 // initialize index for negative numbers at odd indices
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 0) {  // if the current number is negative, place it at the next available odd index
                answer[negative] = nums[i];
                negative += 2;  // move to the next odd index for the next negative number
            } else {
                answer[positive] = nums[i];  // if the current number is positive, place it at the next available even index
                positive += 2;               // move to the next even index for the next positive number
            }
        }
        return answer;
    }
};

// Optimal Complexity
//   Time  : O(n)
//   Space : O(n)

// Another approach (brute force) using two separate vectors for positive and negative numbers
class Solution {
   public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> positivenums;  // create a vector to store positive numbers
        vector<int> negativenums;  // create a vector to store negative numbers
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {  // if the current number is positive, add it to the positive numbers vector
                positivenums.push_back(nums[i]);
            } else {  // if the current number is negative, add it to the negative numbers vector
                negativenums.push_back(nums[i]);
            }
        }
        for (int i = 0; i < n / 2; i++) {       // iterate through half the size of the original array (since there are equal numbers of positive and negative numbers)
            nums[2 * i] = positivenums[i];      // place the positive number at the even index
            nums[2 * i + 1] = negativenums[i];  // place the negative number at the odd index
        }
        return nums;
    }
};

// Brute Force Complexity
//   Time  : O(n+n/2+n/2) = O(2n)
//   Space : O(n/2+n/2) = O(n)