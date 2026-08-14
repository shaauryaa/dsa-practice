// Problem  : 1283. Find the Smallest Divisor Given a Threshold
// Link     : https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/description/
// Difficulty: Medium
// Date     : 13/08/2026

/*Example 1:
Input: nums = [1,2,5,9], threshold = 6
Output: 5
Explanation: We can get a sum to 17 (1+2+5+9) if the divisor is 1.
If the divisor is 4 we can get a sum of 7 (1+1+2+3) and if the divisor is 5 the sum will be 5 (1+1+1+2).

Example 2:
Input: nums = [44,22,33,11,1], threshold = 5
Output: 44*/

#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

// brute force solution
class Solution {
   public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int maxelement = INT_MIN;  // Find the maximum element in the array
        for (int i = 0; i < n; i++) {
            maxelement = max(maxelement, nums[i]);  // Update the maximum element if the current element is greater
        }
        for (int divisor = 1; divisor <= maxelement; divisor++) {  // Iterate through all possible divisors from 1 to maxelement
            long long divisionsum = 0;
            for (int j = 0; j < n; j++) {                          // Calculate the division sum for the current divisor
                divisionsum += (nums[j] + divisor - 1) / divisor;  // This formula calculates the ceiling of nums[j] / divisor without using floating-point division
            }
            if (divisionsum <= threshold) {  // If the division sum is less than or equal to the threshold, return the current divisor
                return divisor;
            }
        }
        return -1;
    }
};

// brute force complexity
// Time Complexity: O(n * maxelement), where n is the size of the input array nums and maxelement is the maximum element in nums. We iterate through all possible divisors from 1 to maxelement, and for each divisor, we calculate the division sum in O(n) time.
// Space Complexity: O(1), as we are using a constant amount of extra space.

// optimal solution
class Solution {
   public:
    // Function to calculate the division sum for a given divisor
    long long calculateDivisionSum(vector<int>& nums, int n, int divisor) {
        long long divisionsum = 0;
        for (int i = 0; i < n; i++) {
            // This formula calculates the ceiling of nums[i] / divisor without using floating-point division
            divisionsum += (nums[i] + divisor - 1) / divisor;
        }
        return divisionsum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        if (n > threshold) {
            return -1;  // Not possible to find a divisor that satisfies the condition
        }
        int maxelement = INT_MIN;
        for (int i = 0; i < n; i++) {
            maxelement = max(maxelement, nums[i]);  // Find the maximum element in the array
        }
        int low = 1;
        int high = maxelement;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long totalsum = calculateDivisionSum(nums, n, mid);
            // If the total division sum is less than or equal to the threshold, we can try a smaller divisor
            if (totalsum <= threshold) {
                high = mid - 1;
            }
            // If the total division sum is greater than the threshold, we need to try a larger divisor
            else {
                low = mid + 1;
            }
        }
        return low;  // Return the smallest divisor that satisfies the condition
    }
};

// optimal complexity
// Time Complexity: O(n * log(maxelement)), where n is the size of the input array nums and maxelement is the maximum element in nums.
// The binary search takes log(maxelement) iterations, and for each iteration, we calculate the division sum in O(n) time.
// Space Complexity: O(1), as we are using a constant amount of extra space.