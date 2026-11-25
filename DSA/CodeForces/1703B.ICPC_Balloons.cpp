/*
====================================================================
Codeforces 1703B - ICPC Balloons
====================================================================

+------------------------------------------------------------------+
| Difficulty  - 800                                                |
| Date of Submission - 25 November 2026 22:54                      |
| Tags - data structures, implementation                           |
+------------------------------------------------------------------+

Every time a problem is solved, that team gets 1 balloon.
The first team to solve a problem gets 1 extra balloon.
Given the order of solved problems as a string, find total balloons.

Input:
First line: t (1 <= t <= 100) — number of test cases.
Each test case:
  Line 1: n (1 <= n <= 50) — length of string.
  Line 2: string s of length n (uppercase A-Z).

Output:
For each test case, one integer — total balloons distributed.

Example:
Input: ABA  -> Output: 5  (A=2, B=2, A=1)
Input: ORZ  -> Output: 6  (O=2, R=2, Z=2)

====================================================================
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
    int T;
    cin >> T;

    for(int t=0 ; t<T ; t++){
        int n;
        cin >> n;
        string s;
        cin >> s;
        int solution = 0;
        bool hashtable[26] = {};
        for(int i=0 ; i<n ; i++){
            if(hashtable[s[i]-'A'] == false){
                solution += 2;
                hashtable[s[i]-'A'] = true;
            }
            else{
                solution += 1;
            }
        }
        cout << solution << "\n";
    }

    return 0;
}

/*
====================================================================
SOLUTION IN MY WORDS
====================================================================

For each problem solved, it's always +1 balloon.
Additionally if it's the first time that problem is solved, +1 more.

Maintained a bool array of size 26 (one per problem A-Z) initialized
to false. For each character in the string:
- If not seen before -> +2 balloons, mark as seen.
- If seen before -> +1 balloon only.

Used bool array instead of map since keys are always fixed A-Z.
s[i]-'A' converts the char to a 0-25 index directly.
Array lookup is O(1) with no overhead vs map's O(log n) tree traversal.

====================================================================
COMPLEXITY
====================================================================

1. TIME COMPLEXITY:

For each test case, one pass through string of length n.

Total: O(t * n)

2. SPACE COMPLEXITY:

bool array of fixed size 26, independent of input.

Total: O(1)
*/