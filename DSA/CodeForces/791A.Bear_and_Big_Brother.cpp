/*
====================================================================
Codeforces 791A - Bear and Big Brother (Difficulty - 800)
====================================================================

Limak weighs a and Bob weighs b. Each year Limak's weight triples
and Bob's weight doubles. Find how many years until Limak is
strictly heavier than Bob.

Constraints:
1 <= a <= b <= 10

Input format:
a b

Example 1:
Input: 4 7
Output: 2

Example 2:
Input: 4 9
Output: 3

Example 3:
Input: 1 1
Output: 1
====================================================================
*/

#include <iostream>
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;

    int years = 0;
    while(a <= b){
        a *= 3;
        b *= 2;
        years += 1;
    }

    cout << years << "\n";

    return 0;
}

/*
====================================================================
SOLUTION IN MY WORDS
====================================================================

First attempt tried to find a direct mathematical formula - 1 + (b/a).
Traced it on all three examples: gave 2, 3, 2. Third example should
be 1, so the formula fails. The problem with a formula is that the
growth rates are different each year - Limak triples, Bob doubles -
so the ratio between them changes every year in a non-linear way.
No simple closed form captures this.

Correct approach is simulation. Loop each year, multiply a by 3
and b by 2, increment year counter, stop when Limak is strictly
larger than Bob.

First submission with simulation got wrong answer on a=4, b=9.
Traced: a goes 4, 12, 36 and b goes 9, 18, 36. After year 2 both
are 36. Loop condition was while(b>a) which is while(36>36) = false,
so loop exited after 2 years and printed 2. But the answer is 3
because equal weights don't satisfy strictly larger. Fixed by
changing condition to while(a<=b) - loop continues as long as
Limak is not strictly larger, so it runs one more iteration when
weights are equal.

====================================================================
COMPLEXITY
====================================================================

1. TIME COMPLEXITY:

Each year a is multiplied by 3 and b by 2. Since a <= b <= 10,
the maximum iterations needed is small and bounded. After k years
a = a0 * 3^k and b = b0 * 2^k. We need 3^k/2^k = (3/2)^k > b0/a0.
With a0=1, b0=10, (3/2)^k > 10 is satisfied at k=6. So at most
a handful of iterations regardless of input.

Total: O(1) given fixed constraints (a,b <= 10)

2. SPACE COMPLEXITY:

a, b, years -> O(1), three fixed variables

Total: O(1)

3. COMMON MISTAKES PEOPLE MAKE ON THIS PROBLEM:

- Trying to find a direct mathematical formula instead of
  simulating - the different growth rates make a clean formula
  difficult and error prone.

- Using while(b>a) instead of while(a<=b) - these look equivalent
  but aren't. when a==b, b>a is false so the loop exits early,
  missing the case where weights are equal and one more year is
  needed since the problem requires strictly greater.

- Integer overflow concern - not an issue here since a,b <= 10
  and only a handful of iterations occur before Limak overtakes
  Bob, but in a version with larger constraints long long would
  be needed.
*/