// Problem  : 73. Set Matrix Zeroes
// Link     : https://leetcode.com/problems/set-matrix-zeroes/
// Difficulty: Medium
// Date     : 03/06/2026

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

/*Example 1:
Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]

Example 2:
Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]*/

// Brute Force Solution
class Solution {
   public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();     // number of rows
        int n = matrix[0].size();  // number of columns
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {                             // if the current element is zero, mark its row and column
                    for (int k = 0; k < n; k++) {                    // iterate through the current row
                        if (matrix[i][k] != 0) matrix[i][k] = -127;  // mark non-zero elements in the row with -127
                    }
                    for (int k = 0; k < m; k++) {                    // iterate through the current column
                        if (matrix[k][j] != 0) matrix[k][j] = -127;  // mark non-zero elements in the column with -127
                    }
                }
            }
        }
        for (int i = 0; i < m; i++) {  // iterate through the matrix again to convert marked elements back to zero
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == -127) matrix[i][j] = 0;  // convert all marked elements back to zero
            }
        }
    }
};

// Brute Force Complexity
// Time : O(m*n)*(m+n)*(m*n) = O(m^2*n^2) somewhere about mn cubed
// Space : O(1)

// Better Solution
class Solution {
   public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();      // number of rows
        int n = matrix[0].size();   // number of columns
        vector<int> rows(m, 0);     // create a vector to mark rows that need to be zeroed
        vector<int> columns(n, 0);  // create a vector to mark columns that need to be zeroed
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {  // if the current element is zero, mark its row and column
                    rows[i] = 1;
                    columns[j] = 1;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (rows[i] || columns[j]) {  // if the current row or column is marked, set the element to zero
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

// Better Complexity
// Time : O(m*n)+(m*n) = O(2*m*n)
// Space : O(m+n)

// Optimal Solution
class Solution {
   public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();     // number of rows
        int n = matrix[0].size();  // number of columns
        int column0 = 1;           // variable to track if the first column needs to be zeroed
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {  // if the current element is zero, mark its row and column using the first row and first column
                    matrix[i][0] = 0;
                    if (j != 0)  // if the current column is not the first column, mark the first row of the current column as zero
                        matrix[0][j] = 0;
                    else  // if the current column is the first column, set column0 to 0 to indicate that the first column needs to be zeroed
                        column0 = 0;
                }
            }
        }
        for (int i = 1; i < m; i++) {  // iterate through the matrix starting from the second row and second column to set elements to zero based on the markings in the first row and first column
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] != 0) {
                    if (matrix[i][0] == 0 || matrix[0][j] == 0) {  // if the current row or column is marked, set the element to zero
                        matrix[i][j] = 0;
                    }
                }
            }
        }
        if (matrix[0][0] == 0) {                           // if the first row needs to be zeroed, set all elements in the first row to zero
            for (int j = 0; j < n; j++) matrix[0][j] = 0;  // set all elements in the first row to zero
        }
        if (column0 == 0) {                                // if the first column needs to be zeroed, set all elements in the first column to zero
            for (int i = 0; i < m; i++) matrix[i][0] = 0;  // set all elements in the first column to zero
        }
    }
};

// Optimal Complexity
// Time : O(m*n)+(m*n) = O(2*m*n)
// Space : O(1)