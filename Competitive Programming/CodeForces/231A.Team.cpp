/*
====================================================================
Codeforces 231A - Team (Difficulty - 800)
====================================================================

Three friends - Petya, Vasya, Tonya - decide to implement a problem
only if at least 2 of them are sure about the solution. Given n
problems, and for each problem three 0/1 values indicating whether
each friend is sure, find how many problems they will implement.

Input:
- First line: n (1 <= n <= 1000)
- Next n lines: three integers (each 0 or 1), space-separated

Output:
- Single integer: count of problems where at least 2 of 3 are sure

Example 1:
Input:
3
1 1 0
1 1 1
1 0 0
Output: 2

Example 2:
Input:
2
1 0 0
0 1 1
Output: 1
====================================================================
*/

#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int result = 0;

    for(int i = 0 ; i < n ; i++){
        int a, b, c;
        cin >> a >> b >> c;
        if(a + b + c >= 2){
            result += 1;
        }
    }

    cout << result;
}

/*
====================================================================
SOLUTION IN MY WORDS
====================================================================

Straightforward: for each problem, sum the three 0/1 values. If the
sum is 2 or 3, at least two friends are sure, so it counts. Loop
over n problems and tally a result.

My first version stored each row in an array (int A[3]) before
summing it, since that was my instinct from how I'd think about it
in C. Got asked whether I actually needed to keep the row around
after using it once - I didn't, since the sum is computed and used
immediately within the same iteration. Switched to three plain
variables (a, b, c) instead, declared fresh each loop iteration,
read directly, summed directly. No container needed at all - not
because arrays are wrong here, but because there was nothing to
store past that single iteration's use.

Also caught myself not initializing `result` before the loop -
declared `int result;` with no initializer would have started at
garbage/undefined value rather than 0, and `result += 1` would have
compounded from that garbage rather than from a clean 0.

Discussed a boolean-based alternative: `(a && b) || (b && c) ||
(a && c)` - checking if any pair simultaneously agrees, logically
equivalent to "sum >= 2" for 0/1 inputs. Confirmed both are O(n)
time overall with no meaningful speed difference between `+` and
`&&`/`||`  at this scale - stuck with the sum-based version since
it reads more directly as "how many are sure."

====================================================================
COMPLEXITY
====================================================================

1. TIME COMPLEXITY:

int n; cin >> n;                    -> O(1)
for loop runs n times                -> O(n) iterations
    int a, b, c; cin >> a >> b >> c; -> O(1) per iteration
    if(a+b+c >= 2) result += 1;      -> O(1) per iteration

Total: O(n) - must read every problem's 3 values at least once,
so this is optimal; no faster approach exists.

2. SPACE COMPLEXITY:

n, result, a, b, c -> fixed number of primitive int variables,
reused/reassigned each iteration, no growing container.

Total: O(1)

3. COMMON MISTAKES PEOPLE MAKE ON THIS PROBLEM:

- Forgetting to initialize `result` to 0 before the loop, leading
  to undefined/garbage starting value.

- Storing each row in an array unnecessarily (int A[3]) when the
  three values are only ever used immediately within that same
  iteration - not wrong, just unneeded overhead.

- Off-by-one in the loop bound (e.g. i <= n instead of i < n),
  causing an extra unwanted read that misaligns with remaining
  input or causes undefined behavior at EOF.

- Checking `a + b + c == 2` instead of `>= 2`, missing the case
  where all three are sure (sum = 3).
*/