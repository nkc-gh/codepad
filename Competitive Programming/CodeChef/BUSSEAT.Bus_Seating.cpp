/*
====================================================================
CodeChef - Bus Seating (BUSSEAT) (Difficulty - 640)
====================================================================

A bus has N rows, each with exactly 2 seats. K people enter one by
one; each tries to sit in an empty row first, and only sits next to
someone if no empty row remains. Find how many people end up sitting
next to somebody else.

Constraints:
1 <= T <= 10100
1 <= N <= 100
1 <= K <= 2*N

Input format:
T (number of test cases)
For each test case: N K

Example 1:
Input:
3
2 3
2 1
4 8
Output:
2
0
8
====================================================================
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    
    for(int i = 0; i < T; i++){
        int N, K;
        cin >> N >> K;
        
        if (K <= N) {
            cout << 0 << endl;
        }
        else {
            cout << (K - N) * 2 << endl;
        }
    }
    
    return 0;
}

/*
====================================================================
SOLUTION IN MY WORDS
====================================================================

Started by tracing test case 3 (N=4, K=8) by hand: the first 4
people each grab an empty row (since there are 4 rows), and only
after all rows are occupied does anyone have to sit next to someone.
Initially reasoned the answer should be K-N (people beyond the first
N), but the expected output was 8, not 4 - revealing a flaw.

Realized N=4, K=8 means the bus is COMPLETELY FULL (4 rows x 2 seats
= 8 capacity, K=8 fills every seat). In that case, every single row
ends up with exactly 2 people, meaning ALL 8 people are "sitting
next to somebody" - not just the ones who arrived after row 4.

This showed the key insight: it's not just "people after the Nth
one" who end up next to someone - once a row has 2 occupants, BOTH
of them count as sitting next to somebody, including the first
person who originally sat there alone.

So the actual quantity to compute is: how many ROWS end up with 2
people (since each such row contributes 2 people to the "sitting
next to somebody" count), not how many people arrived "late."
Number of rows that got a SECOND person = max(0, K-N), since only
people beyond the first N (one per row) are forced to double up.
Each of those (K-N) people forces one row to go from 1 to 2
occupants, and BOTH occupants of that row now count - so the total
affected people is (K-N)*2, not just (K-N).

First code version had a redundant special case for K==2*N
(completely full bus), printing K directly for that case, before
realizing the general formula (K-N)*2 already produces the correct
result for a full bus too - traced N=4,K=8: (8-4)*2=8, matching
without needing a separate branch. Simplified by removing the
special case entirely.

Also confirmed the K<=N branch (nobody doubles up, since there's an
empty row for everyone) correctly returns 0 in this simplified
version, and traced sample 2 (N=2,K=1) to confirm: K<=N is true
(1<=2), so 0 is printed as expected.

====================================================================
COMPLEXITY
====================================================================

1. TIME COMPLEXITY:

cin >> T;                          -> O(1)
for loop over T test cases         -> O(T)
    cin >> N >> K;                    -> O(1)
    if/else branch + arithmetic         -> O(1)
    cout << ...                          -> O(1)

Total: O(T), constant work per test case.

2. SPACE COMPLEXITY:

T, N, K, i -> O(1) fixed variables, no per-test-case storage needed

Total: O(1)

3. COMMON MISTAKES PEOPLE MAKE ON THIS PROBLEM:

- Computing (K-N) as the final answer instead of (K-N)*2 - this
  undercounts by only counting the "late" arrivals who had to double
  up, while forgetting that their row-mates (who arrived earlier and
  originally sat alone) ALSO now count as sitting next to somebody
  once a second person joins their row.

- Adding an unnecessary special case for a completely full bus
  (K==2*N) instead of recognizing the general formula (K-N)*2
  already handles that case correctly without any extra branching.

- Forgetting to loop over T test cases, or reusing a single N/K pair
  across all test cases instead of reading fresh values each
  iteration.
*/