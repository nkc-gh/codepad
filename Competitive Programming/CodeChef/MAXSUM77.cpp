/*
====================================================================
CodeChef - Maximum Sum (MAXSUM77)
====================================================================

Given an array A of N elements, remove either the first or last
element, K times total (each removal independently chosen: front or
back). Find the maximum possible sum of the remaining elements after
all K removals.

Constraints:
1 <= T <= 100
1 <= K < N <= 100
1 <= Ai <= 100

Example 1:
Input:
3
4 2
2 6 3 4
3 2
5 1 2
4 2
8 1 6 5
Output:
9
5
11
====================================================================
*/

#include <bits/stdc++.h>
using namespace std;
int main() {
    int T;
    cin >> T;
    for(int t = 0; t < T; t++){
        int N, K;
        cin >> N >> K;
        int A[N];
        for(int i = 0; i < N; i++) cin >> A[i];

        int windowSize = N - K;
        int maxSum = 0;

        for(int L = 0; L <= K; L++){
            int sum = 0;
            for(int i = L; i < L + windowSize; i++){
                sum += A[i];
            }
            maxSum = max(maxSum, sum);
        }

        cout << maxSum << endl;
    }
}

/*
====================================================================
SOLUTION IN MY WORDS
====================================================================

Struggled a lot with the English of this one at first - didn't
initially grasp that "remove first or last, K times" means each of
the K removals independently picks front or back, not that you're
restricted to one pattern. Once I understood you could do e.g.
front-front-front or front-back-front or any mix, I still couldn't
see how to reason about "which elements survive."

The key realization (had to be walked into it): since every removal
strips from one end or the other, whatever survives at the end can
never have a gap in it - it's always one unbroken contiguous chunk
of the original array. You can never end up with something like
[first element, last element] with a hole in the middle, because
nothing is ever removed from the middle directly.

Traced several removal sequences by hand on [3,2,4,6,9] with K=3
(front-front-front, back-back-back, front-back-front) and confirmed
this - got [6,9], [3,2], and [4,6] respectively, all contiguous
blocks, never scattered.

Also noticed that the specific order of front/back choices doesn't
matter, only how many total came from each side - fbb, bfb, bbf all
strip the same 1 from front and 2 from back, landing on the same
leftover block. This means the only real "choice" is: how many of
the K removals came from the front (call it L, from 0 to K), with
the rest (K-L) from the back.

This reduces the whole problem to: try every possible contiguous
window of size N-K (there are exactly K+1 of them, one for each
split of removals between front and back), compute each window's
sum, and take the maximum. This is just a fixed brute-force sliding
window - no cleverness needed since N, K <= 100 keeps the O(N*K)
work tiny.

Initially wanted to jump to a greedy approach (at each step, remove
whichever end has the smaller current value) but this was flagged
as needing to be checked, not assumed - greedy front-vs-back
decisions made one step at a time don't necessarily lead to the
globally best final window; parked this comparison for a future
session rather than resolving it in the moment, since I needed to
submit quickly.

Also relearned mid-problem: to sum a fixed range from index L to R
inclusive, the loop needs `i <= R`, not `i < R`, or the last element
gets excluded.

====================================================================
COMPLEXITY
====================================================================

1. TIME COMPLEXITY:

for T test cases                          -> O(T) iterations
    read N integers                       -> O(N) per test case
    outer loop L from 0 to K (K+1 times)  -> O(K) iterations
        inner loop sums windowSize (N-K)  -> O(N-K) per L
        elements
    total inner work per test case: O(K * (N-K))

Total per test case: O(N + K*(N-K)), which is at most O(N^2) in the
worst case (K around N/2). Since N <= 100, this is at most ~10,000
operations per test case, well within limits even summed across
T <= 100 test cases.

2. SPACE COMPLEXITY:

int A[N] -> O(N) to store the array.
windowSize, maxSum, sum -> O(1) fixed extra variables.

Total: O(N) per test case.

3. COMMON MISTAKES PEOPLE MAKE ON THIS PROBLEM:

- Misreading the problem as requiring a fixed split (e.g. always
  half from front, half from back) instead of realizing all K+1
  splits (0 to K from front) need to be checked.

- Assuming a greedy strategy (always remove the smaller of the two
  current end elements) gives the optimal answer without verifying
  it against a counterexample - greedy front/back decisions don't
  guarantee the best final contiguous window.

- Recomputing each window's sum with a fresh inner loop (O(N-K) per
  window) instead of using a sliding sum update (subtract outgoing
  element, add incoming element) - not wrong for these small
  constraints, but wasteful and worth knowing as an optimization for
  larger N.

- Off-by-one in the window bounds - using `i < L + windowSize - 1`
  or similar miscalculated end bound, cutting the window one
  element short or reading one past it.

- Forgetting that windows must be exactly size N-K, and instead
  trying to compare windows of different sizes.

- Initializing maxSum to 0 when array elements could theoretically
  make legitimate window sums also compute correctly here since
  Ai >= 1 (sums are always positive), but this initialization habit
  would break if negative numbers were allowed - worth flagging as
  a general "don't assume 0 is a safe initial max" pattern for
  future problems with negative values.
*/