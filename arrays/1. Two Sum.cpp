// Problem  : 1. Two Sum
// Link     : https://leetcode.com/problems/two-sum/
// Difficulty: Easy
// Date     : 20/06/2026

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

/*Example 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:
Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:
Input: nums = [3,3], target = 6
Output: [0,1]*/

class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;  // map to store the numbers we have seen and their indices
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];          // calculate the complement of the current number
            if (seen.find(complement) != seen.end()) {  // check if the complement exists in the map
                return {seen[complement], i};           // if it exists, return the indices of the complement and the current number
            }
            seen[nums[i]] = i;  // store the current number and its index in the map
        }
        return {};  // return an empty vector if no solution is found
    }
};

// Optimal Complexity
//   Time  : O(n)
//   Space : O(n)

class BruteForceSolution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {  // check nums ahead of i to avoid using the same element twice
                if (nums[i] + nums[j] == target) {       // check if the sum of the two numbers equals the target
                    return {i, j};                       // return the indices of the two numbers that add up to the target
                }
            }
        }
        return {};  // return an empty vector if no solution is found
    }
};

// Brute Force Complexity
//   Time  : O(n^2)
//   Space : O(1)

// without hashmap, for a yes or no output we can use two pointers, but for indices we need to use hashmap to store the indices of the elements.
class TwoPointerSolution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> numWithIndex;  // vector to store the numbers along with their original indices
        for (int i = 0; i < nums.size(); i++) {
            numWithIndex.push_back({nums[i], i});  // store the number and its index as a pair
        }
        sort(numWithIndex.begin(), numWithIndex.end());  // sort the vector based on the numbers

        int left = 0;                         // initialize left pointer
        int right = numWithIndex.size() - 1;  // initialize right pointer
        while (left < right) {
            int sum = numWithIndex[left].first + numWithIndex[right].first;      // calculate the sum of the two numbers at the pointers
            if (sum == target) {                                                 // check if the sum equals the target
                return {numWithIndex[left].second, numWithIndex[right].second};  // return the original indices of the two numbers
            } else if (sum < target) {                                           // if the sum is less than the target, move the left pointer to the right to increase the sum
                left++;
            } else {  // if the sum is greater than the target, move the right pointer to the left to decrease the sum
                right--;
            }
        }
        return {};  // return an empty vector if no solution is found
    }
};

// Two Pointer Complexity
//   Time  : O(n log n) due to sorting
//   Space : O(n) for storing the pairs of numbers and their indices