/*
====================================================================
Codeforces 750A - New Year and Hurry
====================================================================
 
+------------------------------------------------------------------+
| Difficulty  - 800                                                |
| Date of Submission - 26 November 2026 17:46                      |
| Tags - binary search, brute force, implementation, math          |
+------------------------------------------------------------------+
 
Contest starts at 20:00, lasts 240 minutes (until midnight).
Problem i takes 5*i minutes. Limak needs k minutes to travel.
Find max problems solvable before needing to leave.
 
Input:
Two integers n and k (1 <= n <= 10, 1 <= k <= 240)
 
Output:
One integer — max problems Limak can solve.
 
Example:
Input: 3 222  ->  Output: 2
Input: 4 190  ->  Output: 4
Input: 7 1    ->  Output: 7
 
====================================================================
*/
 
#include <iostream>
using namespace std;
 
int main() {
    int n, k;
    cin >> n >> k;
 
    int problems = 0;
    int remaining = 240;
    for(int i=1 ; i<=n ; i++){
        remaining -= (5*i);
        if(remaining >= k){
            problems++;
        }
        else break;
    }
 
    cout << problems << "\n";
    return 0;
}
 
/*
====================================================================
SOLUTION IN MY WORDS
====================================================================
 
Total available time = 240 minutes. Each problem i costs 5*i minutes.
Iterated from problem 1 to n, subtracting cost each time.
If remaining time >= k (travel time), Limak can solve it and go.
As soon as remaining < k, he can't solve the next problem — stop.
 
Greedy: always try the next easiest problem first (they're sorted
by difficulty = time cost), so stopping at first failure is correct.
 
====================================================================
COMPLEXITY
====================================================================
 
1. TIME COMPLEXITY: O(N) — at most 10 iterations (n <= 10)
2. SPACE COMPLEXITY: O(1)
====================================================================
*/