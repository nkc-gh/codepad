/*
====================================================================
CodeChef - Greater Average (AVGPROBLEM) (Difficulty - 500)
====================================================================

Three integers A, B, and C are given per test case.
Determine whether the average of A and B is strictly greater than C.

If (A + B) / 2 > C, print YES. Otherwise, print NO.

Constraints:
1 <= T <= 100
1 <= A, B, C <= 1000

Input format:
T
A B C (per test case)

Example 1:
Input:
1
5 8 6
Output: YES

Example 2:
Input:
1
5 7 6
Output: NO
====================================================================
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int A, B, C;
        cin >> A >> B >> C;

        if (((A + B) / 2.0) > C) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}

/*
====================================================================
SOLUTION IN MY WORDS
====================================================================

Read T first, then loop exactly T times using a standard indexed
for loop (for (int i = 0; i < T; i++)) - starts at 0, runs while
i < T, so it executes exactly T times. Each iteration reads a fresh
A, B, C and checks whether the average of A and B strictly exceeds C.

First mistake: wrote (A + B / 2) > C. This is wrong because
division binds tighter than addition in C++, so it evaluates as
A + (B / 2) - adding half of B to A, not dividing the sum by 2.
Fixed by wrapping the addition in parentheses first: (A + B) / 2.

Second mistake: even after fixing the parentheses, ((A + B) / 2) > C
is still wrong when the sum is odd. A and B are both ints, so
(A + B) / 2 performs integer division and silently drops the
fractional part. Traced A=5, B=8, C=6: true average is 13/2 = 6.5,
which is > 6, so the answer should be YES. But integer division
gives 13/2 = 6, and 6 > 6 is false, so the program would print NO
- wrong answer with no error or warning.

Fixed by dividing by 2.0 instead of 2. When one operand is a
floating-point literal, C++ performs floating-point division and
preserves the fractional part. So (A + B) / 2.0 correctly gives
6.5 for the case above, and 6.5 > 6 is true, printing YES.

Also worked out the integer-only alternative: the original
inequality (A + B) / 2 > C can be rewritten by multiplying both
sides by 2 (safe because 2 is positive, so the inequality direction
is preserved): A + B > 2 * C. This avoids floating-point entirely
and is the cleaner competitive-programming approach, though both
are correct here.

Confirmed the strictly-greater-than edge case: A=5, B=7, C=6 gives
average exactly 6. Since 6 > 6 is false, the answer is NO - the
problem says strictly greater, so equality must return NO. The >
operator handles this correctly; >= would be wrong here.

Used "\n" instead of endl throughout. Both add a newline, but endl
also flushes the output buffer - flushing after every single line
adds unnecessary overhead when printing many answers. For ordinary
batch output, "\n" is preferable; endl is only worth using in
interactive problems where the judge must receive output before
the program continues.

====================================================================
COMPLEXITY
====================================================================

1. TIME COMPLEXITY:

cin >> T                              -> O(1)
for loop over T test cases            -> O(T)
    cin >> A >> B >> C                   -> O(1)
    floating-point division + compare    -> O(1)
    cout << ...                           -> O(1)

Total: O(T), constant work per test case.

2. SPACE COMPLEXITY:

T, i, A, B, C -> O(1), five fixed variables, no arrays or containers

Total: O(1)

3. COMMON MISTAKES PEOPLE MAKE ON THIS PROBLEM:

- Forgetting parentheses around A + B: writing (A + B / 2) instead
  of ((A + B) / 2) - division has higher precedence than addition,
  so the unparenthesized version adds half of B to A instead of
  averaging the two.

- Unintended integer division: using ((A + B) / 2) with integer
  operands silently truncates the fractional part when the sum is
  odd - produces a wrong answer with no compile error or runtime
  warning, making the bug easy to miss.

- Using >= instead of >: the problem says strictly greater, so
  equality must return NO - using >= incorrectly prints YES when
  the average exactly equals C.

- Using endl instead of "\n" in a loop: endl flushes the buffer
  on every iteration, adding unnecessary overhead for batch output.

- Overcomplicating with floating-point when the integer rewrite
  A + B > 2 * C avoids it entirely.
*/