/*
====================================================================
CodeChef - Point Calculation (POINTCAL) (Difficulty - 83)
====================================================================

Your team played 3 group-stage games. You're given A wins, B draws,
and C losses. A win = 3 points, a draw = 1 point, a loss = 0 points.
Output total points scored.

Constraints:
0 <= A, B, C <= 3
A + B + C = 3

Example 1:
Input: 3 0 0
Output: 9

Example 2:
Input: 0 1 2
Output: 1
====================================================================
*/

#include <bits/stdc++.h>
using namespace std;
int main() {
    int A, B, C;
    cin >> A >> B >> C;
    cout << (A * 3) + (B * 1) + (C * 0) << endl;
    return 0;
}

/*
====================================================================
SOLUTION IN MY WORDS
====================================================================

Pure arithmetic, no tricky part to this one. Total points is just
each count multiplied by its point value, summed up - wins*3 +
draws*1 + losses*0.

The "first and only line" in the input format threw me for a second
- I thought it might mean my code itself should be a single line.
Actually it just describes how the input is given: A, B and C all
sit on one line, space-separated, not spread across three separate
lines. So I read all three with a single cin >> A >> B >> C
statement, not one cin per variable.

Kept the C * 0 term in even though it obviously contributes nothing
mathematically. Purely a readability choice - it makes the formula
map directly onto "wins give 3, draws give 1, losses give 0" without
someone having to think about why C isn't there. Compiler will
likely optimize it away anyway, so no runtime cost either way.

No edge cases to worry about - constraints guarantee A+B+C=3 always,
so there's nothing to validate on the input side.

====================================================================
COMPLEXITY
====================================================================

1. TIME COMPLEXITY:

int A, B, C;                          -> O(1)
cin >> A >> B >> C;                    -> O(1)
cout << (A*3)+(B*1)+(C*0) << endl;      -> O(1)

No loop, no recursion, fixed number of arithmetic operations
regardless of input values.

Total: O(1)

2. SPACE COMPLEXITY:

A, B, C -> 3 fixed variables, no containers.

Total: O(1)

3. COMMON MISTAKES PEOPLE MAKE ON THIS PROBLEM:

- Misreading "first and only line" as a constraint on the code
  itself rather than the input format.

- Using separate cin statements per line when the input actually
  arrives space-separated on one line - would misalign values if
  not read correctly with a single cin >> A >> B >> C.

- Overcomplicating with if-else branches per game type instead of
  a single arithmetic expression - unnecessary for a pure
  weighted-sum problem.

- Printing extra text ("Points: 9") instead of the bare number -
  causes Wrong Answer on strict judges expecting exact output.
*/