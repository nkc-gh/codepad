/*
====================================================================
CodeChef - Protein Diet (LMP1) (Difficulty - 110)
====================================================================

You consume X grams of protein daily. A balanced diet requires at
least Y grams of protein per day. Determine whether the daily
protein intake fulfills the requirement - fulfilled if and only if
X is greater than or equal to Y.

Constraints:
1 <= X, Y <= 100

Example 1:
Input: 80 65
Output: YES
(80 >= 65, fulfilled)

Example 2:
Input: 16 49
Output: NO
(16 < 49, not fulfilled)

Example 3:
Input: 10 10
Output: YES
(10 == 10, still fulfilled)
====================================================================
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	int X,Y;
	cin >> X >> Y;
	
	if(X>=Y){
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

Direct translation of the problem statement - it explicitly defines
"fulfilled" as X being greater than or equal to Y, so the condition
X>=Y maps straight onto that definition with no derivation needed.

Verified against all three samples, including the equal case
(X=Y=10), which the problem explicitly calls out as still counting
as fulfilled - confirms >= is the right comparison, not a strict >,
since a strict > would have wrongly rejected the equal case.

====================================================================
COMPLEXITY
====================================================================

1. TIME COMPLEXITY:

cin >> X >> Y        -> O(1)
if(X>=Y)              -> O(1)
cout << "YES"/"NO"    -> O(1)

Total: O(1)

2. SPACE COMPLEXITY:

X, Y -> O(1) fixed variables

Total: O(1)

3. COMMON MISTAKES PEOPLE MAKE ON THIS PROBLEM:

- Using strict > instead of >= - the problem explicitly states
  fulfilled means X is greater than OR EQUAL to Y, so an equal
  intake (X==Y) must still print YES, not NO.

- Overcomplicating a single comparison with unnecessary extra
  conditions or nested logic when one if/else fully captures the
  rule as stated.
*/