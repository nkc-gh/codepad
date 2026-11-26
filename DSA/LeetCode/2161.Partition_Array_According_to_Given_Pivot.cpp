/*
====================================================================
LeetCode 2161 - Partition Array According to Given Pivot
====================================================================
 
+------------------------------------------------------------------+
| Difficulty - Medium                                              |
| Date of Submission - 26 November 2026 16:07                      |
| Tags - Array, Two Pointers, Simulation                           |
+------------------------------------------------------------------+
 
You are given a 0-indexed integer array nums and an integer pivot.
Rearrange nums such that:
- Every element less than pivot appears before every element greater than pivot.
- Every element equal to pivot appears in between.
- Relative order of elements less than and greater than pivot is maintained.
Constraints:
1 <= nums.length <= 10^5
-10^6 <= nums[i] <= 10^6
pivot equals to an element of nums.
 
Example 1:
Input: nums = [9,12,5,10,14,3,10], pivot = 10
Output: [9,5,3,10,10,12,14]
 
Example 2:
Input: nums = [-3,4,3,2], pivot = 2
Output: [-3,2,4,3]
 
====================================================================
*/
 
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> num1;
        vector<int> num2;
        vector<int> num3;
 
        for(int i=0 ; i<nums.size() ; i++){
            if(nums[i]<pivot){
                num1.push_back(nums[i]);
            }
            else if(nums[i]==pivot){
                num2.push_back(nums[i]);
            }
            else{
                num3.push_back(nums[i]);
            }
        }
 
        nums.clear();
        nums.insert(nums.end(), num1.begin(), num1.end());
        nums.insert(nums.end(), num2.begin(), num2.end());
        nums.insert(nums.end(), num3.begin(), num3.end());
 
        return nums;
    }
};
 
/*
====================================================================
SOLUTION IN MY WORDS
====================================================================
 
Since classic quicksort's in-place partition breaks relative order
(it's not stable), used a three-array simulation approach instead.
 
Pass 1 — iterate nums and distribute elements into 3 buckets:
num1 (< pivot), num2 (== pivot), num3 (> pivot).
Relative order is maintained naturally since we iterate left to right.
 
Pass 2 — clear nums and merge the three buckets back using insert:
nums.insert(nums.end(), vecName.begin(), vecName.end())
This appends elements one by one (not nested), so result is flat.
 
====================================================================
COMPLEXITY
====================================================================
 
1. TIME COMPLEXITY:
Pass 1 - distribution loop: O(N)
Pass 2 - three inserts combined: O(N)
 
Total: O(N)
 
2. SPACE COMPLEXITY:
Three extra vectors holding all N elements total: O(N)
 
====================================================================
*/