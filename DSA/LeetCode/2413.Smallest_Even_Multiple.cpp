/*
====================================================================
LeetCode 2413 - Smallest Even Multiple
====================================================================

+------------------------------------------------------------------+
| Difficulty  - Easy                                               |
| Date of Submission - 24 November 2026 17:21                      |
| Tags - math, number theory                                       |
+------------------------------------------------------------------+

Given a positive integer n, return the smallest positive integer
that is a multiple of both 2 and n.

Input:
Single integer n (1 <= n <= 150)

Output:
Smallest positive integer that is a multiple of both 2 and n.

Examples:
Input: 5 -> Output: 10  (multiples of 5: 5,10,15... first even one is 10)
Input: 6 -> Output: 6   (6 is already even, so 6 itself)
====================================================================
*/

class Solution {
public:
    int smallestEvenMultiple(int n) {
        if(n%2==0) return n;
        else return 2*n;
    }
};

/*
====================================================================
SOLUTION IN MY WORDS
====================================================================

Need smallest number that is multiple of both 2 and n — this is
just lcm(n, 2).

Multiples of 2 are even numbers only. So need smallest even multiple
of n.

Two cases:
- If n is already even (n%2==0), then n itself is a multiple of 2,
  so answer is n.
- If n is odd, smallest even multiple is 2*n.

This is a specific case of a general rule: for any prime p,
lcm(n, p) = n if p divides n, else n*p. Here p=2.

====================================================================
COMPLEXITY
====================================================================

1. TIME COMPLEXITY:

if(n%2==0) return n;    -> O(1)
else return 2*n;        -> O(1)

Total: O(1)

2. SPACE COMPLEXITY:

No extra variables.

Total: O(1)
*/