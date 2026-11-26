/*
====================================================================
LeetCode 3895 - Count Digit Appearances
====================================================================
 
+------------------------------------------------------------------+
| Difficulty - Medium                                              |
| Date of Submission - 26 November 2026 16:35                      |
| Tags - Array, Math                                               |
+------------------------------------------------------------------+
 
Given an integer array nums and an integer digit, return the total
number of times digit appears in the decimal representation of all
elements in nums.
 
Constraints:
1 <= nums.length <= 1000
1 <= nums[i] <= 10^6
0 <= digit <= 9
 
Example 1:
Input: nums = [12,54,32,22], digit = 2   Output: 4
 
Example 2:
Input: nums = [1,34,7], digit = 9        Output: 0
 
====================================================================
*/
 
class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        string s = "";
        for(int i=0 ; i<nums.size() ; i++){
            s+= to_string(nums[i]);
        }
 
        int output = 0;
        for(int i=0 ; i<s.length() ; i++){
            if(s[i]==digit+'0'){
                output++;
            }
        }
 
        return output;
    }
};
 
/*
====================================================================
SOLUTION IN MY WORDS
====================================================================
 
Concatenated all numbers into a single string using to_string().
Then iterated the string counting occurrences of the target digit.
 
Comparison: s[i] == digit + '0'
Since s[i] is a char and digit is an int, adding '0' (ASCII 48)
converts digit to its char equivalent for correct comparison.
 
Concatenation works here because we're just counting global digit
occurrences — the boundary between numbers doesn't matter.
 
Alternative (O(1) space): extract digits manually using % 10 and / 10,
compare directly without string conversion.
 
====================================================================
COMPLEXITY
====================================================================
 
1. TIME COMPLEXITY:
d = number of digits per number = O(log M) where M = max(nums[i])
Total: O(N log M)
 
2. SPACE COMPLEXITY: O(N log M) — for the concatenated string
Note: Manual digit extraction approach achieves same time but O(1) space.
 
====================================================================
*/