/*
====================================================================
LeetCode 2235 - Add Two Integers
====================================================================

+------------------------------------------------------------------+
| Difficulty  - Easy                                               |
| Date of Submission - 24 November 2026 17:11                      |
| Tags - math                                                      |
+------------------------------------------------------------------+

Given two integers num1 and num2, return the sum of the two integers.

Input:
Two integers num1 and num2 (-100 <= num1, num2 <= 100)

Output:
Sum of num1 and num2.

Examples:
Input: num1 = 12, num2 = 5   -> Output: 17
Input: num1 = -10, num2 = 4  -> Output: -6
====================================================================
*/

class Solution {
public:
    int sum(int num1, int num2) {
        return num1 + num2;
    }
};

/*
====================================================================
SOLUTION IN MY WORDS
====================================================================

Just add two numbers.

====================================================================
COMPLEXITY
====================================================================

1. TIME COMPLEXITY:

return num1 + num2;   -> O(1)

Total: O(1)

2. SPACE COMPLEXITY:

No extra variables.

Total: O(1)
*/