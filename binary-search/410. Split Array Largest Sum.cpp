// Problem: 410. Split Array Largest Sum
// Link: https://leetcode.com/problems/split-array-largest-sum/description/
// Date: 18/08/26
// Difficulty: Hard

#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

// brute force approach
class Solution {
   public:
    int calculatesplits(vector<int>& nums, int sum, int n) {
        int splits = 1;
        long long totalsum = 0;
        for (int i = 0; i < n; i++) {
            if (totalsum + nums[i] <= sum) {
                totalsum += nums[i];
            } else {
                splits++;
                totalsum = nums[i];
            }
        }
        return splits;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < k) return -1;
        int maxelement = *max_element(nums.begin(), nums.end());
        int totalsum = accumulate(nums.begin(), nums.end(), 0);
        for (int sum = maxelement; sum <= totalsum; sum++) {
            int totalsplits = calculatesplits(nums, sum, n);
            if (totalsplits <= k) {
                return sum;
            }
        }
        return -1;
    }
};

// brute force complexity
// Time complexity: O(n * (totalsum - maxelement))
// Space complexity: O(1)

// optimal approach using binary search
class Solution {
   public:
    int calculatesplits(vector<int>& nums, int maxsum, int n) {
        int splits = 1;
        long long totalsum = 0;
        for (int i = 0; i < n; i++) {
            if (totalsum + nums[i] <= maxsum) {
                totalsum += nums[i];
            } else {
                splits++;
                totalsum = nums[i];
            }
        }
        return splits;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < k) return -1;
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int totalsplits = calculatesplits(nums, mid, n);
            if (totalsplits > k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
};

// optimal complexity
// Time complexity: O(n * log(totalsum - maxelement))
// Space complexity: O(1)