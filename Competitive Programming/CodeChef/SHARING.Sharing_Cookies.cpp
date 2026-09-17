/*
====================================================================
CodeChef - Sharing Cookies (SHARING) (Difficulty - 232)
====================================================================

Alice has A cookies, Bob has B cookies, with A > B. Determine if
Alice can give Bob some cookies so both end up with an equal
number. If possible, output how many cookies Alice must give Bob;
otherwise output -1.

Constraints:
1 <= B < A <= 10

Input format:
A B

Example 1:
Input: 6 2
Output: 2
(Alice gives 2, both end up with 4)

Example 2:
Input: 5 2
Output: -1
(total is 7, can't be split evenly)
====================================================================
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B;
    cin >> A >> B;
    
    if ((A + B) % 2 == 0) {
        cout << (A - B) / 2 << endl;
    }
    else {
        cout << -1 << endl;
    }
    
    return 0;
}

/*
====================================================================
ALTERNATE/EARLIER VERSION
====================================================================

First attempt checked whether (A+B)/2 itself was even, instead of
checking whether A+B was evenly divisible in the first place:

#include <bits/stdc++.h>
using namespace std;

int main() {
	int A,B;
	
	cin >> A >> B;
	
	if((A+B)/2 %2 == 0){
	    cout << A - ((A+B)/2) << endl;
	}
	else {
	    cout << -1 << endl;
	}
	
	return 0;

}

====================================================================
SOLUTION IN MY WORDS
====================================================================

First version checked the wrong condition entirely: it computed
(A+B)/2 first, then checked if THAT result was even, which has
nothing to do with whether A+B can be split fairly. Fair sharing
only requires the TOTAL (A+B) to split into two equal integer
halves, which just needs A+B to be even — not for the resulting
half itself to have any particular parity.

Traced this against sample 2 (A=5, B=2): (A+B)/2 = 7/2 = 3
(integer division truncates), and 3%2==0 is false, so it happened
to correctly print -1 — but only by coincidence of these specific
numbers, not because the logic was actually sound.

Fixed by checking (A+B)%2==0 directly on the total, which correctly
captures "can this total be split into two equal integers."

Also simplified the transfer-amount calculation. Instead of first
computing the equal target per person ((A+B)/2) and then subtracting
from A, realized the number of cookies to transfer is just half the
GAP between A and B: (A-B)/2. This works because to close a gap of
(A-B), Alice needs to give away exactly half of that gap - giving
away (A-B)/2 reduces Alice by that amount and increases Bob by the
same amount, closing the full gap and landing both on the same
value.

====================================================================
COMPLEXITY
====================================================================

1. TIME COMPLEXITY:

cin >> A >> B;              -> O(1)
(A+B)%2==0                   -> O(1)
(A-B)/2 or -1                 -> O(1)
cout << ...                   -> O(1)

Total: O(1)

2. SPACE COMPLEXITY:

A, B -> O(1) fixed variables

Total: O(1)

3. COMMON MISTAKES PEOPLE MAKE ON THIS PROBLEM:

- Checking whether (A+B)/2 is itself even, instead of checking
  whether (A+B) is evenly divisible by 2 in the first place - these
  are different conditions and only coincidentally agree on some
  inputs.

- Computing the equalized per-person target first ((A+B)/2) and then
  subtracting to find the transfer amount, instead of directly using
  (A-B)/2 - not wrong, just an unnecessary extra step.

- Forgetting integer division truncates - if (A+B) is odd, (A+B)/2
  silently loses the remainder instead of signaling an error, so the
  odd/even check on the SUM must happen before any division is
  trusted.
*/