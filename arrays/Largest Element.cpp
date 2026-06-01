// Problem  : largest Element
// Link     :
// https://takeuforward.org/plus/dsa/problems/largest-element?source=strivers-a2z-dsa-track
// Difficulty: Easy
// Date     : 02/06/2026

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// Example 1
// Input: nums = [3, 3, 6, 1]
// Output: 6
// Explanation: The largest element in array is 6

// Example 2
// Input: nums = [3, 3, 0, 99, -40]
// Output: 99
// Explanation: The largest element in array is 99

class Solution {
   public:
    int largestElement(vector<int>& nums) {
        if (nums.empty()) return -1;  // remember vecname.empty()

        int largest = nums[0];
        for (int i = 1; i < nums.size();
             i++) {  // start from 1, not 0 as 0 is already initialized as the
                     // largest element and remember () after vecname.size
            if (nums[i] > largest) {
                largest = nums[i];
            }
        }
        return largest;  // remember to return the value from INSIDE the
                         // function
    }
};

// Brute Force Complexity
//   Time  : O(n)
//   Space : O(1)
// Optimal Complexity
//   Time  : O(n)
//   Space : O(1)

// brute force and optimal are the same in this case, as we have to check every
// element to find the largest one.