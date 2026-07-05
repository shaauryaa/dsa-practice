// Problem  : 54. Spiral Matrix
// Link     : https://leetcode.com/problems/spiral-matrix/
// Difficulty: Medium
// Date     : 06/07/2026

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// optimal solution (also the only solution for this problem)
class Solution {
   public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> answer;                 // to store the elements in spiral order
        if (matrix.empty()) return answer;  // return empty answer if the matrix is empty

        int m = matrix.size();     // number of rows
        int n = matrix[0].size();  // number of columns
        int top = 0;               // initialize the top boundary
        int bottom = m - 1;        // initialize the bottom boundary
        int left = 0;              // initialize the left boundary
        int right = n - 1;         // initialize the right boundary

        while (top <= bottom && left <= right) {   // continue until the boundaries overlap
            for (int i = left; i <= right; i++) {  // traverse from left to right along the top boundary
                answer.push_back(matrix[top][i]);
            }
            top++;  // move the top boundary down

            for (int i = top; i <= bottom; i++) {  // traverse from top to bottom along the right boundary
                answer.push_back(matrix[i][right]);
            }
            right--;  // move the right boundary left

            if (top <= bottom) {                       // check if there are rows remaining
                for (int i = right; i >= left; i--) {  // traverse from right to left along the bottom boundary
                    answer.push_back(matrix[bottom][i]);
                }
                bottom--;  // move the bottom boundary up
            }

            if (left <= right) {                       // check if there are columns remaining
                for (int i = bottom; i >= top; i--) {  // traverse from bottom to top along the left boundary
                    answer.push_back(matrix[i][left]);
                }
                left++;  // move the left boundary right
            }
        }

        return answer;  // return the elements in spiral order
    }
};

// Optimal Complexity
//   Time  : O(m*n) where m is the number of rows and n is the number of columns
//   Space complexity is O(m*n) if we consider the output vector as part of the space used.