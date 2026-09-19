/*
====================================================================
CodeChef - Assignment Due (P1_175) (Difficulty - 135)
====================================================================

The deadline for an assignment is in Y days, and it takes X days to
complete it. Determine whether the assignment can be finished on or
before the deadline.

Input format:
X Y   (space-separated integers)

Constraints:
1 <= X <= 100
1 <= Y <= 100

Example 1:
Input: 1 2
Output: YES

Example 2:
Input: 2 2
Output: YES

Example 3:
Input: 3 2
Output: NO
====================================================================
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	int X , Y;
	cin >> X >> Y;
	
	if((Y-X)>=0){
	    cout << "YES" << endl;
	}
	
	else{
	    cout << "NO" << endl;
	}
	
	return 0;

}

/*
====================================================================
SOLUTION IN MY WORDS
====================================================================

First version used `(Y-X)>0` (strict greater-than). Traced sample 2
by hand: X=2, Y=2, so Y-X=0, and 0>0 is false — the code would print
NO. But the expected output is YES, since finishing exactly on the
deadline day still counts as "on or before the deadline."

The problem statement itself says "on or before," which is an
inclusive condition — equality (X==Y) must count as success, not
failure. Strict > silently excludes the equal case.

Fixed by changing the condition to `(Y-X)>=0`, which is equivalent
to X<=Y. Re-traced all three samples against the corrected version:
- (1,2): Y-X=1, >=0 true -> YES, matches expected.
- (2,2): Y-X=0, >=0 true -> YES, matches expected.
- (3,2): Y-X=-1, >=0 false -> NO, matches expected.

This is the same category of mistake as the Watermelon problem
earlier in this session (strict boundary condition dropping a valid
equal/edge case) — inclusive wording in the problem statement
("at least," "at most," "on or before") needs >=/<=, not a strict
inequality.

====================================================================
COMPLEXITY
====================================================================

1. TIME COMPLEXITY:

cin >> X >> Y;          -> O(1)
(Y-X)>=0                 -> O(1), single subtraction and comparison
cout << "YES"/"NO";       -> O(1)

Total: O(1)

2. SPACE COMPLEXITY:

X, Y -> O(1), fixed variables

Total: O(1)

3. COMMON MISTAKES PEOPLE MAKE ON THIS PROBLEM:

- Using strict `>` instead of `>=` — the problem explicitly allows
  finishing exactly on the deadline day ("on or before"), so the
  equal case (X==Y) must print YES, not NO.

- Reversing the subtraction order (X-Y instead of Y-X) and then
  getting the inequality direction backwards, which silently
  flips the logic for all non-equal cases.
*/