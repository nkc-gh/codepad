/*
====================================================================
Codeforces 263A - Beautiful Matrix
====================================================================

+------------------------------------------------------------------+
| Dificulty - 800                                                  |
| Date of Submission - 14 September 09:45 PM                       |
| Tags - implementation                                             |
+------------------------------------------------------------------+

Given a 5x5 matrix containing 24 zeroes and a single 1, find the
minimum number of moves to bring the 1 to the center cell (row 3,
column 3, 1-indexed). Allowed moves: swap two adjacent rows, or
swap two adjacent columns.

Input format:
5 lines, each with 5 space-separated integers, representing the
matrix row by row.

Example 1:
Input:
0 0 0 0 0
0 0 0 0 1
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
Output: 3

Example 2:
Input:
0 0 0 0 0
0 0 0 0 0
0 1 0 0 0
0 0 0 0 0
0 0 0 0 0
Output: 1
====================================================================
*/

#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
    int A[5][5];
    int posi;
    int posj;
    
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cin >> A[i][j];
            if(A[i][j]==1){
                posi=i;
                posj=j;
            }
        }
    }
    
    int moves = abs(2 - posi) + abs(2 - posj);
    
    cout << moves << endl;
    
    
}

/*
====================================================================
SOLUTION IN MY WORDS
====================================================================

First decoded the input format: 5 lines of 5 space-separated
integers, where line i and position j within that line directly map
to row i, column j of the matrix - straightforward nested loop
reading (outer loop for rows, inner loop for columns) into a 2D
array A[5][5], checking each value as it's read to detect the cell
containing 1 and remembering its row/column indices (posi, posj).

Worked out the core insight by tracing both examples directly: in
example 1, the 1 is at (row 2, col 5) in 1-indexed terms, and needs
to reach (row 3, col 3) - row distance is |2-3|=1, column distance
is |5-3|=2, total 1+2=3, matching the expected output exactly. In
example 2, the 1 is at (row 3, col 2), needing (row 3, col 3) - row
distance 0, column distance 1, total 1, also matching.

This revealed that row-swaps and column-swaps are completely
independent of each other - a row swap only ever changes which row
the 1 is in, never which column, and vice versa. So the minimum
total moves is just the row-distance to the center PLUS the
column-distance to the center, with no interaction between the two
axes to reason about.

Since the array is stored 0-indexed (A[0][0] to A[4][4]) while the
problem describes rows/columns as 1-indexed (center at row 3,
column 3), adjusted by using 2 as the center reference for the
0-indexed posi/posj directly, rather than converting posi/posj to
1-indexed first - both approaches give the same result, but adjusting
the target constant (2 instead of 3) avoided an extra conversion step.

First version computed each axis's distance using an explicit
three-way if-else chain (checking if target > pos, target == pos, or
pos > target, and adding the appropriate difference) - correct, but
recognized as unnecessarily verbose for what is fundamentally just
an absolute value calculation. Replaced both six-branch chains with
abs(2 - posi) + abs(2 - posj) using the standard library's abs()
function (from <cstdlib>), collapsing 12 lines of branching logic
into a single expression with identical results.

====================================================================
COMPLEXITY
====================================================================

1. TIME COMPLEXITY:

nested loop reading 5x5 grid   -> O(25), i.e. O(1) since the grid
                                    size is fixed by the problem,
                                    never variable
abs(2-posi) + abs(2-posj)       -> O(1)

Total: O(1), since the matrix is always exactly 5x5 regardless of
input.

2. SPACE COMPLEXITY:

A[5][5] -> O(1), fixed size regardless of input
posi, posj, moves -> O(1) fixed variables

Total: O(1)

*/
