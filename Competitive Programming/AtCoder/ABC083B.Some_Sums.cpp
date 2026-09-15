/*
====================================================================
AtCoder ABC083B - Some Sums
====================================================================

Find the sum of the integers between 1 and N (inclusive) whose sum
of digits (in base 10) is between A and B (inclusive).

Constraints:
1 <= N <= 10^4
1 <= A <= B <= 36

Input format:
N A B

Example 1:
Input: 20 2 5
Output: 84

Example 2:
Input: 10 1 2
Output: 13

Example 3:
Input: 100 4 16
Output: 4554
====================================================================
*/

#include <iostream>
using namespace std;

int main(){
  int N,A,B;
  cin >> N >> A >> B;
  int output = 0;
  
  for(int i=1 ; i<=N ; i++){
    int j = i;
    int store = 0;
    while(j!=0){
      store += j%10;
      j = j/10;
    }
    if(store >=A && store <=B){
      output += i;
    }
  }
  
  cout << output << endl;
}

/*
====================================================================
SOLUTION IN MY WORDS
====================================================================

Initially the wording was confusing — "sum of the integers... whose
sum of digits... is between A and B" sounds like it's asking for a
sum of digit sums, but it's actually asking for a sum of the
original numbers themselves, filtered by a condition on their digit
sums. Worked through sample 1 (N=20, A=2, B=5) by hand to confirm:
qualifying numbers were 2,3,4,5,11,12,13,14,20 (each has digit sum
in [2,5]), and summing those numbers directly (not their digit
sums) gives 84, matching the expected output.

Also clarified "inclusive" — it means the boundary values A and B
themselves count as valid, so the check needs to be store>=A &&
store<=B, not a strict inequality. Same inclusive-boundary pattern
as the earlier Assignment Due problem (>= instead of >).

Strategy: loop i from 1 to N. For each i, extract its digit sum
using the standard peel-off-last-digit idiom: take a scratch copy j
of i (since i itself shouldn't be mutated, it's still needed for
the range check and for adding to output), repeatedly do
store += j%10 to grab the last digit, then j /= 10 to remove it,
until j hits 0. Once store (the digit sum) is computed, check if it
falls in [A,B]; if so, add i (the original number, not store) to
the running output total.

Considered whether there's a way to avoid recomputing the digit sum
from scratch for every i (since i and i+1 are related), but given
N<=10^4, the brute-force approach is already O(N * digits) ~ 40,000
operations, well within the ceiling for the given time limit — no
further optimization needed at this scale.

====================================================================
COMPLEXITY
====================================================================

1. TIME COMPLEXITY:

outer for loop over i=1..N        -> O(N) iterations
    inner while loop (digit peel)   -> O(log10(i)) per i, i.e.
                                        proportional to number of
                                        digits in i (at most 5 for
                                        i<=10^4)
    range check + accumulate         -> O(1) per i

Total: O(N * log10(N)), effectively O(N) since digit count is
bounded by a small constant (~5) for N<=10^4.

2. SPACE COMPLEXITY:

N, A, B, output, i, j, store -> all O(1) fixed variables, no
arrays/containers used.

Total: O(1)

3. COMMON MISTAKES PEOPLE MAKE ON THIS PROBLEM:

- Misreading the problem as summing the digit sums instead of
  summing the original qualifying numbers themselves — the output
  should accumulate i, not store.

- Using strict inequality (store>A && store<B) instead of inclusive
  bounds (store>=A && store<=B), incorrectly excluding numbers whose
  digit sum exactly equals A or B.

- Mutating i directly inside the digit-extraction loop instead of
  using a scratch copy — this destroys the value of i needed later
  for both the loop increment and the output accumulation.

- Forgetting to reset the digit-sum accumulator (store) to 0 at the
  start of each outer iteration, causing digit sums to leak across
  different values of i.
*/