// Problem  : second largest element
// Link :
// https://takeuforward.org/plus/dsa/problems/second-largest-element?source=strivers-a2z-dsa-track
// Difficulty: Easy
// Date     : 07/06/2026

#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

/*Example 1
Input: nums = [8, 8, 7, 6, 5]
Output: 7
Explanation:
The largest value in nums is 8, the second largest is 7

Example 2
Input: nums = [10, 10, 10, 10, 10]
Output: -1
Explanation:
The only value in nums is 10, so there is no second largest value, thus -1 is
returned*/

class Solution {
   public:
    int secondLargestElement(vector<int>& nums) {
        if (nums.size() < 2)
            return -1;  // can't have second largest with < 2 element
        int largest = nums[0];
        int secondlargest = INT_MIN;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > largest) {
                secondlargest = largest;
                largest = nums[i];
            } else if (nums[i] > secondlargest && nums[i] < largest) {
                secondlargest = nums[i];
            }
        }
        return (secondlargest == INT_MIN) ? -1 : secondlargest;
    }
};

// Optimal Complexity
//   Time  : O(n)
//   Space : O(1)