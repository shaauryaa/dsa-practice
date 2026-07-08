// Problem  : 18. 4Sum
// Link     : https://leetcode.com/problems/4sum/
// Difficulty: Medium
// Date     : 08/07/2026

#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

/*Example 1:
Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

Example 2:
Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]*/

// brute force approach
class Solution {
   public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> sett;  // to store unique quadruplets
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    for (int l = k + 1; l < n; l++) {
                        long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];  // calculate the sum of the quadruplet
                        if (sum == target) {                                               // check if the sum of the quadruplet is equal to the target
                            vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};       // create a temporary vector to store the quadruplet
                            sort(temp.begin(), temp.end());                                // sort the quadruplet to ensure uniqueness
                            sett.insert(temp);                                             // insert the quadruplet into the set
                        }
                    }
                }
            }
        }
        vector<vector<int>> answer(sett.begin(), sett.end());  // convert the set to a vector of vectors
        return answer;                                         // return the unique quadruplets that sum up to the target
    }
};

// brute force complexity
// Time complexity: O(n^4 * log(n)) where n is the size of the input array.
// Space complexity: O(n) for storing the unique quadruplets in the set.

// better approach
class Solution {
   public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> sett;  // to store unique quadruplets
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                set<int> hashset;                                            // to store the elements seen so far for the current i and j
                for (int k = j + 1; k < n; k++) {                            // iterate through the array starting from the element after j
                    long long sum = (long long)nums[i] + nums[j] + nums[k];  // calculate the sum of the first three elements of the quadruplet
                    long long fourth = target - (sum);                       // calculate the required fourth element to reach the target sum
                    if (hashset.find(fourth) != hashset.end()) {             // check if the required fourth element exists in the hashset
                        vector<int> temp = {nums[i], nums[j], nums[k], (int)fourth};
                        sort(temp.begin(), temp.end());  // sort the quadruplet to ensure uniqueness
                        sett.insert(temp);
                    }
                    hashset.insert(nums[k]);  // insert the current element into the hashset for future reference
                }
            }
        }
        vector<vector<int>> answer(sett.begin(), sett.end());
        return answer;
    }
};

// better approach complexity
// Time complexity: O(n^3 * log(n)) where n is the size of the input array.
// Space complexity: O(n) for storing the unique quadruplets in the set.

// optimal approach
class Solution {
   public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> answer;
        sort(nums.begin(), nums.end());  // sort the input array to facilitate the two-pointer approach
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;  // skip duplicate elements for the first number
            for (int j = i + 1; j < n; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;  // skip duplicate elements for the second number
                int k = j + 1;                                      // initialize the third pointer just after the second pointer
                int l = n - 1;                                      // initialize the fourth pointer at the end of the array
                while (k < l) {
                    long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];
                    if (sum < target) {  // if the sum is less than the target, move the third pointer to the right to increase the sum
                        k++;
                    } else if (sum > target) {  // if the sum is greater than the target, move the fourth pointer to the left to decrease the sum
                        l--;
                    } else {
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        answer.push_back(temp);
                        k++;
                        l--;
                        while (k < l && nums[k] == nums[k - 1]) k++;  // skip duplicate elements for the third number
                        while (k < l && nums[l] == nums[l + 1]) l--;  // skip duplicate elements for the fourth number
                    }
                }
            }
        }
        return answer;
    }
};

// optimal approach complexity
// Time complexity: O(n^3) where n is the size of the input array.
// Space complexity: O(1) if we don't consider the space used for the output.