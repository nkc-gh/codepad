/*
====================================================================
Codeforces 71A - Word Capitalization (Difficulty - 800)
====================================================================

Given a word (mix of lowercase and uppercase letters), capitalize it —
meaning only the first letter should be uppercased, and all remaining
letters stay exactly as they are.

Constraints:
- Word length: 1 to 10^3
- Letters: lowercase and uppercase English only

Example 1:
Input:  ApPLe
Output: ApPLe

Example 2:
Input:  konjac
Output: Konjac
====================================================================
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    if (s[0] >= 'a' && s[0] <= 'z') {
        s[0] = s[0] - 32;
    }
    cout << s << "\n";
    return 0;
}

/*
====================================================================
SOLUTION IN MY WORDS
====================================================================

The only character that ever needs to change is s[0]. If it's already
uppercase (or a symbol), we leave it alone. If it's a lowercase letter
(ASCII 97–122), we subtract 32 to shift it into the uppercase range
(ASCII 65–90). Every character at index 1 and beyond is completely
untouched — we never loop over the rest of the string.

Verified edge cases mentally:
- First letter already uppercase (e.g. "ApPLe"): the if-condition is
  false, nothing changes, output equals input — correct.
- All lowercase (e.g. "konjac"): only 'k' gets shifted to 'K', rest
  stay lowercase — correct.
- Single character, lowercase (e.g. "a"): s[0] gets shifted to 'A',
  s[1:] is empty, output is "A" — correct.
- Single character, uppercase (e.g. "A"): condition is false, output
  is "A" unchanged — correct.

Could also use s[0] = toupper(s[0]) from <cctype> as a one-liner
replacement for the if-block — produces identical results, but the
explicit ASCII arithmetic makes the underlying transformation clearer.

====================================================================
COMPLEXITY
====================================================================

1. TIME COMPLEXITY:

cin >> s        -> O(L)  where L = length of word
if + s[0] op   -> O(1)
cout << s       -> O(L)

Total: O(L)

2. SPACE COMPLEXITY:

string s        -> O(L)  to store the input word

Total: O(L)

3. COMMON MISTAKES PEOPLE MAKE ON THIS PROBLEM:

- Converting the ENTIRE string to uppercase (e.g. using toupper in
  a loop over all characters) instead of only touching s[0] — the
  problem explicitly says all letters except the first remain unchanged.

- Forgetting to read input with cin >> s, then accessing s[0] on an
  empty string — undefined behavior that may crash or silently produce
  wrong output.

- Using s[0] -= 32 unconditionally without checking if it's already
  uppercase — subtracting 32 from an already-uppercase letter or a
  non-letter character produces garbage output.

- Checking s[0] >= 97 && s[0] <= 122 using magic numbers instead of
  's[0] >= 'a' && s[0] <= 'z'' — functionally identical but harder
  to read and easier to mistype.
*/