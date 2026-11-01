/*
====================================================================
CodeChef - Small Factorial (FLOW018) (Difficulty - 700)
====================================================================

Given T test cases, for each test case find the factorial of N.

Constraints:
1 <= T <= 1000
0 <= N <= 20

Input format:
T
N (per test case)

Example:
Input:
3
3
4
5

Output:
6
24
120
====================================================================
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    for(int i=0 ; i<T ; i++){
        int n;
        cin >> n;

        long long fact = 1;

        for(int i=2 ; i<=n ; i++){
            fact *= i;
        }

        cout << fact << "\n";
    }

    return 0;
}

/*
====================================================================
SOLUTION IN MY WORDS
====================================================================

Logic was correct from the start - read N, loop from 2 to N
multiplying into fact, print. The inner loop starting at 2 instead
of 1 is fine since multiplying by 1 changes nothing. N=0 and N=1
are also handled correctly since the loop condition 2<=n is false
for both, fact stays 1, which is correct (0! = 1! = 1).

Got partially correct on first submission - subtask 1 passed,
subtask 2 failed. The logic was not the bug. The issue was data
type - declared fact as int. 20! = 2,432,902,008,176,640,000 which
exceeds int's max of 2,147,483,647. The value silently overflows
and wraps to garbage. Fixed by declaring fact as long long whose
max is 9,223,372,036,854,775,807, which fits 20! comfortably.

====================================================================
COMPLEXITY
====================================================================

1. TIME COMPLEXITY:

cin >> T                          -> O(1)
outer loop over T test cases      -> O(T)
    cin >> n                      -> O(1)
    inner loop from 2 to n        -> O(N)
    cout << fact                  -> O(1)

Total: O(T * N), with T <= 1000 and N <= 20 this is at most 20000
operations, effectively O(1) given fixed constraints.

2. SPACE COMPLEXITY:

T, i, n, fact -> O(1), fixed variables, no arrays or containers

Total: O(1)

3. COMMON MISTAKES PEOPLE MAKE ON THIS PROBLEM:

- Declaring fact as int instead of long long - 20! overflows int
  silently, produces garbage output with no error or warning,
  only caught when large N test cases fail.

- Starting the factorial loop from 1 instead of 2 - not wrong,
  just a redundant multiplication by 1 every iteration.

- Not handling N=0 explicitly - unnecessary here since the loop
  2<=n is false for n=0, fact stays 1, which is correct since
  0! = 1 by definition.
*/