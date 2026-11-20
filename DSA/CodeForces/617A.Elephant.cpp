/*
====================================================================
Codeforces 617A - Elephant
====================================================================

+------------------------------------------------------------------+
| Difficulty  - 800                                                |
| Date of Submission - 16 November 2026 02:40 AM                   |
| Tags - maths                                                     |
+------------------------------------------------------------------+

An elephant is at point 0 and wants to reach point x (x > 0).
In one step it can move 1, 2, 3, 4, or 5 positions forward.
Find the minimum number of steps to reach exactly x.

Input:
Single integer x (1 <= x <= 1,000,000)

Output:
Minimum number of steps.

Example:
Input: 12
Output: 3
(can move 5+5+2 or 3+5+4, etc.)
====================================================================
*/

#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int x;
    cin >> x;
    cout << static_cast<int>(ceil(x / 5.0)) << "\n";
    return 0;
}

/*
====================================================================
SOLUTION IN MY WORDS
====================================================================

First idea: brute force — run a loop, subtract 5,4,3,2,1 based on
conditions, increment steps each time. Correct but verbose with
5 if-else branches.

Simplified loop: noticed all those if-else cases collapse into
x -= min(x, 5) — always take the max possible step. This is greedy:
locally best choice (take 5) = globally best (fewest steps).

Eliminated loop entirely: spotted the pattern by hand —
x=1-5  → 1 step
x=6-10 → 2 steps
x=11-15→ 3 steps
Answer is just ceil(x / 5). No loop needed.

Key insight: since all steps cost the same (1 step), always taking
the maximum move (5) is optimal. That's the greedy guarantee here.

Also learned: (x + 4) / 5 is the integer-arithmetic equivalent of
ceil(x / 5), using the general formula (x + n - 1) / n for
rounding up integer division.

====================================================================
COMPLEXITY
====================================================================

1. TIME COMPLEXITY:

cin >> x;                        -> O(1)
ceil(x / 5.0)                    -> O(1)
cout                             -> O(1)

Total: O(1)

2. SPACE COMPLEXITY:

x -> single fixed variable.

Total: O(1)
====================================================================
*/