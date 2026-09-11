/*
====================================================================
CodeChef - Missing Number (MISSINGNUM7)
====================================================================

Chef had 4 pieces of paper numbered 1, 2, 3, 4. He lost one, and the
remaining three add up to S. Find the missing number.

Constraints:
6 <= S <= 9

Example 1:
Input: 6
Output: 4

Example 2:
Input: 9
Output: 1
====================================================================
*/

#include <bits/stdc++.h>
using namespace std;
int main() {
	int S;
    cin >> S;
    cout << 10 - S;
}

/*
====================================================================
SOLUTION IN MY WORDS
====================================================================

Total of all 4 papers is fixed: 1+2+3+4 = 10. Since S is the sum of
the 3 remaining papers, the missing one is just 10 - S. No loop, no
conditions, pure arithmetic.

Only real mistake here was declaring `int S;` and forgetting to
actually read it with `cin >> S;` before using it in the output line
- caught this before submitting by noticing S was never assigned
anything from input. Also briefly questioned whether the stated
constraint (6 <= S <= 9) was correct, but confirmed it's consistent
- missing 4 gives S=6 (the minimum, since 4 is the largest number
removed) and missing 1 gives S=9 (the maximum, since 1 is the
smallest number removed), so the range checks out.

====================================================================
COMPLEXITY
====================================================================

1. TIME COMPLEXITY:

int S;             -> O(1)
cin >> S;          -> O(1)
cout << 10 - S;    -> O(1)

No loop, no recursion, single subtraction.

Total: O(1)

2. SPACE COMPLEXITY:

S -> single fixed variable, no containers.

Total: O(1)

3. COMMON MISTAKES PEOPLE MAKE ON THIS PROBLEM:

- Declaring the input variable but forgetting to actually read it
  with cin before using it - leads to using an uninitialized/garbage
  value.

- Hardcoding the missing number via if-else checks for each possible
  S value (6,7,8,9) instead of recognizing the direct arithmetic
  relationship 10 - S - unnecessary and error-prone.

- Assuming the total needs to be computed via a loop or sum of an
  array of {1,2,3,4} rather than recognizing it's a fixed constant
  (10) that can be hardcoded directly.
*/