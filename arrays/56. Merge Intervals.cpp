// Problem  : 56. Merge Intervals
// Link     : https://leetcode.com/problems/merge-intervals/
// Difficulty: Medium
// Date     : 10/07/2026

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

/*Example 1:
Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].

Example 2:
Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.

Example 3:
Input: intervals = [[4,7],[1,4]]
Output: [[1,7]]
Explanation: Intervals [1,4] and [4,7] are considered overlapping.*/

// brute force approach
class Solution {
   public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> answer;
        for (int i = 0; i < n; i++) {
            int start = intervals[i][0];                               // get the start of the current interval
            int end = intervals[i][1];                                 // get the end of the current interval
            if (!answer.empty() && end <= answer.back()[1]) continue;  // if the current interval is completely within the last merged interval, skip it
            for (int j = i + 1; j < n; j++) {
                if (intervals[j][0] <= end) {         // if the next interval overlaps with the current interval
                    end = max(end, intervals[j][1]);  // update the end to the maximum of the current end and the next interval's end
                } else {
                    break;
                }
            }
            answer.push_back({start, end});  // add the merged interval to the answer
        }
        return answer;
    }
};

// brute force complexity analysis
// Time Complexity: O(n log n) - The sorting step takes O(n log n) time, and the merging step takes O(2n) time as each element is processed at most twice
// (once for checking and once for merging). Therefore, the overall time complexity is dominated by the sorting step, resulting in O(n log n)+O(2n).
// Space Complexity: O(n) - The space used for the answer vector is proportional to the number of merged intervals, which can be at most n in the worst case.

// optimal approach
class Solution {
   public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> answer;
        for (int i = 0; i < n; i++) {
            if (answer.empty() || intervals[i][0] > answer.back()[1]) {  // if the answer is empty or the current interval does not overlap with the last merged interval, add it to the answer
                answer.push_back(intervals[i]);
            } else {  // if the current interval overlaps with the last merged interval, merge them by updating the end of the last merged interval to the maximum of the two ends
                answer.back()[1] = max(answer.back()[1], intervals[i][1]);
            }
        }
        return answer;
    }
};

// optimal complexity analysis
// Time Complexity: O(n log n) - The sorting step takes O(n log n) time, and the merging step takes O(n) time as each element is processed at most once. Therefore, the overall time complexity is dominated by the sorting step, resulting in O(n log n).
// Space Complexity: O(n) - The space used for the answer vector is proportional to the number of merged intervals, which can be at most n in the worst case.