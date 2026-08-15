// Problem  : 1011. Capacity To Ship Packages Within D Days
// Link     : https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/
// Difficulty: Medium
// Date     : 15/08/2026

#include <algorithm>
#include <vector>
using namespace std;

// brute force approach
class Solution {
   public:
    int calculatedays(vector<int>& weights, int capacity, int n) {
        int days = 1;
        long long load = 0;
        for (int i = 0; i < n; i++) {
            if (load + weights[i] > capacity) {
                days++;
                load = weights[i];
            } else {
                load += weights[i];
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int maxelement = *max_element(weights.begin(), weights.end());
        long long totalsum = 0;
        for (int i = 0; i < n; i++) {
            totalsum += weights[i];
        }
        for (int capacity = maxelement; capacity <= totalsum; capacity++) {
            int totaldays = calculatedays(weights, capacity, n);
            if (totaldays <= days) {
                return capacity;
            }
        }
        return -1;
    }
};

// brute force complexity
// Time Complexity: O(n * (totalsum - maxelement)), where n is the size of the input array weights, totalsum is the sum of all elements in weights, and maxelement is the maximum element in weights.
// We iterate through all possible capacities from maxelement to totalsum, and for each capacity, we calculate the number of days required in O(n) time.
// Space Complexity: O(1), as we are using a constant amount of extra space.

// optimal approach
class Solution {
   public:
    int calculateDays(vector<int>& weights, int capacity, int n) {
        int days = 1;
        int load = 0;
        for (int i = 0; i < n; i++) {
            if (load + weights[i] > capacity) {
                days++;
                load = weights[i];
            } else {
                load += weights[i];
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int maxelement = *max_element(weights.begin(), weights.end());
        int totalsum = 0;
        for (int i = 0; i < n; i++) {
            totalsum += weights[i];
        }
        int low = maxelement;
        int high = totalsum;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int totalDays = calculateDays(weights, mid, n);
            if (totalDays <= days) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};

// optimal complexity
// Time Complexity: O(n * log(totalsum - maxelement)), where n is the size of the input array weights, totalsum is the sum of all elements in weights, and maxelement is the maximum element in weights.
// We perform a binary search on the range of possible capacities, and for each capacity, we calculate the number of days required in O(n) time.
// Space Complexity: O(1), as we are using a constant amount of extra space.