/*
====================================================================
Codeforces 236A - Boy or Girl (Difficulty - 800)
====================================================================

Given a username (lowercase English letters only, up to 100 chars),
count the number of DISTINCT characters in it. If that count is
even, print "CHAT WITH HER!". If odd, print "IGNORE HIM!".

Constraints:
String is non-empty, lowercase only, at most 100 characters.

Input format:
Single string on one line.

Example 1:
Input: wjmzbmr
Output: CHAT WITH HER!
(6 distinct characters: w,j,m,z,b,r)

Example 2:
Input: xiaodao
Output: IGNORE HIM!

Example 3:
Input: sevenkplus
Output: CHAT WITH HER!
====================================================================
*/

#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    cin >> s;
    bool hashTable[26] = {false};
    
    for(int i=0 ; i<s.length() ; i++){
        hashTable[s[i]-97] = true;
    }
    
    int count = 0;

    for(int i =0 ; i<26 ; i++){
        if(hashTable[i] == true){
            count ++;
        }
    }
    
    if(count %2 == 0){
        cout << "CHAT WITH HER!" << endl;
    }
    
    else{
        cout << "IGNORE HIM!" << endl;
    }
    
    return 0;
}

/*
====================================================================
SOLUTION IN MY WORDS
====================================================================

First idea was a nested loop: for each character, compare it against
every other character in the string to check for duplicates, and
tally up equal pairs to eventually derive the distinct count. This
would work but is O(n^2), and since the alphabet is fixed and small
(only lowercase English letters, 26 possible values), a much simpler
approach was available.

Switched to using a boolean array of size 26 as a presence table —
one slot per possible lowercase letter. The key realization was that
no comparison against previously-seen characters is actually needed:
for each character in the string, just compute its index using the
same char-to-value subtraction trick as the earlier '0'-subtraction
digit trick (here, s[i]-97, since lowercase 'a' starts at ASCII 97),
and set hashTable[that index] = true. If the same character appears
multiple times, its slot just gets set to true redundantly — which
is harmless, since duplicate writes of `true` don't affect anything.

After the loop, distinct character count = number of `true` entries
in hashTable, found with a second loop over all 26 slots.

Then checked count's parity: even -> "CHAT WITH HER!", odd ->
"IGNORE HIM!" — direct translation of the problem's rule.

Minor syntax slip: wrote `True` (capital T, Python-style) instead of
C++'s lowercase `true` boolean literal — caught and fixed.

Also briefly wondered whether `<stdbool.h>` needed to be included for
`bool` to work, but confirmed bool is a native fundamental type in
C++ (unlike C), so no extra header is needed beyond what was already
included.

====================================================================
COMPLEXITY
====================================================================

1. TIME COMPLEXITY:

cin >> s;                          -> O(n), where n = string length
first for loop (i=0..length-1)     -> O(n), marking presence
    hashTable[s[i]-97] = true;       -> O(1) per character
second for loop (i=0..25)          -> O(1), fixed 26 iterations
    (count increments)                -> O(1) each
parity check + cout                -> O(1)

Total: O(n), where n <= 100 per constraints. The second loop is a
fixed constant (26), so it doesn't scale with input size.

2. SPACE COMPLEXITY:

s          -> O(n), stores the input string
hashTable  -> O(1), fixed size 26 regardless of input
count      -> O(1)

Total: O(n) (dominated by storing the input string itself; the
presence table is a constant 26 booleans regardless of n).

3. COMMON MISTAKES PEOPLE MAKE ON THIS PROBLEM:

- Using an O(n^2) nested-loop comparison to find distinct characters
  instead of a fixed-size presence array — unnecessarily slow when
  the alphabet is small and fixed (26 lowercase letters), even
  though n<=100 makes it fast enough to pass regardless.

- Writing `True` (capitalized, Python-style) instead of C++'s
  lowercase `true` boolean literal — compile error.

- Forgetting to initialize the boolean array to all-false at
  declaration (bool hashTable[26] = {false};) — leaving it
  uninitialized results in garbage values, making the "true" count
  unreliable.

- Confusing "count of distinct characters" with "count of characters
  that appear more than once" or some other derived quantity instead
  of simply counting `true` entries in the presence table directly.
*/