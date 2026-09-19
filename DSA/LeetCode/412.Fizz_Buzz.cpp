/*
====================================================================
LeetCode 412 - Fizz Buzz (Easy)
====================================================================

Given an integer n, return a string array answer (1-indexed) where:
- answer[i] == "FizzBuzz" if i is divisible by 3 and 5.
- answer[i] == "Fizz" if i is divisible by 3.
- answer[i] == "Buzz" if i is divisible by 5.
- answer[i] == i (as a string) if none of the above are true.

Constraints:
1 <= n <= 10^4

Example 1:
Input: n = 3
Output: ["1","2","Fizz"]

Example 2:
Input: n = 5
Output: ["1","2","Fizz","4","Buzz"]

Example 3:
Input: n = 15
Output: ["1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz"]
====================================================================
*/

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> answer;

        for (int i = 1; i <= n; i++) {
            if (i % 3 == 0 && i % 5 == 0) {
                answer.push_back("FizzBuzz");
            }
            else if (i % 3 == 0) {
                answer.push_back("Fizz");
            }
            else if (i % 5 == 0) {
                answer.push_back("Buzz");
            }
            else {
                answer.push_back(to_string(i));
            }
        }

        return answer;
    }
};

/*
====================================================================
SOLUTION IN MY WORDS
====================================================================

Logic itself was easy - loop from 1 to n, check divisibility by
both 3 and 5 first (has to come first, otherwise a number like 15
would get caught by the "divisible by 3" check and print "Fizz"
before ever reaching the "divisible by both" case), then check 3
alone, then 5 alone, else just the number itself.

Made several syntax mistakes translating this from logic to actual
C++ code, since I'm still moving from C:

1. Wrote `string[i] = "FizzBuzz";` - treating `string`, the *type*,
   as if it were a variable name I could index into. Never actually
   declared a variable to hold the results. Fixed by declaring
   `vector<string> answer;` and using `answer` as the actual
   variable throughout.

2. Wrote `string[i] = i;` - trying to assign a raw int into a
   string slot directly, which doesn't implicitly convert. Needed
   `to_string(i)` to explicitly convert the int to its string
   representation before storing it.

3. Wrote `return string;` - same root issue as #1, returning the
   type name rather than the variable holding my actual results.

4. Initially used `answer[i]` style indexing while planning to
   declare the vector with a fixed size - but since my loop runs i
   from 1 to n inclusive, and a vector of size n has valid indices
   0 to n-1, direct indexing at i=n would be out of bounds. Switched
   to `push_back()` instead, which sidesteps needing to pre-size the
   vector or worry about the 1-index vs 0-index mismatch entirely -
   it just appends to the end regardless of what index "i" logically
   represents.

5. Final naming slip - declared the vector as `answer` but called
   `.push_back()` on `ans`, a variable that was never declared.
   Simple copy-paste/typo style mismatch, fixed by using the actual
   declared name consistently.

====================================================================
COMPLEXITY
====================================================================

1. TIME COMPLEXITY:

for i from 1 to n                    -> O(n) iterations
    i % 3, i % 5 checks               -> O(1) per iteration
    push_back (amortized)             -> O(1) per iteration

Total: O(n) - must produce one output string per number from 1 to
n, so this is optimal.

2. SPACE COMPLEXITY:

vector<string> answer -> holds n strings, each string itself is
short (at most 8 chars for "FizzBuzz" or up to 5 digits for numbers
up to 10^4).

Total: O(n) - this is also the required output size, not extra
overhead, so it's optimal.

3. COMMON MISTAKES PEOPLE MAKE ON THIS PROBLEM:

- Checking `i % 3 == 0` and `i % 5 == 0` as separate independent
  if-blocks (not if/else if) - causes both "Fizz" and "Buzz" to be
  pushed separately for multiples of 15, instead of "FizzBuzz" once.

- Checking `i % 3` and `i % 5` individually *before* checking
  `i % 15 == 0` (or i%3==0 && i%5==0) - multiples of 15 get caught
  by the Fizz check first and never reach the FizzBuzz case.

- Forgetting to convert the int to a string with `to_string()` and
  trying to push the raw int into a vector<string>, causing a
  compile error.

- Off-by-one in the loop - using i < n instead of i <= n, which
  produces only n-1 elements and misses the last number.

- Confusing vector indices (0 to n-1) with the problem's 1-indexed
  numbering (1 to n) when trying to pre-size the vector and assign
  via answer[i] instead of using push_back.
*/