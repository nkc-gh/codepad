/*
====================================================================
CodeChef - Time Penalty (WAPEN) (Difficulty - 120)
====================================================================

CodeChef Starters 173 applies a 10-minute time penalty for every
incorrect submission. You solved a problem X minutes after the
contest started, with Y incorrect submissions made along the way.
Find the total time penalty for the problem.

Constraints:
1 <= X <= 150
0 <= Y <= 10

Example 1:
Input: 3 2
Output: 23
(3 + 2*10 = 23)

Example 2:
Input: 58 0
Output: 58
(58 + 0*10 = 58)
====================================================================
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	int X,Y;
	cin >> X >> Y;
	
	cout << X+(Y*10) << endl;
	
	return 0;

}

/*
====================================================================
SOLUTION IN MY WORDS
====================================================================

Direct translation of the problem statement - it explicitly gives
the formula (total penalty = minutes to solve + 10 minutes per
wrong submission), so X + Y*10 maps straight onto that definition
with no derivation needed.

Verified against both samples: X=3,Y=2 gives 3+2*10=23, matching.
X=58,Y=0 gives 58+0*10=58, matching - confirms Y=0 correctly adds
nothing extra, which is the expected behavior when no incorrect
submissions were made.

====================================================================
COMPLEXITY
====================================================================

1. TIME COMPLEXITY:

cin >> X >> Y      -> O(1)
X+(Y*10)            -> O(1)
cout << ...         -> O(1)

Total: O(1)

2. SPACE COMPLEXITY:

X, Y -> O(1) fixed variables

Total: O(1)

3. COMMON MISTAKES PEOPLE MAKE ON THIS PROBLEM:

- Misreading the penalty direction and computing X*10+Y or some
  other incorrect combination instead of carefully mapping each
  term in the stated formula (X minutes elapsed, plus 10 minutes
  per wrong submission Y) to the correct operand.

- Adding unnecessary complexity (loops, conditionals) for what is
  purely a one-line arithmetic formula directly given by the
  problem statement.
*/