/*
====================================================================
AtCoder ABC081B - Shift only
====================================================================

There are N positive integers A1,...,AN on a blackboard. While all
integers on the board are even, you may replace every integer X
with X/2 (one operation replaces all of them simultaneously). Find
the maximum number of times this operation can be performed.

Constraints:
1 <= N <= 200
1 <= Ai <= 10^9

Input format:
N
A1 A2 ... AN

Example 1:
Input: 3 / 8 12 40
Output: 2
([8,12,40] -> [4,6,20] -> [2,3,10], stops since 3 is odd)

Example 2:
Input: 4 / 5 6 8 10
Output: 0
(5 is already odd, no operation possible)

Example 3:
Input: 6 / 382253568 723152896 37802240 379425024 404894720 471526144
Output: 8
====================================================================
*/

#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;
    
    int A[N];
    int current = 0;
    int total = 0; 
    
    for(int i = 0; i < N; i++){
        cin >> A[i];
        
        while(A[i] % 2 == 0 && A[i] > 0){
            current++;
            A[i] = A[i] / 2;
        }
       
        if (i==0){
            total = current;
        }
        
        if (current < total) {
            total = current;
        }
        
        current = 0;
    }

    cout << total << endl;
    return 0;
}

/*
====================================================================
SOLUTION IN MY WORDS
====================================================================

First wrong idea: sum all the numbers, then count how many times
that single sum is divisible by 2. This happened to give the right
answer (2) on sample 1 by coincidence, but tracing a smaller case,
[4,4], exposed it as fundamentally wrong: the sum-based approach
gave 3 (8 is divisible by 2 three times: 8->4->2->1), but the real
operation applied to [4,4] gives [4,4]->[2,2]->[1,1], stopping at
2 operations since 1 is odd. Summing has no real connection to the
actual rule - the operation requires every individual number to
stay even, not the sum.

Reframed the problem correctly: each number Ai can individually
survive being halved some number of times before becoming odd -
this is just counting how many times Ai is divisible by 2 (its
count of trailing factors of 2). Since ALL numbers must be even for
an operation to happen, the actual number of operations possible is
the MINIMUM of these individual counts across all N numbers - the
first number to "run out" (become odd) caps every other number's
remaining halvings too, since the operation is applied to the whole
board at once.

Built this in two pieces: an inner while loop that repeatedly
divides a single number by 2 while it's even, incrementing a
counter (current) each time - reused the same loop structure from
the earlier wrong "sum" attempt, just applied per-element instead
of to a combined sum. Then an outer loop over all N numbers, tracks
the running minimum of each element's current count into total.

Debugging history on the minimum-tracking part specifically:
1. First version declared current outside the for loop and never
   reset it between elements - counts from earlier numbers kept
   accumulating into later numbers' counts instead of starting
   fresh each time. Fixed by resetting current = 0 at the end of
   each iteration.
2. Initialized total = 0 and used if(total > current) to update it.
   Traced [8,12,40]: current becomes 3 for the first element, but
   0 > 3 is false, so total never leaves 0 - since 0 is smaller
   than any real positive count, no real count could ever pass the
   check. Needed a way to let the very first element's count in
   unconditionally.
3. Patched this with if(total==0) total=current as a way to
   "seed" total on the first pass. This passed several hand-traced
   cases ([8,12,40], [4,4], [2,4], [8,2,4]) - all coincidentally
   worked because in each case, either total never legitimately
   needed to be exactly 0 at a non-first position, or 0 first
   appeared at index 0 itself. But it broke on [5,6,8,10]: A[0]=5
   is odd, correctly giving current=0 and total=0 - but then for
   A[1]=6, current=1, and if(total==0) fired AGAIN (since total was
   still legitimately 0), incorrectly overwriting the correct
   total=0 with total=1. The bug: checking total==0 can't
   distinguish "total is 0 because it's genuinely the minimum found
   so far" from "total is 0 because it hasn't been initialized
   yet" - both look identical to that check.
4. Fixed by switching the initialization condition from if(total==0)
   to if(i==0) - this ties the "seed total on the first element"
   logic to loop POSITION instead of total's VALUE, completely
   removing the ambiguity. Verified this correctly handles both a
   case needing a mid-sequence minimum update ([8,12,40] -> total
   correctly drops from 3 to 2 when processing 12) and a case where
   the true minimum is legitimately 0 at a non-first position
   ([5,6,8,10] -> total stays correctly at 0 throughout).

Also had an unrelated failed detour: tried restructuring the whole
solution around a single fixed index (i = N-1) with one while loop
outside the for loop, attempting to process "the last element, then
step backward." This introduced two new bugs at once - only
partially draining each element's possible halvings before moving
to the next index, and an i!=0 guard that blocked index 0 from ever
being processed at all. Abandoned this restructuring and returned
to the working nested for+while version instead, since it didn't
fix anything the original didn't already handle correctly.

Considered alternatives after arriving at a correct solution:
initializing total to INT_MAX (from <climits>) instead of using the
if(i==0) check is the more commonly seen idiom - it removes the
need for a special first-iteration branch entirely, since nothing
can beat INT_MAX on the first real comparison. Also, std::min(a,b)
could replace the manual if(current<total) total=current; pattern.
Neither changes correctness or complexity - purely stylistic/
idiomatic alternatives to recognize in others' code.

====================================================================
COMPLEXITY
====================================================================

1. TIME COMPLEXITY:

for loop over N elements                    -> O(N) iterations
    inner while loop per element             -> O(log(Ai)) per
        (halves Ai until odd)                   element, since Ai
                                                 loses one factor
                                                 of 2 per iteration
    if/comparison checks                     -> O(1) per element

Total: O(N * log(max Ai)). With N<=200 and Ai<=10^9 (so
log2(10^9) ~ 30), this is at most ~6000 operations - trivially fast.

2. SPACE COMPLEXITY:

A[N]              -> O(N) to store the array
current, total, i -> O(1) fixed extra variables

Total: O(N)

3. COMMON MISTAKES PEOPLE MAKE ON THIS PROBLEM:

- Summing all elements and checking divisibility of the sum instead
  of finding the minimum of each element's individual halving
  count - the sum's divisibility has no real relationship to the
  actual per-element, all-must-stay-even operation rule.

- Forgetting to reset the per-element halving counter between
  elements when it's declared outside the loop - causes counts to
  wrongly accumulate across elements instead of restarting fresh.

- Initializing the running minimum to 0 and checking
  if(newValue < currentMin) - since 0 is smaller than or equal to
  any valid count, this prevents the first real value (and any
  case where the true minimum is 0) from ever correctly updating
  the minimum without an extra safeguard.

- Using if(total==0) as a proxy for "not yet initialized" - fails
  to distinguish a genuinely correct minimum of 0 (from an odd
  number appearing early) from an uninitialized state, causing a
  later element to wrongly overwrite a correct answer of 0.

- Not testing a case where the correct answer is exactly 0 in a
  non-first position - many minimum-tracking bugs (like the
  total==0 ambiguity here) only surface when the true minimum
  happens to already equal the counter's default/reset value.
*/