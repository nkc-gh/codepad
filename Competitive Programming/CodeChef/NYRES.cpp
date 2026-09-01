/*
====================================================================
CodeChef - New Year Resolution (NYRES)
====================================================================

Chef does exactly X push-ups every day, starting off 2026. If he
sticks to this every day, how many push-ups will he do in the
month of January (31 days)?

Constraints:
1 <= X <= 100

Example 1:
Input: 5
Output: 155
(5 x 31 = 155)

Example 2:
Input: 100
Output: 3100
====================================================================
*/

#include <bits/stdc++.h>
using namespace std;
int main() {
    int x;
    cin >> x;
    cout << x * 31;
}

/*
====================================================================
SOLUTION IN MY WORDS
====================================================================

Straightforward - January always has 31 days, Chef does X push-ups
every single day with no variation, so total = X * 31. No loop
needed since it's a fixed multiplication, not something that
changes per day.

Only real mistake I made wasn't in the logic - it was I initially
wrote `int x;` and then went straight to `cout << x * 31;` without
`cin >> x;` at all, just to test if it would even work.

It "ran" without crashing on CodeChef and gave output 0 for input 5.
Looked fine at first glance ("Successfully executed") but the
actual output was wrong - 0 instead of 155.

Reason: `int x;` only declares the variable, it doesn't put any
value into it. The value sitting there is whatever garbage bits
happen to already be in that memory slot - technically undefined
behavior to even read it. It happened to be 0 on that run purely by
chance (fresh stack frame / OS zeroing), not because C++ guarantees
uninitialized ints are 0. Different run/compiler/judge could've
given a completely different garbage number.

CodeChef does feed the input into stdin regardless of whether my
code reads it or not - so the "5" was sitting in the input buffer
the whole time, just never picked up because I skipped `cin >> x`.

Fix: `cin >> x;` before using x. That's not optional syntax, it's
the only way to guarantee x actually holds the value from input.

====================================================================
COMPLEXITY
====================================================================

1. TIME COMPLEXITY:

int x;              -> O(1)
cin >> x;            -> O(1)
cout << x * 31;       -> O(1)

Per README rule 1 (single operation) and rule 2 (no loop at all
here, straight-line code) - every line is a fixed, constant-cost
operation regardless of what X is.

Total: O(1) + O(1) + O(1) -> O(1)

2. SPACE COMPLEXITY:

x -> single fixed variable, no array/container, no recursion.

Per README space rule 1 (fixed number of variables, count doesn't
grow with input) -> O(1)

Total: O(1)

3. COMMON MISTAKES PEOPLE MAKE ON THIS PROBLEM:

- Forgetting `cin >> x;` entirely (declaring x but never reading
  input into it) - compiles and runs fine, silently gives wrong
  output (0 or garbage) instead of a compile/runtime error, which
  makes it a sneaky bug to catch.

- Hardcoding 31 as a loop counter and summing X, 31 times in a
  for-loop, instead of just multiplying. Gives the right answer but
  is unnecessary O(n)-style work for what's a pure O(1) arithmetic
  problem - wastes time on trivial problems in a contest setting.

- Off-by-one on days - using 30 instead of 31, or reading days as
  input when the problem fixes it at 31 (January).

- Printing extra text like "Answer: 155" instead of just "155" -
  judges expect exact output format, extra text causes Wrong Answer
  even if the number itself is correct.
*/