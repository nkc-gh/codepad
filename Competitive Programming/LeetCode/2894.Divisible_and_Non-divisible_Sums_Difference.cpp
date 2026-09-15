/*
====================================================================
LeetCode 2894 - Divisible and Non-divisible Sums Difference (Easy)
====================================================================

Given positive integers n and m, define:
- num1: sum of all integers in [1, n] that are NOT divisible by m
- num2: sum of all integers in [1, n] that ARE divisible by m

Return num1 - num2.

Constraints:
1 <= n, m <= 1000

Example 1:
Input: n = 10, m = 3
Output: 19
(num1 = 1+2+4+5+7+8+10 = 37, num2 = 3+6+9 = 18, 37-18=19)

Example 2:
Input: n = 5, m = 6
Output: 15
(num1 = 1+2+3+4+5 = 15, num2 = 0 (no multiples of 6 in range))

Example 3:
Input: n = 5, m = 1
Output: -15
(num1 = 0 (every number is divisible by 1), num2 = 1+2+3+4+5 = 15)
====================================================================
*/

class Solution {
public:
    int differenceOfSums(int n, int m) {
        int k = n / m;

        int num2 = m * (k * (k + 1)) / 2;
        int num1 = (n * (n + 1)) / 2 - num2;

        return num1 - num2;
    }
};

/*
====================================================================
ALTERNATE/EARLIER VERSION
====================================================================

First working version used a straightforward O(n) loop, bucketing
each number 1..n into num1 or num2 based on divisibility, without
any closed-form formula:

class Solution {
public:
    int differenceOfSums(int n, int m) {
        int num1=0, num2=0;
        for(int i=1 ; i<=n ; i++){
            if(i%m !=0){
                num1 += i;
            }
            else{
                num2 += i;
            }
        }

        return num1 - num2;
    }
};

====================================================================
SOLUTION IN MY WORDS
====================================================================

The loop version was correct and passed all 3 examples immediately
— straightforward translation of the problem statement, checking
each number's divisibility by m and accumulating into the
appropriate sum.

Since n,m <= 1000 makes the O(n) loop already fast enough, this was
purely for learning: derived an O(1) closed-form version instead of
looping.

Derivation: k = n/m (integer division) gives the COUNT of multiples
of m up to n (e.g. n=10, m=3 -> k=3, since 3,6,9 are the multiples).
Those multiples are m*1, m*2, ..., m*k, so their sum is
m * (1+2+...+k) = m * k*(k+1)/2. This is num2 directly, without
needing to loop through and check divisibility for each number.

num1 is then just the total sum of 1..n (which is n*(n+1)/2) minus
num2, since every number in [1,n] is either divisible by m or not —
no third category.

First attempt at coding this formula had a bug:
`num2 = m*(k*((k+1)/2))` — the inner `(k+1)/2` divides BEFORE
multiplying by k, causing integer truncation to happen too early
and lose information whenever k+1 is odd. Traced this by hand with
k=3: `(k+1)/2` = `4/2` = 2 (fine here since 4 is even), but for
other k values where k+1 is odd, this drops a fraction that should
have survived until after multiplying by k.

Fixed by reordering to `m * (k * (k + 1)) / 2` — multiplying k and
(k+1) FIRST (their product is always even, since they're
consecutive integers, so no information is lost), and only dividing
by 2 as the very last step. This is a general lesson about integer
division: truncation happens at the exact point division occurs, so
placing a division early in an expression can lose precision that
a later multiplication would otherwise have preserved.

====================================================================
COMPLEXITY
====================================================================

1. TIME COMPLEXITY:

k = n/m                          -> O(1)
num2 = m*(k*(k+1))/2               -> O(1), fixed arithmetic ops
num1 = n*(n+1)/2 - num2             -> O(1)
return num1 - num2                  -> O(1)

Total: O(1), constant-time formula regardless of n or m (compare to
the O(n) loop version, which does n iterations).

2. SPACE COMPLEXITY:

k, num1, num2 -> O(1) fixed variables

Total: O(1)

3. COMMON MISTAKES PEOPLE MAKE ON THIS PROBLEM:

- Placing a division too early in the k*(k+1)/2 formula, e.g.
  writing k*((k+1)/2) instead of (k*(k+1))/2 — this truncates
  (k+1) before multiplying by k, silently losing a fraction
  whenever k+1 is odd, and produces a wrong num2 for certain
  inputs even though it may happen to work for some test cases.

- Forgetting that num1 can be computed as (total sum) - num2,
  and instead trying to derive a separate closed-form formula for
  "sum of numbers NOT divisible by m" directly — unnecessarily
  complex when the complement approach is simpler.

- Using the O(n) loop and assuming it's not "good enough" when
  n,m <= 1000 already makes it fast enough for this problem's
  constraints — the O(1) formula is a nice-to-know optimization,
  not a requirement here.

- Integer overflow isn't an issue at these constraints (n,m <= 1000
  keeps all intermediate values well within int range), but the
  same formula with much larger n could overflow int in
  m*(k*(k+1)) if not using a wider type like long long — worth
  keeping in mind for similar problems with bigger bounds.
*/