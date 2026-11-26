/*
====================================================================
Codeforces 318A - Even Odds
====================================================================
 
+------------------------------------------------------------------+
| Difficulty  - 900                                                |
| Date of Submission - 26 November 2026 18:18                      |
| Tags - math                                                      |
+------------------------------------------------------------------+
 
Given first n natural numbers rearranged as: all odds ascending,
then all evens ascending. Find the number at position k.
 
Input:
Two integers n and k (1 <= k <= n <= 10^12)
Use cin/cout (not %lld).
 
Output:
The number at position k.
 
Example:
Input: 10 3  ->  Output: 5
Input: 7 7   ->  Output: 6
 
Note: n=10 sequence: {1,3,5,7,9,2,4,6,8,10}
 
====================================================================
*/
 
#include <iostream>
using namespace std;
 
int main() {
    long long n, k;
    cin >> n >> k;
 
    long long odd = (n+1)/2;
 
    if(k > odd){
        long long ap = 2 * (k - odd);
        cout << ap << "\n";
    }
    else{
        long long ap = 1 + (k-1) * 2;
        cout << ap << "\n";
    }
 
    return 0;
}
 
/*
====================================================================
SOLUTION IN MY WORDS
====================================================================
 
Sequence = [all odds 1..n] then [all evens 1..n].
Count of odd numbers from 1 to n = (n+1)/2.
Count of even numbers from 1 to n = n/2.
 
If k <= odd count -> answer is in the odd section.
  kth odd number (AP: first=1, diff=2) = 1 + (k-1)*2
 
If k > odd count -> answer is in the even section.
  Position in even section = k - odd_count
  kth even number (AP: first=2, diff=2) = 2 * (k - odd_count)
 
Used long long throughout since n <= 10^12 overflows int (max ~2*10^9).
 
====================================================================
COMPLEXITY
====================================================================
 
1. TIME COMPLEXITY: O(1) — pure math, no loops
2. SPACE COMPLEXITY: O(1)
====================================================================
*/