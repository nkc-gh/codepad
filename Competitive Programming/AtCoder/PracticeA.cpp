/*
====================================================================
AtCoder PracticeA - Welcome to AtCoder
====================================================================

Given 3 integers a, b, c and a string s. Output the sum a+b+c and
the string s, separated by a space, on one line.

Constraints:
1 <= a,b,c <= 1,000
1 <= |s| <= 100

Input format:
a
b c
s

Example 1:
Input: 1 / 2 3 / test
Output: 6 test

Example 2:
Input: 72 / 128 256 / myonmyon
Output: 456 myonmyon
====================================================================
*/

#include <iostream>
#include <string>
using namespace std;

int main(){
  int a,b,c;
  string s;

  cin >> a;
  cin >> b >> c;
  cin >> s;

  cout << a+b+c << " " << s << endl;

  return 0;
}

/*
====================================================================
SOLUTION IN MY WORDS
====================================================================

First question was what "half-width" meant in "half-width break" -
this turned out to be a translation artifact from the original
Japanese problem (half-width = regular ASCII character, as opposed
to full-width/zenkaku characters used in Japanese text). So it just
meant: a normal space between the sum and s, and a normal newline
at the end.

Reading the input was straightforward since cin >> automatically
skips whitespace and newlines - so reading a on its own line, then
b and c on a shared line, then s on its own line all work fine with
three separate cin >> statements regardless of how the values are
split across physical lines.

Initial version had no endl/newline at the output. Learned that
this is generally fine on most judges (including AtCoder) since
judges typically normalize trailing whitespace when comparing
output, but it's a zero-cost habit to add - some stricter judges do
byte-compare and expect it, and it avoids visual issues if output
is ever piped elsewhere. Added endl to be safe.

====================================================================
COMPLEXITY
====================================================================

1. TIME COMPLEXITY:

cin >> a, b, c, s          -> O(1) each, fixed number of reads
                               (s length is bounded by 100 but
                               reading it is still a single O(|s|)
                               operation, negligible at this scale)
a+b+c                        -> O(1) arithmetic
cout << ...                  -> O(1) plus O(|s|) to output s

Total: O(|s|), dominated by printing the string, effectively O(1)
given |s| <= 100.

2. SPACE COMPLEXITY:

a, b, c -> O(1) fixed ints
s -> O(|s|) to store the string, bounded by 100

Total: O(|s|), effectively O(1) given the small constraint.

3. COMMON MISTAKES PEOPLE MAKE ON THIS PROBLEM:

- Misreading "s1s2s3"-style or multi-line input formats and trying
  to read everything with a single cin >> statement instead of one
  per value/line - cin >> already handles whitespace/newlines
  correctly across multiple calls.

- Assuming a missing trailing newline will fail the judge - most
  judges normalize trailing whitespace, so this is a non-issue in
  practice, though adding it is harmless and occasionally necessary
  on stricter graders.

- Overcomplicating "half-width" as some special formatting
  requirement instead of recognizing it as just an ASCII space,
  a translation-only distinction from the original Japanese
  wording.
*/