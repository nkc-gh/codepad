/*
====================================================================
Codeforces 266B - Queue at the School
====================================================================

+------------------------------------------------------------------+
| Difficulty  - 800                                                |
| Date of Submission - 23 November 2026 03:36 AM                   |
| Tags - constructive algorithms, graph matchings,                 |
|         implementation, shortest paths                           |
+------------------------------------------------------------------+

During the break the schoolchildren, boys and girls, formed a queue
of n people in the canteen. Initially the children stood in the order
they entered the canteen. However, after a while the boys started
feeling awkward for standing in front of the girls in the queue and
they started letting the girls move forward each second.

If at time x a boy stands on the i-th position and a girl stands on
the (i+1)-th position, then at time x+1 the i-th position will have
a girl and the (i+1)-th position will have a boy.

Input:
First line: n and t (1 <= n, t <= 50)
Second line: string s of 'B' and 'G'

Output:
String after t seconds.

Examples:
Input:    5 1        Input:    5 2        Input:    4 1
          BGGBG                BGGBG                GGGB
Output:   GBGGB      Output:   GGBGB      Output:   GGGB
====================================================================
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, t;
    cin >> n >> t;

    string s;
    cin >> s;

    for (int i = 0; i < t; i++) {
        for (int l = 0; l + 1 < s.length(); l++) {
            if (s[l] == 'B' && s[l + 1] == 'G') {
                swap(s[l], s[l + 1]);
                l = l + 1;
            }
        }
    }

    cout << s << "\n";
    return 0;
}

/*
====================================================================
SOLUTION IN MY WORDS
====================================================================

Simulation — do what the problem says t times.

Each second: scan left to right, wherever BG appears swap to GB.
Nested loop: outer runs t times, inner does one pass.

Bug 1: used outer loop variable i inside inner loop instead of l.
Bug 2: after swap, did l=l+2 thinking need to skip — but loop
already does l++, so total jump was 3, skipping characters.
Fix: l=l+1 inside + loop's l++ = jump of 2, which is correct
since the swapped G can't form another BG pair immediately.

====================================================================
COMPLEXITY
====================================================================

1. TIME COMPLEXITY:

outer loop t times                -> O(t)
inner loop n times                -> O(n)

Total: O(n*t)

2. SPACE COMPLEXITY:

s -> string of length n.

Total: O(n)
====================================================================
*/