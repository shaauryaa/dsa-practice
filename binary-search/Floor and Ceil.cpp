// Problem  : Floor and Ceil in Sorted Array
// Link     : https://takeuforward.org/plus/dsa/problems/floor-and-ceil-in-sorted-array?source=strivers-a2z-dsa-track
// Difficulty: Easy
// Date     : 28/07/2026

/*Example 1
Input : nums =[3, 4, 4, 7, 8, 10], x= 5
Output: 4 7
Explanation: The floor of 5 in the array is 4, and the ceiling of 5 in the array is 7.

Example 2
Input : nums =[3, 4, 4, 7, 8, 10], x= 8
Output: 8 8
Explanation: The floor of 8 in the array is 8, and the ceiling of 8 in the array is also 8.*/

#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> getFloorAndCeil(vector<int> nums, int x) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int floor = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] <= x) {
                floor = nums[mid];
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        low = 0;
        high = n - 1;
        int ceil = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] >= x) {
                ceil = nums[mid];
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return {floor, ceil};
    }
};

//   Time  : 2 * O(log(n))
//   Space : O(1)