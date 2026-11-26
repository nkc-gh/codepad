/*
====================================================================
LeetCode 3760 - Maximum Substrings With Distinct Start
====================================================================
 
+------------------------------------------------------------------+
| Difficulty - Medium                                              |
| Date of Submission - 26 November 2026 16:15                      |
| Tags - Greedy, Hash Table, String                                |
+------------------------------------------------------------------+
 
Given a string s of lowercase English letters, return the maximum
number of substrings you can split s into such that each substring
starts with a distinct character.
 
Constraints:
1 <= s.length <= 10^5
s consists of lowercase English letters.
 
Example 1:
Input: s = "abab"   Output: 2
 
Example 2:
Input: s = "abcd"   Output: 4
 
Example 3:
Input: s = "aaaa"   Output: 1
 
====================================================================
*/
 
class Solution {
public:
    int maxDistinct(string s) {
        bool hashtable[26] = {};
        int output = 0;
        for(int i=0 ; i<s.length() ; i++){
            if(hashtable[s[i]-97]==false){
                output++;
                hashtable[s[i]-97]=true;
            }
        }
 
        return output;
    }
};
 
/*
====================================================================
SOLUTION IN MY WORDS
====================================================================
 
Each substring must start with a distinct character, so we just need
to count how many distinct characters appear in s — that's the max
number of substrings possible (greedily start a new substring every
time we see a new character).
 
Used a bool array of size 26 (one per lowercase letter) initialized
with {} (zero-init = all false). For each character, check if seen:
- Not seen -> increment count, mark as seen.
- Already seen -> skip.
Index mapping: s[i] - 97 (since 'a' = ASCII 97) maps char to 0-25.
 
====================================================================
COMPLEXITY
====================================================================
 
1. TIME COMPLEXITY: O(N) — single pass through string
2. SPACE COMPLEXITY: O(1) — fixed size array of 26 bools
====================================================================
*/