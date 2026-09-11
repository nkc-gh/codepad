/*
====================================================================
CodeChef - Reach Weight (REACHWT)
====================================================================

Buy weights totaling exactly N kg. 1 kg weights cost 20 rupees each,
2 kg weights cost 30 rupees each. Find the minimum cost to reach
exactly N kg.

Constraints:
1 <= T <= 100
1 <= N <= 100

Example 1:
Input:
3
1
2
3
Output:
20
30
50
====================================================================
*/

#include <bits/stdc++.h>
using namespace std;
int main() {
	int T;
	cin >> T;
	
	for (int i = 0 ; i < T ; i++){
	    int N;
	    cin >> N;
	    
	    if(N%2==0){
	        cout << (N/2) * 30 << endl;
	    }
	    
	    else{
	        cout << (((N-1)/2) * 30) + 20 << endl; 
	    }
	}
	
	return 0;
}

/*
====================================================================
SOLUTION IN MY WORDS
====================================================================

My first instinct was recursion - treat cost(N) like a sum-of-
natural-numbers style recursion, with cost(1)=20 and cost(2)=30 as
base cases, and cost(N) = cost(N-1) for anything above that. This
was wrong: cost(N-1) alone doesn't account for the cost of the extra
kg you added to go from N-1 to N - it just silently drops that cost,
so cost(3) incorrectly evaluated to the same as cost(2) = 30 instead
of 50.

Tried patching it with cost(N-1) + money, where money was declared
as 0 and never updated - same bug in a different shape, still adding
nothing.

Got redirected to think about the problem physically instead of
forcing a recursive shape onto it: compare cost per kg. A 1kg weight
is 20 rupees/kg. A 2kg weight is 15 rupees/kg. Since 2kg weights are
strictly cheaper per kg, the optimal strategy is to use as many 2kg
weights as possible, and only fall back to a single 1kg weight if N
is odd (since you can't make an odd total using only even-sized 2kg
weights).

This reduces to a simple parity check with no recursion needed:
- If N is even: N/2 weights of 2kg each, cost = (N/2)*30
- If N is odd: one 1kg weight (20) plus (N-1)/2 weights of 2kg
  (since N-1 is now even), cost = ((N-1)/2)*30 + 20

Verified against samples: N=1 (odd) -> (0)*30 + 20 = 20. N=2 (even)
-> 1*30 = 30. N=3 (odd) -> 1*30 + 20 = 50. All match.

====================================================================
COMPLEXITY
====================================================================

1. TIME COMPLEXITY:

int T; cin >> T;                 -> O(1)
for loop runs T times             -> O(T) iterations
    int N; cin >> N;              -> O(1) per iteration
    if/else + arithmetic + cout   -> O(1) per iteration

Total: O(T) - constant work per test case, T test cases.

2. SPACE COMPLEXITY:

T, N -> fixed primitive variables, no containers, no recursion
stack (recursion was abandoned in favor of direct arithmetic).

Total: O(1)

3. COMMON MISTAKES PEOPLE MAKE ON THIS PROBLEM:

- Reaching for recursion or a greedy simulation loop (repeatedly
  subtracting 2 then 1) when a direct parity-based formula solves
  it in O(1) per test case.

- Recursive attempts that reduce N by 1 each call without adding
  the cost of that reduction step, silently losing money in the
  calculation (cost(N-1) instead of cost_of_1kg + cost(N-1)).

- Not comparing cost-per-kg between the two weight options first,
  leading to a wrong assumption about which weight to prioritize.

- Forgetting to handle the odd-N case separately, assuming all N
  can be reached using only 2kg weights.
*/