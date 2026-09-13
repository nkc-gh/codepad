/*
====================================================================
LeetCode 1 - Two Sum (Easy)
====================================================================

Given an array of integers nums and an integer target, return
indices of the two numbers that add up to target. Exactly one
solution is guaranteed to exist, the same element cannot be used
twice, and the answer can be returned in any order.

Follow-up in the problem statement explicitly asks for a solution
faster than O(n^2), which ruled out the standard nested-loop brute
force from the start - went straight for a single-pass approach
instead of writing the O(n^2) version first.

Constraints:
2 <= nums.length <= 10^4
-10^9 <= nums[i] <= 10^9
-10^9 <= target <= 10^9
Only one valid answer exists.

Example 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]

Example 2:
Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:
Input: nums = [3,3], target = 6
Output: [0,1]
====================================================================
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> seen;
        int sub;
        for(int i=0 ; i<nums.size() ; i++){
            sub = target - nums[i];
            if(seen.count(sub)){
                return {seen[sub] , i};
            }
            else{
                seen[nums[i]] = i;
            }
        }

        return {};
    }
};

/*
====================================================================
SOLUTION IN MY WORDS
====================================================================

Since the follow-up explicitly asked for better than O(n^2), the
brute-force nested loop (check every pair directly) was skipped
entirely - the goal from the start was to avoid the "scan the rest
of the array for a match" pattern that makes brute force slow, and
find a way to check "have I seen the number I need" in better than
O(n) per check.

First confusion was around what to actually store and how. Initial
instinct was to build a map going index -> number (map[0]=2,
map[1]=7, etc.), which is really just the original array again -
this doesn't help, since looking up "does the value 7 exist
somewhere in this map" still requires scanning every entry, as fast
O(1) lookup only works in the key -> value direction, never
value -> key. Realized this by working through a small dictionary
analogy first: a real dictionary lets you look up a word's meaning
instantly, but finding "which word means happy" requires scanning
every entry - same asymmetry applies to unordered_map.

Once that clicked, reframed what's actually needed: for each
nums[i], compute its complement (target - nums[i]), and ask "does
this complement already exist among numbers I've seen so far, and
if so, at what index." Since the thing being searched FOR is the
complement (a number), the number must be the KEY (since only keys
get fast lookup), and the index becomes the VALUE, since that's the
extra information needed once a match is found.

This gives the structure: unordered_map<int,int> seen, where
seen[number] = index. Walking the array left to right: at each
index i, first check if the complement (target-nums[i]) is already
a key in seen (using seen.count(...)) - if yes, immediately return
the current index and the previously-stored index. If not found,
store the CURRENT number (not the complement) into seen before
moving on, so it's available for some FUTURE index to find as ITS
complement.

Traced this on [2,7,11,15], target=9: i=0, nums[0]=2, complement=7,
not in seen (empty) -> store seen[2]=0. i=1, nums[1]=7,
complement=2, IS in seen (seen[2]=0) -> return {seen[2], i} =
{0, 1}. Matches expected output directly.

Checking only against numbers seen so far (not the whole array,
including ahead) also naturally satisfies "may not use the same
element twice" - since the complement is checked against strictly
earlier entries, an element can never match against itself.

Minor syntax issues while writing the return statement: first wrote
nums.length() (a string method) instead of nums.size() (the correct
vector method) - confused which container the method belonged to.
Also first tried returning with Python/JS-style bracket syntax,
return [i, seen[sub]], which isn't valid C++; fixed by using
vector's brace-initializer syntax, return {i, seen[sub]};, and had
to also remember the function needs SOME return reachable on every
code path (even though the loop is guaranteed by the problem's
constraints to always return early) - added a trailing return {};
as an unreachable-but-required fallback for a non-void function.

Also noticed the initial correct version returned {i, seen[sub]},
which sometimes came out in descending order (e.g. {1,0} instead of
{0,1}) - allowed per the problem ("return the answer in any order"),
but switched to {seen[sub], i} instead, since seen[sub] is always
an earlier (smaller) index than the current i by construction (it
was necessarily stored in a previous iteration), making the output
naturally ascending without any extra sorting logic.

====================================================================
COMPLEXITY
====================================================================

1. TIME COMPLEXITY:

for loop over n elements       -> O(n) iterations
    seen.count(sub)              -> O(1) average (hash table lookup)
    seen[nums[i]] = i             -> O(1) average (hash table insert)

Total: O(n), a single pass over the array with O(1) average work
per element - meets the follow-up's requirement of beating O(n^2).

2. SPACE COMPLEXITY:

seen -> O(n) in the worst case, if no match is found until the very
    last element, requiring nearly all n numbers to be stored

Total: O(n)

3. COMMON MISTAKES PEOPLE MAKE ON THIS PROBLEM:

- Storing index -> number in the map instead of number -> index -
  this only reproduces the original array in map form and doesn't
  enable fast lookup by value, since unordered_map only supports
  fast lookup by key, not by value.

- Checking the complement against the ENTIRE array (including
  elements ahead of the current index) instead of only elements
  seen so far - besides being unnecessary, this risks incorrectly
  matching an element with itself when nums[i] happens to equal its
  own complement (e.g. target = 2*nums[i]).

- Storing the current number into the map only AFTER checking for
  its own complement, but in the wrong order relative to the check -
  storing nums[i] into seen BEFORE checking whether nums[i] itself
  already satisfies some earlier index's complement would allow an
  element to incorrectly pair with itself in edge cases.

- Using nums.length() instead of nums.size() - length() is a
  std::string method, size() is the correct method for std::vector;
  calling the wrong one causes a compile error.

- Forgetting that a non-void function needs a reachable return on
  every code path, even when problem constraints guarantee a
  solution always exists within the loop - the compiler cannot
  reason about problem-specific guarantees and may warn or error
  about a missing return after the loop.
*/