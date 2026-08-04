// Problem  : 162. Find Peak Element 2
// Link     : https://leetcode.com/problems/find-a-peak-element-ii/description/
// Difficulty: Medium
// Date     : 04/08/2026

/*Example 1:
Input: mat = [[1,4],[3,2]]
Output: [0,1]
Explanation: Both 3 and 4 are peak elements so [1,0] and [0,1] are both acceptable answers.

Example 2:
Input: mat = [[10,20,15],[21,30,14],[7,16,32]]
Output: [1,1]
Explanation: Both 30 and 32 are peak elements so [1,1] and [2,2] are both acceptable answers.*/

#include <vector>
using namespace std;

// brute force approach using linear search to find maximum element in the matrix which is guaranteed to be a peak element
class Solution {
   public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int maxvalue = mat[0][0];
        int rowindex = 0;
        int colindex = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] > maxvalue) {
                    maxvalue = mat[i][j];
                    rowindex = i;
                    colindex = j;
                }
            }
        }
        return {rowindex, colindex};
    }
};

// brute force complexity
// Time complexity: O(n*m)
// Space complexity: O(1)

// optimal approach using binary search
class Solution {
   public:
    int findmaxindex(vector<vector<int>>& mat, int n, int column) {
        int maxvalue = -1;
        int maxindex = -1;
        for (int i = 0; i < n; i++) {
            // Find the maximum element in the specified column
            if (mat[i][column] > maxvalue) {
                maxvalue = mat[i][column];
                maxindex = i;
            }
        }
        return maxindex;
    }

   public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int low = 0;
        int high = m - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int rowindex = findmaxindex(mat, n, mid);
            // Check the left and right neighbors of the maximum element in the mid column
            int left = mid - 1 >= 0 ? mat[rowindex][mid - 1] : -1;
            int right = mid + 1 < m ? mat[rowindex][mid + 1] : -1;
            // If the maximum element is greater than its neighbors, it is a peak
            if (mat[rowindex][mid] > left && mat[rowindex][mid] > right) {
                return {rowindex, mid};
            }
            // If the left neighbor is greater, search in the left half
            else if (mat[rowindex][mid] < left) {
                high = mid - 1;
            }
            // If the right neighbor is greater, search in the right half
            else {
                low = mid + 1;
            }
        }
        return {-1, -1};
    }
};

// optimal complexity
// Time complexity: O(n*log(m)) where n is the number of rows and m is the number of columns
// Space complexity: O(1)