// Problem  : Painters Partition Problem
// Link : https://takeuforward.org/plus/dsa/problems/painters-partition-problem?source=strivers-a2z-dsa-track
// Difficulty: Medium
// Date     : 19/08/2026

#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

// brute force approach
class Solution {
public:
    int calculatepainters(vector<int>& C, int length, int n) {
        int painters = 1;
        int totallength = 0;
        for (int i = 0; i < n; i++) {
            if (totallength += C[i] <= length) {
                totallength += C[i];
            } else {
                painters++;
                totallength = C[i];
            }
        }
        return painters;
    }
    int paint(int A, int B, vector<int>& C) {
        int n = C.size();
        int maxelement = *max_element(C.begin(), C.end());
        long long totalsum = accumulate(C.begin(), C.end(), 0LL);
        long long bestlength = totalsum;
        for (int length = maxelement; length <= totalsum; length++) {
            int totalpainters = calculatepainters(C, length, n);
            if (totalpainters <= A) {
                bestlength = length;
                break;
            }
        }
        long long besttime = bestlength * B;
        return besttime;
    }
};

// brute force complexity
// Time complexity: O(n * (totalsum - maxelement))
// Space complexity: O(1)

// optimal approach using binary search
class Solution {
public:
    int calculatepainters(vector<int>& C, int length, int n) {
        int painters = 1;
        int totallength = 0;
        for (int i = 0; i < n; i++) {
            if (totallength += C[i] <= length) {
                totallength += C[i];
            } else {
                painters++;
                totallength = C[i];
            }
        }
        return painters;
    }
    int paint(int A, int B, vector<int>& C) {
        int n = C.size();
        int low = *max_element(C.begin(), C.end());
        long long high = accumulate(C.begin(), C.end(), 0LL);
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int totalpainters = calculatepainters(C, mid, n);
            if (totalpainters > A) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low * B;
    }
};

// optimal complexity
// Time complexity: O(n * log(totalsum - maxelement))
// Space complexity: O(1)