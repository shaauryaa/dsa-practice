// Problem  : 1021. Remove Outermost Parentheses
// Link     : https://leetcode.com/problems/remove-outermost-parentheses/description/
// Difficulty: Easy
// Date     : 01/09/2026

/*Example 1:
Input: s = "(()())(())"
Output: "()()()"

Example 2:
Input: s = "(()())(())(()(()))"
Output: "()()()()(())"

Example 3:
Input: s = "()()"
Output: ""*/

#include <stack>
#include <string>
using namespace std;

// brute force approach using stack
class Solution {
   public:
    string removeOuterParentheses(string s) {
        stack<char> stackk;             // stack to store the parentheses
        string answer = "";             // string to store the answer
        for (char c : s) {              // iterate through the string
            if (c == '(') {             // if the character is '(', check if the stack is empty, if it is not empty, add the character to the answer string, then push the character to the stack
                if (!stackk.empty()) {  // if the stack is not empty, add the character to the answer string
                    answer += c;
                }
                stackk.push(c);
            } else {  // if the character is ')', pop the character from the stack, if the stack is not empty, add the character to the answer string
                stackk.pop();
                if (!stackk.empty()) {  // if the stack is not empty, add the character to the answer string
                    answer += c;
                }
            }
        }
        return answer;
    }
};

// brute force approach complexity
//   Time  : O(n) as we are iterating through the string once
//   Space : O(n) as we are using a stack to store the parentheses

// optimal approach using counter
class Solution {
   public:
    string removeOuterParentheses(string s) {
        int count = 0;       // counter to keep track of the number of parentheses
        string answer = "";  // string to store the answer
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ')') {  // if the character is ')', decrement the counter, if the counter is not zero, add the character to the answer string
                count--;
            }
            if (count != 0) {
                answer += s[i];
            }
            if (s[i] == '(') {
                count++;
            }
        }
        return answer;
    }
};

// optimal approach complexity
//   Time  : O(n) as we are iterating through the string once
//   Space : O(1) as we are not using any extra space