/*
====================================================================
Codeforces 996A - Hit the Lottery
====================================================================

+------------------------------------------------------------------+
| Difficulty  - 800                                                |
| Date of Submission - 24 November 2026 16:16                      |
| Tags - dp, greedy                                                |
+------------------------------------------------------------------+

Allen has n dollars in the bank. He wants to withdraw it in cash.
The denominations for dollar bills are 1, 5, 10, 20, 100.
What is the minimum number of bills Allen could receive?

Input:
Single integer n (1 <= n <= 10^9)

Output:
Minimum number of bills.

Examples:
Input: 125  -> Output: 3   (100 + 20 + 5)
Input: 43   -> Output: 5   (20 + 20 + 1 + 1 + 1)
Input: 1000000000 -> Output: 10000000
====================================================================
*/

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int notes = 0;
    notes += n/100; n %= 100;
    notes += n/20;  n %= 20;
    notes += n/10;  n %= 10;
    notes += n/5;   n %= 5;
    notes += n/1;   n %= 1;

    cout << notes << "\n";
    return 0;
}

/*
====================================================================
SOLUTION IN MY WORDS
====================================================================

First idea: while loop — keep subtracting the largest bill that fits
until n becomes 0, increment count each time. Logic was correct.

Problem: n can be up to 10^9. Worst case (all 1s) means 10^9 loop
iterations. That's TLE.

Fix: instead of subtracting one bill at a time, use division to get
the count of each denomination directly, and mod to get the
remainder for the next denomination.

Core math:
- n/100  -> how many 100s fit
- n%100  -> what's left after removing all 100s
- repeat for 20, 10, 5, 1

Example: n = 125
- 125/100 = 1 bill, 125%100 = 25 remaining
- 25/20   = 1 bill, 25%20   = 5 remaining
- 5/10    = 0 bills, 5%10   = 5 remaining
- 5/5     = 1 bill, 5%5     = 0 remaining
- total   = 3 bills

Algorithm: Greedy — always pick the largest denomination first.
Works here because the denominations are structured such that
greedy always gives the optimal result. (Unlike general coin change
where DP is needed.)

Why not DP: n is up to 10^9, a dp[n] array would be too large.
Greedy is O(1) and sufficient for these denominations.

====================================================================
COMPLEXITY
====================================================================

1. TIME COMPLEXITY:

notes += n/100; n %= 100;   -> O(1)
notes += n/20;  n %= 20;    -> O(1)
notes += n/10;  n %= 10;    -> O(1)
notes += n/5;   n %= 5;     -> O(1)
notes += n/1;   n %= 1;     -> O(1)

Total: O(1)

2. SPACE COMPLEXITY:

n, notes -> two fixed variables, no array/container.

Total: O(1)
*/