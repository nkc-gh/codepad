/*
====================================================================
LeetCode 50 - Pow(x, n) (Medium)
====================================================================

Implement pow(x, n), which calculates x raised to the power n
(i.e., x^n), where x is a double and n is a signed 32-bit integer.

Constraints:
-100.0 < x < 100.0
-2^31 <= n <= 2^31 - 1
n is an integer.
Either x is not zero, or n > 0.
-10^4 <= x^n <= 10^4

Example 1:
Input: x = 2.00000, n = 10
Output: 1024.00000

Example 2:
Input: x = 2.10000, n = 3
Output: 9.26100

Example 3:
Input: x = 2.00000, n = -2
Output: 0.25000
====================================================================
*/

class Solution {
public:
    double myPow(double x, int n) {
        long long exp = n;              // promote to 64-bit first
        long double base = x;           // extra precision for repeated squaring

        if (exp < 0) {
            base = 1.0L / base;         // x^-n = (1/x)^n
            exp = -exp;                  // safe now, exp is long long
        }

        long double result = 1.0L;
        long double power = base;

        while (exp > 0) {
            if (exp % 2 == 1) {
                result *= power;
            }
            power *= power;
            exp /= 2;
        }

        return (double)result;
    }
};

/*
====================================================================
SOLUTION IN MY WORDS
====================================================================

The naive approach - multiply x by itself n times in a loop - is
O(n), but n can be up to 2^31-1 (~2 billion), so that's far too
slow. The problem is really asking for an O(log n) approach, even
though it doesn't say so explicitly - that only becomes clear once
you look at how large n's range actually goes.

The key realization: x^a * x^b = x^(a+b), a rule already known from
school. This means x^n can be computed WITHOUT n individual
multiplications, if n can be broken into a SUM of a few convenient
exponents, and x raised to each of those exponents can be computed
cheaply.

The convenient exponents turn out to be powers of 2 (1, 2, 4, 8,
16...), because this ladder can be built by repeated squaring:
x^1 = x, x^2 = x^1 * x^1, x^4 = x^2 * x^2, x^8 = x^4 * x^4, and so
on - each rung costs just ONE multiplication, no matter how large
the exponent on that rung is.

And ANY positive integer n can be written as a sum of some subset
of these powers-of-2 - that's exactly what binary representation
is. For example, 13 = 8 + 4 + 1 (binary 1101), so
x^13 = x^8 * x^4 * x^1.

Initially this felt like it required literally converting n to a
binary string first and looping over its digits. The actual
realization was that checking "is n odd" (n % 2 == 1) and then
integer-dividing n by 2 IS the same mechanical process as
converting to binary via repeated division - just done one digit
at a time, DURING the loop, without ever explicitly building a
binary string. The remainder of n/2 at each step is exactly the
next binary digit, from the bottom up.

This gives the loop: keep a running `power` (starting at x, doubling
its exponent via squaring every iteration) and a running `result`
(starting at 1). At each iteration, if the current n is odd,
multiply `power` into `result` (this rung is "included," matching a
1-bit in n's binary form). Then square `power` and halve n,
regardless of odd/even, and repeat until n reaches 0.

A separate point of confusion was whether the "base 2" used to
convert n to binary had anything to do with x. It doesn't - n's
binary breakdown is pure arithmetic on n alone, completely
independent of whatever x happens to be. x only enters when
building the squaring ladder (x^1, x^2, x^4...); n only enters when
deciding WHICH rungs of that ladder to multiply in. The two are
combined only at the final multiplication step.

NEGATIVE EXPONENT: the loop's mechanics (n > 0 as the loop
condition, n % 2 == 1 as the odd check, n /= 2 to shrink it) only
behave correctly for a NON-NEGATIVE n. Running the loop directly on
a negative n breaks immediately - in C++, -13 % 2 evaluates to -1,
not 1, so the odd-check misfires, and the loop condition `n > 0` is
false from the start, so the loop barely executes at all. This
means negative n cannot just be "handled at the end" without first
getting a positive count to actually drive the loop - the fix is to
use the identity x^-n = (1/x)^n, flip x to its reciprocal UP FRONT,
and run the loop on the positive version of n.

An alternative - run the loop on positive |n| using the ORIGINAL x,
then take 1/result at the very end - is mathematically equivalent
(x^-n = 1/x^n) but has a precision/overflow risk: `power` keeps
squaring the original x throughout the entire loop regardless of
the sign of n. If |x| > 1 and n is very negative, `power` grows
toward x raised to a huge POSITIVE exponent before ever being
inverted, risking overflow to infinity - even though the true final
answer is tiny. Flipping x = 1/x before the loop avoids this,
since then `power` is already shrinking toward 0 throughout, matching
the true magnitude of the answer as it's being built up.

INT OVERFLOW: n is a 32-bit signed int, ranging from -2^31 to
2^31-1 - note this range is NOT symmetric; the most negative allowed
value is -2147483648, but the largest positive int is only
2147483647. Negating -2147483648 directly (as an int) overflows,
since 2147483648 doesn't fit in a 32-bit int. Fix: promote n to a
64-bit `long long` BEFORE negating it, giving enough room for the
positive version of the smallest possible n.

FLOATING POINT PRECISION: for very large |n| (close to 2^31), the
loop runs around 31 times, squaring `power` each time. Each
squaring introduces a tiny rounding error inherent to floating
point, and these errors compound multiplicatively across ~31
rounds - particularly severe when x is very close to +-1, since
small relative errors get amplified more there. A test case like
x = -0.9999999968539456, n = -1669585506 failed using plain
`double` (15-16 significant digits) for exactly this reason - the
compounded error shifted the 5th decimal place of the final answer
just enough to fail LeetCode's tolerance check. Switching all the
loop's working variables (base, power, result) to `long double`
(on most judges, 80-bit extended precision, ~18-19 significant
digits) gives enough extra headroom that the compounded error no
longer surfaces in the visible output digits. Only cast back down
to `double` at the very last moment (the return statement), since
the function's signature requires it - this is a single, one-time
rounding, not a compounding one, so it costs far less precision
than doing all 31 rounds of squaring in plain `double`.

====================================================================
COMPLEXITY
====================================================================

1. TIME COMPLEXITY:

while loop, exp halved every iteration  -> O(log n) iterations
    exp % 2, multiply, square, exp /= 2   -> O(1) work per iteration

Total: O(log n) - exponentially faster than the O(n) brute force,
since n's magnitude can be up to ~2 billion.

2. SPACE COMPLEXITY:

Only a fixed handful of variables (exp, base, result, power) used,
no recursion stack, no extra data structures.

Total: O(1)

3. COMMON MISTAKES PEOPLE MAKE ON THIS PROBLEM:

- Writing the O(n) brute-force loop (multiply x by itself n times),
  which technically works but times out given n's range up to
  2^31-1.

- Negating n directly as an `int` when n could be -2147483648 -
  this overflows since the positive counterpart (2147483648) doesn't
  fit in a 32-bit signed int. Must promote to `long long` (or similar)
  before negating.

- Running the squaring loop directly on a negative n without first
  converting it to a positive count - the loop's `n > 0` condition
  and `n % 2 == 1` odd-check both behave incorrectly on negative
  values in C++ (e.g. -13 % 2 == -1, not 1), causing the loop to
  barely execute or skip multiplications it should include.

- For negative n, squaring the ORIGINAL x throughout the entire loop
  and only taking the reciprocal of the final result - mathematically
  valid, but risks `power` overflowing toward infinity mid-loop when
  |x| > 1 and |n| is large, even though the true final answer is
  small. Flipping x to 1/x BEFORE the loop (when n is negative) keeps
  `power` shrinking throughout instead, avoiding this.

- Not accounting for floating point error accumulation across ~31
  rounds of squaring on large |n| - using plain `double` throughout
  can fail precision-sensitive test cases where x is very close to
  +-1. Using `long double` for the loop's working variables
  (base/power/result), and only narrowing to `double` once at the
  final return, meaningfully reduces compounded rounding error.

- Forgetting the 0^0 / 0^(negative) edge cases don't need explicit
  handling here, since the problem guarantees x is never 0 unless
  n > 0 - but it's worth knowing WHY this constraint exists (0^0 is
  undefined, and 0 raised to a negative power implies division by
  zero), in case a similar problem without that guarantee comes up.
*/