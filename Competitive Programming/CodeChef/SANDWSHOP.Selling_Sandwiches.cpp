/*
====================================================================
CodeChef - Selling Sandwiches (SANDWSHOP) (Difficulty - 115)
====================================================================

Chef sells each sandwich for A rupees. The buns cost B rupees and
the vegetables cost C rupees, with no other costs. Find the profit
(possibly negative, indicating a loss) Chef makes on one sandwich.

Constraints:
100 <= A <= 1000
40 <= B <= 200
40 <= C <= 200

Example 1:
Input: 1000 200 200
Output: 600
(Cost = 400, sold for 1000, profit = 600)

Example 2:
Input: 100 200 200
Output: -300
(Cost = 400, sold for 100, loss of 300)
====================================================================
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	int A,B,C;
	
	cin >> A >> B >> C;
	
	cout << A - (B+C) << endl;
	
	return 0;

}

/*
====================================================================
SOLUTION IN MY WORDS
====================================================================

Direct translation of the problem statement - profit is defined as
selling price minus total ingredient cost, so A - (B+C) computes
this directly. No derivation needed since the problem states the
relationship explicitly, including that a negative result is a
valid and expected output representing a loss.

Verified against both samples: A=1000,B=200,C=200 gives
1000-(200+200)=600, matching the expected profit. A=100,B=200,C=200
gives 100-(200+200)=-300, matching the expected loss - confirms int
correctly represents and prints negative values without needing any
special handling, since C++ ints are signed by default.

====================================================================
COMPLEXITY
====================================================================

1. TIME COMPLEXITY:

cin >> A >> B >> C     -> O(1)
A - (B+C)               -> O(1)
cout << ...             -> O(1)

Total: O(1)

2. SPACE COMPLEXITY:

A, B, C -> O(1) fixed variables

Total: O(1)

3. COMMON MISTAKES PEOPLE MAKE ON THIS PROBLEM:

- Using an unsigned type or otherwise assuming the result must be
  non-negative, which would corrupt the output when Chef makes a
  loss - the problem explicitly allows and expects negative output.

- Adding an unnecessary if-check to print "loss" or reformat
  negative output, when the problem just wants the raw signed
  integer printed directly, negative sign included.

- Overcomplicating a single arithmetic expression with intermediate
  variables or extra logic when one line fully captures the profit
  formula as stated.
*/