// Problem  : 560. Subarray Sum Equals K
// Link     : https://leetcode.com/problems/subarray-sum-equals-k/
// Difficulty: Medium
// Date     : 24/06/2026

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

/*Example 1:
Input: nums = [1,1,1], k = 2
Output: 2

Example 2:
Input: nums = [1,2,3], k = 3
Output: 2*/

// brute force approach
class Solution {
   public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;                     // to store the count of subarrays whose sum equals k
        for (int i = 0; i < n; i++) {      // loop through each element in the array
            for (int j = i; j < n; j++) {  // loop through each subarray starting from the current element
                int sum = 0;
                for (int l = i; l <= j; l++) {
                    sum += nums[l];
                }
                if (sum == k) count++;
            }
        }
        return count;
    }
};

// brute force complexity
//   Time  : O(n^3)
//   Space : O(1)

// better approach
class Solution {
   public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                if (sum == k) count++;
            }
        }
        return count;
    }
};

// better approach complexity
//   Time  : O(n^2)
//   Space : O(1)

// optimal approach
class Solution {
   public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mapp;
        mapp[0] = 1;
        int prefixSum = 0;
        int count = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            prefixSum += nums[i];
            if (mapp.find(prefixSum - k) != mapp.end()) {
                count += mapp[prefixSum - k];
            }
            mapp[prefixSum]++;
        }
        return count;
    }
};

// Optimal Complexity
//   Time  : O(n)
//   Space : O(n)