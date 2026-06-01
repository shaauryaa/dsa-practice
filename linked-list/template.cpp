// ============================================================
// Problem  :
// Link     : https://leetcode.com/problems/
// Difficulty: Easy / Medium / Hard
// Date     :
// ============================================================

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// ------------------------------------------------------------
// Examples
// ------------------------------------------------------------
// Input  :
// Output :
//
// Input  :
// Output :
//
// Edge cases:
//   - Empty input / single element
//   - All elements the same
//   - Negative numbers / overflow
//   - Already sorted / reverse sorted
// ------------------------------------------------------------

class Solution {
public:
    // BRUTE FORCE
    // Approach:
    // Walk through every possibility without any optimisation.
    int solveBrute(vector<int>& nums) {
        // TODO
        return -1;
    }

    // OPTIMAL
    // Approach:
    // Describe the key insight (two-pointer / sliding window / hash / etc.)
    int solveOptimal(vector<int>& nums) {
        // TODO
        return -1;
    }
};

// ------------------------------------------------------------
// Helpers
// ------------------------------------------------------------
void check(const string& label, int got, int expected) {
    cout << label << ": " << (got == expected ? "PASS" : "FAIL")
         << "  (got " << got << ", expected " << expected << ")\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;

    // Test 1 — basic case
    vector<int> t1 = {};
    check("Brute  T1", sol.solveBrute(t1),   /* expected */ 0);
    check("Optimal T1", sol.solveOptimal(t1), /* expected */ 0);

    // Test 2 — edge case
    vector<int> t2 = {};
    check("Brute  T2", sol.solveBrute(t2),   /* expected */ 0);
    check("Optimal T2", sol.solveOptimal(t2), /* expected */ 0);

    // Test 3 — stress / corner case
    vector<int> t3 = {};
    check("Brute  T3", sol.solveBrute(t3),   /* expected */ 0);
    check("Optimal T3", sol.solveOptimal(t3), /* expected */ 0);

    return 0;
}

// ============================================================
// Complexity
// ------------------------------------------------------------
// Brute Force
//   Time  : O( )
//   Space : O( )
//
// Optimal
//   Time  : O( )
//   Space : O( )
// ============================================================
