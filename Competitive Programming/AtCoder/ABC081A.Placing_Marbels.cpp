/*
====================================================================
AtCoder ABC081A - Placing Marbles
====================================================================

Given a string s of length 3, where each character is '0' or '1',
count how many characters are '1' (each '1' means a marble is
placed on that square).

Constraints:
Each of s1, s2, s3 is either '1' or '0'.

Input format:
s1s2s3   (single token, no spaces, e.g. "101")

Example 1:
Input: 101
Output: 2

Example 2:
Input: 000
Output: 0
====================================================================
*/

#include <iostream>
#include <string>
using namespace std;

int main(){
  string s;

  cin >> s;

  cout << ((int)s[0] - (int)'0') + ((int)s[1] - (int)'0') + ((int)s[2] - (int)'0') << endl;
  return 0;
}

/*
====================================================================
SOLUTION IN MY WORDS
====================================================================

First instinct was to read the input as three separate ints
(cin >> a >> b >> c), based on habit from problems with
space-separated values. Traced this against the actual input format
"101" (one unbroken token, no spaces) and realized cin >> a would
swallow the entire "101" as one integer, leaving nothing for b and
c to read - cin >> only splits on whitespace, and this input has
none between the three digits.

Recognized the input needed to be treated as a string instead, so
each character could be accessed individually via indexing (s[0],
s[1], s[2]) - same [] indexing syntax as C, just on a std::string
instead of a char array, so no new syntax to learn there.

First attempt after switching to string used
if(s[0]||s[1]||s[2]) cout << s[0]+s[1]+s[2] - got 146 instead of 2
for input "101". The bug: s[0] is a char, and a char holding '1' is
really just its ASCII code, 49, in memory - not the integer 1.
cout << (char) prints the character symbol, not its underlying
number. So s[0]+s[1]+s[2] on "101" was really computing
49+48+49 = 146, not 1+0+1.

Learned the standard char-to-digit trick: subtracting the char '0'
(ASCII 48) from a digit char converts it to its actual integer
value - e.g. '1'-'0' = 49-48 = 1. This works because subtracting
two chars in C++ automatically promotes both to int for the
arithmetic (integer promotion: any type smaller than int, like
char, short, or bool, gets widened to int before arithmetic unless
a float/double is already involved - float promotion only happens
if one operand is already floating-point).

Also worked through why cout displays the same underlying value
differently depending on type, not value: a char and an int can
hold the identical bit pattern (49), but cout prints a char as its
symbol and an int as its number. This replaces C's %c vs %d format
specifiers - in C++, cout infers display format from the
expression's type instead of a format string, so s[0] alone prints
as a character, but s[0]-'0' (which is of type int, due to
promotion) prints as a number.

Chose to keep explicit (int) casts on both sides in the final
version, even though the cast is technically redundant (the '-'
operator alone already promotes both chars to int without any cast
needed). This was a deliberate clarity choice - writing
(int)s[0] - (int)'0' makes the intent ("I am treating both sides as
integers") visually explicit rather than relying on an implicit
promotion rule that isn't obvious yet at this stage of learning.

Once the conversion logic clicked, realized no if-conditions are
needed at all - converting each character to its digit value (0 or
1) and summing all three directly gives the count of '1's, since
each '1' safely contributes exactly 1 and each '0' contributes
exactly 0.

====================================================================
COMPLEXITY
====================================================================

1. TIME COMPLEXITY:

cin >> s                                -> O(1), fixed length 3
(int)s[0]-(int)'0', etc.                -> O(1) each, 3 total
sum of three values                     -> O(1)
cout << ...                              -> O(1)

Total: O(1), since s is always exactly length 3 per constraints.

2. SPACE COMPLEXITY:

s -> O(1), fixed length 3 string

Total: O(1)

3. COMMON MISTAKES PEOPLE MAKE ON THIS PROBLEM:

- Trying to read the input as separate space-delimited integers
  (cin >> a >> b >> c) without checking that the actual input has
  no spaces between the three values - cin >> only splits on
  whitespace, so this misreads the entire input as one token.

- Summing raw characters directly (s[0]+s[1]+s[2]) without
  converting them to digit values first - silently produces a
  wrong but plausible-looking number (sum of ASCII codes) instead
  of an out-of-bounds crash, making the bug easy to miss without
  manually checking the arithmetic.

- Assuming a char must be explicitly "converted" via a special
  function to become usable as a number - in C++, subtracting two
  chars already promotes both to int automatically; an explicit
  (int) cast is optional for clarity, not required for the
  arithmetic to work correctly.

- Overcomplicating the solution with per-character if-checks
  (if s[0]=='1' add 1, else add 0, repeated three times) instead of
  recognizing the char-to-digit subtraction trick lets a plain sum
  do the counting directly.
*/