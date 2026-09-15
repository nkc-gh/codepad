/*
====================================================================
Codeforces 112A - Petya and Strings (Difficulty - 800)
====================================================================

Given two strings of the same length, consisting of uppercase and
lowercase Latin letters, compare them lexicographically ignoring
case. Print -1 if the first string is smaller, 1 if the second
string is smaller, 0 if they are equal (case-insensitively).

Constraints:
String lengths range from 1 to 100, both strings same length.

Input format:
Two lines, each a string.

Example 1:
Input:
aaaa
aaaA
Output: 0

Example 2:
Input:
abs
Abz
Output: -1

Example 3:
Input:
abcdefg
AbCdEfF
Output: 1
====================================================================
*/

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    for (int i = 0; i < s1.length(); i++) {
        char a = toupper(s1[i]);
        char b = toupper(s2[i]);

        if (a > b) {
            cout << 1 << endl;
            return 0;
        }
        if (a < b) {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << 0 << endl;
    
    return 0;
}

/*
====================================================================
ALTERNATE/EARLIER VERSION
====================================================================

First working version did the case-normalization manually with
ASCII arithmetic (checking if a character was in 'a'-'z' and
subtracting 32 if so) instead of using a library function:

#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    for (int i = 0; i < s1.length(); i++) {
        char a = s1[i];
        char b = s2[i];

        if (a >= 'a' && a <= 'z')
            a = a - 32;

        if (b >= 'a' && b <= 'z')
            b = b - 32;

        if (a == b)
            continue;
        else if (a > b) {
            cout << 1 << endl;
            return 0;
        }
        else {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << 0 << endl;
    return 0;
}

Before this, an even earlier version branched separately on all 4
combinations of case (both lowercase, both uppercase, first
lowercase/second uppercase, first uppercase/second lowercase),
doing a slightly different comparison in each branch. It worked but
was replaced once it became clear that normalizing both characters
to the same case *before* comparing collapses all 4 branches into
one.

====================================================================
SOLUTION IN MY WORDS
====================================================================

First approach branched on every combination of which case each
character was in (both lowercase, both uppercase, mixed either way)
and adjusted the comparison differently in each branch. It passed
all samples but had a lot of repeated logic — four branches doing
essentially the same "compare, maybe with a +/-32 adjustment"
operation.

Simplified by realizing the case-detection and the comparison don't
need to happen together: normalize both characters to the same case
FIRST (converted both to uppercase using manual arithmetic — if a
char was in 'a'-'z', subtracted 32), THEN do a single plain
comparison. This collapsed the four branches down to one comparison
path.

Then learned about toupper() from <cctype>, which does the same
uppercase conversion in one function call instead of manual range
checks and arithmetic. Initially unsure whether toupper() would
mishandle a character that's already uppercase, but confirmed it's
a no-op in that case — toupper() only converts when the input is
lowercase, and leaves anything else (including already-uppercase
letters) unchanged. This let the manual arithmetic be replaced
cleanly with toupper(s1[i]) and toupper(s2[i]).

Final logic: loop through both strings character by character,
normalize each pair to uppercase, then compare directly — a>b means
print 1, a<b means print -1, and if the loop finishes with all
characters equal, print 0 (matches, since strings are guaranteed
equal length so no leftover characters to worry about).

====================================================================
COMPLEXITY
====================================================================

1. TIME COMPLEXITY:

cin >> s1 >> s2;                -> O(n), where n is string length
for loop over i=0..length-1     -> O(n) iterations in the worst case
    toupper(s1[i]), toupper(s2[i]) -> O(1) each
    comparison (a>b, a<b)          -> O(1)

Total: O(n), where n <= 100 per constraints. Loop exits early via
return as soon as a differing character is found.

2. SPACE COMPLEXITY:

s1, s2 -> O(n) each, to store the input strings
a, b   -> O(1), scratch chars per iteration

Total: O(n)

3. COMMON MISTAKES PEOPLE MAKE ON THIS PROBLEM:

- Comparing strings directly without normalizing case first (e.g.
  s1[i] > s2[i] on raw characters) — this compares based on raw
  ASCII values, where all uppercase letters sort before all
  lowercase letters, giving wrong results whenever the two strings
  mix cases differently (e.g. 'a' vs 'B' would wrongly compare as
  'a' > 'B' in raw ASCII, even though case-insensitively 'a' < 'b').

- Writing separate comparison branches for each combination of
  upper/lower case instead of normalizing both characters to the
  same case before a single comparison — works but is unnecessarily
  repetitive and more error-prone.

- Assuming toupper() might corrupt or mishandle characters that are
  already uppercase — toupper() is a safe no-op on non-lowercase
  input, so it can be applied unconditionally to every character
  without a prior case check.

- Forgetting to `return 0;` (or otherwise break out) immediately
  after printing -1 or 1 upon finding the first differing character
  — without an early exit, the loop would continue and potentially
  print multiple times or use later characters that shouldn't
  matter once an earlier difference already decided the answer.
*/