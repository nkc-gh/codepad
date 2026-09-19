/*
====================================================================
CodeChef - Triangles (TRIANGLE7) (Difficulty - 123)
====================================================================

The three angles of a triangle sum to 180 degrees. Given the first
two angles A and B (both integers), find the third angle.

Constraints:
1 <= A, B < 180
A + B < 180

Example 1:
Input: 60 60
Output: 60
(Equilateral triangle, all angles equal)

Example 2:
Input: 1 1
Output: 178
====================================================================
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	int A,B;
	cin >> A >> B;
	
	cout << 180-(A+B) << endl;
	
	return 0;

}

/*
====================================================================
SOLUTION IN MY WORDS
====================================================================

Direct application of the given mathematical fact - since all three
angles sum to 180, the third angle is simply 180 minus the sum of
the two known angles. No derivation needed beyond translating the
stated fact directly into a formula.

Verified against both samples: A=60,B=60 gives 180-(60+60)=60,
matching the equilateral triangle case. A=1,B=1 gives
180-(1+1)=178, matching. The constraint A+B<180 guarantees the
third angle is always a positive value, so no bounds-checking was
needed.

====================================================================
COMPLEXITY
====================================================================

1. TIME COMPLEXITY:

cin >> A >> B      -> O(1)
180-(A+B)           -> O(1)
cout << ...         -> O(1)

Total: O(1)

2. SPACE COMPLEXITY:

A, B -> O(1) fixed variables

Total: O(1)

3. COMMON MISTAKES PEOPLE MAKE ON THIS PROBLEM:

- Forgetting to account for the constraint guaranteeing a valid
  positive third angle, and adding unnecessary validation/edge-case
  handling that the problem's constraints already rule out.

- Miscomputing the formula order (e.g. (A+B)-180 instead of
  180-(A+B)), producing a negative result instead of the correct
  positive angle.
*/