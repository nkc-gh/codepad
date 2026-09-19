/*
====================================================================
LeetCode 2469 - Convert the Temperature (Easy)
====================================================================

Given a non-negative floating point number celsius (rounded to two
decimal places), convert it to Kelvin and Fahrenheit. Return the
result as ans = [kelvin, fahrenheit].

Formulas:
Kelvin = Celsius + 273.15
Fahrenheit = Celsius * 1.80 + 32.00

Answers within 10^-5 of the actual answer are accepted.

Constraints:
0 <= celsius <= 1000

Example 1:
Input: celsius = 36.50
Output: [309.65000, 97.70000]

Example 2:
Input: celsius = 122.11
Output: [395.26000, 251.79800]
====================================================================
*/

class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        double kelvin = celsius + 273.15;
        double fahrenheit = (celsius * 1.80) + 32.00;

        return {kelvin,fahrenheit};
    }
};

/*
====================================================================
SOLUTION IN MY WORDS
====================================================================

Direct application of the two given formulas — no derivation needed,
just compute kelvin and fahrenheit from celsius and return both.

Only snag was the return statement: first tried `return
[kelvin,fahrenheit];`, which isn't valid C++ syntax for constructing
a vector (that's array/list syntax from other languages like Python
or JS). Recalled the same fix used earlier in Two Sum — vector's
brace-initializer syntax, `return {kelvin, fahrenheit};` — which
correctly constructs a vector<double> with those two values in
order.

The "within 10^-5" tolerance mentioned in the problem means exact
decimal-place matching isn't required, so no special rounding or
formatting logic is needed — the judge accepts small floating-point
precision differences.

====================================================================
COMPLEXITY
====================================================================

1. TIME COMPLEXITY:

kelvin = celsius + 273.15         -> O(1)
fahrenheit = celsius*1.80+32.00    -> O(1)
return {kelvin, fahrenheit}         -> O(1)

Total: O(1)

2. SPACE COMPLEXITY:

kelvin, fahrenheit -> O(1) fixed variables
returned vector -> O(1), fixed size 2

Total: O(1)

3. COMMON MISTAKES PEOPLE MAKE ON THIS PROBLEM:

- Using language-specific list/array literal syntax (e.g.
  [kelvin, fahrenheit]) instead of C++'s vector brace-initializer
  syntax ({kelvin, fahrenheit}) — invalid in C++, causes a compile
  error.

- Swapping the order of values in the returned vector (putting
  fahrenheit before kelvin) — the problem specifies the order as
  [kelvin, fahrenheit], so returning them reversed would fail even
  though both values are individually correct.

- Overcomplicating the return with manual rounding or string
  formatting, unnecessary given the problem explicitly accepts
  answers within a small floating-point tolerance.
*/