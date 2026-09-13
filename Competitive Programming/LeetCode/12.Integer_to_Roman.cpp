/*
====================================================================
LeetCode 12 - Integer to Roman (Medium)
====================================================================

Given an integer, convert it to a Roman numeral. Roman numerals use
seven symbols (I=1, V=5, X=10, L=50, C=100, D=500, M=1000). Six
subtractive forms exist: IV=4, IX=9, XL=40, XC=90, CD=400, CM=900.
Powers of ten (I, X, C, M) can repeat up to 3 times consecutively;
V, L, D never repeat - if a symbol would need to appear 4 times,
the subtractive form is used instead.

Constraints:
1 <= num <= 3999

Example 1:
Input: num = 3749
Output: "MMMDCCXLIX"

Example 2:
Input: num = 58
Output: "LVIII"

Example 3:
Input: num = 1994
Output: "MCMXCIV"
====================================================================
*/

class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int, string>> table = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
            {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
        };
        
        string result = "";
        
        for (int i = 0; i < table.size(); i++) {
            while (num >= table[i].first) {
                result += table[i].second;
                num -= table[i].first;
            }
        }
        
        return result;
    }
};

/*
====================================================================
ALTERNATE VERSION I ALSO WROTE
====================================================================

Before refactoring into the table-driven loop above, I first wrote
the same greedy logic out directly as 13 explicit if-else if
branches, ordered largest to smallest, with an outer while(num!=0)
to allow the same branch to fire multiple times in a row (e.g. M
needs to apply three times for 3000). This was also correct and
passed all three samples - keeping it here since I liked having
worked through it this way first, even though the table version
below is the one I consider final.

class Solution {
public:
    string intToRoman(int num) {
        string result = "";
        
        while (num!=0) {
            if (num >= 1000) {
                result += "M";
                num -= 1000;
            } else if (num >= 900) {
                result += "CM";
                num -= 900;
            } else if (num >= 500) {
                result += "D";
                num -= 500;
            } else if (num >= 400) {
                result += "CD";
                num -= 400;
            } else if (num >= 100) {
                result += "C";
                num -= 100;
            } else if (num >= 90) {
                result += "XC";
                num -= 90;
            } else if (num >= 50) {
                result += "L";
                num -= 50;
            } else if (num >= 40) {
                result += "XL";
                num -= 40;
            } else if (num >= 10) {
                result += "X";
                num -= 10;
            } else if (num >= 9) {
                result += "IX";
                num -= 9;
            } else if (num >= 5) {
                result += "V";
                num -= 5;
            } else if (num >= 4) {
                result += "IV";
                num -= 4;
            } else if (num >= 1) {
                result += "I";
                num -= 1;
            }
        }
        
        return result;
    }
};

====================================================================
SOLUTION IN MY WORDS
====================================================================

Having already solved Roman to Integer, I expected this reverse
problem to live in similar territory - some form of matching against
a fixed set of Roman value/symbol pairs rather than something
fundamentally different.

First instinct was to think in terms of decimal place values -
extract the thousands digit, hundreds digit, tens digit, ones digit
separately and convert each one using a place-specific lookup (e.g.
9 in the hundreds place needs a different symbol, CM, than 9 in the
tens place, XC). This would have needed a large, repetitive set of
place-specific tables (up to 10 entries per place, times 4 places),
since I was trying to map decimal digits directly to symbols.

The actual realization: Roman numerals only ever use 13 fixed
value-symbol combinations total across the ENTIRE problem, regardless
of place value - the 7 base symbols (M, D, C, L, X, V, I) plus the 6
subtractive shortcuts (CM, CD, XC, XL, IX, IV). Nothing else is ever
valid, since the problem's own rules restrict Roman numerals to only
these forms. This meant place values didn't need to be reasoned
about explicitly at all - a purely greedy strategy works: repeatedly
find the largest of these 13 values that still fits into what's left
of num, append its symbol, subtract it, and repeat.

Traced this by hand on 1994 to confirm before coding: is 1000<=1994?
Yes, append M, remainder=994. Is 1000<=994? No, check 900: yes,
append CM, remainder=94. Continue down to 90 (append XC,
remainder=4), then down to 4 (append IV, remainder=0). Result:
"MCMXCIV" - matches expected output, and crucially, this required no
knowledge of which decimal place any digit belonged to at any point.

First working version was the 13-branch if-else chain shown above -
correct, but recognized as "a hell lot of if-else" - essentially
hardcoding the same 13 fixed cases directly into control flow rather
than treating them as data.

Refactored by moving the 13 value-symbol pairs into a
vector<pair<int,string>>, ordered largest to smallest - learned pair
for the first time here: a simple two-value bundle accessed via
.first and .second, with no hashing or lookup behavior of its own
(unlike unordered_map, which IS a hash table internally, though its
entries are themselves stored/iterated as pairs under the hood).
This let a single loop over the table fully replace all 13 hardcoded
branches: the outer for walks the table top to bottom once, and an
inner while(num >= table[i].first) at each entry handles a symbol
needing to repeat consecutively, exactly replicating the outer
while(num!=0) from the hardcoded version but scoped per-entry
instead of globally.

Both versions - the 13-branch if-else chain and the table-driven
loop - are logically identical and equally correct; the refactor is
purely a readability/maintainability improvement (data-driven vs
hardcoded), not a complexity or correctness improvement.

====================================================================
COMPLEXITY
====================================================================

1. TIME COMPLEXITY:

vector<pair<int,string>> table construction  -> O(1), fixed 13
    entries regardless of input
outer for loop over table                     -> O(1), fixed 13
    iterations
inner while loop per entry                     -> bounded by a
    small constant total across all entries combined, since num is
    capped at 3999 (e.g. at most 3 M's, at most 1 of any given
    subtractive form, etc.) - total appends across the whole
    function bounded by a fixed constant (at most ~15 characters
    for the longest possible Roman numeral under 4000)

Total: O(1), since both the table size and the maximum possible
number of appends are fixed constants independent of num's specific
value (within the given constraints).

2. SPACE COMPLEXITY:

table -> O(1), fixed 13 pairs regardless of input
result -> O(1) bounded, at most ~15 characters for any valid input
    under the given constraints

Total: O(1)

3. COMMON MISTAKES PEOPLE MAKE ON THIS PROBLEM:

- Trying to convert each decimal place (thousands, hundreds, tens,
  ones) separately with its own dedicated lookup table, instead of
  realizing a single flat greedy pass over all 13 value-symbol pairs
  (largest to smallest) handles every case uniformly, with no need
  to reason about which decimal place a digit belongs to.

- Forgetting to include the 6 subtractive forms (CM, CD, XC, XL, IX,
  IV) in the value-symbol list and only using the 7 base symbols -
  this would produce invalid outputs like "VIIII" instead of "IX"
  for 9, since the greedy strategy needs the subtractive forms
  present in the table to be selected correctly when they're the
  largest fitting value.

- Ordering the value-symbol table smallest-to-largest instead of
  largest-to-smallest - breaks the greedy strategy entirely, since
  it needs to always pick the largest fitting value first at each
  step to produce a valid, non-redundant Roman numeral.

- Using unordered_map instead of an ordered structure (array,
  vector, or vector<pair>) for the value-symbol lookup - since the
  greedy algorithm depends on checking values in a specific
  descending order, and unordered_map provides no guaranteed
  iteration order, this could silently produce incorrect or
  inconsistent output.

- Using a single if per table entry instead of a while - misses
  the case where a symbol needs to be used more than once
  consecutively (e.g. "MMM" for 3000, or "XXX" for 30) - a single if
  would only ever append the symbol once per entry, even when the
  remaining num could still accommodate it again.
*/