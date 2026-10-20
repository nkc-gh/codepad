/*
====================================================================
LeetCode 3110 - Score of a String (Easy)
====================================================================

The score of a string is the sum of absolute differences between
ASCII values of every pair of adjacent characters. Return the score.

Constraints:
2 <= s.length <= 100
s consists only of lowercase English letters.

Example 1:
Input: s = "hello"   Output: 13
|104-101| + |101-108| + |108-108| + |108-111| = 3+7+0+3 = 13

Example 2:
Input: s = "zaz"     Output: 50
|122-97| + |97-122| = 25+25 = 50
====================================================================
*/

class Solution {
public:
    int scoreOfString(string s) {
        int score = 0;

        for (int i = 0; i < s.length() - 1; i++) {
            score += abs(s[i] - s[i + 1]);
        }

        return score;
    }
};

/*
====================================================================
SOLUTION IN MY WORDS
====================================================================

Initialized score = 0, then looped through adjacent character pairs
using index i from 0 to s.length() - 2 (i.e. i < s.length() - 1).
At each step, took the absolute difference of the ASCII values of
s[i] and s[i+1] and added it to score.

Loop bound reasoning: inside the loop, s[i+1] is accessed. If i
were allowed to reach the last index (s.length() - 1), then i+1
would be s.length(), which is one past the end of the string -
out-of-bounds access. Stopping at s.length() - 1 (exclusive) keeps
i+1 always within range.

Characters in C++ are stored as their ASCII values, so subtracting
two chars directly gives the numeric difference between their ASCII
codes. s[i] - s[i+1] is already an int due to integer promotion,
so abs() works on it correctly without any explicit cast.

Initially wrote the difference using an if-else instead of abs():
  if (s[i] > s[i+1]) score += s[i] - s[i+1];
  else score += s[i+1] - s[i];
Both are correct. abs() is cleaner and more direct since it handles
the sign in one call rather than branching.

Used score += to accumulate into the existing total each iteration,
not score = which would overwrite the previous sum.

Traced "hello" (ASCII: h=104, e=101, l=108, l=108, o=111):
  i=0: |104-101| = 3,  score = 3
  i=1: |101-108| = 7,  score = 10
  i=2: |108-108| = 0,  score = 10
  i=3: |108-111| = 3,  score = 13 -> return 13

====================================================================
COMPLEXITY
====================================================================

1. TIME COMPLEXITY:

for loop: i from 0 to s.length()-2   -> O(N)
    abs(s[i] - s[i+1])                 -> O(1)
    score +=                            -> O(1)

Total: O(N), one pass through the string processing each adjacent
pair exactly once.

2. SPACE COMPLEXITY:

score, i -> O(1), two fixed integer variables

Total: O(1)

3. COMMON MISTAKES PEOPLE MAKE ON THIS PROBLEM:

- Looping to s.length() instead of s.length() - 1 - this accesses
  s[i+1] when i is the last index, reading one position past the
  end of the string, which is undefined behavior.

- Computing s[i] - s[i+1] without abs() and forgetting the result
  can be negative - when s[i] < s[i+1], the subtraction gives a
  negative value, which would decrease the score instead of
  increasing it.

- Using score = instead of score += inside the loop - this replaces
  the accumulated total with just the latest difference on every
  iteration, returning only the last pair's difference instead of
  the sum of all pairs.

- Treating characters as needing explicit conversion before
  subtraction - chars are automatically promoted to int in C++
  arithmetic, so s[i] - s[i+1] already gives the correct integer
  difference with no cast needed.
*/