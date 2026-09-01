/*
====================================================================
Codeforces 71A - Way Too Long Words
====================================================================

A word is "too long" if its length is strictly more than 10
characters. Replace every too-long word with an abbreviation: first
letter + count of letters strictly between first and last + last
letter. Words of length <= 10 are printed unchanged.

Input:
First line: integer n (1 <= n <= 100)
Next n lines: one lowercase word each (length 1 to 100)

Output:
n lines, each the transformed (or unchanged) word.

Example:
Input:
4
word
localization
internationalization
pneumonoultramicroscopicsilicovolcanoconiosis

Output:
word
l10n
i18n
p43s
====================================================================
*/

#include <iostream>
#include <string>
using namespace std;
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        if(s.length() > 10){
            cout << s[0] << s.length() - 2 << s[s.length()-1] << endl;
        }
        else{
            cout << s << endl;
        }
    }
    return 0;
}

/*
====================================================================
SOLUTION IN MY WORDS
====================================================================

First wrong instinct: I thought the middle number needed to be
figured out some other way, until I actually counted the letters
between the first and last letter of "localization" by hand and
confirmed it lines up exactly with length - 2 (removing the first
and last character leaves exactly length-2 characters in between).

First real code attempt had several bugs stacked on top of each
other, all from not knowing C++ strings well yet:

1. Declared `int n;` but never did `cin >> n;` - same forgetting-to-
   read-input mistake as my earlier problems. n held garbage, loop
   either ran 0 times or undefined number of times.

2. Declared `string s;` inside the loop but never did `cin >> s;` -
   so s was always an empty string, s.length() was always 0, and the
   too-long branch never triggered no matter what the actual input
   word was.

3. Wrote `"s[0]"` and `"s[s.length()-1]"` in quotes. This was my
   biggest misunderstanding - I thought writing the expression name
   inside quotes would evaluate it. Actually quotes make it a
   literal string of those exact characters (s, [, 0, ]) - it prints
   garbage text, not the actual first character of the word. Fix
   was to drop the quotes entirely and write the real expressions
   s[0] and s[s.length()-1], which C++ evaluates as actual
   characters from the string.

4. Used `+` to try to join char and string pieces together for
   cout, coming from a C/Python instinct of string concatenation.
   In C++, cout uses `<<` to chain multiple values of different
   types (char, int, string) onto the same output stream - `+`
   between quoted literals and numbers doesn't do what I expected.

5. Missed adding `endl` (or "\n") after each cout - without it,
   all n outputs would print stuck together on one line instead of
   n separate lines, which doesn't match "print n lines" in the
   problem statement.

Also learned (from asking): using built-in operations like s[0],
s.length(), s[s.length()-1] isn't a shortcut or "cheating" - these
are basic language features available in every language (Python's
s[0]/len(s), Java's charAt()/length()) and are used exactly this way
in real contests including Codeforces rounds and ICPC. The actual
skill tested is the logic (realizing middle = length-2, handling the
<=10 case), not reimplementing indexing from scratch.

====================================================================
COMPLEXITY
====================================================================

1. TIME COMPLEXITY:

cin >> n;                          -> O(1)
for (i = 0; i < n; i++)            -> O(n), runs n times
    cin >> s;                       -> O(L) to read a word of length L
    if (s.length() > 10)             -> O(1)
        cout << s[0] << ... << endl;  -> O(1), fixed number of prints
    else
        cout << s << endl;             -> O(L) to print the word

Per-word work is O(L) where L is that word's length (max 100).
Total across all n words: O(n * L_max), which with n, L_max <= 100
is small, but formally O(total input size).

Total: O(N) where N = total characters across all words

2. SPACE COMPLEXITY:

n, i -> O(1) fixed variables
s -> one string at a time, reused each iteration, holds at most
     100 characters -> O(L_max), not O(n) since old words aren't
     kept around

Total: O(L_max) i.e. O(1) relative to n since max word length is
capped by constraints, not accumulated across iterations

3. COMMON MISTAKES PEOPLE MAKE ON THIS PROBLEM:

- Forgetting cin >> n or cin >> s (declaring without reading) -
  compiles fine, gives silently wrong output (empty/garbage values)
  instead of a crash, making it a sneaky bug.

- Wrapping expressions like s[0] in quotes, thinking that "runs" the
  expression - it actually prints the literal characters typed
  inside the quotes instead of evaluating anything.

- Using `+` to concatenate char/int/string pieces for cout instead
  of chaining with `<<` - type mismatches or wrong operator behavior
  depending on what's being added.

- Forgetting endl/"\n" after each output line, causing all outputs
  to merge onto a single line and fail the judge's exact-match
  output comparison.

- Off-by-one on the boundary condition - using `>= 10` instead of
  `> 10`, incorrectly abbreviating a word of exactly length 10 which
  should be printed unchanged per "strictly more than 10".
*/