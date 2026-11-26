/*
====================================================================
Codeforces 381A - Sereja and Dima
====================================================================
 
+------------------------------------------------------------------+
| Difficulty  - 800                                                |
| Date of Submission - 26 November 2026 17:28                      |
| Tags - greedy, implementation, two pointers                      |
+------------------------------------------------------------------+
 
n cards in a row, all distinct values. Two players take turns
(Sereja first). Each turn, a player picks the larger of the two
end cards. Find final scores of both players.
 
Input:
First line: n (1 <= n <= 1000)
Second line: n space-separated integers (distinct, 1 to 1000)
 
Output:
Two integers — Sereja's score and Dima's score.
 
Example:
Input: 4 / 4 1 2 10  ->  Output: 12 5
Input: 7 / 1 2 3 4 5 6 7  ->  Output: 16 12
 
====================================================================
*/
 
#include <iostream>
#include <vector>
using namespace std;
 
int main() {
    int n;
    cin >> n;
 
    vector<int> arr(n);
    for(int i=0 ; i<n ; i++){
        cin >> arr[i];
    }
 
    int a=0, b=n-1;
    int sereja=0, dima=0;
 
    for(int i=0 ; i<n ; i++){
        if((i+1)%2==0){
            if(arr[a]>arr[b]){
                dima+= arr[a];
                a++;
            }
            else{
                dima+= arr[b];
                b--;
            }
        }
        else{
            if(arr[a]>arr[b]){
                sereja+= arr[a];
                a++;
            }
            else{
                sereja+= arr[b];
                b--;
            }
        }
    }
 
    cout << sereja << " " << dima << "\n";
    return 0;
}
 
/*
====================================================================
SOLUTION IN MY WORDS
====================================================================
 
Used two pointers a (left) and b (right) on the array.
Each turn, the current player picks whichever end is larger.
Turn number tracked by loop index i:
- (i+1) % 2 == 0 -> Dima's turn
- else -> Sereja's turn
After picking, the corresponding pointer moves inward.
Repeated for all n turns.
 
Traced [4,1,2,10], pivot=10:
  Turn 1 (Sereja): arr[0]=4 vs arr[3]=10 -> picks 10, b=2, sereja=10
  Turn 2 (Dima):   arr[0]=4 vs arr[2]=2  -> picks 4,  a=1, dima=4
  Turn 3 (Sereja): arr[1]=1 vs arr[2]=2  -> picks 2,  b=1, sereja=12
  Turn 4 (Dima):   arr[1]=1              -> picks 1,  dima=5
  Result: 12 5 ✓
 
====================================================================
COMPLEXITY
====================================================================
 
1. TIME COMPLEXITY: O(N) — single pass, n turns total
2. SPACE COMPLEXITY: O(N) — vector storing input
   Note: could use plain int arr[1000] for O(1) since n <= 1000
   and size is known upfront.
====================================================================
*/
