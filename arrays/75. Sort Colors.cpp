// Problem  : 75. Sort Colors
// Link     : https://leetcode.com/problems/sort-colors/
// Difficulty: Medium
// Date     : 27/06/2026

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

/*Example 1:
Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]

Example 2:
Input: nums = [2,0,1]
Output: [0,1,2]*/

class BruteForceSolution {
   public:
    void sortColors(vector<int>& nums) {
        sort(nums.begin(), nums.end());  // merge sort the array in ascending order
    }
};

// Brute Force Complexity
//   Time  : O(n log n)
//   Space : O(1)

class BetterSolution {
   public:
    void sortColors(vector<int>& nums) {
        int count0 = 0, count1 = 0, count2 = 0;  // counters for 0s, 1s, and 2s
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0)
                count0++;  // count the number of 0s
            else if (nums[i] == 1)
                count1++;  // count the number of 1s
            else
                count2++;  // count the number of 2s
        }
        for (int i = 0; i < count0; i++) nums[i] = 0;                     // fill the first count0 elements with 0
        for (int i = count0; i < count0 + count1; i++) nums[i] = 1;       // fill the next count1 elements with 1
        for (int i = count0 + count1; i < nums.size(); i++) nums[i] = 2;  // fill the remaining elements with 2
    }
};

// Better Complexity
//   Time  : O(2n) (two passes through the array)
//   Space : O(1)

class OptimalSolution {
   public:
    void sortColors(vector<int>& nums) {
        int low = 0;                 // pointer for the next position of 0
        int mid = 0;                 // pointer for the current element
        int high = nums.size() - 1;  // pointer for the next position of 2

        while (mid <= high) {
            if (nums[mid] == 0) {            // if the current element is 0, swap it with the element at low pointer
                swap(nums[low], nums[mid]);  // increment both low and mid pointers
                low++;
                mid++;
            } else if (nums[mid] == 1) {  // if the current element is 1, just move the mid pointer forward
                mid++;
            } else {                          // nums[mid] == 2
                swap(nums[mid], nums[high]);  // swap the current element with the element at high pointer and decrement the high pointer
                high--;
            }
        }
    }
};

// Optimal Complexity
//   Time  : O(n)
//   Space : O(1)