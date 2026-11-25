/*
====================================================================
Codeforces 160A - Twins
====================================================================

+------------------------------------------------------------------+
| Difficulty  - 900                                                |
| Date of Submission - 25 November 2026 23:20                      |
| Tags - greedy, sortings                                          |
+------------------------------------------------------------------+

Given n coins, pick the minimum number of coins such that your sum
is strictly greater than the sum of the remaining coins.

Input:
Line 1: n (1 <= n <= 100)
Line 2: n integers a1, a2, ..., an (1 <= ai <= 100)

Output:
Single integer — minimum number of coins needed.

Example:
Input: 3 3     -> Output: 2  (3+3=6 > 0, but 3 not > 3, need both)
Input: 2 1 2   -> Output: 2  (2+2=4 > 1)

====================================================================
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    int total = 0;
    vector<int> arr(n);
    for(int i=0 ; i<n ; i++){
        cin >> arr[i];
        total += arr[i];
    }
    sort(arr.begin(), arr.end());
    int solution = 0;
    int coins = 0;
    int index = n-1;
    while(solution <= (total/2)){
        solution += arr[index];
        coins++;
        index--;
    }
    cout << coins << "\n";
    return 0;
}

/*
====================================================================
SOLUTION IN MY WORDS
====================================================================

Need my sum > twin's sum, which means my sum > total - my sum,
which simplifies to my sum > total/2.

Greedy insight: to minimize the number of coins picked, always pick
the largest available coin first. Sorting ascending and iterating
from the back gives largest coins first.

Keep adding largest coins until sum > total/2, count how many taken.

Integer division works correctly here:
- total=5 -> total/2=2, need sum > 2, so sum >= 3 (correct, need > 2.5)
- total=6 -> total/2=3, need sum > 3, so sum >= 4 (correct, need > 3)

====================================================================
COMPLEXITY
====================================================================

1. TIME COMPLEXITY:

Sorting: O(n log n)
Greedy pass: O(n)

Total: O(n log n)

2. SPACE COMPLEXITY:

vector of size n.

Total: O(n)
*/