/*
====================================================================
Codeforces 158A - Next Round
====================================================================

+------------------------------------------------------------------+
| Dificulty - 800                                                  |
| Date of Submission - 13 September 14:53 PM                       |
| Tags - special problem, implementation                           |
+------------------------------------------------------------------+

n participants took part in a contest, scores given in non-
increasing order. A participant advances to the next round if their
score is greater than or equal to the score of the participant in
k-th place, AND their score is strictly positive (a score of 0
never advances, even if the k-th place score is also 0).

Constraints:
1 <= k <= n <= 50
0 <= ai <= 100
Scores given in non-increasing order (a1 >= a2 >= ... >= an)

Example 1:
Input: n=8, k=5 / 10 9 8 7 7 7 5 5
Output: 6
(k-th place score is 7; six people have score >= 7: the two 5s
don't qualify)

Example 2:
Input: n=4, k=2 / 0 0 0 0
Output: 0
(k-th place score is 0; nobody has a positive score, so nobody
advances despite everyone tying the threshold)
====================================================================
*/

#include <iostream>
using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    int a[n];
    int total = 0;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    
    for(int i=0;i<n;i++){
        if(a[i]>=a[k-1] && a[i]>0){
            total++;
        }
    }

    cout << total << endl;
    
    return 0;
}

/*
====================================================================
SOLUTION IN MY WORDS
====================================================================

The problem statement's wording ("earns a score equal to or greater
than the k-th place finisher's score, as long as the score is positive") was harder to parse than the actual logic once decoded - took a moment to see this is really just two separate conditions ANDed together: score >= threshold, AND score > 0. The second condition matters independently, since a threshold of 0 (everyone tied at 0, as in example 2) would otherwise let everyone "advance" under the first condition alone.

First attempt read input with a 1-indexed loop (for i=1 to n
inclusive) into an array declared as a[n], which only has valid
indices 0 to n-1 - writing to a[n] at the last iteration goes one
past the end of the array (out-of-bounds write), undefined
behavior.

Fixed the indexing to 0-based (for i=0; i<n), but this exposed a
second, more subtle bug: the threshold check (a[i] >= a[k-1]) was
happening inside the SAME loop that was still reading input. For
k=5, that means comparing against a[4] before a[4] has necessarily
been read yet (i.e. while the loop is still at i=0,1,2,3) - this
reads an uninitialized array slot, which is undefined behavior, not
a null or zero value. Ran the code anyway and got the correct
output despite this - a reminder that undefined behavior can appear
to "work" by coincidence on a given run/compiler, but is not
actually correct or reliable, since the same code could produce a
different (wrong) answer on a different machine, compiler, or input
where the garbage value happens to matter.

Fixed properly by splitting into two separate loops: first fully
reads all n scores into the array, then a second loop computes the
threshold-and-positivity check against the now-fully-populated
array. This guarantees a[k-1] holds its real, final value before
any comparison is made against it.

Also had a bracket-matching syntax error along the way
(if((a[i]>=a[k-1] && a[i]>0){ - one extra unmatched opening
parenthesis before a[i]) - caught by carefully counting parens
before compiling rather than after a compiler error.

====================================================================
COMPLEXITY
====================================================================

1. TIME COMPLEXITY:

cin >> n >> k                -> O(1)
first loop, reads n scores    -> O(n)
second loop, n comparisons    -> O(n)

Total: O(n), with n <= 50 this is trivially fast.

2. SPACE COMPLEXITY:

a[n] -> O(n) to store the scores
n, k, total -> O(1) fixed extra variables

Total: O(n)

*/
