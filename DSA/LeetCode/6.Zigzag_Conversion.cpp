/*
====================================================================
LeetCode 6 - Zigzag Conversion
====================================================================

+------------------------------------------------------------------+
| Difficulty - Medium                                              |
| Date of Submission - 25 November 2026 14:08                      |
| Tags - String                                                    |
+------------------------------------------------------------------+

A string is written in a zigzag pattern across numRows rows, then
read line by line. Return the resulting string.

Constraints:
1 <= s.length <= 1000
s consists of English letters (lower-case and upper-case), ',' and '.'
1 <= numRows <= 1000

Example 1:
Input: s = "PAYPALISHIRING", numRows = 3
P   A   H   N
A P L S I I G
Y   I   R
Output: "PAHNAPLSIIGYIR"

Example 2:
Input: s = "PAYPALISHIRING", numRows = 4
P     I    N
A   L S  I G
Y A   H R
P     I
Output: "PINALSIGYAHRPI"

====================================================================
*/

class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> rows(numRows);

        int length = s.length();
        int index = 0;
        if (numRows == 1 || numRows >= s.size())
            return s;
        while(length!=0){
            for(int i=0 ; i<numRows ; i++){
                rows[i]+=s[index];
                index++;
                length-=1;
                if(length==0) break;
                if(i==numRows-1){
                    for(int l=numRows-2 ; l>=1 ; l--){
                        rows[l]+=s[index];
                        index++;
                        length-=1;
                        if(length==0) break;
                    }
                }
            }
        }

        string result = "";
        for(auto& r : rows) result += r;
        return result;
    }
};

/*
====================================================================
SOLUTION IN MY WORDS
====================================================================

Created a vector of numRows empty strings to represent each row.
Used a bouncing pointer approach — traverse the string while going
down rows 0 to numRows-1, then bounce back up from numRows-2 to 1,
then down again, repeat until all characters are placed.

Tracked current position in s using a separate index variable (not
the row counter), since string position always moves forward while
row index bounces back and forth.

Edge cases handled upfront:
- numRows == 1: no zigzag possible, return s directly.
- numRows >= s.size(): more rows than characters, no bounce ever
  happens, result is same as input order, return s directly.

Reverse loop goes from numRows-2 to 1 (not 0, not numRows-1)
because the bottom row (numRows-1) is already handled by the down
loop, and row 0 will be handled by the next iteration of the down
loop. Revisiting them would double-place characters.

length decrements every time a character is placed — in either the
down loop or the reverse loop. Added if(length==0) break in both
to avoid out-of-bounds access on s[index].

At the end, concatenate all row strings into result and return.

Traced "PAYPALISHIRING", numRows=3:
  Down:    row0+=P, row1+=A, row2+=Y
  Bounce:  row1+=P
  Down:    row0+=A, row1+=L, row2+=I
  Bounce:  row1+=S
  Down:    row0+=H, row1+=I, row2+=R
  Bounce:  row1+=I
  Down:    row0+=N, row1+=G
  row0="PAHN", row1="APLSIIG", row2="YIR"
  result = "PAHNAPLSIIGYIR" ✓

====================================================================
COMPLEXITY
====================================================================

1. TIME COMPLEXITY:

while loop + for loops: every character in s is processed
exactly once, either in the down loop or the reverse loop.
length tracks total remaining work and decrements each iteration.
Nested loops do not multiply — they share a single pool of n chars.

Total: O(N)

2. SPACE COMPLEXITY:

vector<string> rows: stores all n characters across numRows strings.

Total: O(N)
*/