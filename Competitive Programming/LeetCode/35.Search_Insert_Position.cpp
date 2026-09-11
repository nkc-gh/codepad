/*
====================================================================
LeetCode 35 - Search Insert Position (Easy)
====================================================================

Given a sorted array of distinct integers and a target value, return
the index if the target is found. If not, return the index where it
would be if it were inserted in order.

Must write an algorithm with O(log n) runtime complexity.

Constraints:
1 <= nums.length <= 10^4
-10^4 <= nums[i] <= 10^4
nums contains distinct values sorted in ascending order.
-10^4 <= target <= 10^4

Example 1:
Input: nums = [1,3,5,6], target = 5
Output: 2

Example 2:
Input: nums = [1,3,5,6], target = 2
Output: 1

Example 3:
Input: nums = [1,3,5,6], target = 7
Output: 4
====================================================================
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        while(low <= high){
            int middle = (low + high)/2;
            if(nums[middle] == target){
                return middle;
            }
            else if(target < nums[middle]){
                high = middle - 1;
            }
            else{
                low = middle + 1;
            }
        }

        return low;
    }
};

/*
====================================================================
SOLUTION IN MY WORDS
====================================================================

O(log n) requirement was the giveaway - straight to binary search.
I could handle the "found" case easily, but the part I was stuck on
was: if target isn't in the array, how do I know where it *should*
go?

I first messed up the setup itself - wrote `int low = nums[0]` and
`int high = nums[nums.size()-1]`, mixing up index with value. low
and high are supposed to be indices into the array, not the actual
numbers stored there. Fixed to `low = 0`, `high = nums.size()-1`.

For the actual insertion logic, I traced target=2 on [1,3,5,6] by
hand:
- mid=1, nums[1]=3, target(2) < 3, so high = mid-1 = 0
- mid=0, nums[0]=1, target(2) > 1, so low = mid+1 = 1
- now low=1, high=0, low>high, loop ends, target not found

Checked: correct insertion index for 2 in [1,3,5,6] is also 1
(gives [1,2,3,5,6]). low matched exactly.

Understood why this always works: every time low moves forward
(low=mid+1), it's because nums[mid] < target - so low always steps
past values smaller than target, landing right after them. Every
time high moves back (high=mid-1), it's because nums[mid] > target
- so high steps past values bigger than target. When the loop ends,
low = high+1, and by construction everything before low is smaller
than target and everything from low onward is bigger (or equal, if
found). So low IS the correct insertion index whether or not target
was actually found in the array.

Also fixed a smaller bug - had `int middle = (low+high)/2` computed
only once before the while loop, so it never updated when low/high
changed inside the loop. Moved it inside the loop so it recalculates
every iteration.

====================================================================
COMPLEXITY
====================================================================

1. TIME COMPLEXITY:

int low = 0;                          -> O(1)
int high = nums.size() - 1;           -> O(1)

while(low <= high){                   -> O(log n), per README rule 6
                                          (halves the search space
                                          each iteration)
    int middle = (low + high)/2;      -> O(1) per iteration
    if(nums[middle] == target)        -> O(1) per iteration
        return middle;
    else if(...) high = middle - 1;   -> O(1) per iteration
    else low = middle + 1;            -> O(1) per iteration
}

return low;                           -> O(1)

Total: O(1) + O(1) + O(log n) + O(1) -> O(log n)

2. SPACE COMPLEXITY:

low, high, middle -> 3 fixed variables, no extra array/container,
no recursion.

Per README space rule 1 -> O(1)

Total: O(1)

3. COMMON MISTAKES PEOPLE MAKE ON THIS PROBLEM:

- Doing a full linear scan (checking each element one by one) and
  only using binary search's O(log n) requirement as a suggestion
  rather than a hard constraint - passes correctness but fails the
  stated complexity requirement (though LeetCode won't flag this
  automatically unless timing on huge inputs is tested).

- Setting up low/high with actual array values instead of indices
  (e.g. `low = nums[0]`) instead of `low = 0` - breaks the whole
  index-arithmetic that binary search depends on.

- Using `high = middle` instead of `high = middle - 1` (or vice
  versa for low) without adjusting the loop condition accordingly -
  mixing invariants from different binary search styles causes
  infinite loops or off-by-one wrong answers.

- Returning `middle` or some other variable instead of `low` when
  target isn't found - forgetting that `low` specifically is what
  ends up holding the correct insertion index once the loop exits.

- Computing `middle` once outside the while loop instead of inside
  it, so it never updates as low/high change across iterations.
*/