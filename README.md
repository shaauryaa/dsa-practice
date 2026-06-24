# DSA Practice — Striver's Sheet

Tracking my progress through [Striver's SDE Sheet](https://takeuforward.org/interviews/strivers-sde-sheet-top-coding-interview-problems/) — a curated list of the most important DSA problems for coding interviews. Each topic has its own folder with solutions. The table below tracks every problem attempted.

---

## Progress

| Question | Topic | Difficulty | Solved | Time Taken | Notes |
|---|---|---|---|---|---|
| [Largest Element](https://takeuforward.org/plus/dsa/problems/largest-element?source=strivers-a2z-dsa-track) | Arrays | Easy | Yes | 5 mins | O(n) time, O(1) space · brute = optimal · init largest to nums[0], loop from index 1 |
| [Second Largest Element](https://takeuforward.org/plus/dsa/problems/second-largest-element?source=strivers-a2z-dsa-track) | Arrays | Easy | Yes | 10 mins | O(n) time, O(1) space · single pass tracking largest & secondLargest |
| [Check if Array Is Sorted and Rotated](https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/) | Arrays | Easy | Yes | 15 mins | O(n) time, O(1) space · count consecutive non-decreasing pairs over doubled array, true if streak hits N |
| [Remove Duplicates from Sorted Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/) | Arrays | Easy | Yes | 15 mins | O(n) time, O(1) space · two-pointer, overwrite duplicates in place |
| [Rotate Array](https://leetcode.com/problems/rotate-array/) | Arrays | Medium | Yes | 15 mins | O(n) time, O(1) space · reverse whole array, then reverse the two parts |
| [Move Zeroes](https://leetcode.com/problems/move-zeroes/) | Arrays | Easy | Yes | 10 mins | O(n) time, O(1) space · two-pointer swap non-zeroes to front |
| [Max Consecutive Ones](https://leetcode.com/problems/max-consecutive-ones/) | Arrays | Easy | Yes | 10 mins | O(n) time, O(1) space · single pass tracking current streak and max |
| [Single Number](https://leetcode.com/problems/single-number/) | Arrays | Easy | Yes | 10 mins | O(n) time, O(1) space · XOR all elements, duplicates cancel out |
| [Two Sum](https://leetcode.com/problems/two-sum/) | Arrays | Easy | Yes | 10 mins | O(n) time, O(n) space · hashmap to store seen numbers and check complement |
| [Two Sum II - Input Array Is Sorted](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/) | Arrays | Medium | Yes | 10 mins | O(n) time, O(1) space · two-pointer on sorted array, shrink window by sum vs target |
| [Merge Sorted Array](https://leetcode.com/problems/merge-sorted-array/) | Arrays | Easy | Yes | 10 mins | O(m+n) time, O(1) space · fill from the back, compare last elements of both arrays |
| [Missing Number](https://leetcode.com/problems/missing-number/) | Arrays | Easy | Yes | 10 mins | O(n) time, O(1) space · XOR all indices and values, missing number is the leftover |
| [Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k/) | Arrays | Medium | Yes | 30 mins | O(n) time, O(n) space · prefix sum + hashmap, count how many times (sum-k) has appeared |
