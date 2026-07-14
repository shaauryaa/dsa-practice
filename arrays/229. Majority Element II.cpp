// Problem  : 229. Majority Element II
// Link     : https://leetcode.com/problems/majority-element-ii/
// Difficulty: Medium
// Date     : 11/07/2026

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

/*Example 1:
Input: nums = [3,2,3]
Output: [3]

Example 2:
Input: nums = [1]
Output: [1]

Example 3:
Input: nums = [1,2]
Output: [1,2]*/

// brute force approach
class Solution {
   public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer;  // to store the majority elements
        for (int i = 0; i < n; i++) {
            if (answer.empty() || answer[0] != nums[i]) {  // check if the element is already in the answer vector
                int count = 0;                             // to count the occurrences of the current element
                for (int j = 0; j < n; j++) {
                    if (nums[i] == nums[j]) {  // count the occurrences of the current element
                        count++;
                    }
                }
                if (count > n / 3) {  // if the count is greater than n/3, add the element to the answer vector
                    answer.push_back(nums[i]);
                }
            }
            if (answer.size() == 2) {  // since there can be at most 2 majority elements, we can break the loop if we have found 2 elements
                break;
            }
        }
        return answer;
    }
};
// brute force complexity
//   Time  : O(n^2)
//   Space : O(1)

// better approach
class Solution {
   public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer;
        unordered_map<int, int> mapp;    // to store the count of each element
        int minimum = (int)(n / 3) + 1;  // minimum count required for an element to be a majority element
        for (int i = 0; i < n; i++) {
            mapp[nums[i]]++;                 // count the occurrences of each element
            if (mapp[nums[i]] == minimum) {  // if the count of the current element is equal to the minimum count required, add it to the answer vector
                answer.push_back(nums[i]);
            }
            if (answer.size() == 2) break;  // since there can be at most 2 majority elements, we can break the loop if we have found 2 elements
        }
        return answer;
    }
};

// better approach complexity
//   Time  : O(n)
//   Space : O(n)