# Strings

Part of [DSA Practice — Striver's Sheet](../README.md).

| Problem | Pattern | Key Idea |
|---|---|---------------------------------------------------------------------------------------------------------------|
| [Remove Outermost Parentheses](https://leetcode.com/problems/remove-outermost-parentheses/description/) | Stack / Counter | 🟢 Easy • ⏱ 10 min<br>**Approach:**<br>Track parenthesis depth with a counter instead of an actual stack — increment on `(` and decrement on `)`; a character belongs to the answer only when the counter is nonzero after accounting for it, which strips exactly the outermost pair of each group.<br>**Complexity:**<br>Time: O(n) · Space: O(1) |
