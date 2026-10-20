/*
====================================================================
AtCoder ABC085C - Otoshidama
====================================================================

Given N bills (total count) and Y yen (total value), find how many
10000-yen, 5000-yen, and 1000-yen bills make exactly N bills worth
exactly Y yen. Print "x y z" if possible, "-1 -1 -1" otherwise.

Constraints:
1 <= N <= 2000
1000 <= Y <= 2×10^7
Y is a multiple of 1000.

Input format:
N Y

Example 1:
Input: 9 45000       Output: 4 0 5

Example 2:
Input: 20 196000     Output: -1 -1 -1

Example 3:
Input: 1000 1234000  Output: 14 27 959

Example 4:
Input: 2000 20000000 Output: 2000 0 0
====================================================================
*/

#include <iostream>
using namespace std;

int main() {
    int N, Y;
    cin >> N >> Y;

    for (int a = 0; a <= N; a++) {
        int remaining = Y / 1000 - N - 9 * a;

        if (remaining < 0 || remaining % 4 != 0) {
            continue;
        }

        int b = remaining / 4;

        int c = N - a - b;

        if (c >= 0 && a + b + c == N && 10000 * a + 5000 * b + 1000 * c == Y) {
            cout << a << " " << b << " " << c << '\n';
            return 0;
        }
    }

    cout << "-1 -1 -1\n";

    return 0;
}

/*
====================================================================
SOLUTION IN MY WORDS
====================================================================

Set up three variables: a = number of 10000-yen bills, b = number
of 5000-yen bills, c = number of 1000-yen bills. These give two
equations:
  a + b + c = N              ... (count equation)
  10000a + 5000b + 1000c = Y ... (value equation)

First idea: three nested loops trying every combination of a, b, c.
This is O(N^3) - up to 2000^3 = 8 billion iterations. Too slow.

Reduced to one loop by eliminating two variables mathematically.
From the count equation: c = N - a - b. Substituted into the value
equation:
  10000a + 5000b + 1000(N - a - b) = Y
  10000a + 5000b + 1000N - 1000a - 1000b = Y
  9000a + 4000b = Y - 1000N
Dividing everything by 1000:
  9a + 4b = Y/1000 - N

Now b can be expressed directly in terms of a:
  b = (Y/1000 - N - 9a) / 4

So only one loop is needed - iterate a from 0 to N and compute
remaining = Y/1000 - N - 9*a for each value. Two checks before
going further: if remaining is negative, the current a already
overshoots the target so no valid b exists; if remaining is not
divisible by 4, there is no integer b that satisfies the equation.
Either case is skipped with continue.

If both checks pass, computed b = remaining / 4, then
c = N - a - b. The final if condition checks three things:
  1. c >= 0 (can't have negative bills)
  2. a + b + c == N (count adds up - redundant given the algebra
     but kept as an explicit guard)
  3. 10000a + 5000b + 1000c == Y (value adds up - also redundant
     but kept as a sanity check)

Once a valid combination is found, printed and returned immediately
- the problem accepts any valid answer, so no need to keep
searching. If the loop exhausts all values of a, printed -1 -1 -1.

Traced sample 1 (N=9, Y=45000):
  a=4: remaining = 45 - 9 - 36 = 0, 0%4==0, b=0, c=9-4-0=5
  c>=0, 4+0+5==9, 40000+0+5000==45000 -> prints 4 0 5

Traced sample 2 (N=20, Y=196000):
  For every a from 0 to 20, remaining is either negative or not
  divisible by 4 -> loop ends without a match -> prints -1 -1 -1

====================================================================
COMPLEXITY
====================================================================

1. TIME COMPLEXITY:

cin >> N >> Y                              -> O(1)
for loop: a from 0 to N                   -> O(N)
    remaining calculation                    -> O(1)
    negativity + divisibility checks          -> O(1)
    b, c calculation + final triple check     -> O(1)

Total: O(N), reduced from the naive O(N^3) three-loop approach by
eliminating b and c algebraically, leaving only one loop variable.

2. SPACE COMPLEXITY:

N, Y, a, b, c, remaining -> O(1), six fixed integer variables,
                             no arrays or containers of any kind

Total: O(1)

3. COMMON MISTAKES PEOPLE MAKE ON THIS PROBLEM:

- Using three nested loops (O(N^3)) without simplifying - with
  N up to 2000 this is 8 billion iterations, far too slow within
  the 2-second time limit.

- Forgetting to check remaining % 4 != 0 before dividing - in C++,
  integer division silently discards the remainder, so skipping
  this check produces a wrong b value without any error.

- Forgetting to check remaining < 0 - a negative remaining means
  the current a already overshoots the target, making b negative.
  Dividing a negative remaining by 4 gives a negative b, which is
  invalid.

- Forgetting to check c >= 0 after computing c = N - a - b - a
  valid remaining and b do not guarantee c is nonnegative; b could
  be large enough to make c go negative.

- Printing all valid combinations instead of stopping at the first
  one - the problem says any valid answer is accepted, so returning
  immediately after the first match is both correct and efficient.
*/