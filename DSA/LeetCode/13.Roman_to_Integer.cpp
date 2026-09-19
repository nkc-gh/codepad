/*
====================================================================
LeetCode 13 - Roman to Integer (Easy)
====================================================================

Roman numerals use symbols I, V, X, L, C, D, M with fixed values
1, 5, 10, 50, 100, 500, 1000. Normally written largest to smallest
left to right and summed. Six exceptions use subtraction when a
smaller symbol precedes a larger one: IV=4, IX=9, XL=40, XC=90,
CD=400, CM=900.

Given a valid roman numeral string, convert it to an integer.

Constraints:
1 <= s.length <= 15
s contains only I, V, X, L, C, D, M
s is guaranteed a valid roman numeral in [1, 3999]

Example 1:
Input: s = "III"
Output: 3

Example 2:
Input: s = "LVIII"
Output: 58

Example 3:
Input: s = "MCMXCIV"
Output: 1994
====================================================================
*/

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> val;
        val['I'] = 1;
        val['V'] = 5;
        val['X'] = 10;
        val['L'] = 50;
        val['C'] = 100;
        val['D'] = 500;
        val['M'] = 1000;

        int total = 0;

        for(int i = 0; i < s.length();){
            if(i == s.length() - 1){
                total += val[s[i]];
                break;
            }
            else if(val[s[i]] >= val[s[i+1]]){
                total += val[s[i]];
                i++;
            }
            else{
                total += val[s[i+1]] - val[s[i]];
                i = i + 2;
            }
        }

        return total;
    }
};

/*
====================================================================
SOLUTION IN MY WORDS
====================================================================

Started by testing whether plain addition of every symbol's value
works. Checked "LVIII": 50+5+1+1+1=58, matches the expected output
- so plain summing works when symbols go largest to smallest.

Then tested plain addition on "IV": 1+5=6, but the real answer is 4.
This is the subtractive case the problem describes - it only breaks
when a smaller-value symbol sits directly before a bigger one.

Generalized the rule using current vs next instead of memorizing
specific letter pairs (I-before-V, X-before-L, etc):
- if value(current) < value(next): this pair contributes
  value(next) - value(current), consume both symbols (jump by 2)
- else: this pair contributes just value(current), consume one
  symbol (jump by 1)

Checked that this scales correctly regardless of how big the gap
is - IV gives 5-1=4, XC gives 100-10=90, CM gives 1000-100=900, all
correct without special-casing per pair.

To look up a symbol's numeric value, needed a way to map a character
(not a sequential index) to a value - learned about unordered_map
here for the first time, syntax: declare with
unordered_map<char,int>, assign with map[key]=value, read with
map[key]. Chained it as val[s[i]] - s[i] pulls the character at
position i from the string (normal array-style indexing), then
val[...] looks up that character's numeric value (map-style keyed
indexing) - two separate indexing operations chained together.

Debugging history, in order:
1. First attempt used a while loop with i incrementing by 1 or 2
   inside, but never guarded against i+1 going out of bounds at the
   last character - crashes/undefined behavior when reading past
   the end of the string.
2. Also had val[s[i]] > val[s[i+1]] as the "subtract" condition,
   which is backwards - equal values (like I,I in "III") fell into
   the subtractive else branch and incorrectly computed 1-1=0
   instead of adding both normally. Fixed by using >= to route
   "equal or bigger" into the add-normally branch.
3. Switched to a for loop but initially still auto-incremented in
   the for header (i++) while ALSO incrementing manually inside the
   body - double-increment bug, same root cause as an earlier
   problem (variable changing more than once per logical step).
   Fixed by leaving the for loop's third slot empty (for(...;...;))
   since the update is fully handled inside the body.
4. Bracket mismatch: wrote val[s[i+1] - val[s[i]] with the outer
   val[...] never properly closed - nested brackets incorrectly,
   intending two separate map lookups subtracted from each other
   but instead building one lookup with a broken/invalid key
   expression. Fixed by writing val[s[i+1]] - val[s[i]] as two
   complete, separate lookups joined by a normal subtraction.
5. Finally added an explicit i == s.length()-1 check before ever
   touching s[i+1], to guard the out-of-bounds access on the last
   character - a lone trailing symbol with nothing after it just
   adds its own value with no comparison possible.
6. Also initially had the function print via cout instead of
   return - LeetCode's judge calls the function and checks its
   return value, printing does nothing for grading.

Considered an alternative "current vs previous" approach (walk left
to right normally with i++ every time; if current value is bigger
than the previous one, subtract 2*val[previous] to undo the earlier
wrong addition and apply the correct subtraction instead). Same
O(n) time and O(1) space - no complexity gain, just avoids lookahead
and index-jumping structurally. Chose to keep my own version since
it's fully understood, debugged, and matches how the problem itself
is described (compare current sms next).

====================================================================
COMPLEXITY
====================================================================

1. TIME COMPLEXITY:

Building the map (7 fixed insertions)      -> O(1)
for loop, i moves by 1 or 2 each pass       -> O(n) total passes,
    where n = s.length(), since i strictly
    increases every iteration and never
    revisits a position
val[s[i]], val[s[i+1]] lookups              -> O(1) average per
    lookup (unordered_map average case)

Total: O(1) + O(n) * O(1) -> O(n), where n = length of s (max 15
per constraints, but the general bound is linear in string length)

2. SPACE COMPLEXITY:

val -> fixed 7 key-value pairs regardless of input size -> O(1)
total, i -> fixed variables -> O(1)

Total: O(1)

3. COMMON MISTAKES PEOPLE MAKE ON THIS PROBLEM:

- Comparing s[i] to s[i+1] without ever checking if i+1 is a valid
  index - causes out-of-bounds access on the last character of the
  string.

- Using > instead of >= (or otherwise mishandling equal adjacent
  values like "II" or "III") - equal values must be added normally,
  never subtracted, since equal-value pairs are never a subtractive
  case in valid roman numerals.

- Manually jumping the index by 2 in a subtractive case while also
  letting a for-loop's own header increment fire - causes
  characters to be skipped or double-counted.

- Malformed nested brackets when doing two map lookups in the same
  expression (val[s[i+1]] - val[s[i]] written incorrectly as one
  nested lookup instead of two separate ones subtracted).

- Returning nothing or printing instead of using return - LeetCode
  grades based on the function's return value, not console output.
*/