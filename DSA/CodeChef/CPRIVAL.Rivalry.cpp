/*
====================================================================
CodeChef - Rivalry (CPRIVAL) (Difficulty - 501)
====================================================================

Dominater and Everule each have an initial rating R1, R2 and a
rating change D1, D2 after a contest. Calculate their final ratings
and print the name of the person with the higher final rating.

Final ratings:
  Dominater = R1 + D1
  Everule   = R2 + D2

The problem guarantees the final ratings are never equal.

Constraints:
Rating changes can be negative (a loss decreases the rating).

Input format:
R1 R2
D1 D2

Example 1:
Input:
1 100
-5 -150
Output: Dominater

Example 2:
Input:
2636 2536
-116 -11
Output: Everule
====================================================================
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int R1, R2;
    cin >> R1 >> R2;

    int D1, D2;
    cin >> D1 >> D2;

    if (R1 + D1 > R2 + D2) {
        cout << "Dominater\n";
    }
    else {
        cout << "Everule\n";
    }

    return 0;
}

/*
====================================================================
SOLUTION IN MY WORDS
====================================================================

Read the initial ratings first (R1 for Dominater, R2 for Everule),
then read the rating changes (D1 and D2). Both reads use separate
cin statements, matching the two-line input format exactly.

The final rating for each person is just their initial rating plus
their change. No special handling needed for negative changes -
adding a negative integer in C++ already performs the subtraction
automatically (e.g. 100 + (-20) = 80), so a single + handles both
gains and losses.

Compared the two final ratings directly inside the if condition
without storing them in separate variables - R1+D1 and R2+D2 can be
computed inline, keeping the solution short and readable. No temp
variables needed here.

The else branch is sufficient because the problem guarantees the
two final ratings are always different - if Dominater's final rating
is not strictly greater, Everule's must be, with no tie possible.

Dry run on sample 1 (R1=1, R2=100, D1=-5, D2=-150):
  Dominater = 1 + (-5)   = -4
  Everule   = 100 + (-150) = -50
  -4 > -50 is true -> prints Dominater
  Note: -4 is greater than -50 because on the number line, -4 is
  closer to zero; the more negative a number, the smaller it is.

Dry run on sample 2 (R1=2636, R2=2536, D1=-116, D2=-11):
  Dominater = 2636 + (-116) = 2520
  Everule   = 2536 + (-11)  = 2525
  2520 > 2525 is false -> else branch prints Everule

====================================================================
COMPLEXITY
====================================================================

1. TIME COMPLEXITY:

cin >> R1 >> R2          -> O(1)
cin >> D1 >> D2          -> O(1)
R1+D1, R2+D2, compare   -> O(1)
cout << ...               -> O(1)

Total: O(1), no loops, no input size that grows - four fixed
integer reads and one comparison regardless of the values.

2. SPACE COMPLEXITY:

R1, R2, D1, D2 -> O(1), four fixed integer variables, no arrays
                  or containers of any kind

Total: O(1)

3. COMMON MISTAKES PEOPLE MAKE ON THIS PROBLEM:

- Comparing only the initial ratings (R1 vs R2) instead of the
  final ratings (R1+D1 vs R2+D2) - the contest result changes
  both ratings, so the winner is determined after the update, not
  before.

- Treating negative rating changes as a special case that needs
  subtraction - adding a negative integer already performs the
  subtraction in C++, so R1+D1 works correctly whether D1 is
  positive or negative.

- Reversing the comparison - the condition must be
  R1+D1 > R2+D2 (Dominater on the left, Everule on the right),
  not the other way around.

- Forgetting a semicolon after a cout statement - compiles without
  error only if caught, but silently produces wrong output or a
  compile error depending on placement.

- Adding an unnecessary equality branch (if/else if/else) when the
  problem guarantees the final ratings are always different - a
  plain if-else is sufficient and cleaner.
*/