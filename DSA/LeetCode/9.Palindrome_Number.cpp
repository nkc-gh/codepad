/*
====================================================================
LeetCode 9 - Palindrome Number (Easy)
====================================================================

Given an integer x, return true if x is a palindrome, false
otherwise. Follow-up: solve without converting to a string.

Constraints:
-2^31 <= x <= 2^31 - 1

Example 1:
Input: x = 121
Output: true

Example 2:
Input: x = -121
Output: false
(reversed becomes "121-", invalid)

Example 3:
Input: x = 10
Output: false
(reversed becomes "01", leading zero invalid)
====================================================================
*/

class Solution {
public:
    bool isPalindrome(int x) {
        int originalnum = x, remainder;
        long long int reverse = 0;
        if(x==0){
            return true;
        }

        else if(x < 0 || x % 10 == 0){
            return false;
        }

        else{
            while(x != 0){
                remainder = x % 10;
                reverse = (reverse * 10) + remainder;
                x = x / 10;
            }

            if(originalnum == reverse){
                return true;
            }

            else{
                return false;
            }
        }
    }
};

/*
====================================================================
SOLUTION IN MY WORDS
====================================================================

Since the follow-up explicitly disallowed string conversion, went
straight for digit-by-digit reversal using % and / instead of
converting to a string and checking it directly - already knew this
peeling technique from Roman to Integer (getting a digit via
remainder, shrinking the number via integer division).

First identified negative numbers as an immediate special case:
since a "-" sign can never be meaningfully reversed as part of a
number (reversing "-121" digit-wise would produce something like
"121-", not a valid number), any x<0 can be rejected immediately
without any digit work at all - matches example 2 directly.

Attempted to reverse the entire number and compare it to the
original. First version had two bugs: (1) the final else branch
wrote a bare `false;` instead of `return false;`, meaning that path
fell through without returning anything meaningful; (2) traced
x=10 by hand and found the reversal produces 1, not 10 or "01" -
since leading zeros cannot exist in a stored integer, any x that is
nonzero but ends in a trailing 0 (i.e. x%10==0 && x!=0) can never
possibly be a palindrome, since its reverse would need to start
with 0. Initially tried patching this with x<=0 as a single
combined negative-and-zero check, but this incorrectly rejected
x=0 itself, which the problem trivially counts as a palindrome
(a single "0" reads the same both ways) - had to separate x==0
(true) from x<0 (false) as genuinely different cases, checked in
an order where x==0 is caught first so it doesn't fall into the
x%10==0 trap (0%10==0 would otherwise wrongly return false for 0).

Once the early-exit logic was correct, ran into a genuine overflow
concern raised proactively before it caused a real failure: with
int's range being -2^31 to 2^31-1, a valid input near INT_MAX could
reverse into something exceeding INT_MAX. Confirmed this concretely
with x=1463847419 (fully valid per constraints), which reverses to
9147483641 - far beyond int's max of 2147483647. Building this
value via reverse = reverse*10 + remainder inside an int would
silently overflow, causing undefined behavior. Fixed by declaring
reverse as long long (64-bit, range up to ~9.2*10^18), comfortably
holding any possible 10-digit reversal. Confirmed that comparing
originalnum (int) against reverse (long long) is safe in C++, since
the smaller type is always automatically promoted/widened to match
the larger type in a comparison - never the reverse (narrowing),
which is what makes the comparison correct without any explicit
cast.

Learned about an existing, more refined standard approach (used in
LeetCode's own editorial) after solving: reversing only HALF the
number instead of the whole thing - see the separate half-reversal
version below, which sidesteps the overflow problem by construction
rather than by switching to a wider type.

====================================================================
COMPLEXITY
====================================================================

1. TIME COMPLEXITY:

while loop, one iteration per digit of x   -> O(d), where d is the
    number of digits in x (at most ~10 for a 32-bit int)
comparisons/early exits                     -> O(1)

Total: O(d), i.e. O(log10(x)), since digit count grows
logarithmically with the value of x.

2. SPACE COMPLEXITY:

originalnum, remainder, reverse -> O(1) fixed variables (reverse
    needs 8 bytes as long long instead of 4 as int, but still a
    fixed, input-independent amount)

Total: O(1)

3. COMMON MISTAKES PEOPLE MAKE ON THIS PROBLEM:

- Writing a bare `false;` instead of `return false;` in an else
  branch - compiles without error (as a discarded expression
  statement) but doesn't actually return anything from that path.

- Treating x=0 the same as other trailing-zero numbers (x%10==0)
  and incorrectly rejecting it - 0 is trivially a palindrome and
  must be handled as its own explicit case, checked before the
  trailing-zero rejection, or ordered so it isn't wrongly caught.

- Reversing the full number into a plain int without considering
  overflow - some valid 32-bit inputs (e.g. those close to
  INT_MAX/INT_MIN) reverse into values that exceed int's range,
  causing undefined behavior; using long long avoids this by giving
  enough headroom for any possible digit reversal.

- Comparing across different-width integer types without
  understanding the promotion rule - assuming a comparison between
  int and long long might silently truncate or behave unexpectedly,
  when in fact C++ always safely widens the smaller type to match
  the larger one for the comparison.

- Not recognizing that trailing zero (for nonzero x) guarantees a
  non-palindrome, and instead relying purely on the full reversal
  to naturally produce a mismatching result - works correctly but
  wastes a full digit-reversal pass on inputs that could have been
  rejected immediately.
*/

