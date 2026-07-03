// Problem  : 53. Maximum Subarray
// Link     : https://leetcode.com/problems/maximum-subarray/
// Difficulty: Medium
// Date     : 29/06/2026

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

/*Example 1:
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.

Example 2:
Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.

Example 3:
Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.*/

class BruteForceSolution {
   public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;  // initialize maxSum to the smallest possible integer
        int n = nums.size();
        for (int i = 0; i < n; i++) {  // iterate through each starting index of the subarray
            for (int j = i; j < n; j++) {
                int sum = 0;                    // initialize sum for the current subarray
                for (int k = i; k <= j; k++) {  // iterate through the current subarray from index i to j
                    sum += nums[k];             // accumulate the sum of the current subarray
                }
                maxSum = max(sum, maxSum);  // update maxSum if the current sum is greater
            }
        }
        return maxSum;
    }
};

// Brute Force Complexity
//   Time  : O(n^3)
//   Space : O(1)

class BetterSolution {
   public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int sum = 0;  // initialize sum for the current starting index i
            for (int j = i; j < n; j++) {
                sum += nums[j];             // accumulate the sum of the subarray starting at index i and ending at index j
                maxSum = max(sum, maxSum);  // update maxSum if the current sum is greater
            }
        }
        return maxSum;
    }
};

// Better Complexity
//   Time  : O(n^2)
//   Space : O(1)

// Optimal Solution using Kadane's Algorithm
class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxSum = INT_MIN;  // initialize maxSum to the smallest possible integer
        int sum = 0;           // initialize sum to keep track of the current subarray sum
        for (int i = 0; i < n; i++) {
            sum += nums[i];  // add the current element to the sum
            if (sum > maxSum) {
                maxSum = sum;
            }
            if (sum < 0) {  // if the current sum is negative, reset it to 0 as it won't contribute to a maximum subarray
                sum = 0;
            }
        }
        return maxSum;
    }
};

// Optimal Complexity
//   Time  : O(n)
//   Space : O(1)

// solution where the maximum subarray is also returned
class SolutionWithSubarray {
   public:
    pair<int, vector<int>> maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxSum = INT_MIN;  // initialize maxSum to the smallest possible integer
        int sum = 0;           // initialize sum to keep track of the current subarray sum
        int start = 0;         // starting index of the current subarray
        int end = 0;           // ending index of the maximum subarray found so far
        int tempStart = 0;     // temporary starting index for the current subarray

        for (int i = 0; i < n; i++) {
            sum += nums[i];  // add the current element to the sum
            if (sum > maxSum) {
                maxSum = sum;
                start = tempStart;  // update the starting index of the maximum subarray
                end = i;            // update the ending index of the maximum subarray
            }
            if (sum < 0) {  // if the current sum is negative, reset it to 0 and update tempStart
                sum = 0;
                tempStart = i + 1;
            }
        }

        vector<int> maxSubarray(nums.begin() + start, nums.begin() + end + 1);  // extract the maximum subarray
        return {maxSum, maxSubarray};                                           // return both the maximum sum and the maximum subarray
    }
};