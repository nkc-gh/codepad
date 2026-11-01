/*
====================================================================
CodeChef - Paper Cutting (CUTPAPER) (Difficulty - 800)
====================================================================

Given a square paper of side N, find the maximum number of K×K
squares that can be cut from it.

Constraints:
1 <= T <= 1000
1 <= K <= N <= 1000

Input format:
T
N K (per test case)

Example:
Input:
3
5 1
2 2
5 2

Output:
25
1
4
====================================================================
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    for(int i=0 ; i<T ; i++){
        int N, K;
        cin >> N >> K;

        cout << (N/K) * (N/K) << "\n";
    }

    return 0;
}

/*
====================================================================
SOLUTION IN MY WORDS
====================================================================

First instinct was area based - total paper area is N*N, each
cutout is K*K, so divide them. Traced N=5, K=2: paper area 25,
cutout area 4, 25/4 = 6 by integer division. But the correct
answer is 4. Area method overcounts because leftover strips along
the edges (the column of width 1 and row of height 1 that remain
after fitting 2x2 squares in a 5x5 grid) cannot form complete
squares, but their area still gets counted as usable space.

Correct approach is dimension by dimension. A 2D square paper is
just two 1D lengths - one for width, one for height. In one
dimension, how many K-length segments fit in N length is simply
N/K using integer division, which automatically discards the
leftover fraction. For a 5x5 paper with K=2: 5/2 = 2 along width,
5/2 = 2 along height. Total squares = 2 * 2 = 4(2 squares along one row , there are 2 rows so 2*2). 
Integer division handles the leftover strip correctly per dimension, which is why
the area method fails but this doesn't.

Since the paper is a square both dimensions are N, so the formula
is (N/K) * (N/K). For a rectangle it would be (length/K) *
(width/K).

====================================================================
COMPLEXITY
====================================================================

1. TIME COMPLEXITY:

cin >> T                          -> O(1)
outer loop over T test cases      -> O(T)
    cin >> N >> K                 -> O(1)
    (N/K) * (N/K)                 -> O(1)
    cout << ...                   -> O(1)

Total: O(T)

2. SPACE COMPLEXITY:

T, i, N, K -> O(1), fixed variables, no arrays or containers

Total: O(1)

3. COMMON MISTAKES PEOPLE MAKE ON THIS PROBLEM:

- Using area method (N*N)/(K*K) instead of (N/K)*(N/K) - leftover
  strips along edges cannot form complete squares but their area
  gets counted as usable, producing an overcount for cases where
  N is not perfectly divisible by K.

- Not using integer division - the leftover strip must be discarded,
  integer division does this automatically per dimension.

- Overflow concern - N and K are at most 1000, so (N/K)*(N/K) is
  at most 1000*1000 = 1,000,000 which fits in int comfortably.
*/