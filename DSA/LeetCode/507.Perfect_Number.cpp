/*
====================================================================
LeetCode 507 - Perfect Number
====================================================================

+------------------------------------------------------------------+
| Difficulty - Easy                                                |
| Date of Submission - 23 November 2026 23:34                      |
| Tags - math                                                      |
+------------------------------------------------------------------+

A perfect number is a positive integer equal to the sum of its
positive divisors, excluding itself.

Given an integer num, return true if it is a perfect number,
otherwise return false.

Constraints:
1 <= num <= 10^8

Example 1:
Input: num = 28
Output: true
Explanation: 1 + 2 + 4 + 7 + 14 = 28

Example 2:
Input: num = 7
Output: false

====================================================================
*/

class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num == 1) return false;
        int sol = 0;
        for(int a = 1 ; a*a <= num ; a++){
            int b = num/a;
            if(a*b == num){
                if(b == num || a == b){
                    sol += a;
                }
                else{
                    sol += a + b;
                }
            }
        }
        return sol == num;
    }
};

/*
====================================================================
SOLUTION IN MY WORDS
====================================================================

For every divisor pair (a, b) where a*b = n, one is always <= sqrt(n).
So loop only till sqrt(n) — for each a that divides num, b = num/a
is the paired divisor.

Three cases when a divides num:
- b == num: means a == 1, so b is num itself — exclude it, add only a.
- a == b: means a = sqrt(num) — add only once to avoid double counting.
- else: both a and b are distinct proper divisors — add both.

Edge case: num == 1 has no proper divisors at all (no positive
integer less than 1 exists), so return false immediately. Without
this, the loop would add 1 to sol and incorrectly return true.

Used a*a <= num instead of a <= sqrt(num) to avoid floating point
computation on every iteration — integer multiplication is cheaper.

====================================================================
COMPLEXITY
====================================================================

1. TIME COMPLEXITY:

loop runs from 1 to sqrt(num)    -> O(sqrt(n)) iterations
    a*b == num check               -> O(1)
    sol += ...                     -> O(1)

Total: O(sqrt(n))

2. SPACE COMPLEXITY:

sol, a, b — all scalar variables  -> O(1)

Total: O(1)
*/