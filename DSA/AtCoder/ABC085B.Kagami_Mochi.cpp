/*
====================================================================
AtCoder ABC085B - Kagami Mochi
====================================================================

Given N mochi with diameters d1..dN, find the maximum number of
layers a kagami mochi can have. Each layer must have a strictly
smaller diameter than the one directly below it. The answer is
simply the number of distinct diameter values in the input.

Constraints:
1 <= N <= 100
1 <= di <= 100
All input values are integers.

Input format:
N
d1
d2
:
dN

Example 1:
Input:        Output: 3
4
10
8
8
6

Example 2:
Input:        Output: 1
3
15
15
15

Example 3:
Input:        Output: 4
7
50
30
50
100
50
80
30
====================================================================
*/

#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int mochi[100];

    for (int i = 0; i < N; i++) {
        cin >> mochi[i];
    }

    bool visited[101] = {};
    int count = 0;

    for (int i = 0; i < N; i++) {
        if (visited[mochi[i]] == false) {
            visited[mochi[i]] = true;
            count++;
        }
    }

    cout << count << '\n';

    return 0;
}

/*
====================================================================
SOLUTION IN MY WORDS
====================================================================

Recognized that the maximum number of layers equals the number of
distinct diameters in the input - each unique diameter contributes
exactly one layer, and duplicates can only be used once since each
layer must be strictly smaller than the one below.

First idea: use a boolean tracking array indexed by diameter value.
If visited[d] is false, this diameter hasn't been seen yet - mark
it true and increment count. Each unique value is counted exactly
once in a single pass, giving O(N) time.

Hit a design question immediately: what size should the tracking
array be? First instinct was to size it by N (number of elements),
but that's wrong - the array is indexed by the DIAMETER VALUE, not
by position. If N=3 but diameters are 50, 80, 100, then
visited[50], visited[80], visited[100] would all be out of bounds
for an array of size 3. The index into the tracking array must
cover the range of possible VALUES, not the count of elements.

The constraints fix this: 1 <= di <= 100, so diameters are always
integers in [1, 100]. A visited array of size 101 covers every
possible diameter value safely (indices 0 through 100, where index
0 is simply never used since di >= 1). This is why a tracking array
works here - the value range is small and fully known from the
constraints.

Confirmed the general rule: a boolean tracking array is safe when
the input values fall in a known, bounded range and can be used
directly as array indices. For arbitrary integers (negative values,
large values, or unknown ranges) this breaks - an out-of-bounds
index either crashes or silently corrupts memory.

Also considered two alternatives before settling on this approach:

O(N^2) comparison: for each element, scan all previous elements to
check for a duplicate. Works correctly for any integer range, but
slow for large N.

Sorting then scanning: sort the array in O(N log N), then walk it
once comparing each element to the previous - adjacent duplicates
become neighbors after sorting, so a single pass counts distinct
values. More general than the boolean array approach since it
handles any integer range, at the cost of O(N log N) instead of
O(N). For this problem's constraints either works, but the boolean
array is simpler to implement.

One syntax note: wrote int arr[N] initially before remembering this
is a variable-length array (VLA). VLAs are supported in C but not
in standard C++. In standard C++, the array size must be a
compile-time constant. Since the constraints cap N at 100, using
int mochi[100] with a fixed size is the correct approach here.
The general alternative for runtime-sized arrays in C++ is
vector<int> arr(N).

====================================================================
COMPLEXITY
====================================================================

1. TIME COMPLEXITY:

cin >> N                              -> O(1)
for loop reading N diameters          -> O(N)
for loop over N elements              -> O(N)
    visited[mochi[i]] check + update     -> O(1), direct index
cout << count                          -> O(1)

Total: O(N), two linear passes over the input with O(1) work each.

2. SPACE COMPLEXITY:

mochi[100]    -> O(1), fixed-size array, size does not grow with N
visited[101]  -> O(1), fixed-size array, size does not grow with N
count, i, N   -> O(1)

Total: O(1), all arrays are fixed at compile time regardless of N.

3. COMMON MISTAKES PEOPLE MAKE ON THIS PROBLEM:

- Sizing the visited array by N instead of by the value range -
  visited[N] means indices 0 to N-1, but the diameters being stored
  can be up to 100, causing out-of-bounds access when N < diameter
  value. The array must be sized to cover the VALUE range, not the
  element count.

- Using a tracking array without checking constraints first - this
  approach only works when values fall in a small, known range and
  can serve as direct array indices. For arbitrary integers it
  causes out-of-bounds access or requires a huge array.

- Sorting and then comparing adjacent pairs but forgetting that
  duplicates must be skipped, not counted extra - after sorting,
  only increment count when mochi[i] != mochi[i-1].

- Using int arr[N] with a runtime variable N - this is a VLA, valid
  in C but not in standard C++. Use a fixed-size array (when the
  max is known from constraints) or vector<int> arr(N) instead.
*/