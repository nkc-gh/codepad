/*
====================================================================
Codeforces 4A - Watermelon
====================================================================

Pete and Billy have a watermelon weighing w kilos. They want to
split it into two parts such that each part weighs an even number
of kilos (parts don't need to be equal), and each part must have
positive weight.

Determine if such a split is possible.

Input:
Single integer w (1 <= w <= 100)

Output:
"YES" if the watermelon can be split as described, "NO" otherwise.

Example:
Input: 8
Output: YES
(can be split as 2+6, or 4+4)
====================================================================
*/

#include <iostream>
using namespace std;

int main() {
    int x;
    cin >> x;
    if(x >= 4 && x % 2 == 0){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
    return 0;
}

/*
====================================================================
SOLUTION IN MY WORDS
====================================================================

First wrong idea: just check `x % 2 == 0`. Seemed obviously right -
"even number splits into two even numbers," right? Tested it on
w=2 by hand: 2 is even, so my condition says YES. But the only way
to split 2 into two positive parts is 1+1, and 1 is odd. So w=2 is
a counterexample - my condition passes it but the real answer is NO.

Second wrong idea: check `x % 4 == 0`. Tested on w=6: 6%4 = 2, not
0, so my code would say NO. But 6 can actually be split as 2+4,
both positive and even, so the real answer is YES. Another
counterexample - %4 is too strict, rejects valid cases.

Went back to basics: two even numbers always sum to an even number,
so any odd w is automatically impossible - already ruled out right
there. Among even numbers, checked the smallest ones by hand:
- w=2: only split is 1+1, one part is odd, so NO
- w=4: split is 2+2, both even and positive, so YES
- w=6: split is 2+4, both even and positive, so YES

Pattern: every even w works except w=2, because for any even w>=4,
you can always split it as 2 + (w-2), and (w-2) stays even and
positive.

So the real condition is: w must be even AND w >= 4. Combined that
into `x >= 4 && x % 2 == 0`.

Also had to actually remember `cin >> x;` - forgot it once again
(same trap as the New Year Resolution problem), caught myself this
time before running it.

====================================================================
COMPLEXITY
====================================================================

1. TIME COMPLEXITY:

int x;                     -> O(1)
cin >> x;                   -> O(1)
if(x >= 4 && x % 2 == 0)     -> O(1), fixed number of comparisons
    cout << "YES";           -> O(1)
else
    cout << "NO";             -> O(1)

Per README rule 1 (single operations) - no loop, no recursion, pure
straight-line constant-time code regardless of the value of w.

Total: O(1)

2. SPACE COMPLEXITY:

x -> single fixed variable, no array/container.

Per README space rule 1 -> O(1)

Total: O(1)

3. COMMON MISTAKES PEOPLE MAKE ON THIS PROBLEM:

- Checking only `w % 2 == 0`, missing that w=2 is a special
  exception (only decomposes into 1+1, which isn't two even parts).
  This is the single most common mistake on this exact problem.

- Trying to actually search for a valid split (looping through
  possible pairs) instead of realizing the whole problem reduces to
  one simple condition - unnecessary complexity for a *800 problem.

- Off-by-one on the boundary: using `w > 4` instead of `w >= 4`,
  incorrectly excluding w=4 (which is a valid YES case, split as
  2+2).

- Forgetting `cin >> w;` before using the variable - compiles fine,
  runs, gives wrong/garbage output silently.
*/