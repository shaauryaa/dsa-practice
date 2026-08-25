// Problem  : 74. Search a 2D Matrix
// Link     : https://leetcode.com/problems/search-a-2d-matrix/description/
// Difficulty: Medium
// Date     : 25/08/2026

/*Example 1:
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true

Example 2:
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
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
                if (matrix[i][j] == target) return true;
            }
        }
        return false;
    }
};

// brute force complexity
// Time complexity: O(n*m), where n is the number of rows and m is the number of columns in the matrix. We iterate through each element in the matrix to check for the target.
// Space complexity: O(1), as we are using a constant amount of extra space.

// better approach using binary search
class Solution {
   public:
    bool binarysearch(vector<int>& array, int target) {  // Perform binary search on the given array to find the target
        int n = array.size();
        int low = 0;
        int high = n - 1;
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
        return false;  // If the target is not found in the array, return false
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        for (int i = 0; i < n; i++) {                                    // Check if the target could be in the current row
            if (matrix[i][0] <= target && target <= matrix[i][m - 1]) {  // If the target is within the range of the current row, perform binary search on that row
                return binarysearch(matrix[i], target);                  // Perform binary search on the current row
            }
        }
        return false;  // If the target is not found in any row, return false
    }
};

// better complexity
// Time complexity: O(n + log(m)), where n is the number of rows and m is the number of columns in the matrix. We perform a binary search on each row that could contain the target.
// Space complexity: O(1), as we are using a constant amount of extra space.

// optimal approach using binary search on the entire matrix
class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int low = 0;             // first index of the matrix when flattened into a 1D array
        int high = (n * m) - 1;  // last index of the matrix when flattened into a 1D array
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int row = mid / m;
            int column = mid % m;
            if (matrix[row][column] == target) {
                return true;
            } else if (matrix[row][column] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return false;
    }
};

// optimal complexity
// Time complexity: O(log(n*m)), where n is the number of rows and m is the number of columns in the matrix. We perform a binary search on the entire matrix.
// Space complexity: O(1), as we are using a constant amount of extra space.