/*
====================================================================
AtCoder ABC087B - Coins
====================================================================

You have A 500-yen coins, B 100-yen coins, and C 50-yen coins. Count
the number of ways to select some of these coins (0 up to the total
available of each type) so that the total value equals exactly X
yen. Two selections are different if the count of any coin type
differs.

Constraints:
0 <= A,B,C <= 50
A+B+C >= 1
50 <= X <= 20000
X is a multiple of 50

Input format:
A
B
C
X

Example 1:
Input: 2 / 2 / 2 / 100
Output: 2
(0 five-hundreds, 1 hundred, 0 fifties = 100; or 0/0/2 = 100)

Example 2:
Input: 5 / 1 / 0 / 150
Output: 0

Example 3:
Input: 30 / 40 / 50 / 6000
Output: 213
====================================================================
*/

#include <iostream>
using namespace std;

int main(){
  int A,B,C,X;
  cin >> A >> B >> C >> X;
  
  int count = 0;
  
  for(int a=0;a<=A;a++){
    for(int b=0;b<=B;b++){
      for(int c=0;c<=C;c++){
        if((500*a)+(100*b)+(50*c) == X){
          count ++;
        }
      }
    }
  }
  
  cout << count << endl;
  
  return 0;
}

/*
====================================================================
SOLUTION IN MY WORDS
====================================================================

Initially got stuck trying to find a shortcut - attempted things
like subtracting one denomination from X and checking divisibility
by another denomination in isolation, which only tests whether ONE
coin type alone can make up X, not every possible combined use of
all three coin types together. This missed the actual structure of
the problem entirely.

The key reframe: since A, B, C are all small (at most 50 each), the
problem doesn't need a clever shortcut at all - it can be solved by
directly trying every possible combination of (number of 500-coins
used, number of 100-coins used, number of 50-coins used) and
checking whether each combination's total equals X. This is
directly analogous to using nested loops to generate every possible
PAIR of two things (as done in earlier problems) - extending that
same idea to three independent choices needs three nested loops
instead of two, one per coin type.

Had to work through a specific point of confusion on loop bounds:
initially expected a loop with A=2 to run only 2 times, expecting
condition a<A. Traced for(int a=0;a<=A;a++) manually with A=2 and
saw it actually iterates for a=0, a=1, AND a=2 - three iterations,
not two. Resolved this by separating "how many times the loop
runs" from "what each value of a MEANS" - a doesn't count loop
iterations, it represents a specific candidate COUNT of coins to
try using in this combination. Since you have 2 coins available,
the valid counts to try are 0, 1, or 2 (three distinct
possibilities, since using all available coins is just as valid a
choice as using none) - so a<=A is correct, not a<A, or the
combination that uses ALL of a coin type would never be tested.

With the loop structure settled, the innermost check is
straightforward: for a given (a,b,c), the total value is
500*a + 100*b + 50*c, and if this equals X exactly, that's one
valid combination - increment a counter.

Traced this on sample 1 (A=2,B=2,C=2,X=100) to confirm: since a
single 500-coin (500) already exceeds X=100, only a=0 combinations
can ever be valid. Among a=0 combinations, checked (b,c) pairs: b=1,
c=0 gives 100+0=100 (valid); b=0,c=2 gives 0+100=100 (valid); no
other (b,c) pair with b,c<=2 sums to exactly 100. Total: 2 valid
combinations, matching the expected output directly.

====================================================================
COMPLEXITY
====================================================================

1. TIME COMPLEXITY:

outer loop over a (0 to A)           -> O(A) iterations
  middle loop over b (0 to B)         -> O(B) iterations
    inner loop over c (0 to C)         -> O(C) iterations
      constant check + possible count++ -> O(1)

Total: O(A*B*C). With A,B,C <= 50, this is at most ~51*51*51 =
~132,651 iterations in the worst case - comfortably fast within the
2 second time limit, well under a million operations.

2. SPACE COMPLEXITY:

A, B, C, X, count, a, b, c -> O(1) fixed variables, no arrays or
    data structures used

Total: O(1)

3. COMMON MISTAKES PEOPLE MAKE ON THIS PROBLEM:

- Trying to find a closed-form/shortcut formula (e.g. checking only
  one denomination's divisibility into X at a time) instead of
  recognizing this is a brute-force "try every combination" problem
  - the small constraints (A,B,C<=50) are a strong signal that
  triple-nested brute force is the intended approach, not a hint
  that a cleverer method is required.

- Using strict less-than (a<A) instead of less-than-or-equal
  (a<=A) in the loop bounds - this silently excludes the valid case
  of using ALL available coins of a given type, undercounting the
  true number of combinations.

- Forgetting that "select zero of a coin type" is itself a valid,
  distinct selection that must be tested (starting each loop at 0,
  not 1) - the problem explicitly counts combinations by differing
  COUNTS per coin type, including zero.

- Not initializing count to 0 before the loops, or placing the
  increment outside the innermost loop's condition check, causing
  either garbage initial values or combinations to be
  miscounted/skipped.
*/