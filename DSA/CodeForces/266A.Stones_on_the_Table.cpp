/*
====================================================================
Codeforces 266A - Stones on the Table
====================================================================

+------------------------------------------------------------------+
| Difficulty  - 800                                                |
| Date of Submission - 23 November 2026 02:00 AM                   |
| Tags - implementation                                            |
+------------------------------------------------------------------+

There are n stones on the table in a row, each can be R, G, or B.
Count the minimum number of stones to remove so that no two
neighboring stones have the same color.

Input:
First line: integer n (1 <= n <= 50)
Second line: string s of length n containing 'R', 'G', 'B'

Output:
Single integer — minimum stones to remove.

Example:
Input: 3, RRG
Output: 1

Input: 5, RRRRR
Output: 4

Input: 4, BRBG
Output: 0
====================================================================
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    int output = 0;
    for(int i = 0; i < s.length() - 1; i++){
        if(s[i] == s[i+1]){
            output++;
        }
    }
    cout << output << "\n";
    return 0;
}

/*
====================================================================
SOLUTION IN MY WORDS
====================================================================

First idea: track groups — check if same color repeats, handle
groups separately. Overcomplicated, not needed.

Simplified: every time s[i] == s[i+1], that's one removal.
No need to actually remove from string — each adjacent conflict
counts as exactly 1 removal regardless of group size.

Key insight: for RRR — 2 conflicts, 2 removals. Removing doesn't
change the conflict count, so just count adjacent same-color pairs.

Also learned: s[i+1] when i is last index gives '\0' in C++ which
won't match R/G/B — works by luck but UB. Fix: loop till
s.length() - 1, not s.length().

====================================================================
COMPLEXITY
====================================================================

1. TIME COMPLEXITY:

cin >> n, s;                     -> O(n)
for loop over s.length()-1       -> O(n)
cout                             -> O(1)

Total: O(n)

2. SPACE COMPLEXITY:

s -> string of length n.

Total: O(n)
====================================================================
*/