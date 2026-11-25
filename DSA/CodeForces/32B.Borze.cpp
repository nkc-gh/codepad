/*
====================================================================
Codeforces - Borze
====================================================================

+------------------------------------------------------------------+
| Difficulty  - 800                                                |
| Date of Submission - 25 November 2026 22:34                      |
| Tags - expression parsing, implementation                        |
+------------------------------------------------------------------+

Ternary digits are encoded in Borze alphabet as:
  0 -> "."
  1 -> "-."
  2 -> "--"

Given a valid Borze-encoded string, decode it back to the ternary number.

Input:
Single line: a string of Borze code (length 1 to 200).

Output:
The decoded ternary number (may have leading zeroes).

Example:
Input: .-.--   -> Output: 012
Input: --.     -> Output: 20
Input: -..-.-- -> Output: 1012

====================================================================
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    string result = "";
    int index = 0;
    while(index < s.length()){
        if(s[index] == '.'){
            result += '0';
            index++;
        }
        else if(s[index] == '-' && s[index+1] == '.'){
            result += '1';
            index += 2;
        }
        else{
            result += '2';
            index += 2;
        }
    }
    cout << result << "\n";
    return 0;
}

/*
====================================================================
SOLUTION IN MY WORDS
====================================================================

Walk the string with an index. At each position check the current char:
- If '.' -> digit is 0, move 1 step.
- If '-' -> look at next char:
    - Next is '.' -> digit is 1, move 2 steps.
    - Next is '-' -> digit is 2, move 2 steps.

Since input is guaranteed valid, no need to handle invalid cases.
The last else covers '--' since if it's not '-.' it must be '--'.

Used s[index] instead of substr(index, 1) to avoid string allocation
overhead on every iteration. substr creates a new string object each
call; direct char access is O(1) with zero allocation.

====================================================================
COMPLEXITY
====================================================================

1. TIME COMPLEXITY:

Each character is visited exactly once — either consumed as a 1-char
token ('.') or as part of a 2-char token ('-.' or '--').

Total: O(n) where n = length of input string.

2. SPACE COMPLEXITY:

result string grows with number of decoded digits, at most n chars.

Total: O(n)
*/