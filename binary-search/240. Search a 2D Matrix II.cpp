// Problem  : 240. Search a 2D Matrix II
// Link     : https://leetcode.com/problems/search-a-2d-matrix-ii/description/
// Difficulty: Medium
// Date     : 26/08/2026

/*Example 1:
Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
Output: true

Example 2:
Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20
Output: false*/

#include <vector>
using namespace std;

// brute force approach using linear search
class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == target) {
                    return true;
                }
            }
        }
        return false;
    }
};

// brute force complexity
// Time complexity: O(n*m), where n is the number of rows and m is the number of columns in the matrix.
// We iterate through each element in the matrix to check for the target.
// Space complexity: O(1), as we are using a constant amount of extra space.

// better approach using binary search on each row
class Solution {
   public:
    bool binarySearch(vector<int>& array, int target, int m) {
        int low = 0;
        int high = m - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (array[mid] == target) {
                return true;
            } else if (array[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        for (int i = 0; i < n; i++) {
            if (binarySearch(matrix[i], target, m)) {
                return true;
            }
        }
        return false;
    }
};

// better approach complexity
// Time complexity: O(n*log(m)), where n is the number of rows and m is the number of columns in the matrix.
// We perform binary search on each row, which takes O(log(m)) time.
// Space complexity: O(1), as we are using a constant amount of extra space.

// optimal approach using search from top-right corner
class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int row = 0;         // Start from the first row
        int column = m - 1;  // Start from the last column of the first row
        while (row < n && column >= 0) {
            if (matrix[row][column] == target) {
                return true;
            } else if (matrix[row][column] < target) {  // If the current element is less than the target, move down to the next row
                row++;
            } else {  // If the current element is greater than the target, move left to the previous column
                column--;
            }
        }
        return false;
    }
};

// optimal approach complexity
// Time complexity: O(n + m), where n is the number of rows and m is the number of columns in the matrix.
// We start from the top-right corner and move either down or left based on the comparison with the target.
// Space complexity: O(1), as we are using a constant amount of extra space.