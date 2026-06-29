// Problem  : 169. Majority Element
// Link     : https://leetcode.com/problems/majority-element/
// Difficulty: Easy
// Date     : 28/06/2026

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

/*Example 1:
Input: nums = [3,2,3]
Output: 3

Example 2:
Input: nums = [2,2,1,1,1,2,2]
Output: 2*/

class BruteForceSolution {
   public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {      // iterate through each element in the array
            int count = 0;                 // initialize count for the current element
            for (int j = 0; j < n; j++) {  // iterate through the array again to count occurrences of nums[i]
                if (nums[j] == nums[i]) {
                    count++;  // increment count if we find a match
                }
            }
            if (count > n / 2) {  // check if the count exceeds half the size of the array
                return nums[i];   // return the majority element
            }
        }
        return -1;  // return -1 if no majority element is found (though the problem guarantees one exists)
    }
};

// Brute Force Complexity
//   Time  : O(n^2)
//   Space : O(1)

class BetterSolution {
   public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> countMap;  // create a hash map to store counts of each element
        int n = nums.size();
        for (int num : nums) {            // iterate through each number in the array
            countMap[num]++;              // increment the count for this number in the map
            if (countMap[num] > n / 2) {  // check if this number's count exceeds half the size of the array
                return num;               // return the majority element
            }
        }
        return -1;  // return -1 if no majority element is found (though the problem guarantees one exists)
    }
};

// Better Complexity
//   Time  : O(n)
//   Space : O(n)

// Optimal Solution using Boyer-Moore Voting Algorithm
class Solution {
   public:
    int majorityElement(vector<int>& nums) {
        int count = 0;  // initialize count to track the number of occurrences of the current candidate for majority element
        int element;    // variable to store the current candidate for majority element
        for (int i = 0; i < nums.size(); i++) {
            if (count == 0) {  // if count is zero, we need to select a new candidate for majority element
                count = 1;
                element = nums[i];
            } else if (nums[i] == element) {  // if the current number matches the candidate, increment the count
                count++;
            } else {  // if the current number does not match the candidate, decrement the count
                count--;
            }
        }
        return element;  // return the candidate that is guaranteed to be the majority element
    }
};

// we dont verify the candidate because the problem guarantees that a majority element always exists in the input array
// if the problem did not guarantee a majority element, we would need to verify the candidate by counting its occurrences in the array and checking if it exceeds n/2
// int count = 0;
// for (int i=0; i<nums.size(); i++) {
//     if (nums[i] == element) {
//         count++;
//     }
//     if (count > nums.size()/2) {
//         return element;
//     }
// }

// Optimal Complexity
//   Time  : O(n)
//   Space : O(1)