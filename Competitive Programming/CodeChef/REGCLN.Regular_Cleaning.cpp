/*
====================================================================
CodeChef - Regular Cleaning (REGCLN) (Difficulty - 113)
====================================================================

Chef deep cleans his house every 10 days - on days 10, 20, 30, ...
Today is day N. Find how many more days until the next day strictly
after today that Chef will deep clean.

Constraints:
1 <= N <= 100

Example 1:
Input: 24
Output: 6
(Next cleaning day is 30, so 30-24=6)

Example 2:
Input: 30
Output: 10
(Today is itself a cleaning day, but we want the NEXT one strictly
after today, so the next is 40, giving 40-30=10)

Example 3:
Input: 49
Output: 1
(Next cleaning day is 50, so 50-49=1)
====================================================================
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	
	cout << (((N/10)*10)+10)-N << endl;
	
	return 0;

}

/*
====================================================================
SOLUTION IN MY WORDS
====================================================================

Initial confusion was over what "strictly after today" meant -
whether a cleaning day that fell exactly on N itself should count.
Sample 2 (N=30, itself a multiple of 10) resolved this: the expected
answer is 10 (distance to 40), not 0 (distance to 30 itself) -
confirming that even if today happens to be a cleaning day, the
answer must skip it and find the next one strictly greater than N.

Built the formula from this: (N/10)*10 uses integer division
truncation to round N down to the nearest multiple of 10 (e.g.
N=24 -> 20, N=30 -> 30, N=49 -> 40). Adding 10 to that always
lands on the next multiple of 10 strictly greater than N, regardless
of whether N itself was already a multiple of 10 - this is exactly
what handles the N=30 edge case correctly without any special-casing
or if-branch, since (30/10)*10=30, and 30+10=40 automatically skips
past N itself.

Subtracting N from that gives the number of days remaining. Traced
all three samples to confirm: N=24 -> 20+10-24=6, N=30 ->
30+10-30=10, N=49 -> 40+10-49=1 - all match.

====================================================================
COMPLEXITY
====================================================================

1. TIME COMPLEXITY:

cin >> N                    -> O(1)
(N/10)*10                    -> O(1)
+10, -N                      -> O(1)
cout << ...                  -> O(1)

Total: O(1)

2. SPACE COMPLEXITY:

N -> O(1) fixed variable

Total: O(1)

3. COMMON MISTAKES PEOPLE MAKE ON THIS PROBLEM:

- Computing 10 - N%10 as a shortcut without handling the case where
  N%10==0 (i.e. N is already a multiple of 10) - this gives 0 in
  that case instead of the correct answer of 10, since the problem
  wants the NEXT day strictly after today, not today itself even
  when today qualifies.

- Using floating-point division or casting instead of relying on
  integer division truncation to round down to the nearest multiple
  of 10 - unnecessary complexity when int division already does
  this correctly and directly.

- Misreading "strictly after" as inclusive of today, leading to an
  answer of 0 whenever N itself happens to be a multiple of 10.
*/