/*
====================================================================
ALTERNATE (MORE OPTIMAL) VERSION - HALF REVERSAL
====================================================================

Found this to be the standard/editorial-preferred approach after
solving my own version. Instead of reversing the ENTIRE number, it
reverses only HALF the digits, stopping once the reversed half
(halfRev) becomes >= the remaining original half (x). This avoids
the overflow problem entirely by construction - since only half the
digits are ever reversed, halfRev can never grow large enough to
exceed a plain int's range, so no long long is needed at all.

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 || (x % 10 == 0 && x != 0)){
            return false;
        }

        int halfRev = 0;

        while(halfRev < x){
            halfRev = halfRev * 10 + (x % 10);
            x /= 10;
        }

        return halfRev == x || halfRev / 10 == x;
    }
};

SOLUTION IN MY WORDS (for this alternate version):

The early-exit conditions collapse the same two special cases from
my version into one combined line: x<0 (negative) OR (x%10==0 AND
x!=0) (nonzero trailing zero) both return false immediately. Unlike
my version, this doesn't need a separate x==0 check first, since
x=0 fails BOTH conditions (0 is not <0, and 0%10==0 is true but
x!=0 is false, so the AND short-circuits to false) - meaning x=0
correctly falls through to the main loop, where the loop condition
halfRev(0) < x(0) is immediately false, so the loop never executes,
and the final check 0==0 correctly returns true.

The core idea: build halfRev digit-by-digit from x's trailing
digits, exactly like a normal reversal, but STOP as soon as
halfRev becomes >= x (the shrinking remainder of the original
number). At that stopping point, roughly half of the original
digits have moved into halfRev, and the other half remain in x.

Traced this on x=1221 (even digit count): iter1: halfRev=1, x=122.
iter2: halfRev=12, x=12. Check halfRev(12)<x(12)? False, stop.
Final: halfRev=12, x=12. halfRev==x -> true, correctly identifies
1221 as a palindrome, with both halves exactly equal since the
digit count was even.

Traced this on x=121 (odd digit count): iter1: halfRev=1, x=12.
iter2: halfRev=12, x=1. Check halfRev(12)<x(1)? False, stop. Final:
halfRev=12, x=1. halfRev==x -> 12==1, false. But halfRev/10==x ->
12/10=1 (integer division), 1==1, true - correctly identifies 121
as a palindrome. The extra halfRev/10==x check exists specifically
for odd-digit-count numbers: the middle digit ends up as the last
digit absorbed into halfRev, but it doesn't need a "partner" digit
to match against (it's the number's own center) - dividing halfRev
by 10 discards that unmatched middle digit before comparing the two
now-equal-length halves.

COMPLEXITY (half-reversal version):

Time: O(d/2), where d is the digit count of x - roughly half as
many iterations as reversing the full number, though this remains
the same O(log10(x)) complexity CLASS as the full-reversal version,
since constant factors don't change Big-O classification.

Space: O(1) - crucially, only ever needs a plain int for halfRev,
since it never builds more than half of x's digits, which can never
be large enough to overflow a 32-bit int even in the worst case.
This is a genuine (if constant-factor) improvement over my version,
which needed a long long specifically to accommodate full-number
reversal overflow - the half-reversal approach avoids the overflow
problem by construction rather than by widening the type.

COMMON MISTAKES SPECIFIC TO THIS APPROACH:

- Forgetting the final halfRev/10==x check and only checking
  halfRev==x - this fails for any odd-digit-count palindrome (like
  121), since the middle digit is absorbed into halfRev without a
  matching partner in x, leaving the two unequal even for genuine
  palindromes.

- Misunderstanding the loop's stopping condition (halfRev < x) as
  needing to run for a fixed/precomputed number of iterations,
  instead of letting it naturally self-terminate once enough digits
  have shifted across - the comparison-based stopping condition
  adapts automatically to any digit count without needing to know
  it in advance.
*/