# DSA

DSA stands for **Data Structures and Algorithms**.

## Index

- [What Is DSA](#what-is-dsa)
- [A Little History](#a-little-history)
- [Complexity — Time and Space](#complexity--time-and-space)
- [Asymptotic Notation — Big O, Big Ω, Big Θ](#asymptotic-notation--big-o-big-ω-big-θ)
- [How To Actually Calculate Complexity](#how-to-actually-calculate-complexity)
- [Common Complexity Classes](#common-complexity-classes)

## What Is DSA

**Data** is just information — numbers, characters, values — stored somewhere in memory so a program can use it. On its own, raw data doesn't have any particular shape or organization.

A **data structure** is a **way of arranging and storing that data** so it can be used efficiently for a particular kind of problem.

An **algorithm** is a **finite, step-by-step procedure** to solve a problem or complete a task. It must be:

- Well-defined (no guesswork, no ambiguity in the steps)
- Finite (it has to actually end, not run forever)
- Effective (each step is something that can actually be carried out)

Put together:

```text
Data             = raw information.
Data structure   = an organized way to store that information.
Algorithm        = a recipe — follow the steps in order, get the result.
DSA              = the combination: how you store data + the steps you use to process it.
```

They're almost always discussed together because the data structure you pick directly affects how fast (or slow) your algorithm can be. A sorting algorithm behaves very differently on an array versus a linked list. An array is great for accessing something by position instantly, but bad for inserting in the middle; a linked list is the opposite. Choosing the structure *is* part of designing the algorithm — picking the right one for the right job is half of problem-solving in CP.

## A Little History

Both halves of "DSA" are old, older than computers themselves in one case.

- The word **algorithm** comes from **al-Khwārizmī**, a 9th-century Persian mathematician who popularized doing math with step-by-step procedures using decimal notation — the approach was called "algorism," which is where the word "algorithm" eventually came from.
- The world's first algorithm designed to run on a machine was written by Ada Lovelace in the 1840s, for Charles Babbage's proposed mechanical computer, the Analytical Engine — before electronic computers even existed.
- Modern **data structures and algorithms as a formal computing discipline** trace back to Alan Turing's 1936 paper describing a universal machine capable of carrying out any algorithm, which laid the groundwork for computer science as a field.
- Through the 1950s and 60s, most of the data structures and algorithms studied today were formalized — arrays, linked lists, binary search trees, hash maps, stacks, and sorting algorithms like merge sort (credited to John von Neumann).
- Through the 60s and 70s, more advanced structures (hash tables, BSTs) and algorithms (quicksort, mergesort) were developed, forming the backbone of modern computing and eventually becoming central to technical interviews and competitive programming.

---

## Complexity — Time and Space

**Time complexity** measures how the **number of operations** a piece of code performs grows as the input size (`n`) grows. It is *not* a literal stopwatch measurement of seconds — it's about the **growth trend**, i.e., "if I double the input, does my code's work roughly double, roughly stay the same, roughly quadruple, or explode?"

**Space complexity** measures how the **extra memory** a piece of code needs (beyond the input itself) grows as `n` grows. A fixed number of variables (however many times their *values* change) does not count — what counts is whether you need *more memory slots* (a new array, a new container, extra storage per element) as input grows.

Simple idea:

```text
Time complexity  -> how work scales with input size.
Space complexity -> how extra memory scales with input size.
Both ignore raw constants and hardware speed — they measure trend, not seconds.
```

## Asymptotic Notation — Big O, Big Ω, Big Θ

Complexity isn't just "one number" — it's a description of how an algorithm's cost grows relative to `n`, and there are three standard notations depending on *which bound* you're describing. Big O is the one used casually 90% of the time, but Ω and Θ are the other two corners of the same idea.

### Big O — upper bound (worst case)

Big O describes the **worst-case upper bound** — the most work an algorithm could possibly do for a given `n`. It answers: "this will never be slower than ___."

Key rules of Big O:

1. **Drop constants.** `O(2n)` becomes `O(n)`. Whether the loop runs `n` times or `n-1` times or `2n` times, for large `n` the difference is insignificant — only the shape of growth matters.
2. **Keep only the dominant term.** If a function does `O(1) + O(1) + O(n) + O(1)` worth of work across different lines, the total is just `O(n)` — the fastest-growing term swallows the smaller ones as `n` gets large.
3. **Worst case, by default.** Unless stated otherwise, Big O describes the worst-case scenario.
4. **One variable's operation is O(1), a loop over n items is O(n), a loop over a loop is O(n²), and so on** — the exponent/degree grows with how many "layers" of iteration scale with input size.

### Big Ω (Omega) — lower bound (best case)

Big Ω describes the **best-case lower bound** — the least amount of work an algorithm will ever do for a given `n`. It answers: "this will never be faster than ___."

Example: linear search for a target has Ω(1) — if the target happens to be the first element, it's found in one check, and no algorithm scanning an unsorted array can guarantee doing *less* than that in the best possible arrangement of the data.

### Big Θ (Theta) — tight bound (when best = worst)

Big Θ describes a **tight bound** — used when the upper bound (O) and lower bound (Ω) are the *same* growth rate, meaning the algorithm does that amount of work regardless of the specific input arrangement, not just on average.

Example: summing all `n` elements of an array is Θ(n) — there is no lucky or unlucky input; it always takes a single full pass, so best case and worst case coincide.

```text
Big O (O) -> worst case  -> "at most this much work"
Big Ω (Ω) -> best case   -> "at least this much work"
Big Θ (Θ) -> tight bound -> "exactly this much work" (used when O and Ω match)
```

In everyday conversation, "complexity" almost always means Big O, since worst-case guarantees are what matter most for reliability — but Ω and Θ are what let you say something more precise, like "quicksort is O(n²) worst case but Θ(n log n) on average with a good pivot."

## How To Actually Calculate Complexity

### PART 1 — General Rules (apply to ANY code, loop or recursive)

**Time — building blocks:**

1. **Any single operation** (assignment, arithmetic, comparison, one array/vector index access `arr[i]`, `.size()` on an STL container) → **O(1)**.
2. **One loop scanning n items once, O(1) work per iteration** → **O(n)**. Holds even with an `if` checked every iteration whose body also runs up to n times worst case — sums to `O(n)+O(n)=O(2n)→O(n)`.
3. **Two+ separate loops, one after another, not nested** → **added**: `O(n)+O(m) → O(n+m)`. Only *nested* loops multiply.
4. **Loop nested inside a loop, both scaling with n** → **O(n²)**. Three nested → O(n³).
5. **Inner loop's range depends on outer loop's position** (e.g. `for j = i to n`) → total iterations sum to ~n²/2 → still **O(n²)**.
6. **Loop that halves/divides the problem by a constant factor each time** (binary search, or a plain `while(n>1) n=n/2`) → **O(log n)**.
7. **Loop scanning n items where each item does a halving-style or sorting step** → **O(n log n)**. Treat a built-in efficient `sort()` as a known O(n log n) cost.
8. **Multiple independent inputs of different sizes** → keep separate: **O(n + m)**, don't collapse to one variable unless guaranteed equal.
9. **Two pointers moving through one array once** (from both ends, or fast/slow) → still a single pass, **O(n)**, not O(n²) — nothing is nested.
10. **Amortized cost** — an operation usually O(1) but occasionally O(n) (e.g. vector's `push_back` on resize) → total over n calls is **O(n) overall, O(1) amortized per call**, not O(n²). A loop calling such an operation n times is still O(n) total.
11. **Best / Average / Worst case can genuinely differ for the same code** (quicksort: O(n log n) average, O(n²) worst case if pivot choice is unlucky; hash map lookup: O(1) average, O(n) worst case on collisions). Default to worst case unless stated otherwise — but know it isn't always the only meaningful number (this is exactly where Ω and Θ from the section above come in).
12. **Graph/tree traversal** — "n" often isn't one shrinking number; complexity is usually stated in terms of vertices and edges: **O(V + E)** for a full traversal (BFS/DFS) touching every vertex and edge once.
13. **Recursion with memoization / DP** — complexity is **(number of distinct subproblems) × (work per subproblem, excluding recursive calls)** — NOT branching^depth. This is because each unique subproblem is computed once and reused, collapsing what would otherwise be exponential repeated work.
14. **Known data structure operations, treated as trusted building blocks** once learned, rather than re-derived each time: balanced BST insert/search ~O(log n), hash map insert/lookup ~O(1) average, heap push/pop ~O(log n).

**Space — building blocks:**

1. **Fixed number of variables**, regardless of value changes, as long as the *count* doesn't grow with n → **O(1)**.
2. **New array/vector/set/map/string holding ~one entry per input element** → **O(n)**.
3. **Modifying input in-place, no new container** → doesn't add to space complexity.
4. **2D array/grid sized around input** (n×n or n×m) → **O(n²)** or **O(n·m)**.
5. **New structure whose size depends on something other than n directly** (e.g. output sized by results found) → express in its own terms, don't assume O(n).
6. **Recursion's own extra space = call stack depth** (how many calls are simultaneously waiting, not total calls made) — generally how far down you go before hitting the base case.
7. **Memoization adds its own space** — the cache/table storing subproblem results, on top of whatever stack depth exists, e.g. O(n) for a 1D memo array, O(n×m) for a 2D one.

---

### PART 2 — Methods (HOW to actually apply the rules above)

**Method A — Iterative code (loops, straight-line):** read top to bottom, assign each line/block a complexity using Part 1's rules, add them up, simplify with Big O (drop constants, keep the dominant term). This is direct — no equation-solving needed, just reading and summing.

**Method B — Brute-force / manual counting (verification tool, any code):** actually run or hand-trace the code for small inputs (n=1,2,3,4...), count real operations or calls, and look for a numeric pattern (e.g. 1,3,7,15 → 2ⁿ-1). This doesn't replace proper analysis, but it's the fastest way to catch a wrong assumption — if your formula-based answer doesn't match what you count by hand on a small case, one of them is wrong.

**Method C — Recursion, via recurrence relations (substitution/unrolling):**
1. Define `T(n)` = cost of running the function on input size n.
2. Read the code, assign cost to each part in terms of T: each recursive call → `T(smaller size)`; everything else → O(1), or Part 1's rules if a loop exists inside.
3. Sum it up into a recurrence: `T(n) = a·T(n/b) + f(n)` or `T(n) = a·T(n-c) + f(n)`, where `a`=calls per invocation, `n/b` or `n-c`=how much smaller, `f(n)`=extra work per call.
4. Write the base case, e.g. `T(1)=O(1)`.
5. Solve via substitution/unrolling: plug the rule into itself repeatedly, spot the pattern, generalize to "after k substitutions," solve for k reaching the base case, substitute back, apply Big O.
6. Cross-check with Method B on small n.

   **Shortcuts once you recognize the shape:** `a` calls, fixed subtraction, no extra per-call work → O(aⁿ). 1 call, divide by constant, O(1) extra work → O(log n). 1 call, shrink by 1, O(n) extra work per call → O(n²).

   **When calls are unequal size or condition-dependent** (Fibonacci-style `f(n-1)+f(n-2)`, or backtracking): a clean formula won't fit — draw the recursion tree, bound the total leaf calls instead. Still generally exponential for unequal-but-similar splits; backtracking needs per-problem reasoning about how pruning cuts the tree.

**Method D — Recursion, via the Master Theorem (shortcut for divide-and-conquer, `a·T(n/b) + f(n)` shape only):**

Instead of unrolling by hand every time, the Master Theorem gives a direct formula for any recurrence of the form:

```text
T(n) = a·T(n/b) + f(n)
```
where `a ≥ 1` (number of subproblems), `b > 1` (factor the size shrinks by), and `f(n)` is the extra work done outside the recursive calls (dividing + combining).

Compare `f(n)` against `n^(log_b(a))` — this value is the "critical exponent," the cost if only the branching mattered with no extra per-call work:

1. **Case 1 — recursion dominates:** if `f(n) = O(n^(log_b(a) - ε))` for some `ε > 0` (i.e., `f(n)` grows strictly slower) → **T(n) = Θ(n^(log_b(a)))**.
2. **Case 2 — balanced:** if `f(n) = Θ(n^(log_b(a)))` (same growth rate, matching exactly) → **T(n) = Θ(n^(log_b(a)) · log n)**.
3. **Case 3 — extra work dominates:** if `f(n) = Ω(n^(log_b(a) + ε))` for some `ε > 0` (i.e., `f(n)` grows strictly faster), *and* it satisfies the regularity condition `a·f(n/b) ≤ c·f(n)` for some `c < 1` → **T(n) = Θ(f(n))**.

If none of the three cases cleanly applies (there's a gap, or the regularity condition fails), the Master Theorem doesn't give an answer — fall back to Method C (substitution).

This only applies to divide-and-conquer style recurrences of exactly that `a·T(n/b) + f(n)` shape — it does not apply to subtractive recurrences like Tower of Hanoi's `T(n-1)+T(n-1)`, which need Method C instead.

---

### Worked Examples

**1. Single loop — Remove Duplicates from Sorted Array:**
```c
int n = nums.size();  int j = 0;             // O(1) each
for (int i = 1; i < n; i++)
    if (nums[i] != nums[j]) { j++; nums[j] = nums[i]; }
return j + 1;
```
Method A: O(1)+O(1)+O(n)+O(1) → **O(n)** time, **O(1)** space.

**2. Nested loop — checking all pairs:**
```c
for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
        // O(1) work
```
Method A: n×n → **O(n²)** time, **O(1)** space.

**3. Two pointers — single pass:**
```c
int i = 0, j = n-1;
while (i < j) 
{ i++; j--; } // O(n)
```
Method A + rule 9: one combined pass → **O(n)**, not O(n²).

**4. Recursive, uniform branching — Tower of Hanoi:**
```c
void toh(int n, ...) {
    if (n == 1) { print; return; } // T(1) -> Base Case
    toh(n-1, ...); print; // T(n-1)
    toh(n-1, ...); // T(n-1)
}
```
Method C: `T(n) = 2·T(n-1) + O(1)` → substitution → `T(n)=2^(n-1)·c + 2^(n-1)-1` → **O(2ⁿ)**. Cross-checked (Method B) via brute count 1,3,7,15 → 2ⁿ-1, and the aⁿ shortcut. Space: stack depth n → **O(n)**. (Subtractive shape — Master Theorem does not apply here.)

**5. Divide and conquer — Merge Sort, via Master Theorem:**
```c
void mergeSort(int arr[], int n) {
    if (n <= 1) return;
    mergeSort(left_half, n/2);   // T(n/2)
    mergeSort(right_half, n/2);  // T(n/2)
    merge(left_half, right_half); // O(n) to merge
}
```
Method D: recurrence is `T(n) = 2·T(n/2) + O(n)`, so `a=2`, `b=2`, `f(n)=O(n)`. Critical exponent: `n^(log_b(a)) = n^(log_2(2)) = n^1 = n`. Since `f(n) = Θ(n)` matches the critical exponent exactly → **Case 2** → **T(n) = Θ(n log n)**. Space: O(n) for the temporary merge arrays.

**6. Divide and conquer — Binary Search, via Master Theorem:**
```c
int bsearch(int arr[], int lo, int hi, int target) {
    if (lo > hi) return -1;
    int mid = (lo+hi)/2;      // O(1)
    if (arr[mid] == target) return mid;
    return bsearch(...half...); // T(n/2)
}
```
Method D: `T(n) = 1·T(n/2) + O(1)`, so `a=1`, `b=2`, `f(n)=O(1)`. Critical exponent: `n^(log_2(1)) = n^0 = 1`. `f(n) = Θ(1)` matches exactly → **Case 2** → **T(n) = Θ(log n)** (the `log n` factor collapses cleanly since `n^0=1`).

## Common Complexity Classes

From fastest to slowest, in increasing order of growth as `n` gets large:

```text
O(1)        Constant     - doesn't depend on input size at all
O(log n)    Logarithmic  - cuts problem size down repeatedly (e.g. binary search)
O(n)        Linear       - one full pass through the input
O(n log n)  Linearithmic - a pass combined with a log-time step (e.g. efficient sorting)
O(n²)       Quadratic    - nested loop over the input (loop inside a loop)
O(n³)       Cubic        - triple nested loop
O(2ⁿ)       Exponential  - roughly doubles with every additional input element (brute force subsets)
O(n!)       Factorial    - every possible ordering (brute force permutations)
```