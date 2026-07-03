// Problem  : 128. Longest Consecutive Sequence
// Link     : https://leetcode.com/problems/longest-consecutive-sequence/
// Difficulty: Medium
// Date     : 03/07/2026

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

/*Example 1:
Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

Example 2:
Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9

Example 3:
Input: nums = [1,0,1,2]
Output: 3*/

// better approach using sorting
class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;      // if the input array is empty, return 0
        sort(nums.begin(), nums.end());  // sort the input array in ascending order
        int longest = 1;                 // initialize longest to 1 since the minimum length of a consecutive sequence is 1
        int currcount = 0;               // initialize currcount to 0 to keep track of the current consecutive sequence length
        int lastelement = INT_MIN;       // initialize lastelement to the minimum integer value to keep track of the last element in the current consecutive sequence
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] - 1 == lastelement) {     // if the current element is one greater than the last element, it is part of the current consecutive sequence
                currcount++;                      // increment currcount to keep track of the current consecutive sequence length
                lastelement = nums[i];            // update lastelement to the current element
            } else if (nums[i] != lastelement) {  // if the current element is not equal to the last element, it is not part of the current consecutive sequence
                currcount = 1;                    // reset currcount to 1 since we have found a new consecutive sequence
                lastelement = nums[i];            // update lastelement to the current element
            }
            longest = max(longest, currcount);  // update longest to the maximum of longest and currcount
        }
        return longest;
    }
};

// better approach complexity
//   Time  : O(nlogn)
//  Space : O(1)

// optimal approach using unordered_set
class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int longest = 1;  // initialize longest to 1 since the minimum length of a consecutive sequence is 1
        unordered_set<int> sett;
        for (int i = 0; i < n; i++) {  // insert all the elements of the input array into an unordered_set to remove duplicates and allow for O(1) average time complexity for lookups
            sett.insert(nums[i]);
        }
        for (auto num : sett) {                                          // iterate through the unordered_set to find the longest consecutive sequence
            if (sett.find(num - 1) == sett.end()) {                      // if the current number is the start of a new consecutive sequence (i.e., there is no number one less than it in the set)
                int count = 1;                                           // initialize count to 1 to keep track of the current consecutive sequence length
                int starting_element = num;                              // initialize starting_element to the current number to keep track of the start of the current consecutive sequence
                while (sett.find(starting_element + 1) != sett.end()) {  // while there is a number one greater than the starting_element in the set, increment starting_element and count
                    starting_element++;
                    count++;
                }
                longest = max(longest, count);  // update longest to the maximum of longest and count
            }
        }
        return longest;
    }
};

// optimal approach complexity
//   Time  : O(3n) as we are traversing the array twice and the while loop will run at most n times
//  Space : O(n)