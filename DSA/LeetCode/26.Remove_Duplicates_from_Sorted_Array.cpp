/*
====================================================================
LeetCode 26 - Remove Duplicates from Sorted Array
====================================================================

+------------------------------------------------------------------+
| Difficulty - Easy                                                |
| Date of Submission - 13 August 17:28 PM                          |
| Tags - array, two pointers                                       |
+------------------------------------------------------------------+

Given an integer array nums sorted in non-decreasing order, remove
the duplicates in-place such that each unique element appears only
once. The relative order of the elements should be kept the same.

Let k = number of unique elements in nums after removing duplicates.
Return k. The first k elements of nums must hold the unique values
in sorted order. Elements beyond index k-1 do not matter.

Constraints:
1 <= nums.length <= 3 * 10^4
-100 <= nums[i] <= 100
nums is sorted in non-decreasing order.

Example 1:
Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]

Example 2:
Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
====================================================================
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int j = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[j]) {
                j++;
                nums[j] = nums[i];
            }
        }
        return j + 1;
    }
};

/*
====================================================================
SOLUTION IN MY WORDS
====================================================================

First thing I noticed: array is already sorted, so duplicates are
always sitting right next to each other, never scattered. That's
the whole reason this problem is even solvable in O(1) space -
if it wasn't sorted I'd have needed a set or sort it first.

My first instinct was wrong - I thought about swapping duplicate
with the last element and shrinking the array from the back. Traced
it by hand and saw it destroys the sorted order, since it dumps a
big number into an early position. Sorted order has to be preserved,
so swapping-from-the-back is out.

Second wrong idea - compare adjacent i and j, and when equal, do
a(j) = a(j+1). Traced this on paper too and saw i and j moving
together does nothing useful, they just re-check the same duplicate
over and over and never actually advance past a run of duplicates.

What actually clicked: I don't need to "delete" anything. The
problem straight up says it doesn't matter what's beyond index k-1,
so I'm free to just overwrite. That's when the two-pointer idea
made sense -

j marks the last unique value I've confirmed so far (the "clean"
boundary). i scans ahead through everything. Every single time
nums[i] is different from nums[j], that means I found a genuinely
new value - so j moves forward one step and I write nums[i] into
that new j slot. If nums[i] equals nums[j], it's just a duplicate
of what I already have, so I do nothing and let i keep moving.

Key thing I had to get right: compare against nums[j] (the last
kept unique), not nums[i-1] (whatever's immediately behind i).
Comparing with i-1 breaks if the same value repeats 3+ times, since
i-1 could itself be an already-skipped duplicate.

By the time i finishes scanning the whole array, j points to the
last unique value's position. Since j is an index (0-based) and I
need a count, the answer is j+1, not j.

Edge case: array can't be empty per constraints (n>=1), so I didn't
need a guard for n==0, but if this were a variant without that
guarantee I'd check that first before touching nums[0].


====================================================================
COMPLEXITY
====================================================================

1. TIME COMPLEXITY:

int n = nums.size();              -> O(1)
int j = 0;                        -> O(1)

for (int i = 1; i < n; i++) {     -> O(n), runs n-1 times
    if (nums[i] != nums[j]) {     -> O(n), checked every iteration
        j++;                      -> O(n) worst case, up to n-1 times
        nums[j] = nums[i];        -> O(n) worst case, up to n-1 times
    }
}
return j + 1;                     -> O(1)

Total: O(1) + O(1) + O(n) + O(n) + O(n) + O(1) -> O(n)

2. SPACE COMPLEXITY:

n, i, j -> 3 fixed variables, O(1). No extra memory slots for these when they grow.

Total: O(1)
*/
