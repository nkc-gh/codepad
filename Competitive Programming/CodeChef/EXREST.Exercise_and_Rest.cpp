/*
====================================================================
CodeChef - Exercise and Rest (EXREST) (Difficulty - 123)
====================================================================

Chef exercises for two days, then rests one day, repeating this
3-day cycle. Today is Chef's N-th rest day. Find how many days
(including today) have passed since he started.

Constraints:
1 <= N <= 10

Example 1:
Input: 2
Output: 6
(Day 3 = rest 1, Day 6 = rest 2; today is day 6)

Example 2:
Input: 4
Output: 12
(Rest days fall on 3, 6, 9, 12; today is day 12)
====================================================================
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	
	cout << N*3 << endl;
	
	return 0;

}

/*
====================================================================
SOLUTION IN MY WORDS
====================================================================

Direct pattern recognition - each full cycle (2 workout days + 1
rest day) is exactly 3 days long, and the N-th rest day always
falls precisely at the end of the N-th cycle. So the N-th rest day
always lands on day 3*N, with no need to simulate day-by-day.

Verified against both samples: N=2 gives 2*3=6 (rest day 2 is on
day 6), N=4 gives 4*3=12 (rest day 4 is on day 12) - both match the
explicitly listed schedules in the problem.

====================================================================
COMPLEXITY
====================================================================

1. TIME COMPLEXITY:

cin >> N       -> O(1)
N*3             -> O(1)
cout << ...     -> O(1)

Total: O(1)

2. SPACE COMPLEXITY:

N -> O(1) fixed variable

Total: O(1)

3. COMMON MISTAKES PEOPLE MAKE ON THIS PROBLEM:

- Simulating the schedule day-by-day with a loop instead of
  recognizing the direct formula 3*N - unnecessary given how small
  the constraint is, but also just missing the underlying pattern
  entirely.

- Off-by-one errors from miscounting where in the 3-day cycle the
  rest day falls (e.g. computing 3*N-1 or 3*N+1) instead of
  correctly identifying that the rest day is always the LAST day of
  its 3-day cycle, landing exactly on 3*N.
*/