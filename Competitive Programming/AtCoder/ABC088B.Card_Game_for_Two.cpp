/*
====================================================================
AtCoder ABC088B - Card Game for Two
====================================================================

There are N cards, with a number a_i written on the i-th card.
Alice and Bob alternately take one card each, Alice going first.
Both play optimally to maximize their own score (sum of numbers on
cards they've taken). Find Alice's score minus Bob's score.

Constraints:
1 <= N <= 100
1 <= a_i <= 100

Input format:
N
a1 a2 a3 ... aN

Example 1:
Input:
2
3 1
Output: 2

Example 2:
Input:
3
2 7 4
Output: 5

Example 3:
Input:
4
20 18 2 18
Output: 18
====================================================================
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  int N;
  cin >> N;
  
  int A[N];
  
  for(int i=0 ; i<N ; i++){
    cin >> A[i];
  }
  
  int bob = 0 , alice = 0;
  
  sort(A,A+N,greater<int>());
  
  for(int i=0 ; i<N ; i++){
    if(i%2 == 0){
      alice += A[i];
    }
    else{
      bob += A[i];
    }
  }
  
  cout << alice - bob << endl;
}

/*
====================================================================
SOLUTION IN MY WORDS
====================================================================

Initially didn't understand the problem statement, so worked through
sample 3 by hand: cards 20,18,2,18. Since both players are greedy and
always grab the single best card available on their turn, Alice takes
20 (best available), then Bob takes 18 (best remaining), then Alice
takes 18 (best remaining), then Bob takes 2 (only one left). Alice =
20+18=38, Bob=18+2=20, difference=18 — matches expected output.

This revealed the key insight: since both players always take the
current maximum, the whole game is equivalent to just sorting ALL
cards in descending order once, then alternating who "gets" each
position in that sorted order — index 0 to Alice, index 1 to Bob,
index 2 to Alice, etc. No need to repeatedly search for and remove
the max card on each turn.

Read input into a plain array (size N, read via a loop with cin),
then sorted it in descending order using sort(A, A+N, greater<int>())
from <algorithm> — didn't know sort() worked on raw arrays (thought
it needed vectors), but confirmed it works with pointer-style range
arguments (start pointer, one-past-end pointer), same idea as vector
iterators.

First loop-writing attempt had two bugs:
1. Turn assignment was initially backwards (i%2==0 assigned to Bob
   instead of Alice) - fixed by re-checking which index parity
   corresponds to Alice going first (index 0, the very first turn,
   must be Alice's).
2. Accumulated the wrong thing entirely - wrote `alice += i` and
   `bob += i`, which adds the LOOP INDEX rather than the actual card
   value at that index. Traced sample 1 by hand to catch this: with
   A={3,1} after sorting, alice+=i would compute alice=0 (from i=0),
   not 3. Fixed by changing to `alice += A[i]` / `bob += A[i]` to
   accumulate the actual value stored at that sorted position.

Confirmed sort() itself costs O(N log N), which dominates the total
complexity since everything else in the solution is O(N).

====================================================================
COMPLEXITY
====================================================================

1. TIME COMPLEXITY:

cin >> N;                        -> O(1)
first for loop (read input)      -> O(N)
sort(A, A+N, greater<int>())     -> O(N log N)
second for loop (turn alternation)
    A[i] access + accumulate       -> O(1) per iteration
    total loop                      -> O(N)
cout << alice - bob                -> O(1)

Total: O(N log N), dominated by the sort call.

2. SPACE COMPLEXITY:

A          -> O(N), stores all card values
bob, alice -> O(1) each

Total: O(N)

3. COMMON MISTAKES PEOPLE MAKE ON THIS PROBLEM:

- Accumulating the loop index (i) instead of the actual array value
  (A[i]) into alice/bob totals - a subtle bug since the code compiles
  fine and runs, but produces numerically wrong results that are easy
  to miss without manually tracing a sample.

- Getting turn-parity backwards - assigning index 0 (Alice's actual
  first turn) to Bob's total instead of Alice's, silently swapping
  both players' final scores.

- Repeatedly searching for the maximum remaining card on each turn
  (O(N) per turn, O(N^2) total) instead of realizing a single
  descending sort upfront makes the "always take current max" turns
  trivial to simulate via a straight index walk.

- Sorting in ascending order and then trying to read the array from
  the back (reverse iteration) instead of directly sorting descending
  with greater<int>() - works but adds unnecessary indexing
  complexity for no benefit.

- Assuming sort() only works on vectors - it works on any random-
  access range, including plain C-style arrays, via pointer-style
  begin/end arguments (A, A+N).
*/