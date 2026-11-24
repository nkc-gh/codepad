/*
====================================================================
LeetCode 709 - To Lower Case
====================================================================

+------------------------------------------------------------------+
| Difficulty  - Easy                                               |
| Date of Submission - 24 November 2026 17:29                      |
| Tags - string                                                    |
+------------------------------------------------------------------+

Given a string s, return the string after replacing every uppercase
letter with the same lowercase letter.

Input:
String s (1 <= s.length <= 100), printable ASCII characters.

Output:
Lowercase version of s.

Examples:
Input: "Hello"  -> Output: "hello"
Input: "here"   -> Output: "here"
Input: "LOVELY" -> Output: "lovely"
====================================================================
*/

class Solution {
public:
    string toLowerCase(string s) {
        for(int i=0 ; i < s.length() ; i++){
            if(s[i]>='A' && s[i]<='Z'){
                s[i] = s[i]+32;
            }
        }

        return s;
    }
};

/*
====================================================================
SOLUTION IN MY WORDS
====================================================================

Loop through every character. If it's uppercase (between 'A' and
'Z'), convert to lowercase by adding 32.

Why 32: In ASCII, 'A' = 65 and 'a' = 97. Difference is 32. So
uppercase + 32 = lowercase for every letter.

Had a bug first: wrote `s = s[i] + 32` which replaced the whole
string with a single char value. Fixed to `s[i] = s[i] + 32` —
assign to the character, not the string.

Also need the bounds check `s[i] >= 'A' && s[i] <= 'Z'` — without
it, adding 32 to already-lowercase letters, digits or symbols would
corrupt them.

Alternative: use transform from <algorithm>:
transform(s.begin(), s.end(), s.begin(), ::tolower);
Both are O(n), transform just hides the loop internally.

====================================================================
COMPLEXITY
====================================================================

1. TIME COMPLEXITY:

for loop runs s.length() times   -> O(n)
if check + s[i]+32               -> O(1) per iteration

Total: O(n)

2. SPACE COMPLEXITY:

No extra variables, modifying s in place.

Total: O(1)
*/