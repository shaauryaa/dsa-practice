// Problem  : Book Allocation Problem
// Link : https://takeuforward.org/plus/dsa/problems/book-allocation-problem?source=strivers-a2z-dsa-track
// Difficulty: Medium
// Date     : 04/08/2026

/*Example 1
Input: nums = [12, 34, 67, 90], m=2
Output: 113
Explanation: The allocation of books will be 12, 34, 67 | 90. One student will get the first 3 books and the other will get the last one.

Example 2
Input: nums = [25, 46, 28, 49, 24], m=4
Output: 71
Explanation: The allocation of books will be 25, 46 | 28 | 49 | 24.*/

#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

// brute force approach
class Solution {
   public:
    int calculatestudents(vector<int>& nums, int pages, int n) {
        int students = 1;
        long long studentpages = 0;
        for (int i = 0; i < n; i++) {
            if (studentpages + nums[i] <= pages) {
                studentpages += nums[i];
            } else {
                students++;
                studentpages = nums[i];
            }
        }
        return students;
    }
    int findPages(vector<int>& nums, int m) {
        int n = nums.size();
        if (n < m) return -1;
        int maxelement = *max_element(nums.begin(), nums.end());
        long long totalsum = 0;
        for (int i = 0; i < n; i++) {
            totalsum += nums[i];
        }
        for (int pages = maxelement; pages <= totalsum; pages++) {
            int totalstudents = calculatestudents(nums, pages, n);
            if (totalstudents <= m) {
                return pages;
            }
        }
    }
};

// brute force complexity
// Time complexity: O(n * (totalsum - maxelement))
// Space complexity: O(1)

// optimal approach using binary search
class Solution {
   public:
    int calculateStudents(vector<int>& nums, int pages, int n) {
        int students = 1;
        long long studentpages = 0;
        for (int i = 0; i < n; i++) {
            if (studentpages + nums[i] <= pages) {
                studentpages += nums[i];
            } else {
                students++;
                studentpages = nums[i];
            }
        }
        return students;
    }
    int findPages(vector<int>& nums, int m) {
        int n = nums.size();
        if (n < m) return -1;
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int totalstudents = calculateStudents(nums, mid, n);
            if (totalstudents > m) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
};

// optimal complexity
// Time Complexity: O(n * log(totalsum - maxelement + 1))
// Space Complexity: O(1)