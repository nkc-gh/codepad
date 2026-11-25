/*
====================================================================
LeetCode 75 - Sort Colors
====================================================================

+------------------------------------------------------------------+
| Difficulty - Medium                                              |
| Date of Submission - 25 November 2026 15:52                      |
| Tags - Array, Two Pointers, Sorting, Quicksort, Bubble Sort      |
+------------------------------------------------------------------+

Given an array nums with n objects colored red, white, or blue,
sort them in-place so that objects of the same color are adjacent,
in the order red, white, blue (0, 1, 2). Cannot use library sort.

Constraints:
n == nums.length
1 <= n <= 300
nums[i] is either 0, 1, or 2.

Example 1:
Input: nums = [2,0,2,1,1,0]   Output: [0,0,1,1,2,2]

Example 2:
Input: nums = [2,0,1]         Output: [0,1,2]

====================================================================
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red = 0, white = 0, blue = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) red++;
            else if (nums[i] == 1) white++;
            else blue++;
        }

        int i = 0;
        for (int r = 0; r < red; r++) { nums[i] = 0; i++; }
        for (int w = 0; w < white; w++) { nums[i] = 1; i++; }
        for (int b = 0; b < blue; b++) { nums[i] = 2; i++; }
    }
};

/*
====================================================================
SOLUTION IN MY WORDS
====================================================================

Since only 3 possible values exist (0, 1, 2), used Counting Sort
instead of a general sorting algorithm.

Pass 1 — count occurrences of each value using 3 counter variables:
red (0s), white (1s), blue (2s).

Pass 2 — overwrite the array in-place using a single index i:
first write red 0s, then white 1s, then blue 2s.

Did not use assign/insert as those reconstruct the vector which
violates the in-place restriction. Instead manually overwrote
existing indices using nums[i] = value with an incrementing pointer.

Function is void — modifies nums directly via reference (vector<int>&),
no return needed.

Traced [2,0,2,1,1,0]:
  Count pass: red=2, white=2, blue=2
  Write pass: i=0,1 -> 0,0 | i=2,3 -> 1,1 | i=4,5 -> 2,2
  Result: [0,0,1,1,2,2] ✓

====================================================================
COMPLEXITY
====================================================================

1. TIME COMPLEXITY:

Pass 1 - count loop: O(N)
Pass 2 - three write loops combined: O(N) total (red+white+blue = n)

Total: O(N)

2. SPACE COMPLEXITY:

red, white, blue, i -> O(1), four fixed integer variables.
Modified in-place, no extra array used.

Total: O(1)

====================================================================
FOLLOW UP
====================================================================

Dutch National Flag (DNF) algorithm solves this in a single pass
using three pointers (low, mid, high). Same O(N) time and O(1)
space but touches each element only once instead of twice.
Worth revisiting after learning more about two pointer techniques.
*/