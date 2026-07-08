// Problem  : 15. 3Sum
// Link     : https://leetcode.com/problems/3sum/
// Difficulty: Medium
// Date     : 07/07/2026

#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

/*Example 1:
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation:
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.

Example 2:
Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.

Example 3:
Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.*/

// brute force approach
class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();    // size of the input array
        set<vector<int>> sett;  // to store unique triplets
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (nums[i] + nums[j] + nums[k] == 0) {              // check if the sum of the triplet is zero
                        vector<int> temp = {nums[i], nums[j], nums[k]};  // create a temporary vector to store the triplet
                        sort(temp.begin(), temp.end());                  // sort the triplet to ensure uniqueness
                        sett.insert(temp);                               // insert the triplet into the set
                    }
                }
            }
        }
        vector<vector<int>> answer(sett.begin(), sett.end());  // convert the set to a vector of vectors
        return answer;                                         // return the unique triplets that sum up to zero
    }
};

// brute force complexity
// Time complexity: O(n^3 * log(n)) where n is the size of the input array.
// Space complexity: O(n) for storing the unique triplets in the set.

// better approach
class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();    // size of the input array
        set<vector<int>> sett;  // to store unique triplets
        for (int i = 0; i < n; i++) {
            unordered_set<int> hashset;  // to store the elements seen so far for the current i
            for (int j = i + 1; j < n; j++) {
                int third = -(nums[i] + nums[j]);                  // calculate the third element needed to make the sum zero
                if (hashset.find(third) != hashset.end()) {        // check if the third element is already in the hashset
                    vector<int> temp = {nums[i], nums[j], third};  // create a temporary vector to store the triplet
                    sort(temp.begin(), temp.end());                // sort the triplet to ensure uniqueness
                    sett.insert(temp);                             // insert the triplet into the set
                }
                hashset.insert(nums[j]);  // insert the current element into the hashset for future checks
            }
        }
        vector<vector<int>> answer(sett.begin(), sett.end());  // convert the set to a vector of vectors
        return answer;                                         // return the unique triplets that sum up to zero
    }
};

// better complexity
// Time complexity: O(n^2 * log(n)) where n is the size of the input array.
// Space complexity: O(n) for storing the unique triplets in the set and O(n) for the hashset used for each i.

// optimal approach
class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> answer;      // to store the unique triplets that sum up to zero
        sort(nums.begin(), nums.end());  // sort the input array to facilitate the two-pointer approach
        int n = nums.size();
        for (int i = 0; i < n - 2; i++) {                   // iterate through the array, stopping at n-2 to leave room for two more elements
            if (i > 0 && nums[i] == nums[i - 1]) continue;  // skip duplicate elements to avoid duplicate triplets
            int j = i + 1;                                  // initialize the second pointer just after the first pointer
            int k = n - 1;                                  // initialize the third pointer at the end of the array
            while (j < k) {                                 // while the second pointer is less than the third pointer
                int sum = nums[i] + nums[j] + nums[k];
                if (sum < 0) {  // if the sum is less than zero, we need a larger number, so we move the second pointer to the right
                    j++;
                } else if (sum > 0) {  // if the sum is greater than zero, we need a smaller number, so we move the third pointer to the left
                    k--;
                } else {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    answer.push_back(temp);
                    j++;                                          // move the second pointer to the right to look for the next potential triplet
                    k--;                                          // move the third pointer to the left to look for the next potential triplet
                    while (j < k && nums[j] == nums[j - 1]) j++;  // skip duplicate elements for the second pointer
                    while (j < k && nums[k] == nums[k + 1]) k--;  // skip duplicate elements for the third pointer
                }
            }
        }
        return answer;
    }
};

// optimal complexity
// Time complexity: O(n^2) + O(n log n) where n is the size of the input array.
// Space complexity: O(1) if we don't consider the space used for the output.