/*
====================================================================
CodeChef - Search an element in an array (SEARCHINARR) (Difficulty - 600)
====================================================================

You are given an array A of size N and an element X. The task is
to determine whether A contains X or not.

Function signature:
string solve(int N, int X, const vector<int>& A)

Returns "YES" if X exists in A, "NO" otherwise.

Constraints:
1 <= N, X <= 10^5
1 <= A[i] <= 10^5

Input format:
N X
A[0] A[1] ... A[N-1]

Example 1:
Input:
5 3
7 3 5 2 1
Output: YES

Example 2:
Input:
5 10
7 3 5 2 1
Output: NO
====================================================================
*/

string solve(int N, int X, const vector<int>& A) {
    for (int i = 0; i < N; i++) {
        if (A[i] == X) {
            return "YES";
        }
    }

    return "NO";
}

/*
====================================================================
SOLUTION IN MY WORDS
====================================================================

First instinct was binary search, since it's faster than checking
every element one by one. But binary search only works correctly
on a SORTED array - it decides which half to discard by comparing
the target to the middle element, and that decision is only valid
if everything to one side is guaranteed smaller and everything to
the other side is guaranteed larger. The sample array, [7,3,5,2,1],
is NOT sorted, so binary search isn't applicable here as given.

Considered two real options once that was clear:

1. Sort the array first, then binary search it
   -> Sorting costs O(N log N), binary search after that costs
      O(log N), total O(N log N).

2. Plain linear search, no sorting
   -> Walk through once, O(N) total.

Sorting only pays off when the SAME array is searched many times
(sort once, amortize the cost across many queries). Here, there's
only a single X to search for against a single array - paying
O(N log N) to sort, just to follow it with an O(log N) search, is
strictly worse than a single O(N) linear pass. So linear search is
the right choice for this specific problem, not because binary
search is "wrong" in general, but because the extra sort cost isn't
justified by a one-time search.

The linear search itself is a straightforward loop over every index
0 to N-1: compare A[i] to X, and return "YES" the moment a match is
found - no need to check the rest of the array once found. If the
loop finishes without ever matching, fall through to return "NO"
after the loop ends.

Early pseudocode attempt mistakenly tried to reuse binary-search
structure on the unsorted array, and additionally compared the
INDEX (mid) directly to the VALUE X (if (mid == X)) instead of
comparing the element AT that index (A[mid] == X) - comparing an
index position to a target value doesn't make sense and wouldn't
work even if the array had been sorted.

Traced both samples through the final linear version: for X=3 in
[7,3,5,2,1], the loop hits index 1 (value 3) and returns "YES"
immediately. For X=10 in the same array, all 5 elements are checked
with no match, so the loop completes and falls through to "NO".
Both match the expected outputs.

====================================================================
COMPLEXITY
====================================================================

1. TIME COMPLEXITY:

for loop over N elements      -> O(N) iterations
    A[i] == X comparison         -> O(1) per element

Total: O(N) - worst case (X absent, or present at the last index)
checks every element exactly once.

2. SPACE COMPLEXITY:

Only the loop variable i is used, no extra array or container.

Total: O(1)

3. COMMON MISTAKES PEOPLE MAKE ON THIS PROBLEM:

- Reaching for binary search out of habit (since it's "faster" in
  general) without checking whether the array is actually sorted -
  binary search on an unsorted array gives incorrect results, since
  its correctness depends entirely on sorted order.

- Sorting the array before searching when only a single query is
  being made - this adds O(N log N) sorting cost that isn't
  recovered, since linear search alone is already O(N) and cheaper
  for a one-time search. Sorting is worth it only when searching the
  same array repeatedly across many queries.

- Comparing an index to the target value (e.g. mid == X) instead of
  comparing the element stored at that index (A[mid] == X) - mixing
  up "position" and "value" is an easy slip when adapting binary
  search pseudocode.

- Not returning immediately on a match inside the loop, instead
  continuing to scan unnecessarily or mishandling the final "NO"
  fallback after the loop.

- Forgetting the trailing return "NO" after the loop - a non-void
  function needs a reachable return on every path, even though the
  problem guarantees list length and search element are always
  valid inputs.
*/