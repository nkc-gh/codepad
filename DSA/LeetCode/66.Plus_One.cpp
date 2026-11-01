/*
====================================================================
LeetCode 66 - Plus One (Difficulty - Easy)
====================================================================

Given a large integer represented as an array of digits, increment
it by one and return the resulting array.

Constraints:
1 <= digits.length <= 100
0 <= digits[i] <= 9
digits does not contain leading zeros.

Example 1:
Input: digits = [1,2,3]
Output: [1,2,4]

Example 2:
Input: digits = [4,3,2,1]
Output: [4,3,2,2]

Example 3:
Input: digits = [9]
Output: [1,0]
====================================================================
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int i = digits.size() - 1; i >= 0; i--) {
            if(digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            else {
                digits[i] = 0;
            }
        }

        digits.insert(digits.begin(), 1);
        return digits;
    }
};

/*
====================================================================
SOLUTION IN MY WORDS
====================================================================

Carry Propagation Technique.

If the last digit is less than 9, adding 1 produces no carry, so
increment it and return directly. If it is 9, adding 1 gives 10 -
write 0 and carry the 1 left by moving to the previous index.
Repeat until a non-9 digit is found or the entire array is
processed. If all digits were 9, every element is now 0 and we
insert 1 at the front.

First attempt had two bugs. First, used == instead of = when
setting digits[i] to 0 - == is comparison, = is assignment, so
the 9s were never actually changed. Second, the check for all-9s
case (digits[0] == 0) was inside the loop instead of after it,
causing incorrect inserts mid-loop.

Also had an unnecessary outer if/else checking the last digit
separately before the loop. Removed it - the loop handles all
cases uniformly, including the simple no-carry case.

====================================================================
COMPLEXITY
====================================================================

1. TIME COMPLEXITY:

Loop runs from i = digits.size()-1 down to 0, at most n iterations.
Each iteration does O(1) work.
insert at front in the all-9s case shifts all elements: O(n).

Total: O(n)

2. SPACE COMPLEXITY:

Modifying the input array in place. No extra arrays or containers.
The insert in the all-9s case grows the array by 1 but that is
the output itself, not auxiliary space.

Total: O(1)

3. COMMON MISTAKES PEOPLE MAKE ON THIS PROBLEM:

- Using == instead of = when setting digits[i] to 0 - silently
  does nothing, 9s are never changed, wrong output with no error.

- Putting the all-9s check inside the loop instead of after it -
  inserts 1 at the front prematurely mid-loop.

- Not handling the all-9s case at all - forgetting that [9,9,9]
  becomes [1,0,0,0], which requires growing the array.

- Looping from front to back instead of back to front - you need
  to find the rightmost non-9 digit first, not the leftmost.
*/