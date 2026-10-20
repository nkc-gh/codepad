/*
====================================================================
CodeChef - Subscriptions (SUBSCRIBE_) (Difficulty - 504)
====================================================================

N friends want to buy Chef-TV subscriptions. One subscription can
be shared by up to 6 people and costs X rupees. Find the minimum
total cost so that every friend is covered.

Constraints:
1 <= T <= 1000
1 <= N <= 100
1 <= X <= 1000

Input format:
T
N X (per test case)

Example:
Input:
3
1 100
12 250
16 135

Output:
100
500
405
====================================================================
*/

#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int N, X;
        cin >> N >> X;

        cout << ((N + 5) / 6) * X << '\n';
    }

    return 0;
}

/*
====================================================================
SOLUTION IN MY WORDS
====================================================================

Read T first, then loop T times. Each iteration reads N (friends)
and X (cost per subscription) and prints the minimum total cost.

First instinct: divide N by 6 and multiply by X. Traced N=12,
X=100: 12/6 = 2 subscriptions, 2*100 = 200. Works perfectly
because 12 is divisible by 6 with no remainder.

Problem: traced N=13. Integer division gives 13/6 = 2, but 2
subscriptions only cover 12 friends - the 13th is left out. Need 3
subscriptions, but plain division gives 2. This is the ceiling
division problem: I need to round UP whenever there is a remainder,
not discard it as integer division does.

Recognized this as the standard ceiling division pattern. General
formula for ceiling division of N by K with positive integers:
(N + K - 1) / K. Here K = 6, so:
(N + 6 - 1) / 6 = (N + 5) / 6.

Why the +5 works: adding 5 before dividing by 6 ensures that any
remainder (1 through 5) pushes the result up to the next whole
number. If N is already a multiple of 6, adding 5 still leaves the
division result unchanged - traced N=12: (12+5)/6 = 17/6 = 2
(integer division, since 17/6 = 2.8... truncates to 2). Correct:
12 friends need exactly 2 subscriptions.

Traced N=13: (13+5)/6 = 18/6 = 3. Correct: 13 friends need 3
subscriptions (covering spots 1-6, 7-12, 13).

Traced N=16 (sample 3): (16+5)/6 = 21/6 = 3, cost = 3*135 = 405.
Matches expected output.

====================================================================
COMPLEXITY
====================================================================

1. TIME COMPLEXITY:

cin >> T                          -> O(1)
for loop over T test cases        -> O(T)
    cin >> N >> X                    -> O(1)
    (N + 5) / 6 * X                  -> O(1), fixed arithmetic
    cout << ...                        -> O(1)

Total: O(T), constant work per test case.

2. SPACE COMPLEXITY:

T, i, N, X -> O(1), four fixed integer variables, no arrays or
              containers of any kind

Total: O(1)

3. COMMON MISTAKES PEOPLE MAKE ON THIS PROBLEM:

- Using plain integer division (N / 6) without ceiling adjustment -
  this undercounts subscriptions whenever N is not a multiple of 6,
  leaving some friends uncovered with no error or warning.

- Reaching for floating-point (ceil((float)N / 6)) instead of the
  integer ceiling formula (N + 5) / 6 - both produce correct
  results, but the integer version is simpler, avoids floating-point
  precision issues, and is the standard competitive-programming
  technique.

- Getting the ceiling formula wrong - the correct formula for
  ceiling division of N by K is (N + K - 1) / K. Using (N + K) / K
  overcounts by one for exact multiples (e.g. N=12 would give
  (12+6)/6 = 3 instead of 2).

- Forgetting the T loop entirely, or reading N and X only once
  outside the loop and reusing them across all test cases.
*/