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
    int findmax(vector<int>& piles, int n) {
        int maxelement = INT_MIN;
        for (int i = 0; i < n; i++) {
            maxelement = max(maxelement, piles[i]);
        }
        return maxelement;
    }
    long long calculatehours(vector<int>& piles, int perhour, int n) {
        long long totalhours = 0;
        for (int i = 0; i < n; i++) {
            totalhours += (piles[i] + perhour - 1) / perhour;
        }
        return totalhours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1;
        int high = findmax(piles, n);
        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long totalh = calculatehours(piles, mid, n);
            if (totalh <= h) {
                high = mid - 1;
            } else {
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
        int maxelement = INT_MIN;
        for (int i = 0; i < n; i++) {
            maxelement = max(maxelement, piles[i]);
        }
        for (int i = 1; i <= maxelement; i++) {
            long long totalhours = 0;
            for (int j = 0; j < n; j++) {
                totalhours += (piles[j] + i - 1) / i;
            }
            if (totalhours <= h) {
                return i;
            }
        }
        return -1;
    }
};

// brute force complexity
// Time complexity: O(n*m) where n is the number of piles and m is the maximum number of bananas in a pile
// Space complexity: O(1)