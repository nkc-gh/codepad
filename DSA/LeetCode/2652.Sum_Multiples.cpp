/*
====================================================================
LeetCode 2652 - Sum of Multiples
====================================================================

+------------------------------------------------------------------+
| Difficulty - Easy                                                |
| Date of Submission - 25 November 2026 14:28                      |
| Tags - Math                                                      |
+------------------------------------------------------------------+

Given a positive integer n, find the sum of all integers in the
range [1, n] inclusive that are divisible by 3, 5, or 7.

Constraints:
1 <= n <= 10^3

Example 1:
Input: n = 7    Output: 21
3, 5, 6, 7 -> 3+5+6+7 = 21

Example 2:
Input: n = 10   Output: 40
3, 5, 6, 7, 9, 10 -> 3+5+6+7+9+10 = 40

Example 3:
Input: n = 9    Output: 30
3, 5, 6, 7, 9 -> 3+5+6+7+9 = 30

====================================================================
*/

class Solution {
public:
    int sumOfMultiples(int n) {
        int sum = 0;
        for(int i=1 ; i<=n ; i++){
            if(i%3==0 || i%5==0 || i%7==0){
                sum+=i;
            }
        }
        return sum;
    }
};

/*
====================================================================
SOLUTION IN MY WORDS
====================================================================

Initialized sum = 0, then looped from 1 to n inclusive. At each i,
checked if it is divisible by 3, 5, or 7 using the modulo operator.
Divisible means remainder is 0 (i % x == 0). If any condition is
true, added i to sum.

Used || (OR) so a number only needs to satisfy one condition to be
included. No risk of double counting since we are adding i itself,
not incrementing a counter per condition.

1 and 2 are naturally skipped — they fail all three checks since
1%3=1, 1%5=1, 1%7=1, 2%3=2, 2%5=2, 2%7=2. No special casing needed.

Traced n=7:
  i=1: 1%3=1, 1%5=1, 1%7=1 -> skip
  i=2: 2%3=2, 2%5=2, 2%7=2 -> skip
  i=3: 3%3=0 -> sum = 3
  i=4: 4%3=1, 4%5=4, 4%7=4 -> skip
  i=5: 5%5=0 -> sum = 8
  i=6: 6%3=0 -> sum = 14
  i=7: 7%7=0 -> sum = 21 -> return 21 ✓

====================================================================
COMPLEXITY
====================================================================

1. TIME COMPLEXITY:

for loop: i from 1 to n         -> O(N)
    i%3, i%5, i%7, sum+=i       -> O(1)

Total: O(N)

2. SPACE COMPLEXITY:

sum, i -> O(1), two fixed integer variables.

Total: O(1)
*/