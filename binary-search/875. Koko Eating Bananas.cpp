// Problem  : 875. Koko Eating Bananas
// Link     : https://leetcode.com/problems/koko-eating-bananas/description/
// Difficulty: Medium
// Date     : 06/08/2026

/*Example 1:
Input: piles = [3,6,7,11], h = 8
Output: 4

Example 2:
Input: piles = [30,11,23,4,20], h = 5
Output: 30

Example 3:
Input: piles = [30,11,23,4,20], h = 6
Output: 23*/

#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

// optimal solution
class Solution {
   public:
    // function to calculate total hours required to eat all bananas at a given speed
    long long calculatehours(vector<int>& piles, int bananas, int n) {
        long long totalhours = 0;
        // iterate through each pile and calculate the hours required to eat all bananas at the given speed
        for (int i = 0; i < n; i++) {
            // calculate hours for each pile using ceil division
            totalhours += (piles[i] + bananas - 1) / bananas;
        }
        return totalhours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int maxelement = INT_MIN;
        // find the maximum number of bananas in a pile
        for (int i = 0; i < n; i++) {
            maxelement = max(maxelement, piles[i]);
        }
        int low = 1;
        int high = maxelement;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long totalh = calculatehours(piles, mid, n);
            // if total hours is less than or equal to h, search in the left half to find a smaller speed
            if (totalh <= h) {
                high = mid - 1;
            }
            // if total hours is greater than h, search in the right half to find a larger speed
            else {
                low = mid + 1;
            }
        }
        return low;
    }
};

// optimal compexity
// Time complexity: O(nlogm) where n is the number of piles and m is the maximum number of bananas in a pile
// Space complexity: O(1)

// brute force solution
class Solution {
   public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        // find the maximum number of bananas in a pile
        int maxelement = INT_MIN;
        for (int i = 0; i < n; i++) {
            maxelement = max(maxelement, piles[i]);
        }
        // iterate from 1 to maxelement to find the minimum eating speed
        for (int bananas = 1; bananas <= maxelement; bananas++) {
            long long totalhours = 0;
            // calculate total hours required to eat all bananas at the current speed
            for (int j = 0; j < n; j++) {
                totalhours += (piles[j] + bananas - 1) / bananas;  // ceil division to calculate hours for each pile
            }
            // if total hours is less than or equal to h, return the current speed
            if (totalhours <= h) {
                return bananas;
            }
        }
        return -1;
    }
};

// brute force complexity
// Time complexity: O(n*m) where n is the number of piles and m is the maximum number of bananas in a pile
// Space complexity: O(1)