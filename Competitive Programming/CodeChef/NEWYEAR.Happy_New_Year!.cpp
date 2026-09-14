/*
====================================================================
CodeChef - Happy New Year! (NEWYEAR) (Difficulty - 125)
====================================================================

It is currently X:00 hours (24-hour format) on December 31st. Find
how many hours remain until midnight (00:00 of the next day).

Constraints:
0 <= X <= 23

Example 1:
Input: 0
Output: 24
(At 00:00, a full 24 hours remain until the next midnight)

Example 2:
Input: 23
Output: 1
(At 23:00, only 1 hour remains)
====================================================================
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	int X;
	cin >> X;
	
	cout << 24-X << endl;
	
	return 0;

}

/*
====================================================================
SOLUTION IN MY WORDS
====================================================================

Direct formula - hours remaining until midnight is always 24 minus
the current hour X. Verified against both edge cases explicitly
given: X=0 (start of day) gives 24-0=24, the maximum possible
remaining time; X=23 (last hour of the day) gives 24-23=1, the
minimum possible remaining time. Both match, confirming the formula
correctly handles the boundaries of the 24-hour range without any
special-casing.

====================================================================
COMPLEXITY
====================================================================

1. TIME COMPLEXITY:

cin >> X       -> O(1)
24-X            -> O(1)
cout << ...     -> O(1)

Total: O(1)

2. SPACE COMPLEXITY:

X -> O(1) fixed variable

Total: O(1)

3. COMMON MISTAKES PEOPLE MAKE ON THIS PROBLEM:

- Off-by-one from treating the range as 1-24 instead of 0-23 (e.g.
  computing 23-X or 25-X), miscounting either the start-of-day or
  end-of-day edge case.

- Overcomplicating with modulo arithmetic (e.g. (24-X)%24) when a
  plain subtraction already correctly handles both boundary values
  (X=0 and X=23) without wraparound ever being needed, since X never
  exceeds 23.
*/