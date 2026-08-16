// Problem  : 1539. Kth Missing Positive Number
// Link     : https://leetcode.com/problems/kth-missing-positive-number/description/
// Difficulty: Easy
// Date     : 16/08/2026

/*Example 1:
Input: arr = [2,3,4,7,11], k = 5
Output: 9
Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.

Example 2:
Input: arr = [1,2,3,4], k = 2
Output: 6
Explanation: The missing positive integers are [5,6,7,...]. The 2nd missing positive integer is 6.*/

#include <vector>
using namespace std;

// brute force approach using linear search to find the kth missing positive number
class Solution {
   public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            if (arr[i] <= k)  // If the current number is less than or equal to k, it means that this number is not missing, so we need to increment k to account for the missing number.
                k++;
            else  // If the current number is greater than k, it means that we have found the kth missing positive number, so we can break out of the loop.
                break;
        }
        return k;
    }
};

// brute force complexity
// Time complexity: O(n)
// Space complexity: O(1)

// optimal approach using binary search
class Solution {
   public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int low = 0;
        int high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            // Calculate the number of missing positive integers up to arr[mid]
            int missing = arr[mid] - (mid + 1);  // The number of missing positive integers up to arr[mid] is equal to the value of arr[mid] minus the index of arr[mid] (which is mid) minus 1 (to account for the fact that the array is 0-indexed).
            if (missing < k) {                   // If the number of missing positive integers up to arr[mid] is less than k, it means that the kth missing positive number is greater than arr[mid], so we need to search in the right half of the array.
                low = mid + 1;
            } else {  // If the number of missing positive integers up to arr[mid] is greater than or equal to k, it means that the kth missing positive number is less than or equal to arr[mid], so we need to search in the left half of the array.
                high = mid - 1;
            }
        }
        return low + k;  // After the binary search is complete, low will be the index of the first element in arr that is greater than or equal to the kth missing positive number. The kth missing positive number can be calculated by adding k to low, since there are low missing positive integers before arr[low].
    }
};

// optimal complexity
// Time complexity: O(log n)
// Space complexity: O(1)