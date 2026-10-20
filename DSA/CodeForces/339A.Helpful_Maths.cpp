/*
====================================================================
Codeforces 339A - Helpful Maths (Difficulty - 800)
====================================================================

Given a string containing digits 1, 2, 3 and '+' signs, rearrange
the summands in non-decreasing order and print the result.

Constraints:
String s contains only digits 1, 2, 3 and '+' characters.
String s is at most 100 characters long.

Input format:
s (single string, no spaces)

Example 1:
Input: 3+2+1       Output: 1+2+3

Example 2:
Input: 1+1+3+1+3   Output: 1+1+1+3+3

Example 3:
Input: 2            Output: 2
====================================================================
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string s;
    cin >> s;

    vector<int> count(4, 0);

    for (char i : s) {
        if (i != '+') {
            count[i - '0']++;
        }
    }

    bool first = true;

    for (int digit = 1; digit <= 3; digit++) {
        for (int j = 0; j < count[digit]; j++) {
            if (!first) {
                cout << "+";
            }

            cout << digit;
            first = false;
        }
    }

    cout << '\n';
    return 0;
}

/*
====================================================================
SOLUTION IN MY WORDS
====================================================================

First instinct was to extract the digits, store them in a vector,
sort them, and print with '+' in between - standard sort approach.
This would work, but then noticed the input only ever contains
digits 1, 2, and 3. When the value range is this small and fixed,
sorting is overkill - a frequency count does the same job more
directly.

Created a vector<int> count(4, 0) - size 4 so the digit itself can
be used as the index (count[1], count[2], count[3]), with index 0
just sitting unused. Walked through the string character by
character with a range-based for loop, skipping any '+' and
incrementing count[i - '0'] for each digit. The char-to-digit
trick (i - '0') converts a digit character to its integer value
by subtracting the ASCII code of '0'.

After counting, printed digits in ascending order using a nested
loop: outer loop runs digit from 1 to 3, inner loop prints that
digit count[digit] times. Since the outer loop already goes 1 -> 3,
the output is automatically in non-decreasing order without any
explicit sorting step.

For the '+' separators, used a bool first = true. The first digit
printed gets no '+' before it; after that first is set to false and
every subsequent digit gets a '+' printed before it. This avoids
a leading or trailing '+' in the output cleanly without any
index arithmetic.

Traced sample 1 ("3+2+1"):
  count[1]=1, count[2]=1, count[3]=1
  digit=1: first=true, print "1", first=false
  digit=2: first=false, print "+2"
  digit=3: first=false, print "+3"
  Output: 1+2+3

Traced sample 2 ("1+1+3+1+3"):
  count[1]=3, count[2]=0, count[3]=2
  digit=1: prints "1", "+1", "+1"
  digit=2: count[2]=0, inner loop skipped entirely
  digit=3: prints "+3", "+3"
  Output: 1+1+1+3+3

Traced sample 3 ("2"):
  count[2]=1
  digit=1: skipped, digit=2: first=true, prints "2", first=false
  digit=3: skipped
  Output: 2

====================================================================
COMPLEXITY
====================================================================

1. TIME COMPLEXITY:

cin >> s                              -> O(N), N = length of string
for loop scanning s                   -> O(N)
    if check + count[i-'0']++           -> O(1)
nested print loop (digit 1 to 3)      -> O(total digits) = O(N)

Total: O(N), two linear passes over the input.

2. SPACE COMPLEXITY:

count vector -> O(1), fixed size 4 regardless of input length
first, digit, j, i, s -> O(N) for the string, O(1) for the rest

Total: O(N) for storing the input string. The frequency vector
itself is O(1) since its size never changes with input.

3. COMMON MISTAKES PEOPLE MAKE ON THIS PROBLEM:

- Sorting the raw string directly - the '+' characters get sorted
  alongside the digits, producing wrong output since '+' has a
  lower ASCII value than '1' and would end up at the front.

- Printing a '+' before every digit unconditionally - produces a
  leading '+' at the start of the output (e.g. "+1+2+3").

- Printing a '+' after every digit unconditionally - produces a
  trailing '+' at the end of the output (e.g. "1+2+3+").

- Sizing the frequency vector by N instead of by value range - the
  vector must be indexed by digit value (1, 2, 3), not by position,
  so it needs size 4 regardless of how long the input is.

- Using count as a variable name cautiously - count is also a
  function in the C++ standard library; it compiles fine here since
  the local variable shadows the std version, but in larger programs
  this naming collision can cause subtle bugs.
*/