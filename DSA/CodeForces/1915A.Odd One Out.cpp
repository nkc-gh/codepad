/*
====================================================================
Codeforces 1915A - Odd One Out
====================================================================

+------------------------------------------------------------------+
| Difficulty  - 800                                                |
| Date of Submission - 24 November 2026 16:48                      |
| Tags - bitmasks, implementation                                  |
+------------------------------------------------------------------+

You are given three digits a, b, c. Two of them are equal, but the
third one is different from the other two.
Find the value that occurs exactly once.

Input:
First line: t (1 <= t <= 270) — number of test cases.
Each test case: three digits a, b, c (0 <= a, b, c <= 9).

Output:
For each test case, output the value that occurs exactly once.

Example:
Input: 1 2 2  -> Output: 1
Input: 4 3 4  -> Output: 3
====================================================================
*/

#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    for(int i=0 ; i<t ; i++){
        int a,b,c;
        cin >> a >> b >> c;

        cout << (a^b^c) << "\n";
    }
    return 0;
}

/*
====================================================================
SOLUTION IN MY WORDS
====================================================================

First idea: check which two are equal using if-else, then print the
third one. That works fine — three cases: a==b, b==c, else.

Then learned a cleaner approach using XOR.

XOR works bitwise. Key properties:
- x ^ x = 0  (same number cancels out)
- x ^ 0 = x  (XOR with 0 returns the number itself)

So for a^b^c, the two equal numbers cancel each other to 0,
and the unique number XORed with 0 just returns itself.

Example: 1, 2, 2
- 1 in binary = 01
- 2 in binary = 10
- 1^2 = 11 = 3
- 3^2 = 11^10 = 01 = 1 ✓

XOR is also associative, so order doesn't matter.

One gotcha: operator precedence. `<<` has higher precedence than `^`
so `cout << a^b^c` parses wrong. Need parentheses: `cout << (a^b^c)`.

====================================================================
COMPLEXITY
====================================================================

1. TIME COMPLEXITY:

cin >> a >> b >> c;    -> O(1)
cout << (a^b^c);       -> O(1), single XOR operation

Total: O(t) — one pass through t test cases.

2. SPACE COMPLEXITY:

a, b, c, t, i -> fixed variables, no array/container.

Total: O(1)
*/