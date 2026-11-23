/*
====================================================================
Codeforces 96A - Football
====================================================================

+------------------------------------------------------------------+
| Difficulty  - 900                                                |
| Date of Submission - 23 November 2026 02:46 AM                   |
| Tags - implementation, strings                                   |
+------------------------------------------------------------------+

Given a string of 0s and 1s representing two teams' players.
If any team has 7 or more players standing consecutively,
the situation is dangerous.

Input:
Single string of '0' and '1', length <= 100

Output:
"YES" if dangerous, "NO" otherwise.

Example:
Input: 001001
Output: NO

Input: 1000000001
Output: YES
====================================================================
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    int count_0 = 0, count_1 = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '0'){
            count_0++;
            count_1 = 0;
        }
        else{
            count_1++;
            count_0 = 0;
        }
        if(count_0 >= 7 || count_1 >= 7){
            cout << "YES\n";
            return 0;
        }
    }

    cout << "NO\n";
    return 0;
}

/*
====================================================================
SOLUTION IN MY WORDS
====================================================================

First idea: two counters count_0 and count_1, increment each
iteration, check after loop. Wrong — counters accumulate across
separate groups, e.g. 000011110000 gives count_0=8 but answer is NO.

Fixed: reset the other counter when you see a character.
See '0' → count_0++, reset count_1. See '1' → count_1++, reset count_0.

Edge case caught: check after increment inside loop, not at top.
If dangerous sequence is at end of string, top-of-loop check misses it.

====================================================================
COMPLEXITY
====================================================================

1. TIME COMPLEXITY:

cin >> s                         -> O(n)
for loop over s.length()         -> O(n)
cout                             -> O(1)

Total: O(n)

2. SPACE COMPLEXITY:

s -> string of length n.

Total: O(n)
====================================================================
*/