// Problem  : 1482. Minimum Number of Days to Make m Bouquets
// Link     : https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/
// Difficulty: Medium
// Date     : 11/08/2026

#include <algorithm>
#include <vector>
using namespace std;

// brute force solution
class Solution {
   public:
    bool possible(vector<int> bloomDay, int day, int m, int k, int n) {
        int count = 0;
        int noofB = 0;
        for (int i = 0; i < n; i++) {
            if (bloomDay[i] <= day) {  // if the flower blooms on or before the given day, increment the count of consecutive bloomed flowers
                count++;
            } else {
                noofB += (count / k);  // if the flower does not bloom on or before the given day, calculate how many bouquets can be made from the consecutive bloomed flowers and reset the count
                count = 0;
            }
        }
        noofB += (count / k);  // after the loop, calculate how many bouquets can be made from the remaining consecutive bloomed flowers
        return noofB >= m;     // return true if the number of bouquets made is greater than or equal to m, otherwise return false
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        // check if it is possible to make m bouquets with k flowers each
        if ((long long)n < (long long)m * k) return -1;  // if the total number of flowers is less than the required number of flowers, return -1
        int min = *min_element(bloomDay.begin(), bloomDay.end());
        int max = *max_element(bloomDay.begin(), bloomDay.end());
        for (int day = min; day <= max; day++) {
            if (possible(bloomDay, day, m, k, n) == true) {  // if it is possible to make m bouquets with k flowers each on this day, return the day
                return day;
            }
        }
        return -1;
    }
};

// brute force complexity
// Time complexity: O(n * (max - min + 1))) where n is the number of elements in bloomDay and max and min are the maximum and minimum values in bloomDay
// Space complexity: O(1)

// optimal solution
class Solution {
   public:
    bool possible(vector<int> bloomDay, int mid, int m, int k, int n) {
        int count = 0;
        int noofB = 0;
        for (int i = 0; i < n; i++) {
            if (bloomDay[i] <= mid) {
                count++;
            } else {
                noofB += (count / k);
                count = 0;
            }
        }
        noofB += (count / k);
        return noofB >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if ((long long)n < (long long)m * k) return -1;
        int min = *min_element(bloomDay.begin(), bloomDay.end());
        int max = *max_element(bloomDay.begin(), bloomDay.end());
        int low = min;
        int high = max;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (possible(bloomDay, mid, m, k, n)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};

// optimal complexity
// Time complexity: O(n * log(max - min + 1)) where n is the number of elements in bloomDay and max and min are the maximum and minimum values in bloomDay
// Space complexity: O(1)