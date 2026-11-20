/*
====================================================================
Codeforces 50A - Domino piling
====================================================================

+------------------------------------------------------------------+
| Dificulty - 800                                                  |
| Date of Submission - 14 September 09:11 PM                       |
| Tags - greedy, math                                               |
+------------------------------------------------------------------+

Given an M x N board and unlimited 2x1 dominoes (which may be
rotated), find the maximum number of non-overlapping dominoes that
can be placed entirely within the board.

Constraints:
1 <= M <= N <= 16

Example 1:
Input: 2 4
Output: 4

Example 2:
Input: 3 3
Output: 4
====================================================================
*/

#include <iostream>
using namespace std;

int main(){
    int M,N;
    cin >> M >> N;
    
    cout << (M*N)/2 << endl;
    
    return 0;
    
}

/*
====================================================================
SOLUTION IN MY WORDS
====================================================================

Each domino covers exactly 2 squares, so the theoretical upper bound
on the number of dominoes is total squares (M*N) divided by 2. Used
integer division directly, which naturally rounds down when M*N is
odd (e.g. 3x3=9, 9/2=4 in integer division), correctly leaving one
square uncovered without needing any explicit odd/even check.

Verified this bound is always actually achievable (not just a loose
upper bound) by reasoning through smaller cases: a 1x1 board (M*N=1)
correctly gives 0, since a domino physically cannot fit into a
single square with no adjacent neighbor. A 1x3 strip gives 1
(floor(3/2)), and this is achievable by placing one horizontal
domino across the first two columns, leaving the third column empty
- confirmed that dominoes being allowed to rotate (placed either
horizontally or vertically, per the problem's explicit permission)
is what allows any M x N rectangle to always be filled up to exactly
floor(M*N/2), regardless of the board's specific shape.

The underlying reason this always works (not just for the tested
cases): thinking of the board like a checkerboard with alternating
colors, every domino placement (in either orientation) always covers
exactly one square of each color, since adjacent squares always
differ in color. This means dominoes can always be packed in simple
row-by-row or column-by-column strips without ever getting
structurally "stuck," and the only possible leftover is a single
unpaired square when the total is odd - never a larger unfillable
gap caused by the board's shape.

Considered an alternative explicit form using an if-else to check
M*N's parity ((M*N-1)/2 if odd, M*N/2 if even) but recognized this
produces identical results to plain integer division truncation,
since integer division already performs the "round down by 1 if
odd" behavior automatically - kept the simpler one-line version
with no branching needed.

====================================================================
COMPLEXITY
====================================================================

1. TIME COMPLEXITY:

cin >> M >> N     -> O(1)
(M*N)/2            -> O(1)
cout << ...        -> O(1)

Total: O(1)

2. SPACE COMPLEXITY:

M, N -> O(1) fixed variables

Total: O(1)

*/
