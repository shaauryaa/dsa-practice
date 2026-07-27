// Problem  : 35. Search Insert Position
// Link     : https://leetcode.com/problems/search-insert-position/description/
// Difficulty: Easy
// Date     : 27/07/2026

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

/*Example 1:
Input: nums = [1,3,5,6], target = 5
Output: 2

Example 2:
Input: nums = [1,3,5,6], target = 2
Output: 1

Example 3:
Input: nums = [1,3,5,6], target = 7
Output: 4*/

// same code as the lower bound code logic
class Solution {
   public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int answer = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] >= target) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return answer;
    }
};

// time compexity = O(logn)
// space compexity = O(1)

// Problem  : Lower Bound
// Link     : https://takeuforward.org/plus/dsa/problems/lower-bound-?source=strivers-a2z-dsa-track

/*Example 1
Input : nums= [1,2,2,3], x = 2
Output:1
Explanation:
Index 1 is the smallest index such that arr[1] >= x.

Example 2
Input : nums= [3,5,8,15,19], x = 9
Output: 3
Explanation:
Index 3 is the smallest index such that arr[3] >= x.*/

#include <vector>
using namespace std;

class Solution {
   public:
    int lowerBound(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int answer = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] >= target) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return answer;
    }
};

// time compexity = O(logn)
// space compexity = O(1)

// upper bound

/*Example 1
Input : n= 4, nums = [1,2,2,3], x = 2
Output:3
Explanation:
Index 3 is the smallest index such that arr[3] > x.

Example 2
Input : n = 5, nums = [3,5,8,15,19], x = 9
Output: 3
Explanation:
Index 3 is the smallest index such that arr[3] > x.*/

class Solution {
   public:
    int upperBound(vector<int>& nums, int x) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int answer = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] > x) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return answer;
    }
};

// time compexity = O(logn)
// space compexity = O(1)