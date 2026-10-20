/*
====================================================================
LeetCode 7 - Reverse Integer (Medium)
====================================================================

Given a signed 32-bit integer x, return x with its digits reversed.
If the reversed value exceeds the 32-bit signed integer range
[-2^31, 2^31 - 1], return 0. Assume 64-bit integers cannot be used.

Constraints:
-2^31 <= x <= 2^31 - 1

Input format:
Single integer x

Example 1:
Input: x = 123    Output: 321

Example 2:
Input: x = -123   Output: -321

Example 3:
Input: x = 120    Output: 21
====================================================================
*/

class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int digit = x % 10;

            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && digit > 7)) {
                return 0;
            }
            if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && digit < -8)) {
                return 0;
            }
            rev = rev * 10 + digit;
            x /= 10;
        }
        return rev;
    }
};

/*
====================================================================
SOLUTION IN MY WORDS
====================================================================

Core digit-extraction loop: get the last digit of x using x % 10,
add it to rev using rev = rev * 10 + digit, then remove the last
digit from x using x /= 10. Repeat until x becomes 0.

Traced x = 123:
  digit = 3, rev = 0*10 + 3 = 3,   x = 12
  digit = 2, rev = 3*10 + 2 = 32,  x = 1
  digit = 1, rev = 32*10 + 1 = 321, x = 0 -> return 321

Initially thought about handling negative numbers separately, but
realized the same loop works for both signs. In C++, the remainder
of a negative number keeps the sign of the dividend, so -123 % 10
gives -3, not 3. This means the reversed number naturally picks up
the correct sign without any extra logic. Trailing zeros are also
handled automatically - reversing 120 gives 021, but leading zeros
are dropped by integer representation, so the result is just 21.

The main challenge is overflow. rev * 10 + digit is computed using
int arithmetic, and if the result exceeds INT_MAX (2147483647) or
goes below INT_MIN (-2147483648), it silently wraps around to a
wrong value without any error.

First idea: check whether rev is out of range AFTER updating it.
This is too late - the overflow already happened in the expression
rev * 10 + digit before the check runs.

Correct approach: check BEFORE updating rev. The check is:
  if rev > INT_MAX / 10, then rev * 10 already overflows -> return 0
  if rev == INT_MAX / 10, then the result depends on digit:
    INT_MAX = 2147483647, last digit is 7, so if digit > 7 -> overflow

For the negative side:
  if rev < INT_MIN / 10 -> return 0
  if rev == INT_MIN / 10, then:
    INT_MIN = -2147483648, last digit is -8, so if digit < -8 -> overflow

Why digit > 7 and digit < -8 specifically: the valid input range is
[-2^31, 2^31 - 1], meaning x itself never overflows a 32-bit int.
So the reversed number's last digit (which was x's first digit)
can only be 1 or 2 for a 10-digit number. In practice the digit
checks at the boundary are rarely triggered, but they are required
for correctness per the problem constraints.

Once both overflow checks pass, safely computed rev = rev * 10 +
digit and removed the last digit from x with x /= 10.

====================================================================
COMPLEXITY
====================================================================

1. TIME COMPLEXITY:

while (x != 0)               -> O(log|x|), one iteration per digit
    x % 10, x /= 10            -> O(1) each
    overflow checks + update    -> O(1)

Total: O(log|x|), since a 32-bit integer has at most 10 digits the
loop runs at most 10 times - effectively O(1) in practice, but
formally O(log|x|) since the number of iterations scales with the
number of digits.

2. SPACE COMPLEXITY:

rev, digit -> O(1), two fixed integer variables, no arrays or
             containers of any kind

Total: O(1)

3. COMMON MISTAKES PEOPLE MAKE ON THIS PROBLEM:

- Checking for overflow AFTER computing rev * 10 + digit - by that
  point the overflow has already happened silently in int arithmetic,
  making the check useless. The check must happen BEFORE the update.

- Using a long long to detect overflow instead of pre-checking -
  the problem explicitly states 64-bit integers cannot be used, so
  casting to long long to check the result is not a valid solution.

- Handling negative numbers separately by converting to positive
  first - unnecessary, since C++ remainder preserves the sign of
  the dividend, so the same loop naturally produces the correct
  negative reversed value.

- Forgetting that trailing zeros disappear automatically - no
  special case is needed for inputs like 120; integer arithmetic
  drops leading zeros in the result on its own.

- Using the magic numbers 2147483647 and -2147483648 directly
  instead of INT_MAX and INT_MIN - both are equivalent, but the
  named constants are clearer and less error-prone to type.
*/