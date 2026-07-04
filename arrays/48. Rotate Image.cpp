// Problem  : 48. Rotate Image
// Link     : https://leetcode.com/problems/rotate-image/
// Difficulty: Medium
// Date     : 04/07/2026

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// brute force solution
class Solution {
   public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> answer(n, vector<int>(n));  // create a new matrix to store the rotated version
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                answer[j][(n - 1) - i] = matrix[i][j];  // rotate the element by placing it in the new position in the answer matrix
            }
        }
        matrix = answer;  // copy the rotated matrix back to the original matrix
    }
};

// Brute Force Complexity
//   Time  : O(n^2)
//   Space : O(n^2)

// Optimal Solution
class Solution {
   public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n - 1; i++) {          // iterate through the rows of the matrix, stopping before the last row
            for (int j = i + 1; j < n; j++) {      // iterate through the columns of the matrix, starting from the next column after the current row index
                swap(matrix[i][j], matrix[j][i]);  // swap the elements at positions (i, j) and (j, i) to transpose the matrix
            }
        }
        for (int i = 0; i < n; i++) {                     // iterate through each row of the transposed matrix
            reverse(matrix[i].begin(), matrix[i].end());  // reverse the elements in each row to achieve the final rotated matrix
        }
    }
};

// Optimal Complexity
//   Time  : O(n^2)
//   Space : O(1)
