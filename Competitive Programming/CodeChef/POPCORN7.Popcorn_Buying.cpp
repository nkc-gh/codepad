/*
====================================================================
CodeChef - Popcorn Buying (POPCORN7) (Difficulty - 99)
====================================================================

Chef has X rupees (X >= 100). He must buy one movie ticket costing
100 rupees. With the leftover money, he buys as many popcorn buckets
as possible, each costing 50 rupees. Output how many buckets he can
buy.

Constraints:
100 <= X <= 250

Example 1:
Input: 145
Output: 0

Example 2:
Input: 225
Output: 2
====================================================================
*/

#include <bits/stdc++.h>
using namespace std;
int main() {
	int X;
	cin >> X;
	cout << (X - 100) / 50;
	return 0;
}

/*
====================================================================
SOLUTION IN MY WORDS
====================================================================

Leftover money after the ticket is X - 100. Number of buckets Chef
can afford is that leftover divided by 50, dropping any remainder
since he can't buy a fraction of a bucket.

I first wrote it with an intermediate `int result` variable, which
worked fine - (X-100)/50 with X as int means both operands of the
division are int, so int division kicks in and truncates the
fraction automatically. 45/50 gives 0, not 0.9 truncated later - the
truncation happens *during* the division itself, before the result
is ever stored anywhere.

Then I got confused and changed `result` to a `float`, expecting
that to somehow recover the decimal part - e.g. expecting 225 to
give 2.5 instead of 2. It still printed 2. The mistake was thinking
the type of the variable on the left of `=` affects how the
expression on the right gets evaluated. It doesn't - the compiler
evaluates (X - 100) / 50 completely on its own first, sees two int
operands, does int division, produces the int 0 or 2, and only
*then* converts that already-truncated int into a float for storage.
By that point the fractional part is gone for good - converting to
float after the fact can't bring back information that integer
division already discarded.

To actually get 2.5, I'd need to make the division itself a float
division by making at least one operand a float before the division
happens - e.g. casting X to float, or dividing by 50.0 instead of
50. Didn't need this for the actual problem since I want the
truncated integer bucket count anyway, but useful to know why the
float attempt didn't do what I expected.

Also cleared up along the way: cout doesn't need format specifiers
like printf's %d/%f because << is an overloaded operator - the
compiler picks the correct operator<< for the exact type at compile
time based on the variable's declared type, rather than reading a
runtime format string like printf does.

Final code just does the division directly in the cout line -
no intermediate variable needed at all.

====================================================================
COMPLEXITY
====================================================================

1. TIME COMPLEXITY:

int X;                          -> O(1)
cin >> X;                       -> O(1)
cout << (X - 100) / 50;         -> O(1)

No loop, no recursion, fixed number of arithmetic operations
regardless of input value.

Total: O(1)

2. SPACE COMPLEXITY:

X -> single fixed variable, no containers.

Total: O(1)

3. COMMON MISTAKES PEOPLE MAKE ON THIS PROBLEM:

- Forgetting to subtract the ticket cost first and dividing the
  full X by 50 directly - overcounts buckets.

- Expecting integer division to somehow produce a decimal result by
  storing it into a float/double variable after the fact - the
  truncation already happened during the division itself, since
  both operands were int.

- Using floating point division unnecessarily (e.g. dividing by
  50.0) and then trying to floor/round the result, when plain int
  division already does exactly what's needed here.

- Not handling the case where leftover money is less than 50
  (e.g. X=145) and assuming the answer must always be at least 1.
*/